#include "vector_access.hpp"


vector_access::vector_access(int line, int col, std::string id1, expression *index)
{
    Line = line;
    Col = col;
    id = id1;
    Index = index;
}

value vector_access::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    gen->MainCode = true;

    symbol symVector = env->GetVariable(this->id,env,tree);
    if(symVector.Tipo == VINT || symVector.Tipo == VFLOAT || symVector.Tipo == VBOOL || symVector.Tipo == VSTRING){
        //verificando que el index sea un entero
        value valIndex = this->Index->traducir(env, tree, gen);
        if(valIndex.TipoExpresion == INTEGER){
            std::string t1 = gen->newTemp();
            std::string t2 = gen->newTemp();
            std::string t3 = gen->newTemp();
            std::string t4 = gen->newTemp();
            std::string L1 = gen->newLabel();
            std::string L2 = gen->newLabel();
            std::string L3 = gen->newLabel();
            std::string L4 = gen->newLabel();

            gen->AddComment("Indice del vector");
            gen->AddAssign(t1, valIndex.Value);
            gen->AddAssign(t2,std::to_string(symVector.size));
            //Indice < size
            gen->AddIf(t1,t2,"<",L1);
            gen->AddGoto(L2);
            //Indice > = 0
            gen->AddLabel(L1);
            gen->AddIf(t1,"0",">=",L3);
            gen->AddGoto(L2);

            gen->AddLabel(L3);
            gen->AddAssign(t3,"stack["+std::to_string(symVector.Posicion)+"]");
            gen->AddExpression(t3,t3,t1,"+");
            //posicion del heap donde se encuentra el valor

            gen->AddAssign(t4,"heap[(int)"+t3+"]");
            gen->AddGoto(L4);
            //Aqui viene cuando no esta dentro del rango
            gen->AddLabel(L2);
            gen->AddAssign(t4,"0");
            gen->GenerateFueraRango();
            gen->AddCall("olc3d_fueraRango");
            //indice fuera de rango
            gen->AddGoto(L4);
            //Finaliza
            gen->AddLabel(L4);
            value val(t4, true, valIndex.TipoExpresion);
            return val;
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "La expresion del indice para el acceso a vector ha retornado ";
            contenido_error += env->obtenerTipo(valIndex.TipoExpresion);
            contenido_error += " - Se esperaba INTEGER";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }
    }else{
        //ERROR SEMANTICO
        std::string contenido_error =  "La variable ";
        contenido_error += this->id;
        contenido_error += " no es un vector";
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;
        val= *new value("NULO", false, NULO);
        return val;
    }
    return val;
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
