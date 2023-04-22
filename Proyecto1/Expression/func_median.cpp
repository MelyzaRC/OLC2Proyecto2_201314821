#include "func_median.hpp"
#include <iostream>
#include <cstdlib>

func_median::func_median(int line, int col, std::string id_vector)
{
    this->Line = line;
    this->Col = col;
    this->id = id_vector;
}

value func_median::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    return val;
}

int func_median::compare(const void* a, const void* b)
{
    const int* x = (int*) a;
    const int* y = (int*) b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}

symbol func_median::ejecutar(environment *env, asttree *tree){

    symbol symReturn(Line, Col, "", NULO, nullptr);
    map<TipoDato, QVector<symbol>> sym_vector = env->GetArray(id,env,tree);
    int x = 0;
    symbol sym;
        for(auto const& vector: sym_vector){
            sym = vector.second[0];
            if(sym.Tipo == INTEGER){
                QVector<symbol> valores = vector.second;
                //ordenamiento burbuja
                int arr[valores.size()];
                for(int i  = 0; i < valores.size(); i++){
                    arr[i] = *static_cast<int*>(valores.value(i).valor);
                }
                for(int i  = 0; i < valores.size(); i++){
                    for(int j  = i+1; j < valores.size(); j++){
                        if(arr[j] < arr[i]){
                            int tmp = arr[j];
                            arr[j] = arr[i];
                            arr[i] = tmp;
                        }
                    }
                }
                x = valores.size();

                if(x%2 == 0){
                    int index1 = (x/2)-1;
                    int index2 = ((x/2)+1)-1;
                    int* indexRet = new int;
                    *indexRet = (arr[index1] + arr[index2])/2;
                    return *new symbol(Line, Col, "", INTEGER, indexRet);
                }else{
                    int* indexRet = new int;
                    *indexRet = arr[x/2];
                    return *new symbol(Line, Col, "", INTEGER, indexRet);
                }

            }else if (sym.Tipo == FLOAT){

            }else{
                //REPORTAR ERROR
                std::cout<<"El vector no es numerico"<<std::endl;
            }
        }
    return symReturn;
}

