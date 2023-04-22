#include "map_struct_dec.hpp"

map_struct_dec::map_struct_dec()
{

}

value map_struct_dec::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    return val;
}

symbol map_struct_dec::ejecutar(environment *env, asttree *tree)
{
    symbol sym (0,0,"",NULO,nullptr);
    return sym;
}

void map_struct_dec::newMap(std::string id, TipoDato tipo)
{
    ListDec[id] = tipo;
}
