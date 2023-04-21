#include "expr_iota.hpp"

expr_iota::expr_iota(int line, int col, expression *a)
{
    Line = line;
    Col = col;
    contenido = a;
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

