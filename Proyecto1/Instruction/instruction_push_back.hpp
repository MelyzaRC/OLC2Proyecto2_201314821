#ifndef INSTRUCTION_PUSH_BACK_HPP
#define INSTRUCTION_PUSH_BACK_HPP
#include "Interface/instruction.hpp"
#include "Interface/expression.hpp"

class instruction_push_back: public instruction
{
public:
    int Line;
    int Col;
    std::string id;
    expression *exp;
    instruction_push_back(int line, int col, std::string id, expression *exp);
    void ejecutar(environment *env, asttree *tree) override;
};

#endif // INSTRUCTION_PUSH_BACK_HPP
