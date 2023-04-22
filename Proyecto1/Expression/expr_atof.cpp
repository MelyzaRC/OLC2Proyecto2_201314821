#include "expr_atof.hpp"

expr_atof::expr_atof(int line, int col, expression *a)
{
    Line = line;
    Col = col;
    contenido = a;
}

value expr_atof::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
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

