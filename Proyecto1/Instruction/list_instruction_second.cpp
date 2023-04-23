#include "list_instruction_second.hpp"

list_instruction_second::list_instruction_second()
{
    this->ListInst = QVector<instruction*>();
    this->tipoInstruccion = 100;
    this->cadenaPrint = "";
}

void list_instruction_second::traducir(environment *env, asttree *tree, generator_code *gen){
    std::cout<<"Traduciendo lista_second"<<std::endl;
    for(int i = 0; i < this->ListInst.size(); i++){
        this->ListInst.value(i)->traducir(env, tree, gen);
    }
}

void list_instruction_second::ejecutar(environment *env, asttree *tree)
{
    std::string* cadenaValor = new std::string;
    this->cadenaPrint = "";
    for(int i = 0; i < this->ListInst.size(); i++){
        ListInst.value(i)->cadenaPrint = "";
        this->ListInst.value(i)->ejecutar(env, tree);
        *cadenaValor += this->ListInst.value(i)->cadenaPrint;
        if(tree->breakFlag == true){
            break;
        }
        if(tree->continueFlag == true){
            tree->inactivarBanderaContinue();
            break;
        }

    }
    this->cadenaPrint = *cadenaValor;
}

void list_instruction_second::newInst(instruction *inst)
{
    this->ListInst.push_back(inst);
}

