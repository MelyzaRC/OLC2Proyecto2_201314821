#include "instruction_push_back.hpp"

instruction_push_back::instruction_push_back(int line, int col, std::string id, expression *exp)
{
    this->Line = line;
    this->Col = col;
    this->id = id;
    this->exp = exp;
}

void instruction_push_back::traducir(environment *env, asttree *tree, generator_code *gen){

    value val("", false, NULO);
    gen->MainCode = true;
    gen->AddComment("PUSH BACK===============");

    symbol symVector = env->GetVariable(this->id,env,tree);


    if(symVector.Tipo == VINT || symVector.Tipo == VFLOAT || symVector.Tipo == VBOOL || symVector.Tipo == VSTRING){
        //verificando que el index sea un entero
        std::string t1 = gen->newTemp();//pos inicial
        std::string t2 = gen->newTemp();//contador
        std::string t3 = gen->newTemp();//index a buscar en el heap
        std::string t4 = gen->newTemp();//recuperar lo del heap
        std::string t5 = gen->newTemp();//nuevo
        std::string t6 = gen->newTemp();//nuevo valor
        std::string L1 = gen->newLabel();
        std::string L2 = gen->newLabel();
        std::string L3 = gen->newLabel();
        std::string L4 = gen->newLabel();
        gen->AddComment("Pos inicial ");
        gen->AddAssign(t1,std::to_string(symVector.Posicion));
        gen->AddComment("Contador");
        gen->AddAssign(t2,"0");
        gen->AddAssign(t6,"H");

        gen->AddLabel(L1);
        gen->AddExpression(t3,t1,t2,"+");
        std::string tnuevo = gen->newTemp();
        gen->AddAssign(tnuevo,"heap[(int)"+t3+"]" );
        gen->AddIf(tnuevo,"-6","==",L2);
        gen->AddGoto(L3);

        //es el final
        gen->AddLabel(L2);
        //meter en t5 lo que venga en exp
        value v = this->exp->traducir(env,tree,gen);
        gen->AddAssign(t5,v.Value);
        gen->AddAssign("heap[(int)H]",t5);
        gen->AddExpression("H","H","1","+");
        gen->AddAssign("heap[(int)H]","-6");
        gen->AddExpression("H","H","1","+");
        gen->AddSetStack("(int)"+t1, t6);
        std::string LSalirPush = gen->newLabel();
        gen->AddGoto(LSalirPush);
        //no es el final
        gen->AddLabel(L3);
        gen->AddAssign(t4,"heap[(int)"+t3+"]");
        gen->AddAssign("heap[(int)H]",t4);
        gen->AddExpression("H","H","1","+");
        gen->AddExpression(t2,t2,"1","+");
        gen->AddGoto(L1);
        gen->AddLabel(LSalirPush);
        symVector.size = symVector.size+1;
        env->saveSize(this->id,symVector.size);
        env->ModificarVariable(symVector, this->id);

    }else{
        //ERROR SEMANTICO
        std::string contenido_error =  "La variable ";
        contenido_error += this->id;
        contenido_error += " no es un vector";
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;
    }
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
