#ifndef LIST_INSTRUCTION_SECOND_HPP
#define LIST_INSTRUCTION_SECOND_HPP
#include "Interface/instruction.hpp"
#include "AST/asttree.hpp"
#include "QVector"

class list_instruction_second: public instruction
{
public:
    QVector<instruction*> ListInst;
    list_instruction_second();
    void ejecutar(environment *env, asttree *tree) override;
    void newInst(instruction *inst);
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // LIST_INSTRUCTION_SECOND_HPP
