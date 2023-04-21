#ifndef INSTRUCTION_PUSH_FRONT_HPP
#define INSTRUCTION_PUSH_FRONT_HPP
#include "Interface/instruction.hpp"
#include "Interface/expression.hpp"

class instruction_push_front: public instruction
{
public:
    int Line;
    int Col;
    std::string id;
    expression *exp;
    instruction_push_front(int line, int col, std::string id, expression *exp);
    void ejecutar(environment *env, asttree *tree) override;
};

#endif // INSTRUCTION_PUSH_FRONT_HPP
