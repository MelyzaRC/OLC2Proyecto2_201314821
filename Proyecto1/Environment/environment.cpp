#include "environment.hpp"


environment::environment(environment *padre, std::string id)
{
    Padre = padre;
    Id = id;
}

void environment::SaveStruct(map<std::string, TipoDato> tabla, std::string id, asttree *tree)
{
    if (TablaStructs.find(id) == TablaStructs.end())
    {
        TablaStructs[id] = tabla;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Ya existe el struct "+id;
    }
}

map<std::string, TipoDato> environment::GetStruct(std::string id, environment *env, asttree *tree)
{
    map<std::string, TipoDato> sym_struct;
    environment tmpEnv = *env;

    for( ; ;)
    {
        if (tmpEnv.TablaStructs.find(id) == tmpEnv.TablaStructs.end())
        {
            if(tmpEnv.Padre == nullptr)
            {
                break;
            }
            else
            {
                tmpEnv = *tmpEnv.Padre;
            }
        }
        else
        {
            sym_struct = tmpEnv.TablaStructs[id];
            break;
        }

    }
    return sym_struct;
}

void environment::ModificarVariable(symbol sym, std::string id){
    if (Tabla.find(id) != Tabla.end()){
        switch (sym.Tipo) {
        case INTEGER:
                {
                    int* res = new int;
                    *res = (int)*static_cast<int*>(sym.valor);
                    Tabla[id].valor = res;
                }
            break;
        case FLOAT:
                {
                    float* res = new float;
                    *res = (float)*static_cast<float*>(sym.valor);
                    Tabla[id].valor = res;
                }
            break;
        case BOOL:
                {
                    bool* res = new bool;
                    *res = (bool)*static_cast<bool*>(sym.valor);
                    Tabla[id].valor = res;
                }
            break;
        case STRING:
                {
                    std::string* res = new std::string;
                    *res = (std::string)*static_cast<std::string*>(sym.valor);
                    Tabla[id].valor = res;
                }
            break;
        }
    }
}

void environment::SaveVariable(symbol sym, std::string id, asttree *tree)
{
    if (this->Tabla.find(id) == this->Tabla.end()){
        this->Tabla[id] = sym;
    }else{
        auto iter = Tabla.begin();
           /* while (iter != Tabla.end()) {
                std::cout << "[" << iter->first << "]\n";
                ++iter;
            }*/

        if(Tabla[id].Tipo == sym.Tipo){
            //aqui solo se sustituye el valor
            Tabla[id] = sym;
        }else{
            //se reporta un error
            std::string contenido_error = "Ya existe la variable ";
            contenido_error += id;
            tree->errores.append(*new error_analisis(0, 0, 3, contenido_error));
            tree->IncrementaErroresSemanticos();
        }

    }
}

symbol environment::GetVariable(std::string id, environment *env, asttree *tree)
{
    symbol sym (0,0,"",NULO,nullptr);
    environment tmpEnv = *env;

    for( ; ;){
        if (tmpEnv.Tabla.find(id) == tmpEnv.Tabla.end()){
            if(tmpEnv.Padre == nullptr){
                break;
            }else{
                tmpEnv = *tmpEnv.Padre;
            }
        }else{
            symbol tempSym (tmpEnv.Tabla[id].Line,
                            tmpEnv.Tabla[id].Col,
                            tmpEnv.Tabla[id].Id,
                            tmpEnv.Tabla[id].Tipo,
                            tmpEnv.Tabla[id].valor);
            sym = tempSym;
            return sym;
        }

    }
    auto iter = Tabla.begin();
        while (iter != Tabla.end()) {
            std::cout << "[" << iter->first << "]\n";
            ++iter;
        }
    // ERROR NO ENCONTRO LA VARIABLE
    tree->IncrementaErroresSemanticos();
    std::string contenido_error = "No se ha encontrado la variable ";
    contenido_error += id;
    error_analisis er = *new error_analisis(0,0,3,contenido_error);
    tree->addError(er);
    return sym;
}

void environment::IncrementarVariable(std::string id, asttree *tree){
     int a = incrementoVar(id, this, tree);
}

int environment::incrementoVar(std::string id, environment *env, asttree *tree){

    if (this->Tabla.find(id) != Tabla.end()){
       if(Tabla[id].Tipo == INTEGER){
           int* res = new int;
           *res  =(int)(*static_cast<int*>( Tabla[id].valor) + 1);
           Tabla[id].valor = res;
           return 1;
       }else if(Tabla[id].Tipo == FLOAT){
           float* res = new float;
           *res  =(float)(*static_cast<float*>( Tabla[id].valor) + 1.0);
           Tabla[id].valor = res;
           return 1;
       }else{
           //ERROR SEMANTICO
           std::string contenido_error =  "La variable ";
           contenido_error += id;
           contenido_error += " no se puede incrementar ya que no es numérica";
           tree->errores.append(*new error_analisis(0, 0, 3, contenido_error));
           tree->erroresSemanticos++;
           return 0;
       }

    }

    if(env->Padre != nullptr){
        return incrementoVar(id, env->Padre, tree);
    }
    return 0;
}

