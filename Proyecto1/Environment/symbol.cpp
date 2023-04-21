#include "symbol.hpp"

symbol::symbol(int line, int col, std::string id, TipoDato tipo, void *val){
    this->Line = line;
    this->Col = col;
    this->Id = id;
    this->Tipo = tipo;
    this->valor = val;
}
symbol::symbol(){

}


