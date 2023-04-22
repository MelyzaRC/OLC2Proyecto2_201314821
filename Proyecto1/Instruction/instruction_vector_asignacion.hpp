#ifndef INSTRUCTION_VECTOR_ASIGNACION_HPP
#define INSTRUCTION_VECTOR_ASIGNACION_HPP
#include "Interface/expression.hpp"
#include "Interface/instruction.hpp"

class instruction_vector_asignacion: public instruction
{
public:
    int line;
    int Col;
    std::string id;
    expression *index;
    expression *exp;
    instruction_vector_asignacion(int line, int col, std::string id, expression *index, expression *exp);
    void ejecutar(environment *env, asttree *tree) override;
    void traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // INSTRUCTION_VECTOR_ASIGNACION_HPP
