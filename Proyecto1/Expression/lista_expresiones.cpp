#include "lista_expresiones.hpp"

lista_expresiones::lista_expresiones()
{
    this->lista = QVector<expression*>();
}

value lista_expresiones::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    return val;
}

void lista_expresiones::newExpr(expression *exp)
{
    this->lista.push_back(exp);
}

symbol lista_expresiones::ejecutar(environment *env, asttree *tree){
}
