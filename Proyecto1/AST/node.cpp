#include "node.hpp"

node::node()
{
    this->hijos = QVector<node*>();
}


void node::addHijo(node *nodo)
{
    this->hijos.push_back(nodo);
}
