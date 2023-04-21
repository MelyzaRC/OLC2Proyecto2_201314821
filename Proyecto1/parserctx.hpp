#ifndef PARSERCTX_HPP
#define PARSERCTX_HPP
#include <string>
#include "Instruction/list_instruction.hpp"
#include "Interface/instruction.hpp"
#include "Error/error_analisis.hpp"

namespace yy {
class Parser;
class location;
}

namespace OCL2Proyecto1 {
    class ParserCtx
    {
        public:
            list_instruction *Functions;
            // constructor
            ParserCtx();
            // destructor
            ~ParserCtx();


        // atributos del analizador
            void* lexer;
            yy::location* loc;
            yy::Parser* Parser;
        // funcion de analisis
            std::string Analizar(std::string entrada);
            node *raiz;
            list_instruction *Main;
            QVector<error_analisis*> lista_errores;
            bool erroresEncontrados;
    };

}



#endif // PARSERCTX_HPP