void environment::SaveFunc(func_symbol funcSym, std::string id, asttree *tree)
{
    if (TablaFunctions.find(id) == TablaFunctions.end())
    {
        TablaFunctions[id] = funcSym;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Error: ya existe la funcion "+id;
    }
}

func_symbol environment::GetFunc(std::string id, environment *env, asttree *tree)
{
    func_symbol sym_func;
    environment tmpEnv = *env;

    for( ; ;)
    {
        if (tmpEnv.TablaFunctions.find(id) == tmpEnv.TablaFunctions.end())
        {
            if(tmpEnv.Padre == nullptr)
            {
                break;
            }
            else
            {
                tmpEnv = *tmpEnv.Padre;
            }
        }
        else
        {
            sym_func = tmpEnv.TablaFunctions[id];
            break;
        }

    }
    return sym_func;
}

void environment::SaveArray(QVector<symbol>valor, TipoDato tipo1,std::string id, asttree *tree){
    if (this->TablaArray.find(id) == this->TablaArray.end()){
        map<TipoDato,QVector<symbol>> aux ={{tipo1,valor}};
        this->TablaArray[id] = aux;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Ya existe el array "+id;
    }
}

map<TipoDato, QVector<symbol>> environment::GetArray(std::string id, environment *env, asttree *tree){
    map<TipoDato, QVector<symbol>> sym_array;
    environment tmpEnv = *env;
    for( ; ; ){
        if(tmpEnv.TablaArray.find(id) == tmpEnv.TablaArray.end()){
            if(tmpEnv.Padre == nullptr){
                //ERROR SEMANTICO
                std::string contenido_error =  "No existe el vector indicado [";
                contenido_error += id;
                contenido_error += "]";
                tree->errores.append(*new error_analisis(0, 0, 3, contenido_error));
                tree->erroresSemanticos++;
                break;
            }else{
                tmpEnv = *tmpEnv.Padre;
            }
        }else{
            return env->TablaArray[id];

        }
    }
    return sym_array;
}

void environment::editArray(map<TipoDato,QVector<symbol>> sym, std::string id, asttree *tree){
    if(TablaArray.find(id) == TablaArray.end()){
        //ERROR SEMANTICO
        std::string contenido_error =  "No se ha encontrado el vector ";
        contenido_error +=id;
        tree->errores.append(*new error_analisis(0, 0, 3, contenido_error));
        tree->erroresSemanticos++;
    }else{
        TablaArray[id] = sym;
    }
}

std::string environment::graficar(){
    std::string tmp = "";
    tmp += "<h3>Entorno <font color=\"#3E36F7\">";
    tmp += this->Id;
    tmp += "</font></h3></br>";
    //Variables**************************************************************************
    //ERRORES SEMANTICOS
    tmp += "</br><table>";
    tmp += "<tr><td colspan=\"3\" bgcolor=\"#950E8B\"><center><font color=\"#FFFFFF\"><h3 margin=\"25\">Variables</h3></font></center></td></tr>";
    tmp += "<tr>";
    tmp += "<td width=\"100\" bgcolor=\"#EA94F8\"><center><b>Tipo</b></center></td>";
    tmp += "<td width=\"100\" bgcolor=\"#EA94F8\"><center><b>Nombre</b></center></td>";
    tmp += "<td width=\"350\" bgcolor=\"#EA94F8\"><center><b>Valor</b></center></td>";
    tmp += "</tr>";
    auto iter = Tabla.begin();
        while (iter != Tabla.end()) {
            tmp +=  "<tr>";
            tmp +=  "<td width=\"100\"><center>";
            tmp +=  this->obtenerTipo(iter->second.Tipo);
            tmp +=  "</center></td>";
            tmp +=  "<td width=\"100\"><center>";
            tmp +=  iter->first;
            tmp +=  "</center></td>";
            tmp +=  "<td width=\"350\">";
            symbol res = iter->second;
                if(res.Tipo == INTEGER ){
                    tmp += std::to_string(*static_cast<int*>(res.valor));
                }else if(res.Tipo == FLOAT ){
                    tmp += std::to_string(*static_cast<float*>(res.valor));
                }else if(res.Tipo == BOOL ){
                    if(*static_cast<bool*>(res.valor)){
                        tmp+= "true";
                    }else{
                        tmp+= "false";
                    }
                }else if(res.Tipo == NULO ){
                    tmp+= "NULO";
                }else{
                    tmp += *static_cast<std::string*>(res.valor);
                }
            tmp +=  "</td>";
            tmp += "</tr>";
            ++iter;
        }
    tmp += "</table></br></br>";
    //Arrays*****************************************************************************
    //Structs****************************************************************************

    return tmp;
}


std::string environment::obtenerTipo(int _tipo){
    switch(_tipo){
        case 0:{ return "INT";      } break;
        case 1:{ return "FLOAT";    } break;
        case 2:{ return "STRING";   } break;
        case 3:{ return "BOOL";     } break;
        case 4:{ return "NULO";     } break;
        case 5:{ return "VOID";     } break;
        case 6:{ return "STRUCT";   } break;
    default:
        return "";
    }
}
