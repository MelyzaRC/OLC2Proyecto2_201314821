/*comando   win_bison --verbose -o parser.cpp  parser.y */

/* Se requiere una versión minima de Bison */
%require  "3.0.4"
/* Se usa el skeleton más recienta para c++ */
%skeleton "lalr1.cc"

/* indica que se deben de crear archivos de cabeceras (.h)
    para las definiciones de tokens
*/
%defines

/* indica el namespace que contiene al parser */
// %name-prefix="yy" ó 
%define api.prefix{yy}

/* indica la clase que envuelve al parser */
%define api.parser.class {Parser}

/* indica que se generaran clases de tipo locations que leerá el lexer*/
%locations

/* indica que se deben crear contructores y funciones tipo make_TOKEN para cada token */

%define api.token.constructor

/* indica que se utilizará la notacion $1 -> $$ de los no terminales */
%define api.value.type variant

/* indica que el analizador mostrara un trace cuando haya un error*/
%define parse.trace

/* indica que el analizador mostrará los errores de forma descriptiva */
%define parse.error verbose

%code requires 
{
    /* código  que se inserta al inicioo por lo regular son cabeceras*/
    #include<iostream> 
    #include<string> 
    #include "parserctx.hpp"
    //INTERFACES
    #include "Interface/expression.hpp"
    //EXPRESIONES
    #include "Expression/primitive.hpp"
    #include "Expression/operation.hpp"
    #include "Expression/llamada_variable.hpp"
    #include "Expression/incremento_expression.hpp"
    #include "Expression/negacion_unaria.hpp"
    #include "Expression/lista_expresiones.hpp"
    #include "Expression/expr_atoi.hpp"
    #include "Expression/expr_atof.hpp"
    #include "Expression/expr_iota.hpp"
    #include "Expression/map_struct_dec.hpp"
    #include "Expression/struct_access.hpp"
    #include "Expression/vector_access.hpp"
    #include "Expression/expr_size_vector.hpp"
    #include "Expression/func_mean.hpp"
    #include "Expression/func_median.hpp"
    #include "Expression/func_moda.hpp"
    #include "Expression/call_exp.hpp"
    //INSTRUCCIONES
    #include "Instruction/declaration.hpp"
    #include "Instruction/list_instruction.hpp"
     #include "Instruction/list_instruction_second.hpp"
    #include "Instruction/func_printf.hpp"
    #include "Instruction/incremento.hpp"
    #include "Instruction/asignacion_variable.hpp"
    #include "Instruction/declaracion_sin_valor.hpp"
    #include "Instruction/instruction_if.hpp"
    #include "Instruction/func_main.hpp"
    #include "Instruction/instruction_while.hpp"
    #include "Instruction/instruction_for.hpp"
    #include "Instruction/instruction_break.hpp"
    #include "Instruction/instruction_continue.hpp"
    #include "Instruction/declaracion_struct.hpp"
    #include "Instruction/create_struct.hpp"
    #include "Instruction/create_vector.hpp"
    #include "Instruction/instruction_push_back.hpp"
    #include "Instruction/instruction_push_front.hpp"
    #include "Instruction/instruction_vector_remove.hpp"
    #include "Instruction/instruction_vector_asignacion.hpp"
    #include "Instruction/function.hpp"
    #include "Instruction/instruction_return.hpp"
    #include "Instruction/call_inst.hpp"
    #include "Instruction/instruction_asign_struct.hpp"

    //ERRORES
    #include "Error/error_analisis.hpp"
    #include "AST/node.hpp"
    #include "QVector"
    
    /*
    Se pueden definir estructuras y tipos para los no terminales
    */
    
    


}
/* enlace con la función del retorno de simbolos */
%code
{
yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Proyecto1::ParserCtx & ctx);
}


%token END 0;  //token de salida

