#include "instruction_break.hpp"

instruction_break::instruction_break(int a , int b)
{
    this->Line = a;
    this->Col = b;
    this->tipoInstruccion = 11;
}

void instruction_break::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode= true;
    if(tree->LabelBreak != ""){
        gen->AddGoto(tree->LabelBreak);
    }
}

void instruction_break::ejecutar(environment *env, asttree *tree){
    tree->activarBanderaBreak();
}
