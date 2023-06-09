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
    gen->MainCode = true ;
    for(int i = 0; i < this->contenido->lista.size(); i++){
        value result = contenido->lista.value(i)->traducir(env, tree, gen);

        if(result.TipoExpresion != STRING){
            //ERROR SEMANTICO
            std::string contenido_error =  "Se detecto un tipo ";
            contenido_error += env->obtenerTipo(result.TipoExpresion);
            contenido_error += " en la funcion printf";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;


            //convierto el nulo a string para que se pueda imprimir
            std::string tmpNulo = gen->newTemp();
            gen->AddAssign(tmpNulo, "H");
            gen->AddComment("N");
            gen->AddSetHeap("(int)H","78" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("U");
            gen->AddSetHeap("(int)H","85" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("L");
            gen->AddSetHeap("(int)H","76" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("L");
            gen->AddSetHeap("(int)H","76" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddSetHeap("(int)H","-1" );
            gen->AddExpression("H", "H", "1", "+");
            result.TipoExpresion = STRING;
            result.Value = tmpNulo;
        }
        if(result.TipoExpresion == STRING){
            gen->AddComment("************imprimiendo string************");
            //llamar a generar printstring
            gen->GeneratePrintString();
            //agregar codigo en el main
            std::string NewTemp1 = gen->newTemp();
            std::string NewTemp2 = gen->newTemp();
            int size = env->Size;
            gen->AddComment("nuevo temporal en pos vacia");
            gen->AddExpression(NewTemp1, "P", std::to_string(size), "+");
            gen->AddComment("se deja espacio de retorno");
            gen->AddExpression(NewTemp1, NewTemp1, "1", "+");
            gen->AddComment("se coloca string en parametro que se manda");
            gen->AddSetStack("(int)"+ NewTemp1, result.Value);
            gen->AddComment("cambio de entorno");
            gen->AddExpression("P", "P", std::to_string(size), "+");
            gen->AddComment("Llamada");
            gen->AddCall("olc3d_printString");
            gen->AddComment("obtencion retorno");
            gen->AddGetStack( "(int)P",NewTemp2);
            gen->AddComment("regreso del entorno");
            gen->AddExpression("P", "P", std::to_string(size), "-");
            gen->AddBr();
        }
    }
    gen->AddComment("salto de linea");
    gen->AddPrintf("c", "10");
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
