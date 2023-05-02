#include "expr_iota.hpp"

expr_iota::expr_iota(int line, int col, expression *a)
{
    Line = line;
    Col = col;
    contenido = a;
}

value expr_iota::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode= true;

    value op1 = this->contenido->traducir(env, tree, gen);
    if(op1.TipoExpresion == INTEGER){
        std::string tmp = gen->newTemp();
        gen->AddAssign(tmp, "H");
        gen->AddSetHeap("(int)H",op1.Value);
        gen->AddExpression("H","H","1","+");
        //indica que es un int
        gen->AddSetHeap("(int)H","-2");
        gen->AddExpression("H","H","1","+");
        //indica el fin de la cadenas
        gen->AddSetHeap("(int)H","-1");
        gen->AddExpression("H","H","1","+");
        value val(tmp, true, STRING);
        return val;
    }else if(op1.TipoExpresion == FLOAT){
        std::string tmp = gen->newTemp();
        gen->AddAssign(tmp, "H");
        gen->AddSetHeap("(int)H",op1.Value);
        gen->AddExpression("H","H","1","+");
        //indica que es un float
        gen->AddSetHeap("(int)H","-3");
        gen->AddExpression("H","H","1","+");
        //indica el fin de la cadena
        gen->AddSetHeap("(int)H","-1");
        gen->AddExpression("H","H","1","+");
        value val(tmp, true, STRING);
        return val;
    }
    else if(op1.TipoExpresion == BOOL){
        std::string labelTrue = gen->newLabel();
        std::string labelFalse = gen->newLabel();
        std::string labelSalir = gen->newLabel();
        std::string tmp = gen->newTemp();
        gen->AddIf(op1.Value,"1","==",labelTrue);
        gen->AddGoto(labelFalse);

        //TRUE
        gen->AddLabel(labelTrue);
        gen->AddAssign(tmp,"H");
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
        gen->AddSetHeap("(int)H","-1" );
        gen->AddExpression("H", "H", "1", "+");
        gen->AddGoto(labelSalir);
        //FALSE
        gen->AddLabel(labelFalse);
        gen->AddAssign(tmp,"H");
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
        gen->AddSetHeap("(int)H","-1" );
        gen->AddExpression("H", "H", "1", "+");
        gen->AddGoto(labelSalir);
        gen->AddLabel(labelSalir);
        value val(tmp, true, STRING);
        return val;
    }
    else{
        //ERROR SEMANTICO
        std::string contenido_error =  "La funcion IOTA solamente acepta valores NUMERICOS o BOOL, se encontro [ ";
        contenido_error += env->obtenerTipo(op1.TipoExpresion);
        contenido_error += " ]";
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;
        value val("", false, NULO);
        return val;
    }


    value val("", false, NULO);
    return val;
}

symbol expr_iota::ejecutar(environment *env, asttree *tree){
    symbol sym = contenido->ejecutar(env,tree);
    symbol symReturn = *new symbol(Line, Col, "", NULO, nullptr);
    switch(sym.Tipo){
    case INTEGER:   {
                    std::string* res = new std::string ;
                    *res = std::to_string(*static_cast<int*>(sym.valor));
                    return *new symbol(Line, Col, "", STRING, res);
                    }
        break;
    case FLOAT:     {
                    std::string* res = new std::string ;
                    std::string tmpRes =  std::to_string(*static_cast<float*>(sym.valor));

                    int indice = -1;
                    for(int i= 0; i < tmpRes.size(); i++){
                        if(tmpRes[i] == '0'){
                            if(indice ==  -1){indice = i;}
                        }else{
                            indice = -1;
                        }
                    }
                    if(indice > -1){
                        for(int i = indice; i < tmpRes.size(); i++){
                            tmpRes[i] = 0;
                        }
                    }
                    *res = tmpRes;
                    return symbol(Line, Col, "", STRING, res);
                    }
        break;
    case BOOL:      {
                    bool val = *static_cast<bool*>(sym.valor);
                    if(val){
                        std::string* v = new std::string;
                        *v = "true";
                        return symbol(Line, Col, "", STRING, v);
                    }else{
                        std::string* v = new std::string;
                        *v = "false";
                        return symbol(Line, Col, "", STRING, v);
                    }
                    }
        break;
    }
    //REPORTAR ERROR
    std::cout<<"Error al convertir en cadena"<<std::endl;
    return symReturn;
}

