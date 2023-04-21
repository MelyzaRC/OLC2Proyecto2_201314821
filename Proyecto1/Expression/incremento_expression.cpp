#include "incremento_expression.hpp"

incremento_expression::incremento_expression(int line, int col, std::string nombre, int tipoIns, std::string operador)
{
    this->Col = col;
    this->Line = line;
    this->nombre = nombre;
    this->tipoIncr = tipoIns;
    this->operador = operador;

}

symbol incremento_expression::ejecutar(environment *env, asttree *tree){
    if(this->tipoIncr == 1){
       env->IncrementarVariable(this->nombre, tree);
        symbol sym = env->GetVariable(this->nombre, env, tree);
        return sym;
    }else{
        symbol sym = env->GetVariable(this->nombre, env, tree);
        env->IncrementarVariable(this->nombre, tree);
        return sym;
    }
}
