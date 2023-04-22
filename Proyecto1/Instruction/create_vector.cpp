#include "create_vector.hpp"
#include <map>
#include <QVector>
#include <QDebug>

create_vector::create_vector(int line,int col,TipoDato tipo,std::string id, lista_expresiones *listaV)
{
    this->Line = line;
    this->Col = col;
    this->tipoDato = tipo;
    this->lista = listaV;
    this->id = id;

}

void create_vector::traducir(environment *env, asttree *tree, generator_code *gen){

}

void create_vector::ejecutar(environment *env, asttree *tree)
{
    //ES UN VECTOR VACIO
    if(lista == nullptr){
        QVector<symbol> value;
        env->SaveArray(value,this->tipoDato,this->id,tree);
    }else{
        //VERIFICA Y AGREGA LOS VALORES
        int estado = 0;
        QVector<symbol> value;
        for(int i = 0; i<lista->lista.size(); i++){
          symbol sym = this->lista->lista[i]->ejecutar(env,tree);
          if(sym.Tipo == this->tipoDato){
            value.push_back(sym);
          }else{
              //ERROR SEMANTICO
              std::string contenido_error =  "Se ha detectado un valor de tipo ";
              contenido_error += env->obtenerTipo(sym.Tipo);
              contenido_error += " en la posición ";
              contenido_error += std::to_string(i);
              tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
              tree->erroresSemanticos++;
              estado = 1;
              break;
          }

        }
        //TODOS LOS ELEMENTOS SON DEL MISMO TIPO DEL VECTOR
        if(estado == 0){
            env->SaveArray(value,this->tipoDato,this->id,tree);
        }
    }
}
