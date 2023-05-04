#include "expr_size_vector.hpp"

expr_size_vector::expr_size_vector(int line, int col, std::string id)
{
    this->Line = line;
    this->Col = col;
    this->id = id;
}

value expr_size_vector::traducir(environment *env, asttree *tree, generator_code *gen){
    gen->MainCode = true;
    value val("", false, NULO);
    symbol sym = env->GetVariable(this->id,env,tree);
    if(sym.Tipo != NULO){
        if(sym.Tipo == VINT || sym.Tipo == VFLOAT || sym.Tipo == VBOOL || sym.Tipo == VSTRING){
            std::string tmpRes = gen->newTemp();
            gen->AddAssign(tmpRes, std::to_string(sym.size));
            value v(tmpRes,true,INTEGER);
            return v;
        }else{
            //ERROR SEMANTICO
            std::string contenido_error =  "La variable  ";
            contenido_error += this->id;
            contenido_error += " no es un vector";
            tree->errores.append(*new error_analisis(Line, Col, 3, contenido_error));
            tree->erroresSemanticos++;
            val= *new value("", false, NULO);
            return val;
        }
    }
    //No encuentra la variable - error controlado en el entorno
    return val;
}

symbol expr_size_vector::ejecutar(environment *env, asttree *tree){
    symbol sym (Line,Col,"",NULO,nullptr);
    map<TipoDato, QVector<symbol>> sym_vector = env->GetArray(id,env,tree);
    TipoDato t = NULO;
        int estado = 0;
        //VERIFICA QUE EXISTA EL VECTOR
        for(auto const& vector: sym_vector){
               t = vector.first;
               break;
        }
        if(t != NULO){
            std::cout<<"si encontro el vector"<<std::endl;
            for(auto const& vector: sym_vector){
                int* tmp = new int;
                *tmp = vector.second.size();
                return symbol(Line,Col,"",INTEGER,tmp);
            }
        }else{
            std::cout<<"no encontro el vector"<<std::endl;
        }
    return sym;
}
