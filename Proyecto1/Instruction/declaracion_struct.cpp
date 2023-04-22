#include "declaracion_struct.hpp"
//
declaracion_struct::declaracion_struct(int line, int col, map_struct_dec *array,std::string id)
{
    Line = line;
    Col = col;
    Array = array;
    Id = id;
}

void declaracion_struct::traducir(environment *env, asttree *tree, generator_code *gen){

}

void declaracion_struct::ejecutar(environment *env, asttree *tree)
{
//    map<std::string, TipoDato>::iterator i;
//    for(i = Array->ListDec.begin(); i != Array->ListDec.end(); ++i){
//        std::cout << i->first << ": " << i->second << std::endl;
//    }
    env->SaveStruct(Array->ListDec,Id, tree);
}
