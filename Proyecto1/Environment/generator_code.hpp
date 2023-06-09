#ifndef GENERATOR_CODE_HPP
#define GENERATOR_CODE_HPP
#include "QVector"

class generator_code
{
public:
    int Temporal;
    int Label;
    QVector<std::string> Code;
    QVector<std::string> FuncCode;
    QVector<std::string> Natives;
    QVector<std::string> TempList;
    bool MainCode;
    bool PrintStringFlag;
    bool mathErrorFlag;
    bool mathErrorAtoiFlag;
    bool mathErrorAtofFlag;
    bool fueraRangoFlag;
    std::string FinalCode;

    generator_code();
    std::string newTemp();
    std::string newLabel();
    void AddIf(std::string left, std::string right, std::string op, std::string label);
    void AddGoto(std::string label);
    void AddLabel(std::string label);
    void AddExpression(std::string target, std::string left, std::string right, std::string op);
    void AddAssign(std::string target, std::string val);
    void AddComment(std::string val);
    void AddCall(std::string target);
    void AddSetHeap(std::string index, std::string value);
    void AddSetStack(std::string index, std::string value);
    void AddGetStack(std::string index, std::string target);
    void AddBr();
    void AddPrintf(std::string typePrint, std::string value);
    void GeneratePrintString();
    void GenerateMathError();
    void GenerateMathErrorATOI();
    void GenerateMathErrorATOF();
    void GenerateFueraRango();
    void GenerateFinalCode();
};

#endif // GENERATOR_CODE_HPP
