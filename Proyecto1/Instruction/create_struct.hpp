#ifndef CREATE_STRUCT_HPP
#define CREATE_STRUCT_HPP
#include "Expression/lista_expresiones.hpp"
#include "Interface/instruction.hpp"

class create_struct : public instruction
{
public:
    int Line;
    int Col;
    std::string IdStruct;
    std::string Id;
    lista_expresiones *ExpList;
    create_struct(int,int, std::string, std::string, lista_expresiones*);
    void ejecutar(environment *env, asttree *tree) override;
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // CREATE_STRUCT_HPP