/// %token<tipo> nombre+  
//cuidado con el orden
// %token <std::string> ID NUMERO 
%token <std::string>    LLAVEABRE
                        LLAVECIERRA
                        RINT
                        RFLOAT
                        RSTRING
                        RBOOL
                        RPRINTF
                        IGUAL
                        PTCOMA
                        OPSUMA
                        OPRESTA
                        OPMULTIPLICACION
                        OPDIVISION
                        OPMODULO
                        PARABRE
                        PARCIERRA
                        TIPO_INTEGER
                        TIPO_FLOAT
                        TIPO_STRING
                        TIPO_BOOL_TRUE
                        TIPO_BOOL_FALSE
                        ID       
                        MAYOR
                        MENOR
                        R_IF
                        R_ELSE
                        R_MAIN
                        RVOID
                        RAND
                        ROR
                        NOT 
                        NOIGUAL
                        RWHILE
                        RFOR
                        RBREAK
                        MASMAS
                        RCONTINUE
                        COMA
                        RIOTA
                        RATOI
                        RATOF
                        RSTRUCT
                        PUNTO
                        RVECTOR
                        CORABRE
                        CORCIERRA
                        RGET
                        RSIZE
                        RPUSHBACK
                        RPUSHFRONT
                        RREMOVE
                        RRETURN
                        RMEAN
                        RMEDIAN
                        RMODE

// token de tipo por defecto
    //token por ID
//%token LLAVE_ABRE LLAVE_CIERRA
    //token por texto
//%token ';' '*' '/'

/*
forma alterna 
%token SUMA '+'
%token ID 'un_id'
*/
// precedencia
%left NOT
%left ROR
%left RAND 
%left IGUAL NOIGUAL
%left MAYOR MENOR MASMAS
%left OPSUMA OPRESTA
%left OPMULTIPLICACION OPDIVISION OPMODULO

/* fin de la definción de tipos*/

/* La clase que envuele al parser se pasa por referencia 
del parser al escaner evitando crear variables globales

*/

%lex-param {void *scanner} {yy::location& loc} { class OCL2Proyecto1::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Proyecto1::ParserCtx & ctx }

/* es posible hacer tipos personalizados para definir no terminales añadiendo lo siguiente
%union {
    std::string  cadenas;
}
*/

/*definicion de no terminales*/


%type<expression*> primitivo;
%type<call_exp*> call_expr;
%type<expression*> expresion;
%type<declaration*> declaracion;
%type<TipoDato> tipo;
%type<list_instruction*> inicio;
%type<func_printf*> func_printf;
%type<incremento*> incremento_instruccion;
%type<instruction*> asignacion;
%type<declaracion_sin_valor*> declaracion_sin_valor;
%type<instruction_if*> instruccion_if;
%type<list_instruction_second*> cuerpo_if;
%type<instruction*> instruccion_if_cuerpo;
%type<list_instruction_second*> list_elseif;
%type<list_instruction_second*> list_else;
%type<TipoDato> otro_tipo_func;
%type<instruction_while*> instruccion_while;
%type<list_instruction_second*> cuerpo_while;
%type<instruction*> instruccion_while_cuerpo;
%type<instruction_for*> instruccion_for;
%type<instruction*> declaracion_for;
%type<instruction*> incremento_for;
%type<list_instruction_second*> cuerpo_for;
%type<instruction*> instruccion_for_cuerpo;
%type<lista_expresiones*> lista_expresiones_printf;
//%type<declaracion_struct*> dec_struct;
%type<map_struct_dec*> dec_list; 
%type<create_struct*> creation_struct ; 
%type<expression*> llamada_variable; 
%type<create_vector*> declaracion_arreglo;
%type<expression*> op_vector;
%type<instruction*> instrucciones_vector;
%type<list_instruction*> list_func;
%type<instruction*>  funcion;
%type<map_struct_dec*> func_list;
%type<instruction*> instruccion_funcion;
%type<list_instruction*> list_inst_func;
%type<instruction_return*> instruccion_return;
%type<instruction*> call_instruction;


// printer
//%printer { yyoutput << $$; } <*>;

/*
inicio de la grámatica
*/
%%
/* produccion inicial */

%start inicio;

inicio  :   list_func   {   
                            $$ = $1;
                            ctx.Functions = $1;
                        }
;
list_func   :   list_func funcion       { 
                                            $1->newInst($2);
                                            $$ = $1;
                                        } 
            |   funcion                 {
                                            $$ = new list_instruction();
                                            $$->newInst($1);
                                        }
;

