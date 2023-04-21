#include "instruction_if.hpp"



instruction_if::instruction_if(int line, int col, expression *condition, instruction *block, instruction *elseifblock, instruction *elseblock)
{
    this->tipoInstruccion = 8;
    Line = line;
    Col = col;
    Condition = condition;
    Block = block;
    ElseIfBlock = elseifblock;
    ElseBlock = elseblock;
}

void instruction_if::ejecutar(environment *env, asttree *tree){
    std::string *cadena_valor;
    symbol sym = Condition->ejecutar(env, tree);
    //creando entorno if
    environment *IfEnv = new environment(env, "IF");
    if(sym.Tipo == BOOL)
    {
        //si se cumple el if
        bool *val = (bool *)sym.valor;
        if(*val)
        {
            //ejecuta el bloque
            Block->ejecutar(IfEnv, tree);
            //valida si es else if
            if(tree->ElseIfFlag)
            {
                tree->ElseIfFlag = false;
                tree->IfReturn = true;
            }
            this->cadenaPrint = this->Block->cadenaPrint;
            return;
        }
        //si no se cumple y existe else if
        if(ElseIfBlock != nullptr)
        {
            //flag de else if
            tree->ElseIfFlag = true;
            tree->IfReturn = false;
            ElseIfBlock->ejecutar(IfEnv, tree);
            this->cadenaPrint = this->ElseIfBlock->cadenaPrint;
            //validación return
            if(tree->IfReturn)
            {
                return;
            }
        }
        //si aun no se cumple y existe else
        if(ElseBlock != nullptr)
        {
            ElseBlock->ejecutar(IfEnv, tree);
            this->cadenaPrint = this->ElseBlock->cadenaPrint;
        }
        //tree->cadenaTab += IfEnv->graficar();
    }
    else
    {
        //ERROR SEMANTICO
        std::string contenido_error =  "La condición evaluada no ha retornado un tipo BOOL sino  ";
        contenido_error += env->obtenerTipo(sym.Tipo);
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;
    }
}
