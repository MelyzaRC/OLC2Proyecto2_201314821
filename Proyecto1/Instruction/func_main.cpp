#include "func_main.hpp"

func_main::func_main(int line, int col, int tipo, list_instruction* list)
{
    this->Line = line;
    this->Col = col;
    this->ListInst = list;
    this->tipoInstruccion = 4;
}

void func_main::ejecutar(environment *env, asttree *tree){
    /*for(int i = 0; i < this->ListInst->ListInst.size(); i++){
        this->ListInst->ListInst.value(i)->ejecutar(env, tree);
        this->cadenaPrint = this->cadenaPrint +  this->ListInst->ListInst.value(i)->cadenaPrint;
    }*/
    this->ListInst->ejecutar(env, tree);
    this->cadenaPrint = this->cadenaPrint +  this->ListInst->cadenaPrint;
}
