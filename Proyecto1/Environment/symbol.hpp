#ifndef SYMBOL_HPP
#define SYMBOL_HPP
#include <iostream>
#include "type.hpp"
#include "Qvector"

class symbol
{
public:
    int Line;
    int Col;
    std::string Id;
    TipoDato Tipo;
    void *valor;
    int Posicion;

    symbol(int line, int col, std::string id, TipoDato tipo, void *val);
    symbol(int line, int col, std::string id, TipoDato tipo, int posicion);
    symbol();
};

#endif // SYMBOL_HPP
