#include "symbol.hpp"

symbol::symbol(int line, int col, std::string id, TipoDato tipo, void *val){
    this->Line = line;
    this->Col = col;
    this->Id = id;
    this->Tipo = tipo;
    this->valor = val;
    this->Posicion = 0;
}

symbol::symbol(int line, int col, std::string id, TipoDato tipo, int posicion)
{
    Line = line;
    Col = col;
    Id = id;
    Tipo = tipo;
    Posicion = posicion;
}


symbol::symbol(){

}


