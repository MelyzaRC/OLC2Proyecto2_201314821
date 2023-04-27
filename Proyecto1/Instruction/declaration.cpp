#include "declaration.hpp"
#include "Environment/type.hpp"

//CONSTRUCTOR
declaration::declaration(){
    this->tipo = 3;
}



declaration::declaration(int line, int col, std::string nombre, expression *val, int tipo)
{
    this->Line = line;
    this->Col = col;
    this->nombre = nombre;
    this->Valor = val;
    this->tipo = tipo;
    this->tipoInstruccion = 3;
}

void declaration::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode = true;
    value val("",false,NULO);
    symbol newVar;

    gen->AddComment("=== DECLARACION ===");
    val = Valor->traducir(env, tree, gen);
    //Validar que los tipos de dato concuerden
    TipoDato t = NULO;
    switch (this->tipo) {
    case 0: {t=INTEGER; }   break;
    case 1: {t=FLOAT;   }   break;
    case 2: {t=STRING;  }   break;
    case 3: {t=BOOL;    }   break;
    case 4: {t=NULO;    }   break;
    default:                break;
    }
    //Los tipos de datos no coinciden
    if(t != val.TipoExpresion){
        //ERROR SEMANTICO
        std::string contenido_error =  "Los tipos de dato no coinciden [";
        contenido_error += env->obtenerTipo(t);
        contenido_error += " - ";
        contenido_error += env->obtenerTipo(val.TipoExpresion);
        contenido_error += "]";
        tree->errores.append(*new error_analisis(0, 0, 3, contenido_error));
        tree->erroresSemanticos++;
        std::cout<<contenido_error<<std::endl;
        return;
    }
    //Los tipos de datos si coinciden
    newVar = env->SaveVariable2(this->nombre, t, tree);

    if(val.TipoExpresion == BOOL)
        {
            //si no es temporal (valor booleano)
            std::string newLabel = gen->newLabel();
            //add true labels
            for(int i=0; i < val.TrueLvl.size(); i++)
            {
                gen->AddLabel(val.TrueLvl[i]);
            }

            gen->AddSetStack(std::to_string(newVar.Posicion),val.Value);
            gen->AddGoto(newLabel);
            //add false labels
            for(int i=0; i < val.FalseLvl.size(); i++)
            {
                gen->AddLabel(val.FalseLvl[i]);
            }
            gen->AddSetStack(std::to_string(newVar.Posicion),val.Value);
            gen->AddGoto(newLabel);
            gen->AddLabel(newLabel);
        }
        else
        {
             //si es temporal (num, string, etc)
            gen->AddSetStack(std::to_string(newVar.Posicion), val.Value);
        }
        gen->AddBr();

}

//METODO EJECUTAR DE LA DECLARACION
void declaration::ejecutar(environment *env, asttree *tree)
{
    //RECUPERANDO EL VALOR DE LA EXPRESION
    symbol sym = this->Valor->ejecutar(env, tree);
    //CONSULTADO TIPOS
    if(this->tipo == sym.Tipo){
        //TIPOS COINCIDEN
        env->SaveVariable(sym, this->nombre, tree);
        //env->Tabla.insert(std::pair<std::string, symbol>(this->nombre, sym));
    } else if(sym.Tipo == 4){
        //ERROR SEMANTICO
        std::string contenido_error = "La expresión ha retornado un valor NULO";
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->IncrementaErroresSemanticos();
    }else{
        //ERROR LOS TIPOS NO COINCIDEN
        //ERROR SEMANTICO
        std::string contenido_error = "Los tipos no coinciden para la  variable ";
        contenido_error += this->nombre;
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->IncrementaErroresSemanticos();
    }

    //  TIPO 1 = variable
    //  TIPO 2 = funcion
    /*entrada entradaIn = *new entrada(nombre, 1, sym);
    env->lista.push_back(entradaIn);*/

}
