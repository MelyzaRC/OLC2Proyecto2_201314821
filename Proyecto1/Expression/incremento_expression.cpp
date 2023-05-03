#include "incremento_expression.hpp"

incremento_expression::incremento_expression(int line, int col, std::string nombre, int tipoIns, std::string operador)
{
    this->Col = col;
    this->Line = line;
    this->nombre = nombre;
    this->tipoIncr = tipoIns;
    this->operador = operador;

}

value incremento_expression::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    gen->MainCode=true;
    symbol sym = env->GetVariable(this->nombre,env,tree);
    if(sym.Tipo != NULO){
        if(sym.Tipo == INTEGER){
            std::string tmp1 = gen->newTemp();
            if(this->tipoIncr== 1){
               //incrementa y devuelve
                gen->AddGetStack(std::to_string(sym.Posicion),tmp1);
                gen->AddExpression(tmp1,tmp1,"1","+");
                gen->AddSetStack(std::to_string(sym.Posicion), tmp1);
                value val(tmp1, true, INTEGER);
                return val;
            }else{
                std::string tmp2 = gen->newTemp();
                //devuelve e incrementa
                gen->AddGetStack(std::to_string(sym.Posicion),tmp1);
                gen->AddAssign(tmp2, tmp1);
                gen->AddExpression(tmp1,tmp1,"1","+");
                gen->AddSetStack(std::to_string(sym.Posicion), tmp1);
                value val(tmp2, true, INTEGER);
                return val;
            }
        }else if(sym.Tipo == FLOAT){
            std::string tmp1 = gen->newTemp();
            if(this->tipoIncr== 1){
               //incrementa y devuelve
                gen->AddGetStack(std::to_string(sym.Posicion),tmp1);
                gen->AddExpression(tmp1,tmp1,"1","+");
                gen->AddSetStack(std::to_string(sym.Posicion), tmp1);
                value val(tmp1, true, FLOAT);
                return val;
            }else{
                std::string tmp2 = gen->newTemp();
                //devuelve e incrementa
                gen->AddGetStack(std::to_string(sym.Posicion),tmp1);
                gen->AddAssign(tmp2, tmp1);
                gen->AddExpression(tmp1,tmp1,"1","+");
                gen->AddSetStack(std::to_string(sym.Posicion), tmp1);
                value val(tmp2, true, FLOAT);
                return val;
            }
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede incrementar una variable de tipo ";
            contenido_error += env->obtenerTipo(sym.Tipo);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }
    }
    return val;
}

symbol incremento_expression::ejecutar(environment *env, asttree *tree){
    if(this->tipoIncr == 1){
       env->IncrementarVariable(this->nombre, tree);
        symbol sym = env->GetVariable(this->nombre, env, tree);
        return sym;
    }else{
        symbol sym = env->GetVariable(this->nombre, env, tree);
        env->IncrementarVariable(this->nombre, tree);
        return sym;
    }
}
