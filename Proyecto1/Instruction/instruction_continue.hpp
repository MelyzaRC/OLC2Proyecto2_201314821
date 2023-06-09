#ifndef INSTRUCTION_CONTINUE_HPP
#define INSTRUCTION_CONTINUE_HPP
#include "Interface/instruction.hpp"

class instruction_continue: public instruction
{
public:
    int Line;
    int Col;
    instruction_continue(int a, int b);
    void ejecutar(environment *env, asttree *tree) override;
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // INSTRUCTION_CONTINUE_HPP
