#ifndef FUNC_MEAN_HPP
#define FUNC_MEAN_HPP
#include "Interface/expression.hpp"

class func_mean: public expression
{
public:
    int Line;
    int Col;
    std::string id;
    func_mean(int line, int col, std::string id_vector);
    symbol ejecutar(environment *env, asttree *tree) override;
};

#endif // FUNC_MEAN_HPP
