#ifndef ERROR_ANALISIS_HPP
#define ERROR_ANALISIS_HPP
#include <iostream>

class error_analisis
{
public:
    int Line;
    int Col;
    int tipo;
    std::string contenido;
    error_analisis();
    error_analisis(int line, int col, int type, std::string cont);
};

#endif // ERROR_ANALISIS_HPP
