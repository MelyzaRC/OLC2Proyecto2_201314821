#include "negacion_unaria.hpp"

negacion_unaria::negacion_unaria(int line, int col, expression *exp)
{
    this->Line = line;
    this->Col = col;
    this->valor = exp;
    this->tipo = 3;
}

value negacion_unaria::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    gen->MainCode = true;
    value op1 = this->valor->traducir(env, tree, gen);
    if(op1.TipoExpresion != NULO){
        std::string tmpR = gen->newTemp();
        if(op1.TipoExpresion == INTEGER){
            gen->AddExpression(tmpR, op1.Value,"-1","*");
            value val(tmpR, true, INTEGER);
            return val;
        }
        else if(op1.TipoExpresion == FLOAT){
            gen->AddExpression(tmpR, op1.Value,"-1","*");
            value val(tmpR, true, FLOAT);
            return val;
        }
        else if(op1.TipoExpresion == BOOL){
            std::string Lt = gen->newLabel();
            std::string Lf = gen->newLabel();
            std::string Ls = gen->newLabel();

            gen->AddIf(op1.Value,"1","==", Lt);
            gen->AddGoto(Lf);
            gen->AddLabel(Lt);
            gen->AddAssign(tmpR, "0");
            gen->AddGoto(Ls);
            gen->AddLabel(Lf);
            gen->AddAssign(tmpR, "1");
            gen->AddGoto(Ls);
            gen->AddLabel(Ls);
            value val(tmpR, true, BOOL);
            return val;
        }
        else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede negar una expresion de tipo ";
            contenido_error += env->obtenerTipo(op1.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }
    }
    return val;
}


symbol negacion_unaria::ejecutar(environment *env, asttree *tree){

    symbol sym = this->valor->ejecutar(env, tree);
    switch (sym.Tipo) {
        case INTEGER:{
            int* res = new int;
            int resultado = (int)*static_cast<int*>(sym.valor)*-1;
            *res = resultado;
            return *new symbol(Line, Col, "", INTEGER, res);
            }
        break;
        case FLOAT:{
            float* res = new float;
            float resultado = (float)*static_cast<float*>(sym.valor)*-1.0;
            *res = resultado;
            return *new symbol(Line, Col, "", FLOAT, res);
            }
        break;
        case STRING:{
        //ERROR SEMANTICO
            std::string contenido_error =  "No se puede negar el tipo ";
            contenido_error += env->obtenerTipo(sym.Tipo);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            return *new symbol(Line, Col, "", NULO, nullptr);
            }
            break;
        case BOOL:
            {
                bool* res = new bool;
                bool resultado = !((bool)*static_cast<bool*>(sym.valor));
                *res = resultado;
                return *new symbol(Line, Col, "", BOOL, res);
            }
            break;
    }
    //ERROR SEMANTICO
        std::string contenido_error =  "No se puede negar el tipo ";
        contenido_error += env->obtenerTipo(sym.Tipo);
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;
    return *new symbol(Line, Col, "", NULO, nullptr);
}
