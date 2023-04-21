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

    symbol(int line, int col, std::string id, TipoDato tipo, void *val);
    symbol();
};

#endif // SYMBOL_HPP
