#ifndef FUNC_MAIN_HPP
#define FUNC_MAIN_HPP
#include "Interface/instruction.hpp"
#include "Instruction/list_instruction.hpp"

class func_main: public instruction
{
public:
    int Line;
    int Col;
    int tipo;
    list_instruction* ListInst;
    func_main(int line, int col, int tipo, list_instruction* list);
    void ejecutar(environment *env, asttree *tree) override;
};

#endif // FUNC_MAIN_HPP
