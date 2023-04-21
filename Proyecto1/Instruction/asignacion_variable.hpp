#ifndef ASIGNACION_VARIABLE_HPP
#define ASIGNACION_VARIABLE_HPP
#include "Interface/expression.hpp"
#include "Interface/instruction.hpp"
#include "AST/asttree.hpp"

class asignacion_variable: public instruction
{
public:
    int Line;
    int Col;
    std::string nombre;
    expression *valor;
    asignacion_variable();
    asignacion_variable(int line, int col, std::string name, expression *val);
    void ejecutar(environment *env, asttree *tree) override;
    int asignar(environment *env, asttree *tree);
};

#endif // ASIGNACION_VARIABLE_HPP
