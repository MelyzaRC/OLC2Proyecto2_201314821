#include "func_mean.hpp"

func_mean::func_mean(int line, int col, std::string id_vector)
{
    this->Line = line;
    this->Col = col;
    this->id = id_vector;
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
