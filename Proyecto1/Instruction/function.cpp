#include "function.hpp"

function::function(int line, int col, TipoDato tipo, std::string id, map_struct_dec *paramlist, list_instruction *instlist)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    ParamList = paramlist;
    InstList = instlist;
    this->tipoInstruccion = 100;
}

void function::traducir(environment *env, asttree *tree, generator_code *gen){

}

void function::ejecutar(environment *env, asttree *tree)
{
    func_symbol funcSym = func_symbol(Line, Col, NULO, "", nullptr, nullptr);
    if(this->ParamList != nullptr){
        funcSym = func_symbol(Line, Col, Tipo, Id, ParamList, InstList);
    }else{
        funcSym = func_symbol(Line, Col, Tipo, Id, nullptr, InstList);
    }
    env->SaveFunc(funcSym, Id, tree);
}
