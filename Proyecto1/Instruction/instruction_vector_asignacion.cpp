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
    value val("", false, NULO);
    gen->MainCode = true;

    symbol symVector = env->GetVariable(this->id,env,tree);
    if(symVector.Tipo == VINT || symVector.Tipo == VFLOAT || symVector.Tipo == VBOOL || symVector.Tipo == VSTRING){
        //verificando que el index sea un entero
        TipoDato t = NULO;
        if(symVector.Tipo == VINT){ t = INTEGER;}
        else if(symVector.Tipo == VFLOAT){ t = FLOAT;}
        else if(symVector.Tipo == VBOOL){ t = BOOL;}
        else if(symVector.Tipo == VSTRING){ t = STRING;}
        value valIndex = this->index->traducir(env, tree, gen);
        if(valIndex.TipoExpresion == INTEGER){
            std::string t1 = gen->newTemp();
            std::string t2 = gen->newTemp();
            std::string t3 = gen->newTemp();
            std::string t4 = gen->newTemp();
            std::string t5 = gen->newTemp();
            std::string t6 = gen->newTemp();
            std::string L1 = gen->newLabel();
            std::string L2 = gen->newLabel();
            std::string L3 = gen->newLabel();
            std::string L4 = gen->newLabel();
            std::string L5 = gen->newLabel();
            std::string L6 = gen->newLabel();

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
            gen->AddAssign(t3,std::to_string(symVector.Posicion));
            gen->AddExpression(t3,t3,t1,"+");
            //posicion del heap donde se encuentra el valor
            //*******************************************************************************
            value valExpr = this->exp->traducir(env, tree, gen);
            if(valExpr.TipoExpresion == t){
                gen->AddAssign(t5, valExpr.Value);
                gen->AddSetHeap("(int)"+t3,t5);
                gen->AddGoto(L4);
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "Los tipos de datos no coinciden ";
                tree->errores.append(*new error_analisis(0, 0, 3, contenido_error));
                tree->erroresSemanticos++;
            }
            //*******************************************************************************
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
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "La expresion del indice para el acceso a vector ha retornado ";
            contenido_error += env->obtenerTipo(valIndex.TipoExpresion);
            contenido_error += " - Se esperaba INTEGER";
            tree->errores.append(*new error_analisis(0,0, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }else{
        //ERROR SEMANTICO
        std::string contenido_error =  "La variable ";
        contenido_error += this->id;
        contenido_error += " no es un vector";
        tree->errores.append(*new error_analisis(0, 0, 3, contenido_error));
        tree->erroresSemanticos++;
    }
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
