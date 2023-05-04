#include "create_vector.hpp"
#include <map>
#include <QVector>
#include <QDebug>
#include "Environment/value.hpp"

create_vector::create_vector(int line,int col,TipoDato tipo,std::string id, lista_expresiones *listaV)
{
    this->Line = line;
    this->Col = col;
    this->tipoDato = tipo;
    this->lista = listaV;
    this->id = id;

}

void create_vector::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode = true;
    gen->AddComment("CREACION VECTOR =================");
    std::string tmpInicioVector = gen->newTemp();
    std::string L1 = gen->newLabel();
    std::string L2 = gen->newLabel();
    std::string L3 = gen->newLabel();
    std::string L4 = gen->newLabel();
    std::string L5 = gen->newLabel();

    //Asignando H a t que guarda el inicio del vector
    gen->AddComment("Posicion inicial");
    gen->AddAssign(tmpInicioVector, "H");
    TipoDato t = NULO;
    symbol newVar;
    if(this->tipoDato == INTEGER){
        newVar = env->SaveVariable2(this->id, VINT, tree);
        std::cout<<"Tipo de valor :"<<newVar.Posicion<<std::endl;
        t=INTEGER;
    }else if(this->tipoDato == FLOAT){
        newVar = env->SaveVariable2(this->id, VFLOAT, tree);
        t=FLOAT;
    }else if(this->tipoDato == BOOL){
        newVar = env->SaveVariable2(this->id, VBOOL, tree);
        t=BOOL;
    }else if(this->tipoDato == STRING){
        newVar = env->SaveVariable2(this->id, VSTRING, tree);
        t=STRING;
    }


    value tmpVal("",false,NULO);

    if(this->lista->lista.size() > 0 ){
        //Vector tiene valores
        int* a = new int;
        *a = this->lista->lista.size();
        newVar.size = *a;
        std::string tVector = gen->newTemp();
        std::string tmpAlmacenar = gen->newTemp();
        std::string tmpPosicion = gen->newTemp();
        std::string LError = gen->newLabel();
        std::string LFinVec = gen->newLabel();
        int size;
        //Posicion donde empieza el vector
        gen->AddComment("Posicion inicial del vector");
        gen->AddAssign(tVector, "H");
        gen->AddAssign(tmpPosicion, "H");
        for(int i = 0; i < this->lista->lista.size(); i++){
            //verifico si es correcto el tipo de dato
            tmpVal = this->lista->lista.value(i)->traducir(env, tree, gen);
            if(tmpVal.TipoExpresion == t){
                if(t == INTEGER){
                    //no necesito convertir

                    gen->AddAssign(tmpAlmacenar, tmpVal.Value);
                    gen->AddSetHeap("(int)H", tmpAlmacenar);
                    gen->AddExpression("H","H","1","+");
                }else if(t == FLOAT){

                }else if(t == BOOL ){

                }else if(t == STRING){

                }
            }else{
                //no coinciden los tipos de datos
                //reporto el error
                //ERROR SEMANTICO
                std::string contenido_error =  "Error en dato de vector INTEGER - Se encontro ";
                contenido_error += env->obtenerTipo(tmpVal.TipoExpresion);
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
                gen->AddGoto(LError); // me falta agregar el LError
                //salir
            }
        }
        gen->AddSetHeap("(int)H", "-6");
        gen->AddExpression("H","H","1","+");
        gen->AddSetStack("(int)"+std::to_string(newVar.Posicion),tVector);
        gen->AddGoto(LFinVec);

        //Error en datos
        gen->AddLabel(LError);
        gen->AddGoto(LFinVec);

        gen->AddLabel(LFinVec);
        env->ModificarVariable(newVar,this->id);
    }else{
        //Vector vacio
        newVar.size = this->lista->lista.size();
    }
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
