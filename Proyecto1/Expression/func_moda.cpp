#include "func_moda.hpp"

func_moda::func_moda(int line, int col, std::string id_vector)
{
    this->Line = line;
    this->Col = col;
    this->id = id_vector;
}

value func_moda::traducir(environment *env, asttree *tree, generator_code *gen){
    value val("", false, NULO);
    return val;
}

int func_moda::contarRepitencia(int numeros[], int dimension, int numero){
    int x = 0;
    for(int i = 0; i < dimension; i++ ){
        if(numeros[i] == numero) x++;
    }
    return x;
}

symbol func_moda::ejecutar(environment *env, asttree *tree){

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
                for(int i  = 0; i < valores.size(); i++){
                    std::cout<<","<<arr[i];
                }
                std::cout<<std::endl;
                x = valores.size();
                int indexMayor = 0;
                int repMayor = 0;
                for(int i = 0; i < x; i++){
                    if(contarRepitencia(arr, x, arr[i]) > repMayor ){
                        repMayor = contarRepitencia(arr, x, arr[i]);
                        indexMayor = i;
                    }
                }
                int* ret = new int;
                *ret = arr[indexMayor];
                return *new symbol(Line, Col, "", INTEGER, ret);
            }else if (sym.Tipo == FLOAT){

            }else{
                //REPORTAR ERROR
                std::cout<<"El vector no es numerico"<<std::endl;
            }
        }
    return symReturn;
}
