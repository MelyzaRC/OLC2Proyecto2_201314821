#include "instruction_for.hpp"
#include "asignacion_variable.hpp"
#include "declaracion_sin_valor.hpp"
#include "declaration.hpp"

instruction_for::instruction_for(int line, int col, instruction* inst_iterador, expression* condicion, instruction* salto, list_instruction_second* lista)
{
    this->cadenaPrint = "";
    this->Line = line;
    this->Col = col;
    this->variable_iterador = inst_iterador;
    this->Condicion = condicion;
    this->salto = salto;
    this->tipoInstruccion = 7;
    this->ListInst = lista;
}

void instruction_for::ejecutar(environment *env, asttree *tree){
    environment *ForEnv = new environment(env, "FOR");
    this->variable_iterador->ejecutar(ForEnv, tree);
    this->cadenaPrint = ejecutarFor(ForEnv, tree);
}

bool instruction_for::validarIterador(environment *env, asttree *ast){
    if(this->variable_iterador == nullptr) return false;
    this->variable_iterador->ejecutar(env, ast);
    switch(this->variable_iterador->tipoInstruccion){
        case 1: {
                    asignacion_variable* dec = new asignacion_variable();
                    *dec = *static_cast<asignacion_variable*>(variable_iterador);
                    this->iterador = dec->nombre;
                    symbol sTipo = env->GetVariable(iterador,env, ast);
                    if(sTipo.Tipo == INTEGER || sTipo.Tipo == FLOAT){
                        return true;
                    }
                    //ERROR EL ITERADOR DEBE SER UNA VARIABLE NUMERICA
                    return false;
                }
            break;
        case 2: {
                    declaracion_sin_valor* dec = new declaracion_sin_valor();
                    *dec = *static_cast<declaracion_sin_valor*>(variable_iterador);
                    this->iterador = dec->nombre;
                    symbol sTipo = env->GetVariable(iterador,env,ast);
                    if(sTipo.Tipo == INTEGER || sTipo.Tipo == FLOAT){
                        return true;
                    }
                    //ERROR EL ITERADOR DEBE SER UNA VARIABLE NUMERICA
                    return false;
                }
            break;
        case 3: {
                    declaration* dec = new declaration();
                    *dec = *static_cast<declaration*>(variable_iterador);
                    this->iterador = dec->nombre;
                    symbol sTipo = env->GetVariable(iterador,env, ast);
                    if(sTipo.Tipo == INTEGER || sTipo.Tipo == FLOAT){
                        return true;
                    }
                    //ERROR EL ITERADOR DEBE SER UNA VARIABLE NUMERICA
                    return false;
                }
            break;
        default:
            std::cout<<"REPORTAR ERROR EN FOR"<<std::endl;
            break;
    }
    return false;
}

std::string instruction_for::ejecutarFor(environment *env, asttree *ast){
    //RECUPERANDO EL SIMBOLO DE LA CONDICION
    std::string* cadenaValor = new std::string;
    symbol resultadoCondicion = this->Condicion->ejecutar(env, ast);
    //std::cout<<"Tipo"<<resultadoCondicion.Tipo<<std::endl;
        if(resultadoCondicion.Tipo == BOOL){
            //std::cout<<"Si es booleano"<<std::endl;
            //environment *ForEnv = new environment(env, "FOR");
            while(*static_cast<bool*>(resultadoCondicion.valor)){
                //std::cout<<"Si es true"<<std::endl;
                //EJECUTAR LAS INSTRUCCIONES DEL FOR
                this->ListInst->cadenaPrint = "";
                this->ListInst->ejecutar(env, ast);
                *cadenaValor += this->ListInst->cadenaPrint;
                this->salto->ejecutar(env,ast);
                resultadoCondicion = this->Condicion->ejecutar(env,ast);
            }
            //ast->cadenaTab += env->graficar();
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "La condición evaluada para el FOR no retornó un tipo BOOL sino ";
            contenido_error += env->obtenerTipo(resultadoCondicion.Tipo);
            ast->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            ast->erroresSemanticos++;
        }
    return *cadenaValor;
}
