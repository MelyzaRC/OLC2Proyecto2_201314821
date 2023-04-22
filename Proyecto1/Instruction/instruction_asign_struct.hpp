#ifndef INSTRUCTION_ASIGN_STRUCT_HPP
#define INSTRUCTION_ASIGN_STRUCT_HPP
#include "Interface/instruction.hpp"
#include "Interface/expression.hpp"

class instruction_asign_struct: public instruction
{
public:
    int Line;
    int Col;
    std::string idStruct;
    std::string idValue;
    expression *exp;
    instruction_asign_struct(int line, int col, std::string idStruct, std::string idValue, expression *exp);
    void ejecutar(environment *env, asttree *tree) override;
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // INSTRUCTION_ASIGN_STRUCT_HPP
