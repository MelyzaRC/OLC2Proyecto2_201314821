#include "instruction_push_front.hpp"

instruction_push_front::instruction_push_front(int line, int col, std::string id, expression *exp)
{
    this->Line = line;
    this->Col = col;
    this->id = id;
    this->exp = exp;
}

void instruction_push_front::traducir(environment *env, asttree *tree, generator_code *gen){

}

void instruction_push_front::ejecutar(environment *env, asttree *tree ){
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol expres = exp->ejecutar(env,tree);
    map<TipoDato, QVector<symbol>> sym_vector = env->GetArray(id,env,tree);
    QVector<symbol> aux;
    TipoDato t = NULO;
    int estado= 1;
         for(auto const& vector: sym_vector){
            if(vector.first == expres.Tipo){
                t = vector.first;
                aux = vector.second;
                estado = 0;
                break;
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No puede insertar un valor de tipo ";
                contenido_error += env->obtenerTipo(expres.Tipo);
                contenido_error += " a un vector de tipo ";
                contenido_error += env->obtenerTipo(vector.first);
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
                estado = 1;
                break;
            }

        }
        if(estado == 0){
            aux.push_front(expres);
            sym_vector = {{t,aux}};
            env->editArray(sym_vector,id,tree);
        }
}
