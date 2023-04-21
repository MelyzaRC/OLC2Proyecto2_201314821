#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP
#include "Interface/expression.hpp"
#include "AST/asttree.hpp"

class primitive : public expression
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string StrVal;
    int NumVal;
    float FloatVal;
    bool BoolVal;


    primitive(int a,int b,TipoDato c,std::string strVal, int numVal, float floatVal, bool boolVal);
    symbol ejecutar(environment *env, asttree *tree) override;
};

#endif // PRIMITIVE_HPP
