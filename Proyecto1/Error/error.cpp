#include "error.hpp"

error::error(){}

error::error(int line, int col, int type, std::string cont)
{
    this->Line = line;
    this->Col = col;
    this->tipo = type;
    this->contenido = cont;
}


