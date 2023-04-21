#ifndef INCREMENTO_HPP
#define INCREMENTO_HPP
#include "Interface/instruction.hpp"
#include "AST/asttree.hpp"

class incremento : public instruction
{
public:
    int Line;
    int Col;
    std::string nombre;
    incremento(int line, int col, std::string nombre);
    void ejecutar(environment *env, asttree *tree) override;
    int incrementar(environment *env, asttree *tree);
};

#endif // INCREMENTO_HPP
