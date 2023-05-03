#ifndef ASTTREE_HPP
#define ASTTREE_HPP
#include <iostream>
#include <QVector>
#include "Environment/symbol.hpp"
#include "Error/error_analisis.hpp"

class asttree
{
public:
    std::string LabelBreak;
    std::string LabelContinue;
    std::string ConsoleOut;
    std::string ErrorOut;
    std::string GraphOut;
    std::string cadenaTab;
    std::string salirLbl;
    bool breakFlag;
    bool continueFlag;
    bool ElseIfFlag;
    bool IfReturn;
    QVector<symbol> ListReturn;
    QVector<error_analisis> errores;
    int erroresSemanticos;

    asttree();
    void IncrementaErroresSemanticos();
    void addError(error_analisis);

    void activarBanderaBreak();
    void inactivarBanderaBreak();
    void activarBanderaContinue();
    void inactivarBanderaContinue();

    void activarBanderaIf();
    void inactivarBanderaIf();
};

#endif // ASTTREE_HPP
