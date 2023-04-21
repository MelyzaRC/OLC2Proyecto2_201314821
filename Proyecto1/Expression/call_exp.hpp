#ifndef CALL_EXP_HPP
#define CALL_EXP_HPP
#include "Expression/lista_expresiones.hpp".hpp"
#include "Interface/expression.hpp"

class call_exp: public expression
{
public:
    int Line;
    int Col;
    std::string Id;
    lista_expresiones *ExpList;
    call_exp(int, int, std::string, lista_expresiones*);
    symbol ejecutar(environment *env, asttree *tree) override;
};

#endif // CALL_EXP_HPP
