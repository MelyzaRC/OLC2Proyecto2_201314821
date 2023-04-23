#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP
#include "AST/asttree.hpp"
#include "Environment/environment.hpp"
#include "Environment/symbol.hpp"
#include "AST/node.hpp"
#include "Environment/generator_code.hpp"

class instruction
{
public:
    int tipoInstruccion;
    std::string cadenaPrint;
    std::string contenidoDot;
    int referencia;
    virtual void ejecutar(environment *env, asttree *tree) = 0;
    virtual void traducir(environment *env, asttree *tree, generator_code *gen) = 0;
};

#endif // INSTRUCTION_HPP
