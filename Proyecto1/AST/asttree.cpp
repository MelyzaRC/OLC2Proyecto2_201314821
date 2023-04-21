#include "asttree.hpp"

asttree::asttree()
{
    this->breakFlag = false;
    this->continueFlag = false;
    this->ElseIfFlag = false;
    ListReturn = QVector<symbol>();
    errores =  QVector<error_analisis>();
    this->erroresSemanticos = 0;
    this->cadenaTab = "";
}

void asttree::addError(error_analisis er){
    this->errores.push_back(er);
}

void asttree::IncrementaErroresSemanticos(){
    int* tmp = new int;
    *tmp = 1+ this->erroresSemanticos;
    this->erroresSemanticos = *tmp;
}

void asttree::activarBanderaBreak(){
    bool* tmp = new bool;
    *tmp = true;
    this->breakFlag = true;
}

void asttree::inactivarBanderaBreak(){
    bool* tmp = new bool;
    *tmp = false;
    this->breakFlag = false;
}

void asttree::activarBanderaIf(){
    bool* tmp = new bool;
    *tmp = true;
    this->ElseIfFlag = true;
}

void asttree::inactivarBanderaIf(){
    bool* tmp = new bool;
    *tmp = false;
    this->ElseIfFlag = false;
}

void asttree::activarBanderaContinue(){
    bool* tmp = new bool;
    *tmp = true;
    this->continueFlag = true;
}

void asttree::inactivarBanderaContinue(){
    bool* tmp = new bool;
    *tmp = false;
    this->continueFlag = false;
}

