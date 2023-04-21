#ifndef CALL_INST_HPP
#define CALL_INST_HPP
#include "Expression/lista_expresiones.hpp"
#include "Interface/instruction.hpp"

class call_inst : public instruction
{
public:
    int Line;
        int Col;
        std::string Id;
        lista_expresiones *ExpList;

        call_inst(int, int, std::string, lista_expresiones*);
        void ejecutar(environment *env, asttree *tree) override;
};

#endif // CALL_INST_HPP
