#include "llamada_variable.hpp"

llamada_variable::llamada_variable(int line, int col, std::string name)
{
    this->Line = line;
    this->Col = col;
    this->nombre = name;
    this->tipo = 2;
}

value llamada_variable::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    return val;
}

symbol llamada_variable::ejecutar(environment *env, asttree *tree){
    //BUSCAR EN EL ENTORNO
    return buscar(env, tree);
}

//BUSCAR EN EL ENTORNO - SI NO LO ENCUENTRA BUSCAR EN EL PADRE
symbol llamada_variable::buscar(environment *env, asttree *tree){
    symbol sym1 = env->GetVariable(this->nombre, env, tree);
    if(sym1.Tipo != NULO){
        return sym1;
    }
    return *new symbol(0,0,"",NULO,0);
}
