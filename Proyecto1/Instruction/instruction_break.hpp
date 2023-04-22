#ifndef INSTRUCTION_BREAK_HPP
#define INSTRUCTION_BREAK_HPP
#include "Interface/instruction.hpp"


class instruction_break: public instruction
{
public:
    int Line;
    int Col;
    instruction_break(int a , int b);
    void ejecutar(environment *env, asttree *tree) override;
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // INSTRUCTION_BREAK_HPP
