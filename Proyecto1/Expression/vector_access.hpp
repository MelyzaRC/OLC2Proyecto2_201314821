#ifndef VECTOR_ACCESS_HPP
#define VECTOR_ACCESS_HPP
#include "Interface/expression.hpp"

class vector_access: public expression
{
public:
    int Line;
    int Col;
    std::string id;
    expression *Index;
    vector_access(int line, int col,  std::string , expression*);
    symbol ejecutar(environment *env, asttree *tree) override;
    value traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // VECTOR_ACCESS_HPP