funcion     :   RINT ID PARABRE func_list PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA    {   $$ = new function(0,0,INTEGER,$2,$4,$7);         }
            |   RINT ID PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA              {   $$ = new function(0,0,INTEGER,$2,nullptr,$6);         }
            |   RINT R_MAIN PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA          {   
                                                                                                $$ = new func_main(0,0,INTEGER,$6);
                                                                                                ctx.Main = $6;
                                                                                            }
            |   RVOID ID PARABRE func_list PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA   {   $$ = new function(0,0,VOID,$2,$4,$7);    }
            |   RVOID ID PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA             {   $$ = new function(0,0,VOID,$2,nullptr,$6);    }
            |   RVOID R_MAIN PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA         {   
                                                                                                $$ = new func_main(0,0,INTEGER,$6);
                                                                                                ctx.Main = $6;
                                                                                            }
            |   otro_tipo_func ID PARABRE func_list PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA    {   $$ = new function(0,0,$1,$2,$4,$7);         }
            |   otro_tipo_func ID PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA    {   $$ = new function(0,0,$1,$2,nullptr,$6);           }
            |   RSTRUCT ID LLAVEABRE dec_list LLAVECIERRA   { $$ = new declaracion_struct(0, 0, $4, $2);      }      
;



dec_list    :   dec_list tipo ID PTCOMA     {
                                                $1->newMap($3,$2);
                                                $$ = $1;
                                            }
            |   tipo ID PTCOMA              {   
                                                $$ = new map_struct_dec();
                                                $$->newMap($2, $1);
                                            }
;
otro_tipo_func      :   RFLOAT      {   $$ = FLOAT;         }
                    |   RSTRING     {   $$ = STRING;        }
                    |   RBOOL       {   $$ = BOOL;          }
;


func_list   :   func_list COMA tipo ID  {
                                            $1->newMap($4,$3);
                                            $$ = $1;
                                        }
            |   tipo ID                 {   
                                            $$ = new map_struct_dec();
                                            $$->newMap($2, $1);
                                        }
;

list_inst_func  :   list_inst_func instruccion_funcion  { 
                                                            $1->newInst($2);
                                                            $$ = $1;
                                                        }
                |   instruccion_funcion                 {
                                                            $$ = new list_instruction();
                                                            $$->newInst($1);
                                                        }
;

instruccion_funcion     :   instruccion_return PTCOMA       {   $$ = $1 ;   }
                        |   declaracion PTCOMA              {   $$ = $1 ;   }
                        |   func_printf PTCOMA              {   $$ = $1 ;   }
                        |   incremento_instruccion PTCOMA   {   $$ = $1 ;   }
                        |   asignacion PTCOMA               {   $$ = $1 ;   }
                        |   declaracion_sin_valor PTCOMA    {   $$ = $1 ;   }
                        |   instruccion_if                  {   $$ = $1 ;   }
                        |   instruccion_while               {   $$ = $1 ;   }
                        |   instruccion_for                 {   $$ = $1 ;   }
                        |   declaracion_arreglo             {   $$ = $1 ;   }
                        |   creation_struct                 {   $$ = $1 ;   }
                        |   instrucciones_vector            {   $$ = $1 ;   }
                        |   call_instruction                {   $$ = $1 ;   }   
;

instruccion_return  :   RRETURN expresion   { $$ = new instruction_return(0,0,$2); }
                    |   RRETURN             { $$ = new instruction_return(0,0,nullptr); }
;





call_instruction    :   ID PARABRE lista_expresiones_printf PARCIERRA PTCOMA    {   $$ = new call_inst(0,0,$1,$3);          } 
                    |   ID PARABRE PARCIERRA PTCOMA                             {   $$ = new call_inst(0,0,$1,nullptr);     }
                    |   ID PUNTO ID IGUAL expresion PTCOMA                      {   $$ = new instruction_asign_struct(0,0,$1,$3,$5);}
;
instrucciones_vector    :   ID PUNTO RPUSHBACK PARABRE expresion PARCIERRA PTCOMA   {   $$ = new instruction_push_back(0,0,$1, $5);         }
                        |   ID PUNTO RPUSHFRONT PARABRE expresion PARCIERRA PTCOMA  {   $$ = new instruction_push_front(0,0,$1, $5);        }
                        |   ID PUNTO RREMOVE PARABRE expresion PARCIERRA PTCOMA     {   $$ = new instruction_vector_remove(0,0,$1, $5);     }          
;

declaracion_arreglo :   RVECTOR MENOR tipo MAYOR ID PTCOMA                                                  {   $$ = new create_vector(0, 0, $3, $5, nullptr);  }
                    |   RVECTOR MENOR tipo MAYOR ID IGUAL CORABRE lista_expresiones_printf CORCIERRA PTCOMA {   $$ = new create_vector(0, 0, $3, $5, $8);  }
                    |   RVECTOR MENOR tipo MAYOR ID IGUAL CORABRE CORCIERRA PTCOMA                          {   $$ = new create_vector(0, 0, $3, $5, nullptr);  }
