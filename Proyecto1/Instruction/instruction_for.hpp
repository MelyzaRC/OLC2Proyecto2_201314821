#ifndef INSTRUCTION_FOR_HPP
#define INSTRUCTION_FOR_HPP
#include "Interface/instruction.hpp"
#include "Interface/expression.hpp"
#include "AST/asttree.hpp"
#include "Instruction/list_instruction.hpp"
#include "Instruction/list_instruction_second.hpp"

class instruction_for: public instruction
{
public:
    int Line;
    int Col;
    std::string iterador;
    instruction *variable_iterador;
    expression *Condicion;
    instruction *salto;
    list_instruction_second* ListInst;
    instruction_for(int line, int col, instruction* inst_iterador, expression* condicion, instruction* salto, list_instruction_second* lista);
    void ejecutar(environment *env, asttree *ast) override;
    bool validarIterador(environment *env, asttree *ast);
    std::string ejecutarFor(environment *env, asttree *ast);
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // INSTRUCTION_FOR_HPP
