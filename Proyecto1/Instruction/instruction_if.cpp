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

void instruction_if::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode= true;
    gen->AddComment("generando instruccion if");
        value condicion = Condition->traducir(env, tree, gen);
        std::string salir = gen->newLabel(); //etiqueta de salida
        if(condicion.TipoExpresion == BOOL){

            std::string labelTrueIf = gen->newLabel();
            std::string labelFalseIf = gen->newLabel();

            gen->AddIf(condicion.Value,"1","==",labelTrueIf);
            gen->AddGoto(labelFalseIf);

            gen->AddLabel(labelTrueIf);
            //agregando etiquetas verdaderas
            for(int i=0; i < condicion.TrueLvl.size(); i++)
            {
                gen->AddLabel(condicion.TrueLvl.value(i));
            }
            //instrucción del IF - entra al if
            Block->traducir(env, tree, gen);
            if(tree->salirLbl == ""){
                gen->AddGoto(salir);
                tree->salirLbl = salir;
            }else{
                gen->AddGoto(tree->salirLbl);
            }
            //No entra al if
            gen->AddLabel(labelFalseIf);
            for(int i=0; i < condicion.FalseLvl.size(); i++)
            {
                gen->AddLabel(condicion.FalseLvl.value(i));
            }
            //Tiene else if??
            //etiqueta salida
            if(this->ElseIfBlock != nullptr){
                //agregar else if
                this->ElseIfBlock->traducir(env,tree,gen);
                //gen->AddGoto(salir);
            }
            //Tiene else???
            if(this->ElseBlock != nullptr){
                //agregar else
                this->ElseBlock->traducir(env, tree, gen);
                gen->AddGoto(salir);
            }

            //salida
            gen->AddLabel(salir);
            tree->salirLbl="";

        }else{
            //ERROR SEMANTICO
            gen->AddGoto(salir);
            gen->AddLabel(salir);
            std::string contenido_error =  "La condicion no retorno un valor de tipo BOOL - Se detectó ";
            contenido_error += env->obtenerTipo(condicion.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
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
