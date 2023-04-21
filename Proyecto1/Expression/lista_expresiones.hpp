#ifndef LISTA_EXPRESIONES_HPP
#define LISTA_EXPRESIONES_HPP
#include "Interface/expression.hpp"
#include "QVector"

class lista_expresiones: public expression
{
public:
    int Line;
    int Col;
    QVector<expression*> lista;
    symbol ejecutar(environment *env, asttree *tree) override;
    lista_expresiones();
    void newExpr(expression *inst);
};

#endif // LISTA_EXPRESIONES_HPP
