#ifndef FUNC_MODA_HPP
#define FUNC_MODA_HPP
#include "Interface/expression.hpp"

class func_moda: public expression
{
public:
    int Line;
    int Col;
    std::string id;
    func_moda(int line, int col, std::string id_vector);
    symbol ejecutar(environment *env, asttree *tree) override;
    int contarRepitencia(int numeros[], int dimension, int numero);
};

#endif // FUNC_MODA_HPP
