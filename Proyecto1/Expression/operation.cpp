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
            }
            val = value(newTemp, true, FLOAT);
            return val;
        }else if(DominanteDato == STRING){
            //CONCATENACION
            if(op1.TipoExpresion == STRING){
                if(op2.TipoExpresion == INTEGER){
                    gen->AddExpression("H", "H", "1", "-");
                    std::string valor_concatenado = op2.Value;
                }
                else if(op2.TipoExpresion == FLOAT){
                    gen->AddExpression("H", "H", "1", "-");
                    std::string valor_concatenado = op2.Value;
                }
                else if(op2.TipoExpresion == BOOL){
                    gen->AddExpression("H", "H", "1", "-");
                    if(op2.Value == "true"){
                        std::string valor_concatenado = "true";
                    }else{
                        std::string valor_concatenado = "false";
                    }
                }
                else if(op2.TipoExpresion == STRING){}
            }
            //Retrocedo una posicion en el heap para que quede junto al string


            //nuevo temporal
            //std::string newTemp = gen->newTemp();
            //igualar a Heap Pointer
            //gen->AddAssign(newTemp, "H");
            //recorrer cadena
            //for (int i = 0; i < valor_concatenado.length(); i++) {
                //se agrega ascii a heap
               // gen->AddSetHeap("(int)H", std::to_string(int(valor_concatenado[i])));
                //suma heap pointer
              //  gen->AddExpression("H", "H", "1", "+");
           // }
            //caracteres de escape
            //gen->AddSetHeap("(int)H", "-1");
            //gen->AddExpression("H", "H", "1", "+");
            //gen->AddBr();

            //gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            val = value(newTemp, true, STRING);
            return val;
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "No se puede operar la suma entre ";
            contenido_error += env->obtenerTipo(op1.TipoExpresion);
            contenido_error += " y ";
            contenido_error += env->obtenerTipo(op2.TipoExpresion);
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
        }

    }

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