;


creation_struct :       RSTRUCT ID ID IGUAL LLAVEABRE lista_expresiones_printf LLAVECIERRA PTCOMA   {
                                                                                                        $$ = new create_struct(0,0,$2,$3,$6);
                                                                                                    }
                    |   RSTRUCT ID ID PTCOMA    {   $$ = new create_struct(0,0,$2,$3,nullptr);   }
;

declaracion :   tipo ID IGUAL expresion       {  $$ = new declaration(0, 0, $2, $4, $1);    }
            
;

tipo :      RINT        {   $$ = INTEGER; }
        |   RFLOAT      {   $$ = FLOAT; }
        |   RSTRING     {   $$ = STRING; }
        |   RBOOL       {   $$ = BOOL; }
;

expresion :     expresion OPSUMA expresion                  { $$ = new operation(0, 0, $1, $3, "+"      );  }
            |   expresion OPRESTA expresion                 { $$ = new operation(0, 0, $1, $3, "-"      );  }
            |   expresion OPMULTIPLICACION expresion        { $$ = new operation(0, 0, $1, $3, "*"      );  }
            |   expresion OPDIVISION expresion              { $$ = new operation(0, 0, $1, $3, "/"      );  }
            |   expresion OPMODULO expresion                { $$ = new operation(0, 0, $1, $3, "%"      );  }
            |   expresion IGUAL IGUAL expresion             { $$ = new operation(0, 0, $1, $4, "=="     );  }
            |   expresion NOIGUAL expresion                 { $$ = new operation(0, 0, $1, $3, "!="     );  }
            |   expresion MAYOR expresion                   { $$ = new operation(0, 0, $1, $3, ">"      );  }
            |   expresion MENOR expresion                   { $$ = new operation(0, 0, $1, $3, "<"      );  }
            |   expresion MAYOR IGUAL expresion             { $$ = new operation(0, 0, $1, $4, ">="     );  }
            |   expresion MENOR IGUAL expresion             { $$ = new operation(0, 0, $1, $4, "<="     );  }
            |   expresion RAND expresion                    { $$ = new operation(0, 0, $1, $3, "&&"     );  }
            |   expresion ROR expresion                     { $$ = new operation(0, 0, $1, $3, "||"     );  }
            |   NOT expresion                               { $$ = new operation(0, 0, $2, $2, "!"      );  }
            |   MASMAS ID                                   { $$ = new incremento_expression(0, 0, $2, 1, "++1");  }
            |   ID  MASMAS                                  { $$ = new incremento_expression(0, 0, $1, 2, "++2");  }
            |   PARABRE   expresion PARCIERRA               { $$ = $2;                                      }
            |   OPRESTA expresion                           { $$ = new negacion_unaria(0, 0, $2);           }
            |   RATOI PARABRE expresion PARCIERRA           { $$ = new expr_atoi(0, 0, $3);                 }
            |   RATOF PARABRE expresion PARCIERRA           { $$ = new expr_atof(0, 0, $3);                 }
            |   RIOTA PARABRE expresion PARCIERRA           { $$ = new expr_iota(0, 0, $3);                 }
            |   op_vector                                   { $$ = $1;                                      }
            |   primitivo                                   { $$ = $1;                                      }
            |   RMEAN PARABRE ID PARCIERRA                  { $$ = new func_mean(0, 0, $3);                 }
            |   RMEDIAN PARABRE ID PARCIERRA                { $$ = new func_median(0, 0, $3);               }
            |   RMODE PARABRE ID PARCIERRA                  { $$ = new func_moda(0, 0, $3);                 }
            |   call_expr                                   { $$ = $1;                                      }           
;

call_expr   :   ID PARABRE lista_expresiones_printf PARCIERRA   {   $$ = new call_exp(0, 0, $1, $3);        }
            |   ID PARABRE PARCIERRA                            {   $$ = new call_exp(0, 0, $1, nullptr);   }
;

