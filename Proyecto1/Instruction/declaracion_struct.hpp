#ifndef DECLARACION_STRUCT_HPP
#define DECLARACION_STRUCT_HPP
#include "Interface/instruction.hpp"
#include "Expression/map_struct_dec.hpp"

class declaracion_struct: public instruction
{
public:
    int Line;
    int Col;
    map_struct_dec *Array;
    std::string Id;

    declaracion_struct(int,int, map_struct_dec*, std::string);
    void ejecutar(environment *env, asttree *tree) override;
};

#endif // DECLARACION_STRUCT_HPP
