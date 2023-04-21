#include "vector_access.hpp"


vector_access::vector_access(int line, int col, std::string id1, expression *index)
{
    Line = line;
    Col = col;
    id = id1;
    Index = index;
}

symbol vector_access::ejecutar(environment *env, asttree *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
        map<TipoDato, QVector<symbol>> sym_vector = env->GetArray(id,env,tree);
        TipoDato t = NULO;
        //VERIFICA QUE EXISTA EL VECTOR
           for(auto const& vector: sym_vector){
                  t = vector.first;
                  break;
           }
           if(t != NULO){
        //obtener el index
        symbol i = this->Index->ejecutar(env,tree);
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
                    sym = vector.second[x];
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
        }}
        return sym;
}