primitivo :     TIPO_INTEGER            {   
                                            primitive *tmp = new primitive(0, 0, INTEGER,"",    std::stoi($1),  0.0, false);
                                            $$ = tmp ;
                                        }      
            |   TIPO_STRING             {   std::string cadena = $1.erase(0,1);
                                            $$ = new primitive(0,0,STRING, cadena.erase(cadena.length()-1,1),0,0.0, false);
                                        }
            |   TIPO_FLOAT              {   $$ = new primitive(0, 0, FLOAT, "",     0,  std::stof($1),  false); }
            |   TIPO_BOOL_TRUE          {   $$ = new primitive(0, 0, BOOL,  "",     0,  0.0,            true);  }
            |   TIPO_BOOL_FALSE         {   $$ = new primitive(0, 0, BOOL,  "",     0,  0.0,            false); }
            |   llamada_variable        {   $$ = $1;                                                            }
;

op_vector   :   ID CORABRE expresion CORCIERRA              {   $$ = new vector_access(0, 0, $1, $3);           }
            |   ID PUNTO RGET PARABRE expresion PARCIERRA   {   $$ = new vector_access(0, 0, $1, $5);           }
            |   ID PUNTO RSIZE PARABRE PARCIERRA            {   $$ = new expr_size_vector(0, 0, $1);            }
;

llamada_variable    :   ID              {   $$ = new llamada_variable(0, 0, $1);    }
                    |   ID PUNTO ID     {   $$ = new struct_access(0, 0, new llamada_variable(0,0,$1), $3);   }
;

func_printf :   RPRINTF PARABRE lista_expresiones_printf PARCIERRA  { $$ = new func_printf(0,0, $3);            }
;

lista_expresiones_printf    :   lista_expresiones_printf COMA expresion         { 
                                                                                    $1->newExpr($3);
                                                                                    $$ = $1;
                                                                                }      
                            |   expresion                                       {
                                                                                    $$ = new lista_expresiones();
                                                                                    $$->newExpr($1);
                                                                                }
;

incremento_instruccion  :   ID MASMAS                    { $$ = new incremento(0,0, $1);  }
                        |   MASMAS ID                    { $$ = new incremento(0,0, $2);  }
;

asignacion  :   ID IGUAL expresion                              { $$ = new asignacion_variable(0, 0, $1, $3);                   }
            |   ID CORABRE expresion CORCIERRA IGUAL expresion  { $$ = new instruction_vector_asignacion(0, 0, $1, $3, $6);     }
;

declaracion_sin_valor    :  tipo ID                             { $$ = new declaracion_sin_valor(0,0,$2 , $1);  }
;

instruccion_if  :   R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA list_elseif list_else  {   $$ = new instruction_if(0,0,$3, $6,$8, $9);}
                |   R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA list_elseif            {   $$ = new instruction_if(0,0,$3, $6,$8, nullptr);}
                |   R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA list_else              {   $$ = new instruction_if(0,0,$3, $6,nullptr, $8);}
                |   R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA                        {   $$ = new instruction_if(0,0,$3, $6,nullptr, nullptr);}
;

cuerpo_if   :   cuerpo_if instruccion_if_cuerpo     { 
                                                        $1->newInst($2);
                                                        $$ = $1;
                                                    } 
            |   instruccion_if_cuerpo               {
                                                        $$ = new list_instruction_second();
                                                        $$->newInst($1);
                                                    }
;

instruccion_if_cuerpo   :   func_printf PTCOMA                  {   $$ = $1;                                }
                        |   instruccion_for                     {   $$ = $1;                                }
                        |   instruccion_if                      {   $$ = $1;                                }
                        |   incremento_instruccion PTCOMA       {   $$ = $1;                                }
                        |   asignacion PTCOMA                   {   $$ = $1;                                }
                        |   RBREAK PTCOMA                       {   $$ = new instruction_break(0,0);        }
                        |   RCONTINUE PTCOMA                    {   $$ = new instruction_continue(0,0);     }
                        |   instruccion_while                   {   $$ = $1;                                }
                        |   declaracion PTCOMA                  {   $$ = $1;                                }
                        |   declaracion_sin_valor PTCOMA        {   $$ = $1;                                }
                        |   creation_struct                 {   $$ = $1 ;   }
                        |   declaracion_arreglo             {   $$ = $1 ;   }
                        |   instrucciones_vector            {   $$ = $1 ;   }
                        |   instruccion_return PTCOMA       {   $$ = $1 ;   }
;

