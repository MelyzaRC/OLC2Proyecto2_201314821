#include "negacion_unaria.hpp"

negacion_unaria::negacion_unaria(int line, int col, expression *exp)
{
    this->Line = line;
    this->Col = col;
    this->valor = exp;
    this->tipo = 3;
}


symbol negacion_unaria::ejecutar(environment *env, asttree *tree){

    symbol sym = this->valor->ejecutar(env, tree);
    switch (sym.Tipo) {
        case INTEGER:{
            int* res = new int;
            int resultado = (int)*static_cast<int*>(sym.valor)*-1;
            *res = resultado;
            return *new symbol(Line, Col, "", INTEGER, res);
            }
        break;
        case FLOAT:{
            float* res = new float;
            float resultado = (float)*static_cast<float*>(sym.valor)*-1.0;
            *res = resultado;
            return *new symbol(Line, Col, "", FLOAT, res);
            }
        break;
        case STRING:{
        //ERROR SEMANTICO
            std::string contenido_error =  "No se puede negar el tipo ";
            contenido_error += env->obtenerTipo(sym.Tipo);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            return *new symbol(Line, Col, "", NULO, nullptr);
            }
            break;
        case BOOL:
            {
                bool* res = new bool;
                bool resultado = !((bool)*static_cast<bool*>(sym.valor));
                *res = resultado;
                return *new symbol(Line, Col, "", BOOL, res);
            }
            break;
    }
    //ERROR SEMANTICO
        std::string contenido_error =  "No se puede negar el tipo ";
        contenido_error += env->obtenerTipo(sym.Tipo);
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;
    return *new symbol(Line, Col, "", NULO, nullptr);
}
