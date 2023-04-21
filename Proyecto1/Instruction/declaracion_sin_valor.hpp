#ifndef DECLARACION_SIN_VALOR_HPP
#define DECLARACION_SIN_VALOR_HPP
#include "Interface/instruction.hpp"
#include "Interface/expression.hpp"
#include "Environment/type.hpp"


class declaracion_sin_valor: public instruction
{
public:
    int Line;
    int Col;
    std::string nombre;
    int tipo;
    void ejecutar(environment *env, asttree *tree) override;
    declaracion_sin_valor(int line, int col, std::string nombre, int tipo);
    declaracion_sin_valor();
};

#endif // DECLARACION_SIN_VALOR_HPP
