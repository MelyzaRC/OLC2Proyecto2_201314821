#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include "Expression/map_struct_dec.hpp"
#include "Instruction/list_instruction.hpp"
#include "Interface/instruction.hpp"

class function: public instruction
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string Id;
    map_struct_dec *ParamList;
    list_instruction *InstList;

    function(int,int, TipoDato, std::string, map_struct_dec*, list_instruction*);
    void ejecutar(environment *env, asttree *tree) override;
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // FUNCTION_HPP
