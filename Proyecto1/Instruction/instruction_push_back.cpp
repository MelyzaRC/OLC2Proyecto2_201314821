#include "instruction_push_back.hpp"

instruction_push_back::instruction_push_back(int line, int col, std::string id, expression *exp)
{
    this->Line = line;
    this->Col = col;
    this->id = id;
    this->exp = exp;
}

void instruction_push_back::ejecutar(environment *env, asttree *tree ){
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
            aux.push_back(expres);
            sym_vector = {{t,aux}};
            env->editArray(sym_vector,id,tree);
        }
}
