#include "instruction_return.hpp"

instruction_return::instruction_return(int line, int col, expression *exp)
{
    Line = line;
    Col = col;
    Exp = exp;
}

void instruction_return::ejecutar(environment *env, asttree *tree)
{
    if(Exp != nullptr)
    {
        symbol sym = Exp->ejecutar(env, tree);
        tree->ListReturn.push_back(sym);
    }
}
