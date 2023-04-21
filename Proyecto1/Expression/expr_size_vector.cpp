#include "expr_size_vector.hpp"

expr_size_vector::expr_size_vector(int line, int col, std::string id)
{
    this->Line = line;
    this->Col = col;
    this->id = id;
}

symbol expr_size_vector::ejecutar(environment *env, asttree *tree){
    symbol sym (Line,Col,"",NULO,nullptr);
    map<TipoDato, QVector<symbol>> sym_vector = env->GetArray(id,env,tree);
    TipoDato t = NULO;
        int estado = 0;
        //VERIFICA QUE EXISTA EL VECTOR
        for(auto const& vector: sym_vector){
               t = vector.first;
               break;
        }
        if(t != NULO){
            std::cout<<"si encontro el vector"<<std::endl;
            for(auto const& vector: sym_vector){
                int* tmp = new int;
                *tmp = vector.second.size();
                return symbol(Line,Col,"",INTEGER,tmp);
            }
        }else{
            std::cout<<"no encontro el vector"<<std::endl;
        }
    return sym;
}
