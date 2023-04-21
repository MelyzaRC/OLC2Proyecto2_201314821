#include "expr_atoi.hpp"


expr_atoi::expr_atoi(int line, int col, expression *a)
{
    Line = line;
    Col = col;
    contenido = a;
}

symbol expr_atoi::ejecutar(environment *env, asttree *tree){
   symbol sym = contenido->ejecutar(env, tree);
   symbol symReturn = *new symbol(0,0,"",NULO, nullptr);
   if(sym.Tipo == STRING){
    std::string valorCadena = *static_cast<std::string*>(sym.valor);
    try{
        int* valorConvertido = new int;
        *valorConvertido = std::stoi(valorCadena);
        return symbol(Line, Col, "", INTEGER, valorConvertido);
    }
    catch(const std::logic_error &er){
        //reportar error
        std::cout<<"Error no se puede convertir en INTEGER"<<std::endl;
    }
   }else{
       //REPORTAR ERROR
       std::cout<<"El valor enviado a la funcion atoi no es una cadena"<<std::endl;
   }
   return symReturn;
}
