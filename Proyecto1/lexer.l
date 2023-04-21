/* se convierte con: win_flex --verbose lexer.l*/
/* opcciones para encapsulamiento */

%option reentrant noyywrap nounput batch noinput
%option debug 

/*%option outfile="lexer.cpp" */
/* %option header-file="lexer.hpp"*/
%{
    #include <iostream>
    // definicion del tipo de funcion del retorno de simbolos
    // yy::Parser ¿Por qué?
    // yy es el namespace de parser
    // Parser es el nombre de la clase que lo envuelve (wapper)
    #define YY_DECL yy::Parser::symbol_type yylex(yyscan_t yyscanner, yy::location& loc, class OCL2Proyecto1::ParserCtx & ctx)
    // definición de acciones
    #define YY_USER_ACTION loc.columns(yyleng);
    // defincion de caracter EOF
    #define yyterminate() return Parser::make_END(loc)
    //se incrusta el parser
    #include "parser.hpp"
    #include "Error/error.hpp"


    using namespace yy;
    //typedefs (abreviaturas DefLarga DefCorta) para definiciones de tokens
    typedef yy::Parser::token token;
    typedef yy::Parser::token_type token_type;
/// código adicinoal aquí
%}

/* ============== INICIO DE SCANNER ==========  */


/* EXPRESIONES REGULARES */
ID                              ([a-zA-Z\_]+[0-9a-zA-Z\_]*)
TIPO_INTEGER                    [0-9]+
TIPO_FLOAT                      [0-9]+"."[0-9]+
TIPO_STRING                     \"(\\.|[^"\\])*\"
TIPO_BOOL_TRUE                  "true"
TIPO_BOOL_FALSE                 "false"
%%

%{
// inicia la lectura
    loc.step();
%}

    /* inicia la defincion de tokens   */

\/\/[^\n]+                                  ;   /* COMENTARIO DE UNA LINEA */
\/[*]+[^\"]+[*]+\/                          ;   /* COMENTARIO DE MULTI-LINEA */
[ \t\v\r\n\f]                               ;   /* ESPACIOS Y CARACTERES EN BLANCO */
    /* Lexemas */
    /* defincion moderna
        token::ID ID sin caracteres especiales
    */



    /* TOKENS  */
"{"                     return Parser::symbol_type( token::LLAVEABRE,           loc );
"}"                     return Parser::symbol_type( token::LLAVECIERRA,         loc );
"int"                   return Parser::symbol_type( token::RINT,                loc );
"float"                 return Parser::symbol_type( token::RFLOAT,              loc );
"string"                return Parser::symbol_type( token::RSTRING,             loc );
"bool"                  return Parser::symbol_type( token::RBOOL,               loc );
"printf"                return Parser::symbol_type( token::RPRINTF,             loc );
"="                     return Parser::symbol_type( token::IGUAL,               loc );
"+"                     return Parser::symbol_type( token::OPSUMA,              loc );
"-"                     return Parser::symbol_type( token::OPRESTA,             loc );
"*"                     return Parser::symbol_type( token::OPMULTIPLICACION,    loc );
"/"                     return Parser::symbol_type( token::OPDIVISION,          loc );
"%"                     return Parser::symbol_type( token::OPMODULO,            loc );
"("                     return Parser::symbol_type( token::PARABRE,             loc );
")"                     return Parser::symbol_type( token::PARCIERRA,           loc );
";"                     return Parser::symbol_type( token::PTCOMA,              loc );
"!="                    return Parser::symbol_type( token::NOIGUAL,             loc );
">"                     return Parser::symbol_type( token::MAYOR,               loc );
"<"                     return Parser::symbol_type( token::MENOR,               loc );
"if"                    return Parser::symbol_type( token::R_IF,                loc );
"else"                  return Parser::symbol_type( token::R_ELSE,              loc );
"main"                  return Parser::symbol_type( token::R_MAIN,              loc );
"void"                  return Parser::symbol_type( token::RVOID,               loc );
"&&"                    return Parser::symbol_type( token::RAND,                loc );
"||"                    return Parser::symbol_type( token::ROR,                 loc );
"!"                     return Parser::symbol_type( token::NOT,                 loc );
"while"                 return Parser::symbol_type( token::RWHILE,              loc );
"for"                   return Parser::symbol_type( token::RFOR,                loc );
"break"                 return Parser::symbol_type( token::RBREAK,              loc );
"continue"              return Parser::symbol_type( token::RCONTINUE,           loc );
"++"                    return Parser::symbol_type( token::MASMAS,              loc );
"atoi"                  return Parser::symbol_type( token::RATOI,               loc );
"atof"                  return Parser::symbol_type( token::RATOF,               loc );
"iota"                  return Parser::symbol_type( token::RIOTA,               loc );
","                     return Parser::symbol_type( token::COMA,                loc );
"struct"                return Parser::symbol_type( token::RSTRUCT,             loc );
"."                     return Parser::symbol_type( token::PUNTO,               loc );
"vector"                return Parser::symbol_type( token::RVECTOR,             loc );
"["                     return Parser::symbol_type( token::CORABRE,             loc );
"]"                     return Parser::symbol_type( token::CORCIERRA,           loc );
"get"                   return Parser::symbol_type( token::RGET,                loc );
"size"                  return Parser::symbol_type( token::RSIZE,               loc );
"push_back"             return Parser::symbol_type( token::RPUSHBACK,           loc );
"push_front"            return Parser::symbol_type( token::RPUSHFRONT,          loc );
"remove"                return Parser::symbol_type( token::RREMOVE,             loc );
"return"                return Parser::symbol_type( token::RRETURN,             loc );
"mean"                  return Parser::symbol_type( token::RMEAN,               loc );
"median"                return Parser::symbol_type( token::RMEDIAN,             loc );
"mode"                  return Parser::symbol_type( token::RMODE,               loc );
{TIPO_INTEGER}          return Parser::make_TIPO_INTEGER(yytext,                loc );
{TIPO_FLOAT}            return Parser::make_TIPO_FLOAT  (yytext,                loc );
{TIPO_STRING}           return Parser::make_TIPO_STRING (yytext,                loc );
{TIPO_BOOL_TRUE}        return Parser::make_TIPO_BOOL_TRUE(yytext,              loc );
{TIPO_BOOL_FALSE}       return Parser::make_TIPO_BOOL_FALSE(yytext,             loc );
{ID}                    return Parser::make_ID( yytext,                         loc );

.   {
        std::cerr<<loc <<": "<<"error léxico token no esperado "<< yytext <<  std::endl; 
    } 

    /*si no se usa yyterminate() se agrega lo siguiente*/
    /* <<EOF>> {return Parser::make_END(loc);} */
%%


 // más código - normalmente para manejo de errores
