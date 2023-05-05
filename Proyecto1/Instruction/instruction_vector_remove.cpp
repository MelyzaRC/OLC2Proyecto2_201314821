#include "instruction_vector_remove.hpp"

instruction_vector_remove::instruction_vector_remove(int line, int col, std::string id, expression *index)
{
    Line = line;
    Col = col;
    this->id = id;
    Index = index;
}

void instruction_vector_remove::traducir(environment *env, asttree *tree, generator_code *gen){

    value val("", false, NULO);
    gen->MainCode = true;

    symbol symVector = env->GetVariable(this->id,env,tree);
    if(symVector.Tipo == VINT || symVector.Tipo == VFLOAT || symVector.Tipo == VBOOL || symVector.Tipo == VSTRING){
        //verificando que el index sea un entero
        value valIndex = this->Index->traducir(env, tree, gen);
        if(valIndex.TipoExpresion == INTEGER){
            std::string t1 = gen->newTemp();
            std::string t2 = gen->newTemp();
            std::string t4 = gen->newTemp();
            std::string t5 = gen->newTemp();
            std::string t6 = gen->newTemp();
            std::string t7 = gen->newTemp();
            std::string t8 = gen->newTemp();


            std::string L1 = gen->newLabel();
            std::string L2 = gen->newLabel();
            std::string L3 = gen->newLabel();
            std::string L4 = gen->newLabel();
            std::string L5 = gen->newLabel();
            std::string L6 = gen->newLabel();
            std::string L7 = gen->newLabel();
            std::string L8= gen->newLabel();
            std::string tNuevoVector = gen->newTemp();


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

            //empezar con el nuevo vector
            gen->AddLabel(L3);
            gen->AddComment("Remove =============");
            gen->AddAssign(tNuevoVector, "H");
            //recorrer y cuando se encuentre con t1 solo ignorar
            gen->AddAssign(t5,t1);
            //en t5 tengo la pos del heap del vector
            gen->AddAssign(t6,"0");
            //en t6 tengo el contador index
            gen->AddLabel(L7);
            gen->AddIf(t5,t6,"==",L5); // es el indice
            gen->AddGoto(L6);//no es el indice

            //SI ES EL INDICE
            gen->AddLabel(L5);
            gen->AddExpression(t6,t6,"1","+");
            gen->AddGoto(L7);
            //NO ES EL INDICE
            gen->AddLabel(L6);
            gen->AddAssign(t7,"heap[(int)"+t6+"]");
            gen->AddIf(t7,"-6","==",L8);
            gen->AddAssign("heap[(int)H]",t7);
            gen->AddExpression("H","H","1","+");
            gen->AddExpression(t6,t6,"1","+");
            gen->AddGoto(L7);
            //Termina el vector
            gen->AddLabel(L8);
            gen->AddSetHeap("(int)H","-6");
            gen->AddExpression("H","H","1","+");
            gen->AddSetStack(std::to_string(symVector.Posicion),tNuevoVector);
            env->saveSize(this->id, symVector.size-1);
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
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "La expresion del indice para el acceso a vector ha retornado ";
            contenido_error += env->obtenerTipo(valIndex.TipoExpresion);
            contenido_error += " - Se esperaba INTEGER";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }else{
        //ERROR SEMANTICO
        std::string contenido_error =  "La variable ";
        contenido_error += this->id;
        contenido_error += " no es un vector";
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;
    }
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
