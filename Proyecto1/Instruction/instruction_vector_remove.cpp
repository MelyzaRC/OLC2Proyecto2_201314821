#include "instruction_vector_remove.hpp"

instruction_vector_remove::instruction_vector_remove(int line, int col, std::string id, expression *index)
{
    Line = line;
    Col = col;
    this->id = id;
    Index = index;
}

void instruction_vector_remove::traducir(environment *env, asttree *tree, generator_code *gen){

}

void instruction_vector_remove::ejecutar(environment *env, asttree *tree ){
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol i = this->Index->ejecutar(env,tree);
    map<TipoDato, QVector<symbol>> sym_vector = env->GetArray(id,env,tree);
    QVector<symbol> aux;
    TipoDato t = NULO;
    int estado = 0;
    //VERIFICA QUE EXISTA EL VECTOR
    for(auto const& vector: sym_vector){
           t = vector.first;
           break;
    }
    if(t != NULO){
    if(i.Tipo == INTEGER){


        //INDICE
        int x = *static_cast<int*>(i.valor);
        //VERIFICANDO TAMANO DEL VECTOR
        int tmp = 0;
        for(auto const& vector: sym_vector){
            tmp = vector.second.size();
        }
        if(x < tmp && x >= 0 ){

                for(auto const& vector: sym_vector){
                       t = vector.first;
                       aux = vector.second;
                       break;

               }
               if(t != NULO){
                   aux.remove(x);
                   sym_vector = {{t,aux}};
                   env->editArray(sym_vector,id,tree);
               }else{
                   //ERROR SEMANTICO
                   std::string contenido_error =  "Vector ";
                   contenido_error += this->id;
                   contenido_error += " no encontrado";
                   tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                   tree->erroresSemanticos++;
               }

        }else if(x<0){
            //ERROR SEMANTICO
            std::string contenido_error =  "Índice fuera de rango [INDICE=";
            contenido_error += std::to_string(x);
            contenido_error += "] No existen índices negativos";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
        else{
            //ERROR SEMANTICO
            std::string contenido_error =  "Índice fuera de rango [INDICE=";
            contenido_error += std::to_string(x);
            contenido_error += "] [TAMAÑO=";
            contenido_error += std::to_string(tmp);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }else{
        //ERROR SEMANTICO
        std::string contenido_error =  "La expresión evaluada no retornó un tipo INT sino ";
        contenido_error += env->obtenerTipo(i.Tipo);
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;

    }
}


}
