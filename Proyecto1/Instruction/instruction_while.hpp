#ifndef INSTRUCTION_WHILE_HPP
#define INSTRUCTION_WHILE_HPP
#include "Interface/instruction.hpp"
#include "Interface/expression.hpp"
#include "AST/asttree.hpp"
#include "Instruction/list_instruction.hpp"
#include "Instruction/list_instruction_second.hpp"

class instruction_while: public instruction
{
public:
    int Line;
    int Col;
    expression* condicion;
    list_instruction_second* ListInst;
    int iteracion;

    instruction_while(int line, int col, expression* ex, list_instruction_second* list);
    void ejecutar(environment *env, asttree *tree) override;
   std::string ejecutarWhile(environment *env, asttree *tree);
   void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // INSTRUCTION_WHILE_HPP
