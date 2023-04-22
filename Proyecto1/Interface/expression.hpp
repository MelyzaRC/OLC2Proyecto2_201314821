#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP
#include "AST/asttree.hpp"
#include "Environment/symbol.hpp"
#include "Environment/environment.hpp"
#include "AST/node.hpp"
#include "Environment/value.hpp"
#include "Environment/generator_code.hpp"


class expression
{
public:
    int tipo;
    node *node;
    std::string contenidoDot;
    int referencia;
    virtual symbol ejecutar(environment *env, asttree *tree) = 0;
    virtual value traducir(environment *env, asttree *tree, generator_code *gen) = 0;
};

#endif // EXPRESSION_HPP
