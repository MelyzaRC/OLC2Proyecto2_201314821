#include "error_analisis.hpp"

error_analisis::error_analisis(int line, int col, int type, std::string cont)
{
    this->Line = line;
    this->Col = col;
    this->tipo = type;
    this->contenido = cont;
    //std::cout<<this->contenido<<std::endl;
}

error_analisis::error_analisis()
{
}

