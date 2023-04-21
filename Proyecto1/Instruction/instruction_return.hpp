#ifndef INSTRUCTION_RETURN_HPP
#define INSTRUCTION_RETURN_HPP
#include "Interface/expression.hpp"
#include "Interface/instruction.hpp"

class instruction_return : public instruction
{
public:
    int Line;
    int Col;
    expression *Exp;
    instruction_return(int, int, expression*);
    void ejecutar(environment *env, asttree *tree) override;
};

#endif // INSTRUCTION_RETURN_HPP
