#ifndef NEGACION_UNARIA_HPP
#define NEGACION_UNARIA_HPP
#include "Interface/expression.hpp"

class negacion_unaria: public expression
{
public:
    int Line;
    int Col;
    expression *valor;
    negacion_unaria(int line, int col, expression *exp);
    symbol ejecutar(environment *env, asttree *tree) override;
};

#endif // NEGACION_UNARIA_HPP
