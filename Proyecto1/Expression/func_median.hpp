#ifndef FUNC_MEDIAN_HPP
#define FUNC_MEDIAN_HPP
#include "Interface/expression.hpp"

class func_median: public expression
{
public:
    int Line;
    int Col;
    std::string id;
    func_median(int line, int col, std::string id_vector);
    symbol ejecutar(environment *env, asttree *tree) override;
    int compare(const void* a, const void* b);
    value traducir(environment *env, asttree *tree, generator_code *gen) override;
};

#endif // FUNC_MEDIAN_HPP
