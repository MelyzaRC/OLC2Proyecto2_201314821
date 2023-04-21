#include "call_inst.hpp"
#include "Expression/map_struct_dec.hpp"
#include "Instruction/list_instruction.hpp"

call_inst::call_inst(int line, int col, std::string id, lista_expresiones *explist)
{
    Line = line;
    Col = col;
    Id = id;
    ExpList = explist;
}

void call_inst::ejecutar(environment *env, asttree *tree)
{
    environment *FuncEnv = new environment(env, Id);
    func_symbol sym_func = env->GetFunc(Id, env, tree);
    map_struct_dec mapStrTemp =  map_struct_dec();
    if(sym_func.ParamList != nullptr){
        mapStrTemp = *(map_struct_dec*)sym_func.ParamList;
    }
    list_instruction* instTemp = (list_instruction*)sym_func.InstList;
    if(ExpList != nullptr && !mapStrTemp.ListDec.empty())
    {
        map<std::string, TipoDato> mapTemp = mapStrTemp.ListDec;
        if(ExpList->lista.size() == mapTemp.size())
        {
            //comparando tipos de parametros
            int cont = 0;
            map<std::string, TipoDato>::iterator i;
            for(i = mapTemp.begin(); i != mapTemp.end(); ++i)
            {
                symbol sym = ExpList->lista[cont]->ejecutar(env, tree);
                if(sym.Tipo == i->second){
                    FuncEnv->SaveVariable(sym,i->first, tree);
                }
                else
                {
                    //ERROR SEMANTICO
                    std::string contenido_error =  "No coinciden los tipos en los parametros";
                    tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                    tree->erroresSemanticos++;
                    return;
                }
                cont++;
            }
        }
        else
        {
            //ERROR SEMANTICO
            std::string contenido_error =  "No coincide la cantidad de parametros";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            return;
        }
    }
    //ejecutando instrucciones
    instTemp->ejecutar(FuncEnv, tree);
    this->cadenaPrint = instTemp->cadenaPrint;
}
