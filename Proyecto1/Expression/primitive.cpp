#include "primitive.hpp"
#include "AST/asttree.hpp"
#include "Environment/symbol.hpp"
#include <iostream>
#include <math.h>

primitive::primitive(int a,int b,TipoDato c,std::string strVal, int numVal, float floatVal, bool boolVal){
    this->Line = a;
    this->Col = b;
    this->Tipo = c;
    this->NumVal = numVal;
    this->StrVal = strVal;
    this->FloatVal = floatVal;
    this->BoolVal = boolVal;
    this->tipo = 5;
}

value primitive::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    return val;
}

symbol primitive::ejecutar(environment *env, asttree* tree)
{
    //*********************************************************
    symbol sym (Line,Col,"",NULO, nullptr);

    switch (this->Tipo) {
        case INTEGER:{
            sym = *new symbol(Line, Col, "", INTEGER, &NumVal);
            }
        break;
        case FLOAT:{
            float numF = FloatVal;
            float* floatv = new float;
            *floatv = numF;
            sym = *new symbol(Line, Col, "", FLOAT, floatv);
            }
        break;
        case STRING:
            {
                sym = *new symbol(Line, Col, "", STRING, &StrVal);
            }
            break;
        case BOOL:
            {
            sym = *new symbol(Line, Col, "", BOOL, &BoolVal);
            }
            break;
    }
    return sym;
}