list_elseif :   list_elseif R_ELSE R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA     {
                                                                                                            $1->newInst(new instruction_if(0,0,$5,$8, nullptr, nullptr));
                                                                                                            $$ = $1;
                                                                                                        }
            |   R_ELSE R_IF PARABRE expresion PARCIERRA  LLAVEABRE cuerpo_if LLAVECIERRA                {
                                                                                                            $$ = new list_instruction_second();
                                                                                                            $$->newInst(new instruction_if(0,0,$4,$7, nullptr, nullptr));
                                                                                                        }
            
;

list_else   :   R_ELSE LLAVEABRE cuerpo_if LLAVECIERRA                                                   {   $$ = $3;    }
;

instruccion_while   :   RWHILE PARABRE expresion PARCIERRA LLAVEABRE cuerpo_while LLAVECIERRA               {
                                                                                                                $$ = new instruction_while(0,0,$3,$6);
                                                                                                            }
;

cuerpo_while    :   cuerpo_while instruccion_while_cuerpo       {  
                                                                    $1->newInst($2);
                                                                    $$ = $1;
                                                                } 
                |   instruccion_while_cuerpo                    {
                                                                    $$ = new list_instruction_second();
                                                                    $$->newInst($1);
                                                                }
;

instruccion_while_cuerpo    :   func_printf PTCOMA                  {   $$ = $1;                                }
                            |   instruccion_for                     {   $$ = $1;                                }
                            |   instruccion_if                      {   $$ = $1;                                }
                            |   incremento_instruccion PTCOMA       {   $$ = $1;                                }
                            |   asignacion PTCOMA                   {   $$ = $1;                                }
                            |   RBREAK PTCOMA                       {   $$ = new instruction_break(0,0);        }
                            |   RCONTINUE PTCOMA                    {   $$ = new instruction_continue(0,0);     }
                            |   instruccion_while                   {   $$ = $1;                                }
                            |   declaracion PTCOMA                  {   $$ = $1;                                }
                            |   declaracion_sin_valor PTCOMA        {   $$ = $1;                                }
                            |   creation_struct                     {   $$ = $1 ;   }
                            |   declaracion_arreglo                 {   $$ = $1 ;   }
                            |   instrucciones_vector                {   $$ = $1 ;   }
                            |   instruccion_return PTCOMA           {   $$ = $1 ;   }
;

instruccion_for :   RFOR PARABRE declaracion_for PTCOMA expresion PTCOMA incremento_for PARCIERRA LLAVEABRE cuerpo_for LLAVECIERRA { $$ = new instruction_for(0, 0, $3, $5, $7, $10); }
;

declaracion_for :   declaracion             {   $$ = $1;    }
                |   asignacion              {   $$ = $1;    }
                |   declaracion_sin_valor   {   $$ = $1;    }
;

incremento_for  :   asignacion              { $$ = $1;    }
                |   incremento_instruccion  { $$ = $1;    }            
;

cuerpo_for      :   cuerpo_for instruccion_for_cuerpo   {  
                                                            $1->newInst($2);
                                                            $$ = $1;
                                                        } 
                |   instruccion_for_cuerpo              {
                                                            $$ = new list_instruction_second();
                                                            $$->newInst($1);
                                                        }
;

instruccion_for_cuerpo  :   func_printf PTCOMA                  {   $$ = $1;                                }
                        |   instruccion_for                     {   $$ = $1;                                }
                        |   instruccion_if                      {   $$ = $1;                                }
                        |   incremento_instruccion PTCOMA       {   $$ = $1;                                }
                        |   asignacion PTCOMA                   {   $$ = $1;                                }
                        |   RBREAK PTCOMA                       {   $$ = new instruction_break(0,0);        }
                        |   RCONTINUE PTCOMA                    {   $$ = new instruction_continue(0,0);     }
                        |   instruccion_while                   {   $$ = $1;                                }
                        |   declaracion PTCOMA                  {   $$ = $1;                                }
                        |   declaracion_sin_valor PTCOMA        {   $$ = $1;                                }
                        |   creation_struct                     {   $$ = $1 ;   }
                        |   declaracion_arreglo                 {   $$ = $1 ;   }
                        |   instrucciones_vector                {   $$ = $1 ;   }
                        |   instruccion_return PTCOMA       {   $$ = $1 ;   }
;

%%


void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
    ctx.erroresEncontrados  = true;
    std::string contenido = "";
    contenido += m;
    error_analisis *ero = new error_analisis(l.begin.line, l.begin.column,2, contenido);
    ctx.lista_errores.push_back(ero);
}

