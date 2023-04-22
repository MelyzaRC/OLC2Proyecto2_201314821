#include "instruction_asign_struct.hpp"

instruction_asign_struct::instruction_asign_struct(int line, int col, std::string idStruct, std::string idValue, expression *exp)
{
    this->Line = line;
    this->Col = col;
    this->idStruct = idStruct;
    this->idValue = idValue;
    this->exp = exp;
    this->tipoInstruccion = 100;
}

void instruction_asign_struct::traducir(environment *env, asttree *tree, generator_code *gen){

}

void instruction_asign_struct::ejecutar(environment *env, asttree *tree){
    symbol sym = env->GetVariable(this->idStruct,env,tree);
    if(sym.Tipo == STRUCT){

        environment envValue = *(environment*)sym.valor;
        symbol symValue = envValue.GetVariable(this->idValue,env,tree);
        std::cout<<"TIPO "<<symValue.Tipo<<std::endl;
        if(symValue.Tipo != NULO){
            std::cout<<"encontro el atributo"<<std::endl;
            symbol expValue = this->exp->ejecutar(env,tree);
            if(symValue.Tipo == expValue.Tipo){
                if(expValue.Tipo == STRING){
                    std::string valor = *static_cast<std::string*>(symValue.valor);
                    symbol symEdit(this->Line,this->Col,this->idValue,symValue.Tipo,&valor);
                    envValue.ModificarVariable(symEdit,this->idValue);
                    environment *StructValue = &envValue;
                    symbol symStruct (this->Line,Col,this->idStruct,STRUCT,StructValue);
                    env->ModificarVariable(symStruct,this->idStruct);
                }else if(expValue.Tipo == INTEGER){
                    int valor = *static_cast<int*>(symValue.valor);
                    symbol symEdit(this->Line,this->Col,this->idValue,symValue.Tipo,&valor);
                    envValue.ModificarVariable(symEdit,this->idValue);
                    environment *StructValue = &envValue;
                    symbol symStruct (this->Line,Col,this->idStruct,STRUCT,StructValue);
                    env->ModificarVariable(symStruct,this->idStruct);
                }else if(expValue.Tipo == FLOAT){
                    float valor = *static_cast<float*>(symValue.valor);
                    symbol symEdit(this->Line,this->Col,this->idValue,symValue.Tipo,&valor);
                    envValue.ModificarVariable(symEdit,this->idValue);
                    environment *StructValue = &envValue;
                    symbol symStruct (this->Line,Col,this->idStruct,STRUCT,StructValue);
                    env->ModificarVariable(symStruct,this->idStruct);
                }else if(expValue.Tipo == BOOL){
                    bool valor = *static_cast<bool*>(symValue.valor);
                    symbol symEdit(this->Line,this->Col,this->idValue,symValue.Tipo,&valor);
                    envValue.ModificarVariable(symEdit,this->idValue);
                    environment *StructValue = &envValue;
                    symbol symStruct (this->Line,Col,this->idStruct,STRUCT,StructValue);
                    env->ModificarVariable(symStruct,this->idStruct);
                }else{
                    tree->ErrorOut+= "Error: no coinciden los tipos en la asignación de exp con la variable struct";
                }
            }else{
                tree->ErrorOut+= "Error: no coinciden los tipos en la asignación de exp con la variable struct";
            }
        }
    }else{
        tree->ErrorOut+= "Error en la asignación del struct";
    }
}
