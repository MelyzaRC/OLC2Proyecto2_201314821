#ifndef EXPR_SIZE_VECTOR_HPP
#define EXPR_SIZE_VECTOR_HPP
#include "Interface/expression.hpp"

class expr_size_vector: public expression
{
public:
    int Line;
    int Col;
    std::string id;
    expr_size_vector(int line, int col, std::string id);
    symbol ejecutar(environment *env, asttree *tree) override;
    value traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // EXPR_SIZE_VECTOR_HPP
