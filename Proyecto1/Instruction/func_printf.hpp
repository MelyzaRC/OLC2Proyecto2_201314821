#ifndef FUNC_PRINTF_HPP
#define FUNC_PRINTF_HPP
#include "Interface/instruction.hpp"
#include "Interface/expression.hpp"
#include "Expression/lista_expresiones.hpp"
#include "Environment/type.hpp"

class func_printf : public instruction
{
public:
    int Line;
    int Col;
    lista_expresiones *contenido;
    func_printf(int line, int col, lista_expresiones *val);
    void ejecutar(environment *env, asttree *tree) override;
};

#endif // FUNC_PRINTF_HPP
