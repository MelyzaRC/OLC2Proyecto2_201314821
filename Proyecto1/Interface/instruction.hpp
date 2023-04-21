#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP
#include "AST/asttree.hpp"
#include "Environment/environment.hpp"
#include "Environment/symbol.hpp"
#include "AST/node.hpp"

class instruction
{
public:
    int tipoInstruccion;
    std::string cadenaPrint;
    node *node;
    std::string contenidoDot;
    int referencia;
    virtual void ejecutar(environment *env, asttree *tree) = 0;
};

#endif // INSTRUCTION_HPP
