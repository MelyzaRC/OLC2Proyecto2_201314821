#ifndef ERROR_HPP
#define ERROR_HPP
#include <iostream>

class error
{
public:
    int Line;
    int Col;
    int tipo;
    std::string contenido;
    error();
    error(int line, int col, int type, std::string cont);
};

#endif // ERROR_HPP
