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
    for(int i = 0; i < this->contenido->lista.size(); i++){
        value result = contenido->lista.value(i)->traducir(env, tree, gen);

        if(result.TipoExpresion != STRING){
            //ERROR SEMANTICO
            std::string contenido_error =  "Se detecto un tipo ";
            contenido_error += env->obtenerTipo(result.TipoExpresion);
            contenido_error += " en la funcion printf";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;

            gen->MainCode = true;
            //concatenar false
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
            /*if(result.TipoExpresion == INTEGER)
            {
                gen->AddComment("************imprimiendo numero************");
                gen->AddPrintf("d", "(int)"+ result.Value);
                gen->AddPrintf("c", "10");
                gen->AddBr();
            }else if(result.TipoExpresion == FLOAT)
            {
                gen->AddComment("************imprimiendo numero************");
                gen->AddPrintf("f", "(float)"+ result.Value);
                gen->AddPrintf("c", "10");
                gen->AddBr();
            }
            else*/ if(result.TipoExpresion == STRING)
            {
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
                gen->AddComment("salto de linea");
                gen->AddPrintf("c", "10");
                gen->AddBr();
            }/*
            else if(result.TipoExpresion == BOOL)
            {
                gen->AddComment("************imprimiendo bool************");
                std::string newLabel = gen->newLabel();
                std::string newFalseLabel = gen->newLabel();
                if(result.IsTemp)
                {
                    gen->AddIf(result.Value, "1", "!=", newFalseLabel);
                }
                //add true labels
                for(int i=0; i < result.TrueLvl.size(); i++)
                {
                    gen->AddLabel(result.TrueLvl[i]);
                }
                gen->AddPrintf("c", "(char)116");
                gen->AddPrintf("c", "(char)114");
                gen->AddPrintf("c", "(char)117");
                gen->AddPrintf("c", "(char)101");
                gen->AddGoto(newLabel);
                //add false labels
                for(int j=0; j < result.FalseLvl.size(); j++)
                {
                    gen->AddLabel(result.FalseLvl[j]);
                }
                gen->AddLabel(newFalseLabel);
                gen->AddPrintf("c", "(char)102");
                gen->AddPrintf("c", "(char)97");
                gen->AddPrintf("c", "(char)108");
                gen->AddPrintf("c", "(char)115");
                gen->AddPrintf("c", "(char)101");
                gen->AddLabel(newLabel);
                gen->AddPrintf("c", "10");
                gen->AddBr();
            }*/
    }
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
