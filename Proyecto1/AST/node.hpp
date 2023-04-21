#ifndef NODE_HPP
#define NODE_HPP
#include "QVector"

class node
{
public:
    std::string ref;
    std::string contenido;
    QVector<node*> hijos;
    node();
    void addHijo(node *nodo);

};

#endif // NODE_HPP
