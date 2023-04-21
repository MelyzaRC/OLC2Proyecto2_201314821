#ifndef EXPR_ATOF_HPP
#define EXPR_ATOF_HPP
#include "Interface/expression.hpp"

class expr_atof: public expression
{
public:
    int Line;
    int Col;
    expression *contenido;
    expr_atof(int line, int col, expression *a);
    symbol ejecutar(environment *env, asttree *tree) override;
};

#endif // EXPR_ATOF_HPP
