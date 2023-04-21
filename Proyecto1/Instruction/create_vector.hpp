#ifndef CREATE_VECTOR_HPP
#define CREATE_VECTOR_HPP
#include "Interface/instruction.hpp"
#include "Expression/lista_expresiones.hpp"

class create_vector: public instruction
{
public:
    int Line;
    int Col;
    TipoDato tipoDato;
    std::string id;
    void *value;
    lista_expresiones *lista;
    create_vector(int line,int col,TipoDato tipo,std::string id, lista_expresiones *lista);
    void ejecutar(environment *env, asttree *tree) override;
};

#endif // CREATE_VECTOR_HPP
