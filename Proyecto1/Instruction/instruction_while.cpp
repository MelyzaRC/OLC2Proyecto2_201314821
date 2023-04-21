#include "instruction_while.hpp"

instruction_while::instruction_while(int line, int col, expression* ex, list_instruction_second* list)
{
    this->Line = line;
    this->Col = col;
    this->condicion = ex;
    this->ListInst = list;
    this->iteracion = 0;
    this->cadenaPrint = "";
    this->tipoInstruccion = 9;
}

void instruction_while::ejecutar(environment *env, asttree *tree){
    std::string* cadenaValor = new std::string;
    symbol condicionResultado = this->condicion->ejecutar(env, tree);
    environment *WhileEnv = new environment(env, "while");
    if(condicionResultado.Tipo == BOOL){
        while(*static_cast<bool*>(condicionResultado.valor)){
            this->ListInst->cadenaPrint = "";
            this->ListInst->ejecutar(WhileEnv, tree);
            *cadenaValor += this->ListInst->cadenaPrint;
            if(tree->breakFlag==true){
                tree->inactivarBanderaBreak();
                break;
            }
            if(tree->continueFlag==true){
                tree->inactivarBanderaContinue();
            }
            condicionResultado = this->condicion->ejecutar(env, tree);
            //std::cout<<"RES de condicion "<<*static_cast<bool*>(this->condicion->ejecutar(env, tree).valor)<<std::endl;
        }
        tree->cadenaTab += WhileEnv->graficar();
    }else{
        //ERROR SEMANTICO
        std::string contenido_error =  "La condición evaluada no retorna un tipo BOOL sino ";
        contenido_error += env->obtenerTipo(condicionResultado.Tipo);
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;
    }

    this->cadenaPrint = *cadenaValor;
}

std::string  instruction_while::ejecutarWhile(environment *env, asttree *tree){
    std::string* cadenaValor = new std::string;
    symbol condicionResultado = this->condicion->ejecutar(env, tree);
    //environment *WhileEnv = new environment(env, "while");
    //environment *entorno = new environment(env, "while");


    if(condicionResultado.Tipo == BOOL){
        while(*static_cast<bool*>(condicionResultado.valor)){
            this->ListInst->cadenaPrint = "";
            this->ListInst->ejecutar(env, tree);
            *cadenaValor += this->ListInst->cadenaPrint;
            if(tree->breakFlag == 1){
                tree->inactivarBanderaBreak();
                break;
            }
            if(tree->continueFlag == 1){
                tree->inactivarBanderaContinue();
            }
            condicionResultado = this->condicion->ejecutar(env, tree);
        }
    }else{
        //REPORTAR ERROR
        std::cout<<"Condicion del while no retorna booleano"<<std::endl;
    }

    return *cadenaValor;
}
