#include "list_instruction.hpp"

list_instruction::list_instruction()
{
    this->ListInst = QVector<instruction*>();
    this->tipoInstruccion = 10;
    this->cadenaPrint = "";
}

void list_instruction::traducir(environment *env, asttree *tree, generator_code *gen){

}

void list_instruction::ejecutar(environment *env, asttree *tree)
{
    std::string* cadenaValor = new std::string;

    for(int i = 0; i < this->ListInst.size(); i++){
        ListInst.value(i)->cadenaPrint = "";
        this->ListInst.value(i)->ejecutar(env, tree);
        *cadenaValor += this->ListInst.value(i)->cadenaPrint;
        /*if(tree->breakFlag== true){
            break;
        }
        if(tree->continueFlag== true){
            break;
        }*/

    }
    this->cadenaPrint = *cadenaValor;
    tree->cadenaTab += env->graficar();

}

void list_instruction::ejecutar2(environment *env, asttree *tree)
{
    for(int i = 0; i < this->ListInst.size(); i++){
        if(this->ListInst.value(i)->tipoInstruccion != 4){
            this->ListInst.value(i)->ejecutar(env, tree);
        }
    }
}

void list_instruction::newInst(instruction *inst)
{
    this->ListInst.push_back(inst);
}
