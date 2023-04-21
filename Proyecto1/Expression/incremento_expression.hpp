#ifndef INCREMENTO_EXPRESSION_HPP
#define INCREMENTO_EXPRESSION_HPP
#include "Interface/expression.hpp"
#include "AST/asttree.hpp"

class incremento_expression: public expression
{
public:
    int Line;
    int Col;
    std::string nombre;
    int tipoIncr;
    std::string operador;
    incremento_expression(int line, int col, std::string nombre, int tipo, std::string operador);
    symbol ejecutar(environment *env, asttree *tree) override;
};

#endif // INCREMENTO_EXPRESSION_HPP
