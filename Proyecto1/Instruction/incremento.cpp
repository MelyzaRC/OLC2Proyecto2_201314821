#include "incremento.hpp"
#include "AST/asttree.hpp"

incremento::incremento(int line, int col, std::string nombre)
{
    this->Col = col;
    this->Line = line;
    this->nombre = nombre;
    this->cadenaPrint = "";
    this->tipoInstruccion = 6;
}

void incremento::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode=true;
    symbol sym = env->GetVariable(this->nombre,env,tree);
    if(sym.Tipo != NULO){
        if(sym.Tipo == INTEGER){
            std::string tmp1 = gen->newTemp();
            //incrementa
             gen->AddGetStack(std::to_string(sym.Posicion),tmp1);
             gen->AddExpression(tmp1,tmp1,"1","+");
             gen->AddSetStack(std::to_string(sym.Posicion), tmp1);
        }else if(sym.Tipo == FLOAT){
            std::string tmp1 = gen->newTemp();
            //incrementa
             gen->AddGetStack(std::to_string(sym.Posicion),tmp1);
             gen->AddExpression(tmp1,tmp1,"1","+");
             gen->AddSetStack(std::to_string(sym.Posicion), tmp1);
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede incrementar una variable de tipo ";
            contenido_error += env->obtenerTipo(sym.Tipo);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
}

void incremento::ejecutar(environment *env, asttree *tree){
    int tmp = incrementar(env, tree);
    this->cadenaPrint = "";

}

//BUSCAR EN EL ENTORNO - SI NO LO ENCUENTRA BUSCAR EN EL PADRE
int incremento::incrementar(environment *env, asttree *tree){
    //ACTUAL
    //std::map<std::string, symbol>::iterator it = env->Tabla.find(this->nombre);
   /* symbol findSym = env->GetVariable(this->nombre, env);

        if(findSym.Tipo == INTEGER){
            env->IncrementarVariable(this->nombre);
            return 1;
        }else if(findSym.Tipo == FLOAT){
            env->IncrementarVariable(this->nombre);
            return 1;
        }else{
            cadenaPrint = "La variable " + this->nombre;
            cadenaPrint += " no es una variable numérica. \n";
            //REPORTAR ERROR
        }*/



    for (std::map<std::string, symbol>::iterator i=env->Tabla.begin(); i!=env->Tabla.end(); ++i)
    {
        if(i->first == this->nombre){
            symbol findSym = i->second;
            if(findSym.Tipo == INTEGER){
                /*int res = *static_cast<int*>(findSym.valor) + 1;
                findSym.valor  = &res;
                i->second = findSym;*/
                env->IncrementarVariable(this->nombre, tree);
                return 1;
            }else if(findSym.Tipo == FLOAT){
                /*symbol* symPtr;
                symPtr = &i->second;

                float res = *static_cast<float*>(findSym.valor);
                float sum = 1.0;
                float res1 = res+sum;
                findSym.valor  = &res1;
                symbol as = *new symbol(0,0,"",FLOAT,&res1);
                *symPtr = as;*/
                env->IncrementarVariable(this->nombre, tree);
                return 1;
            }else{
                std::cout<<"ERROR"<<std::endl;
                //REPORTAR ERROR PORQUE NO ES UN TIPO NUMERICO
                return 0;
            }

        }
    }
    //PADRE
    if(env->Padre != nullptr){
        return this->incrementar(env->Padre, tree);
    }
}
