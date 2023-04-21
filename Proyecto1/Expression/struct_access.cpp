#include "struct_access.hpp"

struct_access::struct_access(int line,int col, expression* structexp, std::string id)
{
    Line = line;
    Col = col;
    StructExp = structexp;
    Id = id;
}

symbol struct_access::ejecutar(environment *env, asttree *tree)
{
    symbol sym (0,0,"",NULO,nullptr);

    //recuperar struct
    symbol symStruct = StructExp->ejecutar(env, tree);
    if(symStruct.Tipo == STRUCT){
        environment *envStruct = (environment *)symStruct.valor;
        sym = envStruct->GetVariable(Id, envStruct,tree);
    }else{
        //REPORTAR ERROR
        std::cout<<"Error el simbolo no es un struct"<<std::endl;
    }
    return sym;
}
