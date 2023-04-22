#include "create_struct.hpp"

create_struct::create_struct(int line,int col, std::string idstruct, std::string id, lista_expresiones *explist)
{
    Line = line;
    Col = col;
    IdStruct = idstruct;
    Id = id;
    ExpList = explist;
}

void create_struct::traducir(environment *env, asttree *tree, generator_code *gen){

}

void create_struct::ejecutar(environment *env, asttree *tree)
{
    //buscar el struct en tabla de structs
    map<std::string, TipoDato> sym_struct = env->GetStruct(IdStruct, env, tree);
    //validar tamaños
    if(this->ExpList != nullptr){
        if(sym_struct.size() == ExpList->lista.size())
        {
            //creando entorno struct
            environment *StructValue = new environment(nullptr, Id);
            //comparando tipos en iteraciones
            int cont = 0;
            map<std::string, TipoDato>::reverse_iterator it = sym_struct.rbegin();
            while (it != sym_struct.rend()) {
                symbol sym = ExpList->lista[cont]->ejecutar(env, tree);
                if(sym.Tipo == it->second){
                    //se asigna el valor
                    StructValue->SaveVariable(sym,it->first, tree);
                }
                else
                {
                    //ERROR SEMANTICO
                    std::string contenido_error =  "Los tipos no coinciden [";
                    contenido_error += env->obtenerTipo(sym.Tipo);
                    contenido_error += " - ";
                    contenido_error += env->obtenerTipo(it->second);
                    contenido_error += "]";
                    tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                    tree->erroresSemanticos++;
                    return;
                }
                it++;
                cont++;
            }

            //se guarda el StructValue en el entorno de simbolos
            symbol symStruct (Line,Col,Id,STRUCT,StructValue);
            env->SaveVariable(symStruct,Id, tree);
        }
        else
        {
            //ERROR SEMANTICO
            std::string contenido_error =  "Los parámetros no coinciden para el STRUCT ";
            contenido_error += this->Id;
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            return;
        }
    }else{
        environment *StructValue = new environment(nullptr, Id);
        int cont = 0;
        map<std::string, TipoDato>::reverse_iterator it = sym_struct.rbegin();
        while (it != sym_struct.rend()) {
            symbol sym;
            switch(it->second){
            case INTEGER:{
                int* intDef = new int;
                *intDef = 0;
                sym = *new symbol(this->Line, this->Col, "", INTEGER, intDef);
            }break;
            case FLOAT:{
                float floatDef = 0.0;
                sym = *new symbol(this->Line, this->Col, "", FLOAT, &floatDef);
            }break;
            case STRING:{
                std::string stringDef = "";
                sym = *new symbol(this->Line, this->Col, "", STRING, &stringDef);
            }break;
            case BOOL:{
                bool boolDef = false;
                sym = *new symbol(this->Line, this->Col, "", BOOL, &boolDef);
            }break;
            }
            StructValue->SaveVariable(sym,it->first, tree);
            it++;
            cont++;
        }
        symbol symStruct (Line,Col,Id,STRUCT,StructValue);
        env->SaveVariable(symStruct,Id, tree);
    }
}
