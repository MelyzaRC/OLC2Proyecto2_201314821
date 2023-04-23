#include "func_printf.hpp"
#include "QVector"
#include "Expression/lista_expresiones.hpp"

func_printf::func_printf(int line, int col, lista_expresiones *val)
{
    this->Line = line;
    this->Col = col;
    this->contenido = val;
    this->cadenaPrint = "";
    this->tipoInstruccion = 5;
}

void func_printf::traducir(environment *env, asttree *tree, generator_code *gen){
}

void func_printf::ejecutar(environment *env, asttree *tree){
    //RECORRER LA LISTA QUE SE ENCUENTRA EN CONTENIDO
    QVector<expression*> lista = QVector<expression*>();
    lista = this->contenido->lista;
    for(int i = 0; i < lista.size(); i++){
        symbol res = lista.value(i)->ejecutar(env, tree);
        if(res.Tipo == STRING){
            std::string *sp = static_cast<std::string*>(res.valor);
            this->cadenaPrint += *sp;
        }else if(res.Tipo == NULO){
            this->cadenaPrint += "NULL";
        }else{
            //REPORTAR ERROR
            break;
        }
    }
    if(this->cadenaPrint != ""){
        this->cadenaPrint += "\n";
    }
}
