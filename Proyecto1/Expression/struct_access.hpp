#ifndef STRUCT_ACCESS_HPP
#define STRUCT_ACCESS_HPP
#include "Interface/expression.hpp"

class struct_access : public expression
{
public:
    int Line;
    int Col;
    expression *StructExp;
    std::string Id;
    struct_access(int,int, expression*, std::string);
    symbol ejecutar(environment *env, asttree *tree) override;
    value traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // STRUCT_ACCESS_HPP
