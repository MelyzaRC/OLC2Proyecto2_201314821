#include "instruction_vector_asignacion.hpp"

instruction_vector_asignacion::instruction_vector_asignacion(int line, int col, std::string id, expression *index, expression *exp)
{
    this->line = line;
    this->Col = col;
    this->id = id;
    this->index = index;
    this->exp = exp;
}

void instruction_vector_asignacion::traducir(environment *env, asttree *tree, generator_code *gen){

}

void instruction_vector_asignacion::ejecutar(environment *env, asttree *tree){
    symbol sym (line,Col,"",NULO,nullptr);
    map<TipoDato, QVector<symbol>> sym_vector = env->GetArray(id,env,tree);
    //obtener el index
    QVector<symbol> aux;
    TipoDato t = NULO;
    symbol i = index->ejecutar(env,tree);
    if(i.Tipo == INTEGER){
        for(auto const& vector: sym_vector){
            aux = vector.second;
            t = vector.first;
            break;
        }
    }
    symbol valor = exp->ejecutar(env,tree);
    int x = *static_cast<int*>(i.valor);
    if(t == INTEGER){
        int result = *static_cast<int*>(valor.valor);
        int *re = new int;
        *re = result;
        aux[x] = symbol(this->line,this->Col,"",valor.Tipo,re);
    }else if(t == FLOAT){
        float result = *static_cast<float*>(valor.valor);
        float *re = new float;
        *re = result;
        aux[x] = symbol(this->line,this->Col,"",valor.Tipo,re);
    }
    else if(t == BOOL){
        bool result = *static_cast<bool*>(valor.valor);
        bool *re = new bool;
        *re = result;
        aux[x] = symbol(this->line,this->Col,"",valor.Tipo,re);
    }
    else if(t == STRING){
        std::string result = *static_cast<std::string*>(valor.valor);
        std::string *re = new std::string;
        *re = result;
        aux[x] = symbol(this->line,this->Col,"",valor.Tipo,re);
    }

    sym_vector = {{t,aux}};
    env->editArray(sym_vector,id,tree);

}
