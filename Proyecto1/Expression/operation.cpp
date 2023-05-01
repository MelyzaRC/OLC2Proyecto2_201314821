#include "operation.hpp"
#include "AST/asttree.hpp"
#include "Environment/type.hpp"
#include <cstdint>
#include <cmath>

operation::operation(int line, int col, expression *op_izq, expression *op_der, std::string operador){
    this->Line = line;
    this->Col = col;
    this->Op_izq = op_izq;
    this->Op_der = op_der;
    this->Operator = operador;
    this->tipo = 4;
}

value operation::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    //cualquier interaccion con nulo retorna nulo
    TipoDato MatrizSuma[5][5] =     {
                                        {INTEGER,   FLOAT,  STRING, INTEGER,    NULO},
                                        {FLOAT,     FLOAT,  STRING,  FLOAT,     NULO},
                                        {STRING,    STRING, STRING, STRING,     NULO},
                                        {INTEGER,   FLOAT,  STRING, INTEGER,    NULO},
                                        {NULO,      NULO,   NULO,   NULO,       NULO}
                                    }
                                    ;
    TipoDato MatrizResta[5][5] =    {
                                        {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                        {FLOAT,     FLOAT,  NULO,   FLOAT,      NULO},
                                        {NULO,      NULO,   NULO,   NULO,       NULO},
                                        {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                        {NULO,      NULO,   NULO,   NULO,       NULO}

                                    }
                                    ;
    TipoDato MatrizMultiplicacion[5][5] =   {
                                                {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                                {FLOAT,     FLOAT,  NULO,   FLOAT,      NULO},
                                                {NULO,      NULO,   NULO,   NULO,       NULO},
                                                {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                                {NULO,      NULO,   NULO,   NULO,       NULO}
                                            }
                                            ;
    TipoDato MatrizDivision[5][5] =     {
                                            {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                            {FLOAT,     FLOAT,  NULO,   FLOAT,      NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO},
                                            {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO}
                                        }
                                        ;
    TipoDato MatrizModulo[5][5] =       {
                                            {INTEGER,   NULO,   NULO,   INTEGER,    NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO},
                                            {INTEGER,   NULO,   NULO,   INTEGER,    NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO}
                                        }
                                        ;
    TipoDato MatrizComparacion[5][5] =  {
                                            {BOOL,  BOOL,   NULO,   BOOL,   NULO},
                                            {BOOL,  BOOL,   NULO,   BOOL,   NULO},
                                            {NULO,  NULO,   BOOL,   NULO,   NULO},
                                            {BOOL,  BOOL,   NULO,   BOOL,   NULO},
                                            {NULO,  NULO,   NULO,   NULO,   NULO}
                                        }
                                        ;

    std::string tmpTraduccion = "";
    std::string newTemp = gen->newTemp();

    //EVALUANDO LA SUMA
    if(Operator == "+")
    {
        value op1 = Op_izq->traducir(env, tree, gen);
        value op2 = Op_der->traducir(env, tree, gen);
        TipoDato DominanteDato = MatrizSuma[op1.TipoExpresion][op2.TipoExpresion];
        if(DominanteDato == INTEGER){
            //CASOS
            //int + int = int
            //int + bool = int =================================================================
            if(op2.TipoExpresion == BOOL && op1.TipoExpresion == INTEGER){
                if(op2.Value== "1"){
                    //TRUE
                    for(int i = 0; i <op2.TrueLvl.size(); i++){
                        gen->AddLabel(op2.TrueLvl.value(i));
                    }
                }else{
                    //FALSE
                    for(int i = 0; i <op2.FalseLvl.size(); i++){
                        gen->AddLabel(op2.FalseLvl.value(i));
                    }
                }
                gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            }else if(op1.TipoExpresion == BOOL && op2.TipoExpresion == INTEGER){
                //bool + int = int =================================================================
                if(op1.Value== "1"){
                    //TRUE
                    for(int i = 0; i <op1.TrueLvl.size(); i++){
                        gen->AddLabel(op1.TrueLvl.value(i));
                    }
                }else{
                    //FALSE
                    for(int i = 0; i <op1.FalseLvl.size(); i++){
                        gen->AddLabel(op1.FalseLvl.value(i));
                    }
                }
                gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            }else if(op1.TipoExpresion == BOOL && op2.TipoExpresion == BOOL){
                //bool + bool = int =================================================================
                if(op1.Value== "1"){
                    //TRUE
                    for(int i = 0; i <op1.TrueLvl.size(); i++){
                        gen->AddLabel(op1.TrueLvl.value(i));
                    }
                    if(op2.Value== "1"){
                        //TRUE
                        for(int i = 0; i <op2.TrueLvl.size(); i++){
                            gen->AddLabel(op2.TrueLvl.value(i));
                        }
                    }else{
                        //FALSE
                        for(int i = 0; i <op2.FalseLvl.size(); i++){
                            gen->AddLabel(op2.FalseLvl.value(i));
                        }
                    }
                }else{
                    //FALSE
                    for(int i = 0; i <op1.FalseLvl.size(); i++){
                        gen->AddLabel(op1.FalseLvl.value(i));
                    }
                    if(op2.Value== "1"){
                        //TRUE
                        for(int i = 0; i <op2.TrueLvl.size(); i++){
                            gen->AddLabel(op2.TrueLvl.value(i));
                        }
                    }else{
                        //FALSE
                        for(int i = 0; i <op2.FalseLvl.size(); i++){
                            gen->AddLabel(op2.FalseLvl.value(i));
                        }
                    }
                }
                gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            }else{
               gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            }
            val = value(newTemp, true, INTEGER);
            return val;
        }else if(DominanteDato == FLOAT){
            //int + float = float =================================================================
            //float + float = float ===============================================================
            //float + int = float =================================================================
            if(op1.TipoExpresion == FLOAT && op2.TipoExpresion == BOOL){
                //float + bool = float ================================================================
                if(op2.Value== "1"){
                    //TRUE
                    for(int i = 0; i <op2.TrueLvl.size(); i++){
                        gen->AddLabel(op2.TrueLvl.value(i));
                    }
                }else{
                    //FALSE
                    for(int i = 0; i <op2.FalseLvl.size(); i++){
                        gen->AddLabel(op2.FalseLvl.value(i));
                    }
                }
                gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            }else if(op1.TipoExpresion == BOOL && op2.TipoExpresion == FLOAT){
                 //bool + float = float ================================================================
                if(op1.Value== "1"){
                    //TRUE
                    for(int i = 0; i <op1.TrueLvl.size(); i++){
                        gen->AddLabel(op1.TrueLvl.value(i));
                    }
                }else{
                    //FALSE
                    for(int i = 0; i <op1.FalseLvl.size(); i++){
                        gen->AddLabel(op1.FalseLvl.value(i));
                    }
                }
                gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            }else{
                gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            }
            val = value(newTemp, true, FLOAT);
            return val;
        }else if(DominanteDato == STRING){
            //CONCATENACION
            if(op1.TipoExpresion == INTEGER || op1.TipoExpresion == FLOAT){
                //int   + string = string ==============================================================
                //float + string = string ==============================================================
                gen->AddComment("Concatenando NUMERO+STRING");
                gen->AddComment("Parte NUMERO");
                std::string tmp = gen->newTemp();
                gen->AddAssign(tmp,"H");
                //Agregar el numero al heap seguido de -2 para indicarle que es un numero y no un ascii
                gen->AddComment("Parte NUMERO");
                if(op1.IsTemp){
                    std::string tmpNumero = gen->newTemp();
                    gen->AddAssign(tmpNumero, op1.Value);
                    gen->AddSetHeap("(int)H",tmpNumero);
                    gen->AddExpression("H", "H", "1", "+");
                    if(op1.TipoExpresion == INTEGER){
                        gen->AddSetHeap("(int)H","-2");
                    }else if(op1.TipoExpresion == FLOAT){
                        gen->AddSetHeap("(int)H","-3");
                    }
                    gen->AddExpression("H", "H", "1", "+");

                }else{
                    //es un valor
                    gen->AddSetHeap("(int)H",op1.Value);
                    gen->AddExpression("H", "H", "1", "+");
                    if(op1.TipoExpresion == INTEGER){
                        gen->AddSetHeap("(int)H","-2");
                    }else if(op1.TipoExpresion == FLOAT){
                        gen->AddSetHeap("(int)H","-3");
                    }//INDICA QUE ES VALOR ENTERO
                    gen->AddExpression("H", "H", "1", "+");
                }
                gen->AddComment("Parte STRING");
                //NO AGREGO -1 PORQUE QUIERO CONCATENAR
                std::string labelRepetir = gen->newLabel();
                std::string labelSalir = gen->newLabel();
                //EL SEGUNDO OPERANDO TIENE QUE SER STRING
                //Temporal del string
                std::string tmpInicio = gen->newTemp();
                gen->AddAssign(tmpInicio, op2.Value);
                gen->AddLabel(labelRepetir);
                std::string tmpIterar = gen->newTemp();
                gen->AddAssign(tmpIterar, "heap[(int)"+tmpInicio+"]");
                std::string labelTrue = gen->newLabel();
                gen->AddIf(tmpIterar,"-1","!=",labelTrue);
                gen->AddGoto(labelSalir);
                gen->AddLabel(labelTrue);
                gen->AddSetHeap("(int)H", tmpIterar);
                gen->AddExpression("H", "H", "1", "+");
                gen->AddExpression(tmpInicio, tmpInicio, "1", "+");
                gen->AddGoto(labelRepetir);
                //encuentra en el heap -1
                gen->AddLabel(labelSalir);
                gen->AddSetHeap("(int)H", "-1");
                gen->AddExpression("H", "H", "1", "+");
                gen->AddBr();
                //string retorna el temporal creado al inicio
                val = value(tmp, true, STRING);
                return val;

            }else if(op2.TipoExpresion == INTEGER || op2.TipoExpresion == FLOAT){
                //string + int   = string ==============================================================
                //string + float = string ==============================================================
                gen->AddComment("Concatenando STRING + NUMERO");
                std::string tmp = gen->newTemp();
                gen->AddAssign(tmp,"H");
                gen->AddComment("Parte STRING");
                std::string labelRepetir = gen->newLabel();
                std::string labelSalir = gen->newLabel();
                //EL SEGUNDO OPERANDO TIENE QUE SER STRING
                //Temporal del string
                std::string tmpInicio = gen->newTemp();
                gen->AddAssign(tmpInicio, op1.Value);
                gen->AddLabel(labelRepetir);
                std::string tmpIterar = gen->newTemp();
                gen->AddAssign(tmpIterar, "heap[(int)"+tmpInicio+"]");
                std::string labelTrue = gen->newLabel();
                gen->AddIf(tmpIterar,"-1","!=",labelTrue);
                gen->AddGoto(labelSalir);
                gen->AddLabel(labelTrue);
                gen->AddSetHeap("(int)H", tmpIterar);
                gen->AddExpression("H", "H", "1", "+");
                gen->AddExpression(tmpInicio, tmpInicio, "1", "+");
                gen->AddGoto(labelRepetir);
                //encuentra en el heap -1
                gen->AddLabel(labelSalir);

               // gen->AddExpression("H", "H", "1", "+");

                //Agregar el numero al heap seguido de -2 para indicarle que es un numero y no un ascii
                gen->AddComment("Parte NUMERO");
                if(op2.IsTemp){
                    std::string tmpNumero = gen->newTemp();
                    gen->AddAssign(tmpNumero, op2.Value);
                    gen->AddSetHeap("(int)H",tmpNumero);
                    gen->AddExpression("H", "H", "1", "+");
                    if(op2.TipoExpresion == INTEGER){
                        gen->AddSetHeap("(int)H","-2");
                    }else if(op2.TipoExpresion == FLOAT){
                        gen->AddSetHeap("(int)H","-3");
                    }
                    gen->AddExpression("H", "H", "1", "+");
                }else{
                    //es un valor
                    gen->AddSetHeap("(int)H",op2.Value);
                    gen->AddExpression("H", "H", "1", "+");
                    if(op2.TipoExpresion == INTEGER){
                        gen->AddSetHeap("(int)H","-2");
                    }else if(op2.TipoExpresion == FLOAT){
                        gen->AddSetHeap("(int)H","-3");
                    }//INDICA QUE ES VALOR ENTERO
                    gen->AddExpression("H", "H", "1", "+");
                }
                gen->AddSetHeap("(int)H", "-1");
                gen->AddExpression("H", "H", "1", "+");
                //string retorna el temporal creado al inicio
                val = value(tmp, true, STRING);
                return val;
            }
            else  if(op1.TipoExpresion == BOOL ){
                if(op1.Value=="1"){
                    for(int i = 0; i < op1.TrueLvl.size(); i++){
                        gen->AddLabel(op1.TrueLvl.value(i));
                    }
                }
                else{
                    for(int i = 0; i < op1.FalseLvl.size(); i++){
                        gen->AddLabel(op1.FalseLvl.value(i));
                    }
                }
                //bool + string   = string ==============================================================
                gen->AddComment("Concatenando BOOL + STRING");
                std::string tmp = gen->newTemp();
                gen->AddAssign(tmp,"H");
                gen->AddComment("Parte BOOL");
                if(op1.IsTemp){
                    //AQUI AGREGAR BOOL RESULTANTE DE LOGICAS Y RELACIONALES
                    std::string labelTrueTmp = gen->newLabel();
                    std::string labelFalseTmp = gen->newLabel();
                    std::string labelSalirTmp = gen->newLabel();
                    gen->AddIf(op1.Value,"1","==",labelTrueTmp);
                    gen->AddGoto(labelFalseTmp);
                    gen->AddLabel(labelTrueTmp);
                    //concatenar true
                    gen->AddComment("t");
                    gen->AddSetHeap("(int)H","116" );
                    gen->AddExpression("H", "H", "1", "+");
                    gen->AddComment("r");
                    gen->AddSetHeap("(int)H","114" );
                    gen->AddExpression("H", "H", "1", "+");
                    gen->AddComment("u");
                    gen->AddSetHeap("(int)H","117" );
                    gen->AddExpression("H", "H", "1", "+");
                    gen->AddComment("e");
                    gen->AddSetHeap("(int)H","101" );
                    gen->AddExpression("H", "H", "1", "+");
                    gen->AddGoto(labelSalirTmp);
                    gen->AddLabel(labelFalseTmp);
                    //concatenar false
                    gen->AddComment("f");
                    gen->AddSetHeap("(int)H","102" );
                    gen->AddExpression("H", "H", "1", "+");
                    gen->AddComment("a");
                    gen->AddSetHeap("(int)H","97" );
                    gen->AddExpression("H", "H", "1", "+");
                    gen->AddComment("l");
                    gen->AddSetHeap("(int)H","108" );
                    gen->AddExpression("H", "H", "1", "+");
                    gen->AddComment("s");
                    gen->AddSetHeap("(int)H","115" );
                    gen->AddExpression("H", "H", "1", "+");
                    gen->AddComment("e");
                    gen->AddSetHeap("(int)H","101" );
                    gen->AddExpression("H", "H", "1", "+");
                    gen->AddGoto(labelSalirTmp);
                    gen->AddLabel(labelSalirTmp);
                }else{
                    if(op1.Value=="1"){
                        //concatenar true
                        gen->AddComment("t");
                        gen->AddSetHeap("(int)H","116" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("r");
                        gen->AddSetHeap("(int)H","114" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("u");
                        gen->AddSetHeap("(int)H","117" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("e");
                        gen->AddSetHeap("(int)H","101" );
                        gen->AddExpression("H", "H", "1", "+");
                    }else{
                        //concatenar false
                        gen->AddComment("f");
                        gen->AddSetHeap("(int)H","102" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("a");
                        gen->AddSetHeap("(int)H","97" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("l");
                        gen->AddSetHeap("(int)H","108" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("s");
                        gen->AddSetHeap("(int)H","115" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("e");
                        gen->AddSetHeap("(int)H","101" );
                        gen->AddExpression("H", "H", "1", "+");
                    }
                }
                gen->AddComment("Parte STRING");
                //NO AGREGO -1 PORQUE QUIERO CONCATENAR
                std::string labelRepetir = gen->newLabel();
                std::string labelSalir = gen->newLabel();
                //EL SEGUNDO OPERANDO TIENE QUE SER STRING
                //Temporal del string
                std::string tmpInicio = gen->newTemp();
                gen->AddAssign(tmpInicio, op2.Value);
                gen->AddLabel(labelRepetir);
                std::string tmpIterar = gen->newTemp();
                gen->AddAssign(tmpIterar, "heap[(int)"+tmpInicio+"]");
                std::string labelTrue = gen->newLabel();
                gen->AddIf(tmpIterar,"-1","!=",labelTrue);
                gen->AddGoto(labelSalir);
                gen->AddLabel(labelTrue);
                gen->AddSetHeap("(int)H", tmpIterar);
                gen->AddExpression("H", "H", "1", "+");
                gen->AddExpression(tmpInicio, tmpInicio, "1", "+");
                gen->AddGoto(labelRepetir);
                //encuentra en el heap -1
                gen->AddLabel(labelSalir);
                gen->AddSetHeap("(int)H", "-1");
                gen->AddExpression("H", "H", "1", "+");
                gen->AddBr();
                //string retorna el temporal creado al inicio
                val = value(tmp, true, STRING);
                return val;
            }
            else  if(op2.TipoExpresion == BOOL ){
                if(!op2.IsTemp){
                    if(op2.Value=="1"){
                        for(int i = 0; i < op2.TrueLvl.size(); i++){
                            gen->AddLabel(op2.TrueLvl.value(i));
                        }
                    }
                    else{
                        for(int i = 0; i < op2.FalseLvl.size(); i++){
                            gen->AddLabel(op2.FalseLvl.value(i));
                        }
                    }
                }
                //string + bool   = string ==============================================================
                gen->AddComment("Concatenando STRING + BOOL");
                std::string tmp = gen->newTemp();
                gen->AddAssign(tmp,"H");
                gen->AddComment("Parte STRING");
                //NO AGREGO -1 PORQUE QUIERO CONCATENAR
                std::string labelRepetir = gen->newLabel();
                std::string labelSalir = gen->newLabel();
                //EL SEGUNDO OPERANDO TIENE QUE SER STRING
                //Temporal del string
                std::string tmpInicio = gen->newTemp();
                gen->AddAssign(tmpInicio, op1.Value);
                gen->AddLabel(labelRepetir);
                std::string tmpIterar = gen->newTemp();
                gen->AddAssign(tmpIterar, "heap[(int)"+tmpInicio+"]");
                std::string labelTrue = gen->newLabel();
                gen->AddIf(tmpIterar,"-1","!=",labelTrue);
                gen->AddGoto(labelSalir);
                gen->AddLabel(labelTrue);
                gen->AddSetHeap("(int)H", tmpIterar);
                gen->AddExpression("H", "H", "1", "+");
                gen->AddExpression(tmpInicio, tmpInicio, "1", "+");
                gen->AddGoto(labelRepetir);
                //encuentra en el heap -1
                gen->AddLabel(labelSalir);
                gen->AddComment("Parte BOOL");
                if(op2.IsTemp){
                //AQUI AGREGAR BOOL RESULTANTE DE LOGICAS Y RELACIONALES
                }else{
                    if(op2.Value=="1"){
                        //concatenar true
                        gen->AddComment("t");
                        gen->AddSetHeap("(int)H","116" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("r");
                        gen->AddSetHeap("(int)H","114" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("u");
                        gen->AddSetHeap("(int)H","117" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("e");
                        gen->AddSetHeap("(int)H","101" );
                        gen->AddExpression("H", "H", "1", "+");
                    }else{
                        //concatenar false
                        gen->AddComment("f");
                        gen->AddSetHeap("(int)H","102" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("a");
                        gen->AddSetHeap("(int)H","97" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("l");
                        gen->AddSetHeap("(int)H","108" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("s");
                        gen->AddSetHeap("(int)H","115" );
                        gen->AddExpression("H", "H", "1", "+");
                        gen->AddComment("e");
                        gen->AddSetHeap("(int)H","101" );
                        gen->AddExpression("H", "H", "1", "+");
                    }
                }
                gen->AddSetHeap("(int)H", "-1");
                gen->AddExpression("H", "H", "1", "+");
                val = value(tmp, true, STRING);
                return val;
            }
            else{
                //string + string = string ==============================================================
                gen->AddComment("Concatenando STRING + STRING");
                std::string tmp = gen->newTemp();
                gen->AddAssign(tmp,"H");
                gen->AddComment("Primer STRING");
                //NO AGREGO -1 PORQUE QUIERO CONCATENAR
                std::string labelRepetir = gen->newLabel();
                std::string labelSalir = gen->newLabel();
                //Temporal del string
                std::string tmpInicio = gen->newTemp();
                gen->AddAssign(tmpInicio, op1.Value);
                gen->AddLabel(labelRepetir);
                std::string tmpIterar = gen->newTemp();
                gen->AddAssign(tmpIterar, "heap[(int)"+tmpInicio+"]");
                std::string labelTrue = gen->newLabel();
                gen->AddIf(tmpIterar,"-1","!=",labelTrue);
                gen->AddGoto(labelSalir);
                gen->AddLabel(labelTrue);
                gen->AddSetHeap("(int)H", tmpIterar);
                gen->AddExpression("H", "H", "1", "+");
                gen->AddExpression(tmpInicio, tmpInicio, "1", "+");
                gen->AddGoto(labelRepetir);
                //encuentra en el heap -1
                gen->AddLabel(labelSalir);
                gen->AddComment("Segundo STRING");
                //NO AGREGO -1 PORQUE QUIERO CONCATENAR
                labelRepetir = gen->newLabel();
                labelSalir = gen->newLabel();
                //Temporal del string
                tmpInicio = gen->newTemp();
                gen->AddAssign(tmpInicio, op2.Value);
                gen->AddLabel(labelRepetir);
                tmpIterar = gen->newTemp();
                gen->AddAssign(tmpIterar, "heap[(int)"+tmpInicio+"]");
                labelTrue = gen->newLabel();
                gen->AddIf(tmpIterar,"-1","!=",labelTrue);
                gen->AddGoto(labelSalir);
                gen->AddLabel(labelTrue);
                gen->AddSetHeap("(int)H", tmpIterar);
                gen->AddExpression("H", "H", "1", "+");
                gen->AddExpression(tmpInicio, tmpInicio, "1", "+");
                gen->AddGoto(labelRepetir);
                //encuentra en el heap -1
                gen->AddLabel(labelSalir);


                gen->AddSetHeap("(int)H", "-1");
                gen->AddExpression("H", "H", "1", "+");
                val = value(tmp, true, STRING);
                return val;
            }

            val = value(newTemp, true, STRING);
            return val;
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar la SUMA entre ";
            contenido_error += env->obtenerTipo(op1.TipoExpresion);
            contenido_error += " y ";
            contenido_error += env->obtenerTipo(op2.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }

    }
    else if(Operator == "-"){
        std::string newRestaTmp = gen->newTemp();
        value op1 = Op_izq->traducir(env, tree, gen);
        value op2 = Op_der->traducir(env, tree, gen);
        TipoDato DominanteDato = MatrizResta[op1.TipoExpresion][op2.TipoExpresion];
        //CASOS
        //int - int = int       ******************************************************
        //int - float = float   ******************************************************
        //int - bool = int      ******************************************************
        //float - float = float ******************************************************
        //float - bool = float  ******************************************************
        //bool - bool = int     ******************************************************
        //bool - int = int      ******************************************************
        //bool - float = float  ******************************************************


        if(DominanteDato == NULO){
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar la RESTA entre ";
            contenido_error += env->obtenerTipo(op1.TipoExpresion);
            contenido_error += " y ";
            contenido_error += env->obtenerTipo(op2.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }

        if(op1.TipoExpresion == BOOL && !op1.IsTemp){
            if(op1.Value=="1"){
                for(int i = 0; i < op1.TrueLvl.size(); i++){
                    gen->AddLabel(op1.TrueLvl.value(i));
                }
            }
            else{
                for(int i = 0; i < op1.FalseLvl.size(); i++){
                    gen->AddLabel(op1.FalseLvl.value(i));
                }
            }
        }

        if(op1.TipoExpresion == BOOL && !op2.IsTemp){
            if(op2.Value=="1"){
                for(int i = 0; i < op2.TrueLvl.size(); i++){
                    gen->AddLabel(op2.TrueLvl.value(i));
                }
            }
            else{
                for(int i = 0; i < op2.FalseLvl.size(); i++){
                    gen->AddLabel(op2.FalseLvl.value(i));
                }
            }
        }

        gen->AddExpression(newRestaTmp, op1.Value, op2.Value, "-");
        val= *new value(newRestaTmp, true, DominanteDato);
        return val;
    }
    else if(Operator == "*"){
        std::string newMultiplicacionTmp = gen->newTemp();
        value op1 = Op_izq->traducir(env, tree, gen);
        value op2 = Op_der->traducir(env, tree, gen);
        TipoDato DominanteDato = MatrizMultiplicacion[op1.TipoExpresion][op2.TipoExpresion];
        //CASOS
        //int * int = int       ******************************************************
        //int * float = float   ******************************************************
        //int * bool = int      ******************************************************
        //float * float = float ******************************************************
        //float * int = float   ******************************************************
        //float * bool = float  ******************************************************
        //bool * bool = int     ******************************************************
        //bool * int = int      ******************************************************
        //bool * float = float  ******************************************************


        if(DominanteDato == NULO){
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar la MULTIPLICACION entre ";
            contenido_error += env->obtenerTipo(op1.TipoExpresion);
            contenido_error += " y ";
            contenido_error += env->obtenerTipo(op2.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }

        if(op1.TipoExpresion == BOOL && !op1.IsTemp){
            if(op1.Value=="1"){
                for(int i = 0; i < op1.TrueLvl.size(); i++){
                    gen->AddLabel(op1.TrueLvl.value(i));
                }
            }
            else{
                for(int i = 0; i < op1.FalseLvl.size(); i++){
                    gen->AddLabel(op1.FalseLvl.value(i));
                }
            }
        }

        if(op1.TipoExpresion == BOOL && !op2.IsTemp){
            if(op2.Value=="1"){
                for(int i = 0; i < op2.TrueLvl.size(); i++){
                    gen->AddLabel(op2.TrueLvl.value(i));
                }
            }
            else{
                for(int i = 0; i < op2.FalseLvl.size(); i++){
                    gen->AddLabel(op2.FalseLvl.value(i));
                }
            }
        }

        gen->AddExpression(newMultiplicacionTmp, op1.Value, op2.Value, "*");
        val= *new value(newMultiplicacionTmp, true, DominanteDato);
        return val;
    }
    else if(Operator == "/"){
        std::string newDivisionTmp = gen->newTemp();
        value op1 = Op_izq->traducir(env, tree, gen);
        value op2 = Op_der->traducir(env, tree, gen);
        TipoDato DominanteDato = MatrizDivision[op1.TipoExpresion][op2.TipoExpresion];
        //CASOS
        //int / int = int       ******************************************************
        //int / float = float   ******************************************************
        //int / bool = int      ******************************************************
        //float / float = float ******************************************************
        //float / int = float   ******************************************************
        //float / bool = float  ******************************************************
        //bool / bool = int     ******************************************************
        //bool / int = int      ******************************************************
        //bool / float = float  ******************************************************

        if(DominanteDato == NULO){
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar la DIVISION entre ";
            contenido_error += env->obtenerTipo(op1.TipoExpresion);
            contenido_error += " y ";
            contenido_error += env->obtenerTipo(op2.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }

        if(op1.TipoExpresion == BOOL && !op1.IsTemp){
            if(op1.Value=="1"){
                for(int i = 0; i < op1.TrueLvl.size(); i++){
                    gen->AddLabel(op1.TrueLvl.value(i));
                }
            }
            else{
                for(int i = 0; i < op1.FalseLvl.size(); i++){
                    gen->AddLabel(op1.FalseLvl.value(i));
                }
            }
        }

        if(op1.TipoExpresion == BOOL && !op2.IsTemp){
            if(op2.Value=="1"){
                for(int i = 0; i < op2.TrueLvl.size(); i++){
                    gen->AddLabel(op2.TrueLvl.value(i));
                }
            }
            else{
                for(int i = 0; i < op2.FalseLvl.size(); i++){
                    gen->AddLabel(op2.FalseLvl.value(i));
                }
            }
        }
        //Agregar la validacion de division entre 0
        std::string divCeroTrue = gen->newLabel();
        std::string divCeroFalse = gen->newLabel();
        std::string divCeroSalir = gen->newLabel();
        //El divisor es 0?
        gen->AddIf(op2.Value,"0","==",divCeroTrue );
        gen->AddGoto(divCeroFalse);

        //SI es 0
        gen->AddLabel(divCeroTrue);
        //Muestro math error en pantalla
        gen->GenerateMathError();
        gen->AddCall("olc3d_mathError");
        gen->AddGoto(divCeroSalir);

        //NO es 0
        gen->AddLabel(divCeroFalse);
        gen->AddExpression(newDivisionTmp, op1.Value, op2.Value, "/");
        gen->AddGoto(divCeroSalir);

        //Sale
        gen->AddLabel(divCeroSalir);
        val= *new value(newDivisionTmp, true, DominanteDato);
        return val;
    }
    else if(Operator == "%"){
        std::string newDivisionModulo = gen->newTemp();
        value op1 = Op_izq->traducir(env, tree, gen);
        value op2 = Op_der->traducir(env, tree, gen);
        TipoDato DominanteDato = MatrizModulo[op1.TipoExpresion][op2.TipoExpresion];
        //CASOS
        //int % int = int       ******************************************************
        //int % bool = int      ******************************************************
        //bool % bool = int     ******************************************************
        //bool % int = int      ******************************************************

        if(DominanteDato == NULO){
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar MODULO entre ";
            contenido_error += env->obtenerTipo(op1.TipoExpresion);
            contenido_error += " y ";
            contenido_error += env->obtenerTipo(op2.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }

        if(op1.TipoExpresion == BOOL && !op1.IsTemp){
            if(op1.Value=="1"){
                for(int i = 0; i < op1.TrueLvl.size(); i++){
                    gen->AddLabel(op1.TrueLvl.value(i));
                }
            }
            else{
                for(int i = 0; i < op1.FalseLvl.size(); i++){
                    gen->AddLabel(op1.FalseLvl.value(i));
                }
            }
        }

        if(op1.TipoExpresion == BOOL && !op2.IsTemp){
            if(op2.Value=="1"){
                for(int i = 0; i < op2.TrueLvl.size(); i++){
                    gen->AddLabel(op2.TrueLvl.value(i));
                }
            }
            else{
                for(int i = 0; i < op2.FalseLvl.size(); i++){
                    gen->AddLabel(op2.FalseLvl.value(i));
                }
            }
        }
        //Agregar la validacion de division entre 0
        std::string divCeroTrue = gen->newLabel();
        std::string divCeroFalse = gen->newLabel();
        std::string divCeroSalir = gen->newLabel();
        //El divisor es 0?
        gen->AddIf(op2.Value,"0","==",divCeroTrue );
        gen->AddGoto(divCeroFalse);

        //SI es 0
        gen->AddLabel(divCeroTrue);
        //Muestro math error en pantalla
        gen->GenerateMathError();
        gen->AddCall("olc3d_mathError");
        gen->AddGoto(divCeroSalir);

        //NO es 0
        gen->AddLabel(divCeroFalse);
        gen->AddExpression(newDivisionModulo, "(int)"+op1.Value, "(int)"+op2.Value, "%");
        gen->AddGoto(divCeroSalir);

        //Sale
        gen->AddLabel(divCeroSalir);
        val= *new value(newDivisionModulo, true, DominanteDato);
        return val;
    }
    else if(Operator == "=="){
        std::string newIgualIgualTmp = gen->newTemp();
        value op1 = Op_izq->traducir(env, tree, gen);
        value op2 = Op_der->traducir(env, tree, gen);
        TipoDato DominanteDato = MatrizComparacion[op1.TipoExpresion][op2.TipoExpresion];

        if(DominanteDato == NULO){
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede comparar un tipo de dato ";
            contenido_error += env->obtenerTipo(op1.TipoExpresion);
            contenido_error += " con un tipo de dato ";
            contenido_error += env->obtenerTipo(op2.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }

        //SI se puede comparar
        std::string newResultTmp = gen->newTemp();
        std::string newIgualTmp = gen->newLabel();
        std::string newDifTmp = gen->newLabel();
        std::string newSalirTmp = gen->newLabel();
        //Pregunta comparacion
        gen->AddIf(op1.Value, op2.Value, "==", newIgualTmp);
        gen->AddGoto(newDifTmp);

        //Si es igual
        gen->AddLabel(newIgualTmp);
        gen->AddAssign(newResultTmp, "1");
        gen->AddGoto(newSalirTmp);

        //No es igual
        gen->AddLabel(newDifTmp);
        gen->AddAssign(newResultTmp, "0");
        gen->AddGoto(newSalirTmp);

        //Sale
        gen->AddLabel(newSalirTmp);

        //RETORNO
        val= *new value(newResultTmp, true, BOOL);
        return val;
    }
    else if(Operator == "!="){
        std::string newIgualIgualTmp = gen->newTemp();
        value op1 = Op_izq->traducir(env, tree, gen);
        value op2 = Op_der->traducir(env, tree, gen);
        TipoDato DominanteDato = MatrizComparacion[op1.TipoExpresion][op2.TipoExpresion];

        if(DominanteDato == NULO){
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede comparar un tipo de dato ";
            contenido_error += env->obtenerTipo(op1.TipoExpresion);
            contenido_error += " con un tipo de dato ";
            contenido_error += env->obtenerTipo(op2.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("NULO", false, NULO);
            return val;
        }

        //SI se puede comparar
        std::string newResultTmp = gen->newTemp();
        std::string newIgualTmp = gen->newLabel();
        std::string newDifTmp = gen->newLabel();
        std::string newSalirTmp = gen->newLabel();
        //Pregunta comparacion
        gen->AddIf(op1.Value, op2.Value, "!=", newIgualTmp);
        gen->AddGoto(newDifTmp);

        //Si es igual
        gen->AddLabel(newIgualTmp);
        gen->AddAssign(newResultTmp, "1");
        gen->AddGoto(newSalirTmp);

        //No es igual
        gen->AddLabel(newDifTmp);
        gen->AddAssign(newResultTmp, "0");
        gen->AddGoto(newSalirTmp);

        //Sale
        gen->AddLabel(newSalirTmp);

        //RETORNO
        val= *new value(newResultTmp, true, BOOL);
        return val;
    }
    else if(Operator == ">"){}
    else if(Operator == "<"){}
    else if(Operator == ">="){}
    else if(Operator == "<="){}
    else if(Operator == "&&"){}
    else if(Operator == "||"){}
    else if(Operator == "!"){}
    //FIN
    val= *new value(tmpTraduccion, false, INTEGER);
    return val;

}

symbol operation::ejecutar(environment *env, asttree *tree)
{
    symbol sym(this->Line,this->Col,"",NULO, nullptr);

    symbol op1 = Op_izq->ejecutar(env, tree);

    symbol op2 = Op_der->ejecutar(env, tree);

    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    //cualquier interaccion con nulo retorna nulo
    TipoDato MatrizSuma[5][5] =     {
                                        {INTEGER,   FLOAT,  STRING, INTEGER,    NULO},
                                        {FLOAT,     FLOAT,  STRING,  FLOAT,     NULO},
                                        {STRING,    STRING, STRING, STRING,     NULO},
                                        {INTEGER,   FLOAT,  STRING, INTEGER,    NULO},
                                        {NULO,      NULO,   NULO,   NULO,       NULO}
                                    }
                                    ;
    TipoDato MatrizResta[5][5] =    {
                                        {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                        {FLOAT,     FLOAT,  NULO,   FLOAT,      NULO},
                                        {NULO,      NULO,   NULO,   NULO,       NULO},
                                        {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                        {NULO,      NULO,   NULO,   NULO,       NULO}

                                    }
                                    ;
    TipoDato MatrizMultiplicacion[5][5] =   {
                                                {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                                {FLOAT,     FLOAT,  NULO,   FLOAT,      NULO},
                                                {NULO,      NULO,   NULO,   NULO,       NULO},
                                                {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                                {NULO,      NULO,   NULO,   NULO,       NULO}
                                            }
                                            ;
    TipoDato MatrizDivision[5][5] =     {
                                            {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                            {FLOAT,     FLOAT,  NULO,   FLOAT,      NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO},
                                            {INTEGER,   FLOAT,  NULO,   INTEGER,    NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO}
                                        }
                                        ;
    TipoDato MatrizModulo[5][5] =       {
                                            {INTEGER,   NULO,   NULO,   FLOAT,      NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO},
                                            {INTEGER,   NULO,   NULO,   INTEGER,    NULO},
                                            {NULO,      NULO,   NULO,   NULO,       NULO}
                                        }
                                        ;
    TipoDato MatrizComparacion[5][5] =  {
                                            {BOOL,  BOOL,   NULO,   BOOL,   NULO},
                                            {BOOL,  BOOL,   NULO,   BOOL,   NULO},
                                            {NULO,  NULO,   BOOL,   NULO,   NULO},
                                            {BOOL,  BOOL,   NULO,   BOOL,   NULO},
                                            {NULO,  NULO,   NULO,   NULO,   NULO}
                                        }
                                        ;
    //TIPO DE DATO RESULTANTE DE LA OPERACION
    TipoDato DominanteDato;
    //EVALUANDO LA SUMA
    if(Operator == "+")
    {
        DominanteDato = MatrizSuma[op1.Tipo][op2.Tipo];
        if(DominanteDato == INTEGER){
            int s1 = (int) *static_cast<int*>(op1.valor);
            int s2 = (int) *static_cast<int*>(op2.valor);
            if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1;
                }else{
                    s1 = 0;
                }
            }
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1;
                }else{
                    s2 = 0;
                }
            }
            int* rest = new int;
            int result= s1 + s2;
            *rest = result;
            return symbol(Line,Col,"",DominanteDato,rest);
        }
        else if(DominanteDato == STRING){
            std::string s1;
            std::string s2;
            if(op1.Tipo == INTEGER){
                s1 = std::to_string(*static_cast<int*>(op1.valor));
            }else if(op1.Tipo == FLOAT){
                //AQUI SE DEBE TRUNCAR EL VALOR
                s1 = std::to_string(*static_cast<float*>(op1.valor));
                int indice = -1;
                for(int i= 0; i < s1.size(); i++){
                    if(s1[i] == '0'){
                        if(indice ==  -1){indice = i;}
                    }else{
                        indice = -1;
                    }
                }
                if(indice > -1){
                    for(int i = indice; i < s1.size(); i++){
                        s1[i] = 0;
                    }
                }
            }else if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor) == 1){
                    s1 = "true";
                }else{
                    s1 = "false";
                }
            }else{
                s1 = *static_cast<std::string*>(op1.valor);
            }
            if(op2.Tipo == INTEGER){
                s2 = std::to_string(*static_cast<int*>(op2.valor));
            }else if(op2.Tipo == FLOAT){
                s2 = std::to_string(*static_cast<float*>(op2.valor));
            }else if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor) == 1){
                    s2 = "true";
                }else{
                    s2 = "false";
                }
            }else{
                s2 = *static_cast<std::string*>(op2.valor);
            }
            std::string* rest = new std::string;
            std::string result = s1 + s2;
            *rest = result;
            return symbol(Line,Col,"",DominanteDato,rest);
        }
        else if(DominanteDato == FLOAT){
            float s1 = (float) *static_cast<float*>(op1.valor);
            float s2 = (float) *static_cast<float*>(op2.valor);
            if(op1.Tipo == INTEGER){
                s1 = (float) *static_cast<int*>(op1.valor);
            }
            if(op2.Tipo == INTEGER){
                s2 = (float) *static_cast<int*>(op2.valor);
            }
            if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1.0;
                }else{
                    s1 = 0.0;
                }
            }
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1.0;
                }else{
                    s2 = 0.0;
                }
            }
            float* rest = new float;
            float result = s1 + s2;
            *rest = result;
            return symbol(Line,Col,"",DominanteDato,rest);
        }
        else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar la SUMA [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " + ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    //EVALUANDO LA RESTA
    if(Operator == "-")
    {
        DominanteDato = MatrizResta[op1.Tipo][op2.Tipo];
        if(DominanteDato == INTEGER){
            int s1 = (int) *static_cast<int*>(op1.valor);
            int s2 = (int) *static_cast<int*>(op2.valor);
            if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1;
                }else{
                    s1 = 0;
                }
            }
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1;
                }else{
                    s2 = 0;
                }
            }
            int* rest = new int;
            int result = s1 - s2;
            *rest = result;
            return symbol(Line,Col,"",DominanteDato,rest);
        }
        else if(DominanteDato == FLOAT){
            float s1 = (float) *static_cast<float*>(op1.valor);
            float s2 = (float) *static_cast<float*>(op2.valor);
            if(op1.Tipo == INTEGER){
                s1 = (float) *static_cast<int*>(op1.valor);
            }
            if(op2.Tipo == INTEGER){
                s2 = (float) *static_cast<int*>(op2.valor);
            }
            if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1.0;
                }else{
                    s1 = 0.0;
                }
            }
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1.0;
                }else{
                    s2 = 0.0;
                }
            }
            float* rest = new float;
            float result = s1 - s2;
            *rest = result;
            return symbol(Line,Col,"",DominanteDato,rest);
        }
        else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar la RESTA [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " - ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    //EVALUANDO LA MULTIPLICACION
    if(Operator == "*")
    {
        DominanteDato = MatrizMultiplicacion[op1.Tipo][op2.Tipo];
        if(DominanteDato == INTEGER){
            int s1 = (int) *static_cast<int*>(op1.valor);
            int s2 = (int) *static_cast<int*>(op2.valor);
            if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1;
                }else{
                    s1 = 0;
                }
            }
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1;
                }else{
                    s2 = 0;
                }
            }
            int* rest = new int;
            int result= s1 * s2;
            *rest = result;
            return symbol(Line,Col,"",INTEGER,rest);
        }
        else if(DominanteDato == FLOAT){
            float s1 = (float) *static_cast<float*>(op1.valor);
            float s2 = (float) *static_cast<float*>(op2.valor);
            if(op1.Tipo == INTEGER){
                s1 = (float) *static_cast<int*>(op1.valor);
            }
            if(op2.Tipo == INTEGER){
                s2 = (float) *static_cast<int*>(op2.valor);
            }
            if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1.0;
                }else{
                    s1 = 0.0;
                }
            }
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1.0;
                }else{
                    s2 = 0.0;
                }
            }
            float* rest = new float;
            float result = s1 * s2;
            *rest = result;
            return symbol(Line,Col,"",DominanteDato,rest);
        }
        else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar la MULTIPLICACIÓN [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " * ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    //EVALUANDO LA DIVISION
    if(Operator == "/")
    {
        DominanteDato = MatrizDivision[op1.Tipo][op2.Tipo];
        if(DominanteDato == INTEGER){
            int s1 = (int) *static_cast<int*>(op1.valor);
            int s2 = (int) *static_cast<int*>(op2.valor);
            if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1;
                }else{
                    s1 = 0;
                }
            }
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1;
                }else{
                    s2 = 0;
                }
            }
            if(s2 == 0){
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede operar la DISIÓN entre 0";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
                return symbol(Line,Col,"",NULO,nullptr);
                 return symbol(Line,Col,"",NULO,nullptr);
            }else{
                int* rest = new int;
                int result= s1 / s2;
                *rest = result;
                return symbol(Line,Col,"",DominanteDato,rest);
            }

        }
        else if(DominanteDato == FLOAT){
            float s1 = (float) *static_cast<float*>(op1.valor);
            float s2 = (float) *static_cast<float*>(op2.valor);
            if(op1.Tipo == INTEGER){
                s1 = (float) *static_cast<int*>(op1.valor);
            }
            if(op2.Tipo == INTEGER){
                s2 = (float) *static_cast<int*>(op2.valor);
            }
            if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1.0;
                }else{
                    s1 = 0.0;
                }
            }
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1.0;
                }else{
                    s2 = 0.0;
                }
            }
            if(s2 == 0){
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede operar la DISIÓN entre 0";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
                return symbol(Line,Col,"",NULO,nullptr);
            }else{
                float* rest = new float;
                float result = s1 / s2;
                *rest = result;
                return symbol(Line,Col,"",DominanteDato,rest);
            }
        }
        else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar la DIVISIÓN [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " / ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    //EVALUANDO EL MODULO
    if(Operator == "%")
    {
        DominanteDato = MatrizModulo[op1.Tipo][op2.Tipo];
        if(DominanteDato == INTEGER){
            int s1 = *static_cast<int*>(op1.valor);
            int s2 = *static_cast<int*>(op2.valor);
            if(op1.Tipo == BOOL){
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1;
                }else{
                    s1 = 0;
                }
            }
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1;
                }else{
                    s2 = 0;
                }
            }
            if(s2 == 0){
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede operar el MÓDULO entre 0";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
                return symbol(Line,Col,"",NULO,nullptr);
                 return symbol(Line,Col,"",NULO,nullptr);
            }else{
                int* rest = new int;
                int result= s1 % s2;
                *rest = result;
                return symbol(Line,Col,"",DominanteDato,rest);
            }

        }
        else if(DominanteDato == FLOAT){
            int s1 = *static_cast<int*>(op1.valor);
            int s2 = 0;
            if(op2.Tipo == BOOL){
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1.0;
                }else{
                    s2 = 0.0;
                }
            }
            if(s2 == 0){
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede operar el MÓDULO entre 0";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
                return symbol(Line,Col,"",NULO,nullptr);
                 return symbol(Line,Col,"",NULO,nullptr);
            }else{
                int result = s1 % s2;
                float* rest = new float;
                float tmp = (float) result;
                *rest = tmp;
                return symbol(Line,Col,"",DominanteDato,rest);
            }
        }
        else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar el MÓDULO [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " % ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    //EVALUANDO COMPARACION
    if(Operator == "=="){
        DominanteDato = MatrizComparacion[op1.Tipo][op2.Tipo];
        if(DominanteDato == BOOL){
            if(op1.Tipo == INTEGER){
                int s1 = (int) *static_cast<int*>(op1.valor);
                if(op2.Tipo == INTEGER){
                    int s2 = (int) *static_cast<int*>(op2.valor);
                    if(s1 == s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == FLOAT){
                    float s2 = (float) *static_cast<float*>(op2.valor);
                    float s1_float = (float) s1;
                    if(s1_float == s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == BOOL){
                    int s2  = 0;
                    if(*static_cast<bool*>(op2.valor)){
                        s2 = 1;
                    }
                    if(s1 == s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
            }
            if(op1.Tipo == FLOAT){
                float s1 = (float) *static_cast<float*>(op1.valor);
                if(op2.Tipo == INTEGER){
                    int s2 = (int) *static_cast<int*>(op2.valor);
                    float s2_float = (float) s2;
                    if(s1 == s2_float){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == FLOAT){
                    float s2 = (float) *static_cast<float*>(op2.valor);
                    if(s1 == s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == BOOL){
                    float s2  = 0.0;
                    if(*static_cast<bool*>(op2.valor)){
                        s2 = 1.0;
                    }
                    if(s1 == s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
            }
            if(op1.Tipo == BOOL){
                bool s1 = false;
                if(*static_cast<bool*>(op1.valor)){
                        s1 = true;
                    }
                if(op2.Tipo == INTEGER){
                    int s2_int = (int) *static_cast<int*>(op2.valor);
                    bool s2 = false;
                    if(s2_int > 0){
                        s2 = true;
                    }else{
                        s2 = false;
                    }
                    if(s1 == s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == FLOAT){
                    float s2_float = (float) *static_cast<float*>(op2.valor);
                    bool s2 = false;
                    if(s2_float > 0){
                        s2 = true;
                    }else{
                        s2 = false;
                    }
                    if(s1 == s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == BOOL){
                    bool s2 = false;
                    if(*static_cast<bool*>(op2.valor)){
                        s2 = true;
                    }
                    if(s1 == s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
            }
            else if(op1.Tipo == STRING){
                std::string s1 = *static_cast<std::string*>(op1.valor);
                std::string s2 = *static_cast<std::string*>(op2.valor);

                if(s1 == s2){
                    bool trueVal = true;
                    return symbol(Line,Col,"",BOOL,&trueVal);
                }else{
                    bool falseVal = falseVal;
                    return symbol(Line,Col,"",BOOL,&falseVal);
                }
            }
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede comparar [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " == ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    //EVALUANDO NO IGUAL
    if(Operator == "!="){
        DominanteDato = MatrizComparacion[op1.Tipo][op2.Tipo];
        if(DominanteDato == BOOL){
            if(op1.Tipo == INTEGER){
                int s1 = (int) *static_cast<int*>(op1.valor);
                if(op2.Tipo == INTEGER){
                    int s2 = (int) *static_cast<int*>(op2.valor);
                    if(s1 != s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == FLOAT){
                    float s2 = (float) *static_cast<float*>(op2.valor);
                    float s1_float = (float) s1;
                    if(s1_float != s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == BOOL){
                    int s2  = 0;
                    if(*static_cast<bool*>(op2.valor)){
                        s2 = 1;
                    }
                    if(s1 != s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
            }
            if(op1.Tipo == FLOAT){
                float s1 = (float) *static_cast<float*>(op1.valor);
                if(op2.Tipo == INTEGER){
                    int s2 = (int) *static_cast<int*>(op2.valor);
                    float s2_float = (float) s2;
                    if(s1 != s2_float){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == FLOAT){
                    float s2 = (float) *static_cast<float*>(op2.valor);
                    if(s1 != s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == BOOL){
                    float s2  = 0.0;
                    if(*static_cast<bool*>(op2.valor)){
                        s2 = 1.0;
                    }
                    if(s1 != s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
            }
            if(op1.Tipo == BOOL){
                bool s1 = false;
                if(*static_cast<bool*>(op1.valor)){
                        s1 = true;
                    }
                if(op2.Tipo == INTEGER){
                    int s2_int = (int) *static_cast<int*>(op2.valor);
                    bool s2 = false;
                    if(s2_int > 0){
                        s2 = true;
                    }else{
                        s2 = false;
                    }
                    if(s1 != s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == FLOAT){
                    float s2_float = (float) *static_cast<float*>(op2.valor);
                    bool s2 = false;
                    if(s2_float > 0){
                        s2 = true;
                    }else{
                        s2 = false;
                    }
                    if(s1 != s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
                else if(op2.Tipo == BOOL){
                    bool s2 = false;
                    if(*static_cast<bool*>(op2.valor)){
                        s2 = true;
                    }
                    if(s1 != s2){
                        bool boolTrue = true;
                        return *new symbol(0,0,"", BOOL,&boolTrue);
                    }else{
                        bool boolFalse = false;
                        return *new symbol(0,0,"", BOOL,&boolFalse);
                    }
                }
            }
            else if(op1.Tipo == STRING){
                std::string s1 = *static_cast<std::string*>(op1.valor);
                std::string s2 = *static_cast<std::string*>(op2.valor);

                if(s1 != s2){
                    bool trueVal = true;
                    return symbol(Line,Col,"",BOOL,&trueVal);
                }else{
                    bool falseVal = falseVal;
                    return symbol(Line,Col,"",BOOL,&falseVal);
                }
            }
        }else{
            //REPORTAR ERROR
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede comparar [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " != ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    //EVALUANDO RELACIONALES
    if(Operator == ">" ){
        if(op1.Tipo == INTEGER){
            int s1 = (int) *static_cast<int*>(op1.valor);
            if(op2.Tipo == INTEGER){
                int s2 = (int) *static_cast<int*>(op2.valor);
                if(s1 > s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                float s1_float = (float)s1;
                if(s1_float > s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                int s2 = 0;
                if(*static_cast<bool*>(op2.valor)){
                    s2 = 1;
                }
                if(s1 > s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " > ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }
        else if(op1.Tipo == FLOAT){
            float s1 = (float) *static_cast<float*>(op1.valor);
            if(op2.Tipo == INTEGER){
                int s2_int = (int) *static_cast<int*>(op2.valor);
                float s2 = (float)s2_int;
                if(s1 > s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                if(s1 > s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                float s2 = 0.0;
                if(*static_cast<bool*>(op2.valor)){
                    s1 = 1.0;
                }
                if(s1 > s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " > ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }
        else if(op1.Tipo == BOOL){
            bool s1 = false;
            if(*static_cast<bool*>(op1.valor)){
                s1 = true;
            }
            if(op2.Tipo == INTEGER){
                int s2 = (int) *static_cast<int*>(op2.valor);
                int s1_int = 0;
                if(s1){
                    s1_int = 1;
                }
                if(s1_int > s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                float s1_float = 0.0;
                if(s1){
                    s1_float = 1;
                }
                if(s1_float > s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                bool s2 = false;
                if(*static_cast<bool*>(op2.valor)){
                    s2 = true;
                }
                int s1_int = 0;
                int s2_int = 0;
                if(s1){
                    s1_int = 1;
                }
                if(s2){
                    s2_int = 1;
                }
                if(s1 > s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " > ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }
        else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede comparar [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " > ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    if(Operator == "<" ){
        if(op1.Tipo == INTEGER){
            int s1 = (int) *static_cast<int*>(op1.valor);
            if(op2.Tipo == INTEGER){
                int s2 = (int) *static_cast<int*>(op2.valor);
                if(s1 < s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                float s1_float = (float)s1;
                if(s1_float < s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                int s2 = 0;
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1;
                }
                if(s1 < s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " menor que ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }
        else if(op1.Tipo == FLOAT){
            float s1 = (float) *static_cast<float*>(op1.valor);
            if(op2.Tipo == INTEGER){
                int s2_int = (int) *static_cast<int*>(op2.valor);
                float s2 = (float)s2_int;
                if(s1 < s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                if(s1 < s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                float s2 = 0.0;
                if(*static_cast<bool*>(op2.valor)){
                    s1 = 1.0;
                }
                if(s1 < s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " menor que ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }
        else if(op1.Tipo == BOOL){
            bool s1 = false;
            if(*static_cast<bool*>(op1.valor)){
                s1 = true;
            }
            if(op2.Tipo == INTEGER){
                int s2 = (int) *static_cast<int*>(op2.valor);
                int s1_int = 0;
                if(s1){
                    s1_int = 1;
                }
                if(s1_int < s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                float s1_float = 0.0;
                if(s1){
                    s1_float = 1;
                }
                if(s1_float < s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                bool s2 = false;
                if(*static_cast<bool*>(op2.valor)){
                    s2 = true;
                }
                int s1_int = 0;
                int s2_int = 0;
                if(s1){
                    s1_int = 1;
                }
                if(s2){
                    s2_int = 1;
                }
                if(s1 < s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " menor que ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede comparar [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " menor que ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    if(Operator == ">=" ){
        if(op1.Tipo == INTEGER){
            int s1 = (int) *static_cast<int*>(op1.valor);
            if(op2.Tipo == INTEGER){
                int s2 = (int) *static_cast<int*>(op2.valor);
                if(s1 >=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                float s1_float = (float)s1;
                if(s1_float >=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                int s2 = 0;
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1;
                }
                if(s1 >=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " >= ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }
        else if(op1.Tipo == FLOAT){
            float s1 = (float) *static_cast<float*>(op1.valor);
            if(op2.Tipo == INTEGER){
                int s2_int = (int) *static_cast<int*>(op2.valor);
                float s2 = (float)s2_int;
                if(s1 >=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                if(s1 >=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                float s2 = 0.0;
                if(*static_cast<bool*>(op2.valor)){
                    s1 = 1.0;
                }
                if(s1 >=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " >= ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }
        else if(op1.Tipo == BOOL){
            bool s1 = false;
            if(*static_cast<bool*>(op1.valor)){
                s1 = true;
            }
            if(op2.Tipo == INTEGER){
                int s2 = (int) *static_cast<int*>(op2.valor);
                int s1_int = 0;
                if(s1){
                    s1_int = 1;
                }
                if(s1_int >=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                float s1_float = 0.0;
                if(s1){
                    s1_float = 1;
                }
                if(s1_float >=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                bool s2 = false;
                if(*static_cast<bool*>(op2.valor)){
                    s2 = true;
                }
                int s1_int = 0;
                int s2_int = 0;
                if(s1){
                    s1_int = 1;
                }
                if(s2){
                    s2_int = 1;
                }
                if(s1 >=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " >= ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede comparar [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " >= ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    if(Operator == "<=" ){
        if(op1.Tipo == INTEGER){
            int s1 = (int) *static_cast<int*>(op1.valor);
            if(op2.Tipo == INTEGER){
                int s2 = (int) *static_cast<int*>(op2.valor);
                if(s1 <=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                float s1_float = (float)s1;
                if(s1_float <=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                int s2 = 0;
                if(*static_cast<bool*>(op1.valor)){
                    s1 = 1;
                }
                if(s1 <=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " menor ó igual que ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }
        else if(op1.Tipo == FLOAT){
            float s1 = (float) *static_cast<float*>(op1.valor);
            if(op2.Tipo == INTEGER){
                int s2_int = (int) *static_cast<int*>(op2.valor);
                float s2 = (float)s2_int;
                if(s1 <=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                if(s1 <=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                float s2 = 0.0;
                if(*static_cast<bool*>(op2.valor)){
                    s1 = 1.0;
                }
                if(s1 <=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }
            else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " menor ó igual que ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }
        else if(op1.Tipo == BOOL){
            bool s1 = false;
            if(*static_cast<bool*>(op1.valor)){
                s1 = true;
            }
            if(op2.Tipo == INTEGER){
                int s2 = (int) *static_cast<int*>(op2.valor);
                int s1_int = 0;
                if(s1){
                    s1_int = 1;
                }
                if(s1_int <=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == FLOAT){
                float s2 = (float) *static_cast<float*>(op2.valor);
                float s1_float = 0.0;
                if(s1){
                    s1_float = 1;
                }
                if(s1_float <=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else if(op2.Tipo == BOOL){
                bool s2 = false;
                if(*static_cast<bool*>(op2.valor)){
                    s2 = true;
                }
                int s1_int = 0;
                int s2_int = 0;
                if(s1){
                    s1_int = 1;
                }
                if(s2){
                    s2_int = 1;
                }
                if(s1 <=s2){
                    bool boolTrue = true;
                    return *new symbol(0,0,"", BOOL,&boolTrue);
                }else{
                    bool boolFalse = false;
                    return *new symbol(0,0,"", BOOL,&boolFalse);
                }
            }else{
                //ERROR SEMANTICO
                std::string contenido_error =  "No se puede comparar [";
                contenido_error += obtenerTipo(op1.Tipo);
                contenido_error += " menor ó igual que ";
                contenido_error += obtenerTipo(op2.Tipo);
                contenido_error += "]";
                tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
                tree->erroresSemanticos++;
            }
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede comparar [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " menor ó igual que ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "]";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    //EVALUANDO LOGICOS
    if(Operator == "&&"){
        if(op1.Tipo == BOOL && op2.Tipo == BOOL){
            bool s1 = *static_cast<bool*>(op1.valor);
            bool s2 = *static_cast<bool*>(op2.valor);
            bool result = s1 && s2;
            std::cout<<result<<std::endl;
            return *new symbol(0,0,"", BOOL,&result);
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " && ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "], ambos operandos deben ser de tipo BOOL";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    if(Operator == "||"){
        if(op1.Tipo == BOOL && op2.Tipo == BOOL){
            bool s1 = *static_cast<bool*>(op1.valor);
            bool s2 = *static_cast<bool*>(op2.valor);
            bool result = s1 || s2;
            return *new symbol(0,0,"", BOOL,&result);
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar [";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += " || ";
            contenido_error += obtenerTipo(op2.Tipo);
            contenido_error += "], ambos operandos deben ser de tipo BOOL";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    if(Operator == "!"){
        if(op1.Tipo == BOOL && op2.Tipo == BOOL){
            bool s1 = *static_cast<bool*>(op1.valor);
            if(s1){
                bool* result = new bool;
                *result = false;
                return *new symbol(0,0,"", BOOL,result);
            }else{
                bool* result = new bool;
                *result = true;
                return *new symbol(0,0,"", BOOL,result);
            }

        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar [! ";
            contenido_error += obtenerTipo(op1.Tipo);
            contenido_error += "], el valor debe ser de tipo BOOL";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }
    }
    return sym;
}


std::string operation::obtenerTipo(int _tipo){
    switch(_tipo){
        case 0:{ return "INT";      } break;
        case 1:{ return "FLOAT";    } break;
        case 2:{ return "STRING";   } break;
        case 3:{ return "BOOL";     } break;
        case 4:{ return "NULO";     } break;
        case 5:{ return "VOID";     } break;
        case 6:{ return "STRUCT";   } break;
    default:
        return "";
    }
}
