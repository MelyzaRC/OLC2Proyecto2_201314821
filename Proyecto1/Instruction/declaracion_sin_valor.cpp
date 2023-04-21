#include "declaracion_sin_valor.hpp"

declaracion_sin_valor::declaracion_sin_valor(){}

declaracion_sin_valor::declaracion_sin_valor(int line, int col, std::string nombre, int tipo)
{
    this->Line = line;
    this->Col = col;
    this->tipo  = tipo;
    this->nombre = nombre;
    this->tipoInstruccion = 2;
}

void declaracion_sin_valor::ejecutar(environment *env, asttree *tree){
    //aqui me falta verificar que las variables no se repitan
    //verificar que no sea una reservada
    switch(tipo){
    case INTEGER:{
        int* intDef = new int;
        *intDef = 0;
        symbol symInsert(this->Line, this->Col, "", INTEGER, intDef);
        env->SaveVariable(symInsert, this->nombre, tree);
    }break;
    case FLOAT:{
        float floatDef = 0.0;
        symbol symInsert(this->Line, this->Col, "", FLOAT, &floatDef);
        env->SaveVariable(symInsert, this->nombre, tree);
    }break;
    case STRING:{
        std::string stringDef = "";
        symbol symInsert(this->Line, this->Col, "", STRING, &stringDef);
        env->SaveVariable(symInsert, this->nombre, tree);
    }break;
    case BOOL:{
        bool boolDef = false;
        symbol symInsert(this->Line, this->Col, "", BOOL, &boolDef);
        env->SaveVariable(symInsert, this->nombre, tree);
    }break;
    }
}
