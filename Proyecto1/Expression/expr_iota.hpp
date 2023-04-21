#ifndef EXPR_IOTA_HPP
#define EXPR_IOTA_HPP
#include "Interface/expression.hpp"

class expr_iota: public expression
{
public:
    int Line;
    int Col;
    expression *contenido;
    expr_iota(int line, int col, expression *a);
    symbol ejecutar(environment *env, asttree *tree) override;
};

#endif // EXPR_IOTA_HPP
