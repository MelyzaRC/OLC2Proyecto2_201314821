#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include <map>
#include "Environment/symbol.hpp"
#include "Environment/func_symbol.hpp"
#include "AST/asttree.hpp"
using std::map;

class environment
{
public:
    int Size;
    environment *Padre;
    map<std::string, symbol> Tabla;
    std::string Id;
    map<std::string, map<std::string, TipoDato>> TablaStructs;
    map<std::string,map<TipoDato,QVector<symbol>>> TablaArray;
    map<std::string, func_symbol> TablaFunctions;

    environment(environment *pad, std::string id);
    //VARIABLES
    void SaveVariable(symbol sym, std::string id, asttree *tree);
    symbol SaveVariable2(std::string id, TipoDato tipo, asttree *tree);
    void ModificarVariable(symbol sym, std::string id);
    symbol GetVariable(std::string id,environment *env, asttree *tree);
    //INCREMENTOS
    void IncrementarVariable(std::string id, asttree *tree);
    int incrementoVar(std::string id, environment *env, asttree *tree);
    //METODOS STRUCTS
    void SaveStruct(map<std::string, TipoDato> tabla, std::string id, asttree *tree);
    map<std::string, TipoDato> GetStruct(std::string id, environment *env, asttree *tree);
    //METODOS ARRAYS
    void SaveArray(QVector<symbol> valor, TipoDato tipo,std::string id, asttree *tree);
    map<TipoDato, QVector<symbol>> GetArray(std::string id, environment *env, asttree *tree);
    void editArray(map<TipoDato,QVector<symbol>> sym, std::string id, asttree *tree);
    //FUNCIONES
    func_symbol GetFunc(std::string id, environment *env, asttree *tree);
    void SaveFunc(func_symbol sym, std::string id, asttree *tree);

    std::string obtenerTipo(int _tipo);
    std::string obtenerTipoTraduccion(int _tipo);
    std::string graficar();
    void saveSize(std::string nombre, int tam);
};

#endif // ENVIRONMENT_HPP
