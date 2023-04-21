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
