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

void declaracion_sin_valor::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode = true;
    value val("",false,NULO);
    symbol newVar;
    TipoDato t = NULO;
    switch (this->tipo) {
    case 0: {t=INTEGER; }   break;
    case 1: {t=FLOAT;   }   break;
    case 2: {t=STRING;  }   break;
    case 3: {t=BOOL;    }   break;
    case 4: {t=NULO;    }   break;
    default:                break;
    }

    gen->AddComment("=== DECLARACION SIN VALOR ===");
    newVar = env->SaveVariable2(this->nombre, t, tree);

    switch(t){
    case INTEGER:{
        val.Value= "0";
    }break;
    case FLOAT:{
        val.Value= "0.0";
    }break;
    case STRING:{
        std::string tmpString = gen->newTemp();
        gen->AddAssign(tmpString, "H");
        gen->AddSetHeap("(int)H","00");
        gen->AddExpression("H","H","1","+");
        val.Value= tmpString;
    }break;
    case BOOL:{
        val.Value= "0";
    }break;
    }
    gen->AddSetStack(std::to_string(newVar.Posicion), val.Value);
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
