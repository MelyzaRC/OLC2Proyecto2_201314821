#ifndef LLAMADA_VARIABLE_HPP
#define LLAMADA_VARIABLE_HPP
#include "Interface/expression.hpp"
#include "AST/asttree.hpp"


class llamada_variable: public expression
{
public:
    std::string nombre;
    int Line;
    int Col;
    llamada_variable(int line, int col, std::string name);
    symbol buscar(environment *env, asttree *tree);
    symbol ejecutar(environment *env, asttree *tree) override;
};

#endif // LLAMADA_VARIABLE_HPP
