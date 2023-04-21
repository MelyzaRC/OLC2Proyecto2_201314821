#ifndef INSTRUCTION_VECTOR_REMOVE_HPP
#define INSTRUCTION_VECTOR_REMOVE_HPP
#include "Interface/expression.hpp"
#include "Interface/instruction.hpp"

class instruction_vector_remove: public instruction
{
public:
    int Line;
    int Col;
    std::string id;
    expression *Index;
    instruction_vector_remove(int,int, std::string id, expression*);
    void ejecutar(environment *env, asttree *tree) override;
};

#endif // INSTRUCTION_VECTOR_REMOVE_HPP
