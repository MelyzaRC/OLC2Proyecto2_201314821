#ifndef DECLARATION_HPP
#define DECLARATION_HPP
#include "Interface/instruction.hpp"
#include "Interface/expression.hpp"
#include "Environment/type.hpp"


class declaration : public instruction
{
public:
    int Line;
    int Col;
    std::string nombre;
    expression *Valor;
    int tipo;
    void ejecutar(environment *env, asttree *tree) override;
    declaration(int line, int col, std::string nombre, expression *val, int tipo);
    declaration();
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // DECLARATION_HPP
