#include "instruction_continue.hpp"

instruction_continue::instruction_continue(int a , int b)
{
    this->Line = a;
    this->Col = b;
    this->tipoInstruccion =  12;
}

void instruction_continue::traducir(environment *env, asttree *tree, generator_code *gen){

}

void instruction_continue::ejecutar(environment *env, asttree *tree){
    tree->activarBanderaContinue();
}
