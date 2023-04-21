#ifndef INSTRUCTION_IF_HPP
#define INSTRUCTION_IF_HPP
#include "Interface/instruction.hpp"
#include "Interface/expression.hpp"
#include "AST/asttree.hpp"
#include "Instruction/list_instruction.hpp"
#include "Instruction/list_instruction_second.hpp"

class instruction_if : public instruction
{
public:
    int Line;
    int Col;
    expression *Condition;
    instruction *Block;
    int estado;
    list_instruction_second* ListElseIf;
    instruction *ElseIfBlock;
    instruction *ElseBlock;

    instruction_if(int line, int col, expression *condition, instruction *block, instruction *elseifblock, instruction *elseblock);
    void ejecutar(environment *env, asttree *tree) override;
};

#endif // INSTRUCTION_IF_HPP
