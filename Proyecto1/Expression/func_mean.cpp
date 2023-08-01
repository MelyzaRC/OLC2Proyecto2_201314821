#include "func_mean.hpp"

func_mean::func_mean(int line, int col, std::string id_vector)
{
    this->Line = line;
    this->Col = col;
    this->id = id_vector;
}

value func_mean::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode = true;
    gen->AddComment("MEAN============================");
    value val("", false, NULO);

    symbol sym = env->GetVariable(this->id,env,tree);
    gen->AddComment(std::to_string(sym.Tipo));
    if(sym.Tipo != NULO){
        if(sym.Tipo == VINT || sym.Tipo == VFLOAT || sym.Tipo == VBOOL || sym.Tipo == VSTRING){
            std::string tmpRes = gen->newTemp();
            gen->AddAssign(tmpRes, std::to_string(sym.size));
            value v(tmpRes,true,INTEGER);
            std::string cant_elementos = gen->newTemp();
            std::string total = gen->newTemp();
            std::string index = gen->newTemp();
            std::string actual = gen->newTemp();
            std::string L1 = gen->newLabel();
            std::string L2 = gen->newLabel();
            std::string L3 = gen->newLabel();
            std::string L4 = gen->newLabel();
            gen->AddAssign(cant_elementos, std::to_string(sym.size));
            gen->AddAssign(index, "stack[(int)"+std::to_string(sym.Posicion)+"]");
            gen->AddLabel(L1);
            gen->AddAssign(actual,"heap[(int)"+index+"]");
            gen->AddIf(actual, "-6","==",L2);
            gen->AddExpression(total, total, actual, "+");
            gen->AddExpression(index, index, "1","+");
            gen->AddGoto(L1);

            gen->AddLabel(L2);
            gen->AddExpression(total, total, cant_elementos,"/");
            value val = *new value(total, true, FLOAT);
            return val;
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "La variable  ";
            contenido_error += this->id;
            contenido_error += " no es un vector";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("", false, NULO);
            return val;
        }
    }
    //No encuentra la variable - error controlado en el entorno
    return val;
}

symbol func_mean::ejecutar(environment *env, asttree *tree){

    symbol symReturn(Line, Col, "", NULO, nullptr);
    map<TipoDato, QVector<symbol>> sym_vector = env->GetArray(id,env,tree);
    //SE RETORNA UN FLOAT
    int totalInt = 0;
    float totalFloat = 0;
    int x = 0;
    symbol sym;

        for(auto const& vector: sym_vector){
            sym = vector.second[0];
            if(sym.Tipo == INTEGER){
                QVector<symbol> valores = vector.second;
                x = valores.size();
                for(int i = 0; i < valores.size(); i++){

                    int* r = new int;
                    *r = *static_cast<int*>(valores.value(i).valor);
                    totalInt += *r;
                    //std::cout<<"Entra "<<totalInt<<std::endl;
                }
            }else if (sym.Tipo == FLOAT){
                QVector<symbol> valores = vector.second;
                x = valores.size();
                for(int i = 0; i < valores.size(); i++){

                    float* r = new float;
                    *r = *static_cast<float*>(valores.value(i).valor);
                    totalFloat += *r;
                    //std::cout<<"Entra "<<totalInt<<std::endl;
                }
            }else{
                //REPORTAR ERROR
                std::cout<<"El vector no es numerico"<<std::endl;
            }
        }
    if(totalInt == 0 &&totalFloat > 0){

        float* res = new float;
        *res = (totalFloat +0.0 )/ x;
        std::cout<<"Entra "<<*res<<std::endl;
        return *new symbol(Line, Col, "", FLOAT, res);

    }else if(totalFloat == 0 && totalInt > 0 ){
        float* res = new float;
        *res = (totalInt +0.0 )/ x;
        std::cout<<"Entra "<<*res<<std::endl;
        return *new symbol(Line, Col, "", FLOAT, res);
    }
    return symReturn;
}
