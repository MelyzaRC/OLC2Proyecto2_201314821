#ifndef MAP_STRUCT_DEC_HPP
#define MAP_STRUCT_DEC_HPP
#include "Interface/expression.hpp"

class map_struct_dec : public expression
{
public:
    map<std::string, TipoDato> ListDec;
    symbol ejecutar(environment *env, asttree *tree) override;
    void newMap(std::string, TipoDato);
    map_struct_dec();
    value traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // MAP_STRUCT_DEC_HPP
