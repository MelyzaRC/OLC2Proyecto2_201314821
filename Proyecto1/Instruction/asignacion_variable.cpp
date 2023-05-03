#include "asignacion_variable.hpp"

asignacion_variable::asignacion_variable(){
    this->tipoInstruccion = 1;
    this->cadenaPrint = "";
}

asignacion_variable::asignacion_variable(int line, int col, std::string name, expression *val)
{
    this->Line = line;
    this->Col = col;
    this->nombre = name;
    this->valor = val;
    this->tipoInstruccion = 1;
    this->cadenaPrint = "";
}

void asignacion_variable::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode=true;
        //buscando variable en entorno
        symbol sym = env->GetVariable(nombre,env, tree);
        if(sym.Tipo != NULO){
            //SI ENCONTRO LA VARIABLE
            //ejecutando valor
            value val = this->valor->traducir(env, tree, gen);
            if(val.TipoExpresion != NULO){
                if(val.TipoExpresion == sym.Tipo){
                    //COINCIDEN LOS TIPOS
                    gen->AddComment("ASIGNACION ==============");
                    //asignando valor
                    gen->AddSetStack(std::to_string(sym.Posicion), val.Value);
                    gen->AddBr();
                }else{
                    //NO COINCIDEN LOS TIPOS
                    //ERROR SEMANTICO
                    std::string contenido_error =  "No coinciden los tipos para la variable  ";
                    contenido_error += this->nombre;
                    contenido_error += " [ ";
                    contenido_error += env->obtenerTipo(sym.Tipo);
                    contenido_error += " - ";
                    contenido_error += env->obtenerTipo(val.TipoExpresion);
                    contenido_error += "]";
                    tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                    tree->erroresSemanticos++;
                }

            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "La expresion que se intento asignar a la variable ";
                contenido_error += this->nombre;
                contenido_error += " devolvio un valor NULO";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }

        }
        //NO ENCONTRO LA VARIABLE
        //ERROR SE REPORTA EN EL ENTORNO

}

void asignacion_variable::ejecutar(environment *env, asttree *tree){
    int res = asignar(env, tree);
}

int  asignacion_variable::asignar(environment *env, asttree *tree){
    for (std::map<std::string, symbol>::iterator i=env->Tabla.begin(); i!=env->Tabla.end(); ++i)
    {
        if(i->first == this->nombre){
            //asignar
            symbol tmp = this->valor->ejecutar(env, tree);
            if(tmp.Tipo != i->second.Tipo){
                //ERROR SEMANTICO
                std::string contenido_error = "El tipo de la variable no coincide con el valor especificado [";
                contenido_error += env->obtenerTipo(i->second.Tipo);
                contenido_error += " - ";
                contenido_error += env->obtenerTipo(tmp.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
                return 0;
            }else{
                env->ModificarVariable(tmp,this->nombre);
                return 1;
            }
        }
    }
    //PADRE
    if(env->Padre != nullptr){
        return asignar(env->Padre, tree);
    }
    //ERROR SEMANTICO
    std::string contenido_error =  "No se ha encontrado la variable ";
    contenido_error += this->nombre;
    tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
    tree->erroresSemanticos++;
    return 0;
}
