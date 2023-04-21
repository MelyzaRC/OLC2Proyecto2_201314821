#ifndef EXPR_ATOI_HPP
#define EXPR_ATOI_HPP
#include "Interface/expression.hpp"

class expr_atoi: public expression
{
public:
    int Line;
    int Col;
    expression *contenido;
    expr_atoi(int line, int col, expression *a);
    symbol ejecutar(environment *env, asttree *tree) override;
};

#endif // EXPR_ATOI_HPP
