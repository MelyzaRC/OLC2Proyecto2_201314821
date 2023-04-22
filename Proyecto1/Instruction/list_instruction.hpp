#ifndef LIST_INSTRUCTION_HPP
#define LIST_INSTRUCTION_HPP
#include "Interface/instruction.hpp"
#include "AST/asttree.hpp"
#include "QVector"

class list_instruction : public instruction
{
public:
    QVector<instruction*> ListInst;
    list_instruction();
    void ejecutar(environment *env, asttree *tree) override;
    void ejecutar2(environment *env, asttree *tree);
    void newInst(instruction *inst);
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // LIST_INSTRUCTION_HPP
