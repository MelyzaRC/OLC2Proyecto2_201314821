#include "expr_atof.hpp"

expr_atof::expr_atof(int line, int col, expression *a)
{
    Line = line;
    Col = col;
    contenido = a;
}

value expr_atof::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode= true;

    value op1 = this->contenido->traducir(env, tree, gen);
    value val("", false, NULO);

    //Esta funcion solamente recibe strings
    if(op1.TipoExpresion == STRING){
        std::string LEntera = gen->newLabel();


        gen->AddComment("======== Expresion ATOF ========");
        std::string t2 = gen->newTemp();
        std::string t3 = gen->newTemp();
        std::string t4 = gen->newTemp();
        std::string tpeso = gen->newTemp();

        std::string L1 = gen->newLabel();
        std::string L2 = gen->newLabel();
        std::string L3 = gen->newLabel();//final del reconocimiento inicial
        std::string L4 = gen->newLabel();
        std::string L5 = gen->newLabel();

        //Encontrar la ultima posicion del string y asignarsela al temporal que va a iterar
        //Pos del heap donde empieza el valor String
        gen->AddAssign(tpeso, "1");
        gen->AddAssign(t2, op1.Value);
        gen->AddAssign(t3, "0");
        gen->AddLabel(L4);
        gen->AddAssign(t4, "heap[(int)"+t2+"]");
        gen->AddIf(t4, "-1","==",L1);
        gen->AddComment("Validando solo caracteres numericos");
        gen->AddIf(t4,"46","==",L2);
        gen->AddIf(t4,"48","<",L5);
        gen->AddIf(t4,"57",">",L5);

        gen->AddGoto(L2);
        gen->AddLabel(L1);

        gen->AddGoto(L3);
        gen->AddLabel(L2);
        gen->AddAssign(t3,t2);
        gen->AddExpression(t2, t2,"1","+");
        gen->AddGoto(L4);
        gen->AddLabel(L3);
        //AQUI TENGO EN t3 la ultima posicion de la cadena (Ej. 510 t3= 2, pos 2 del heap es la ultima pos de la cadena)
        std::string t5 = gen->newTemp();
        std::string t6 = gen->newTemp();
        std::string L6 = gen->newLabel();
        std::string L7 = gen->newLabel();
        std::string tresultado = gen->newTemp();
        std::string LSalir = gen->newLabel();

        gen->AddAssign(t5,t3);
        std::string LRec = gen->newLabel();
        //Aqui iria la etiqueta
        gen->AddLabel(LRec);
        gen->AddAssign(t6,"heap[(int)"+t5+"]");
        gen->AddIf(t6,"-3","==", L6);
        gen->AddIf(t6,"-2","==", L5);
        gen->AddIf(t6,"-1","==", LSalir);
        //ENCUENTRA EL PUNTO DECIMAL
        gen->AddIf(t6,"46","==", LEntera);
        gen->AddIf(t5, "-1","==",LSalir);
        gen->AddGoto(L7);

        //es -2 es un int
        gen->AddLabel(L6);
        gen->AddExpression(t5,t5,"1","-");
        gen->AddAssign(tresultado, "heap[(int)"+t5+"]");
        gen->AddGoto(LSalir);

        //es una cadena de caracteres
        gen->AddLabel(L7);
        std::string tmpComparar = gen->newTemp();
        std::string L8 = gen->newLabel();
        std::string L9 = gen->newLabel();
        gen->AddAssign(tmpComparar,"heap[(int)" + t5 +"]");
        gen->AddIf(tpeso, "1","==", L8);
        gen->AddGoto(L9);
        gen->AddLabel(L8);
        //primer digito de la derecha restar 48 para obtener digito
        std::string tmpOperar = gen->newTemp();
        gen->AddExpression(tmpComparar, tmpComparar,"48","-");
        gen->AddExpression(tmpOperar,tmpComparar,"1","*");
        gen->AddExpression(tresultado,tresultado,tmpOperar,"+");
        gen->AddExpression(t5,t5,"1","-");
        gen->AddExpression(tpeso,tpeso,"10","*");
        gen->AddGoto(LRec);

        //no es el primer digito de la derecha - restar 48 para obtener digito
        gen->AddLabel(L9);
        std::string tmpOperar2 = gen->newTemp();
        gen->AddExpression(tmpComparar, tmpComparar,"48","-");
        gen->AddExpression(tmpOperar2,tmpComparar,tpeso,"*");
        gen->AddExpression(tresultado,tresultado,tmpOperar2,"+");
        gen->AddExpression(t5,t5,"1","-");
        gen->AddExpression(tpeso,tpeso,"10","*");
        gen->AddGoto(LRec);

        //MATH ERROR - NO ES UN FLOAT****************************************************
        gen->AddLabel(L5);
        gen->AddComment("No se puede convertir la cadena a FLOAT");
        gen->GenerateMathErrorATOF();
        gen->AddCall("olc3d_mathErrorAtof");
        gen->AddGoto(LSalir);

        //PARTE ENTERA =========================================================
        gen->AddComment("Recolectando la parte entera");
        gen->AddLabel(LEntera);
        gen->AddExpression(tresultado, tresultado, tpeso,"/");
        gen->AddAssign(tpeso,"1");
        gen->AddExpression(t5, t5,"1","-");
        gen->AddGoto(LRec);
        //t5 tiene la pos actual
        //tpeso esta en 1
        //tresultado ya tiene la parte decimal
        gen->AddGoto(LSalir);


        //SALIDA ===============================================================
        gen->AddLabel(LSalir);

        val = value(tresultado, true, FLOAT);
        return val;

    }else{
        //ERROR SEMANTICO
        std::string contenido_error =  "Se esperaba un valor de tipo STRING para la función ATOF, se encontró ";
        contenido_error += env->obtenerTipo(op1.TipoExpresion);
        tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
        tree->erroresSemanticos++;
        return val;
    }

    return val;
}

symbol expr_atof::ejecutar(environment *env, asttree *tree){
   symbol sym = contenido->ejecutar(env, tree);
   symbol symReturn = *new symbol(0,0,"",NULO, nullptr);
   if(sym.Tipo == STRING){
    std::string valorCadena = *static_cast<std::string*>(sym.valor);
    try{
        float* valorConvertido = new float;
        *valorConvertido = std::stof(valorCadena);
        return symbol(Line, Col, "", FLOAT, valorConvertido);
    }
    catch(const std::logic_error &er){
        //reportar error
        std::cout<<"Error no se puede convertir en FLOAT"<<std::endl;
    }
   }else{
       //REPORTAR ERROR
       std::cout<<"El valor enviado a la funcion atof no es una cadena"<<std::endl;
   }
   return symReturn;
}

