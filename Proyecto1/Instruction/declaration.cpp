#include "declaration.hpp"
#include "Environment/type.hpp"

//CONSTRUCTOR
declaration::declaration(){
    this->tipo = 3;
}



declaration::declaration(int line, int col, std::string nombre, expression *val, int tipo)
{
    this->Line = line;
    this->Col = col;
    this->nombre = nombre;
    this->Valor = val;
    this->tipo = tipo;
    this->tipoInstruccion = 3;
}

void declaration::traducir(environment *env, asttree *tree, generator_code *gen){
    std::cout<<"Traduciendo declaracion"<<std::endl;
    std::string tmpTraduccion = env->obtenerTipoTraduccion(this->tipo);
    tmpTraduccion += " ";
    tmpTraduccion += this->nombre;
    tmpTraduccion += " = ";
    value v = this->Valor->traducir(env, tree, gen);
    tmpTraduccion += v.Value;
    tmpTraduccion += ";\n";
    gen->Code.append(tmpTraduccion);
}

//METODO EJECUTAR DE LA DECLARACION
void declaration::ejecutar(environment *env, asttree *tree)
{
    //RECUPERANDO EL VALOR DE LA EXPRESION
    symbol sym = this->Valor->ejecutar(env, tree);
    //CONSULTADO TIPOS
    if(this->tipo == sym.Tipo){
        //TIPOS COINCIDEN
        env->SaveVariable(sym, this->nombre, tree);
        //env->Tabla.insert(std::pair<std::string, symbol>(this->nombre, sym));
    } else if(sym.Tipo == 4){
        //ERROR SEMANTICO
        std::string contenido_error = "La expresión ha retornado un valor NULO";
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->IncrementaErroresSemanticos();
    }else{
        //ERROR LOS TIPOS NO COINCIDEN
        //ERROR SEMANTICO
        std::string contenido_error = "Los tipos no coinciden para la  variable ";
        contenido_error += this->nombre;
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->IncrementaErroresSemanticos();
    }

    //  TIPO 1 = variable
    //  TIPO 2 = funcion
    /*entrada entradaIn = *new entrada(nombre, 1, sym);
    env->lista.push_back(entradaIn);*/

}
