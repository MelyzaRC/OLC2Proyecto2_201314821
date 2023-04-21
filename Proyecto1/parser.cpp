// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 103 "parser.y"

yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Proyecto1::ParserCtx & ctx);

#line 50 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 142 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (void *scanner_yyarg, yy::location& loc_yyarg, class OCL2Proyecto1::ParserCtx & ctx_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      ctx (ctx_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_otro_tipo_func: // otro_tipo_func
      case symbol_kind::S_tipo: // tipo
        value.YY_MOVE_OR_COPY< TipoDato > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_expr: // call_expr
        value.YY_MOVE_OR_COPY< call_exp* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_creation_struct: // creation_struct
        value.YY_MOVE_OR_COPY< create_struct* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaracion_arreglo: // declaracion_arreglo
        value.YY_MOVE_OR_COPY< create_vector* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaracion_sin_valor: // declaracion_sin_valor
        value.YY_MOVE_OR_COPY< declaracion_sin_valor* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaracion: // declaracion
        value.YY_MOVE_OR_COPY< declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_primitivo: // primitivo
      case symbol_kind::S_op_vector: // op_vector
      case symbol_kind::S_llamada_variable: // llamada_variable
        value.YY_MOVE_OR_COPY< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_printf: // func_printf
        value.YY_MOVE_OR_COPY< func_printf* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_incremento_instruccion: // incremento_instruccion
        value.YY_MOVE_OR_COPY< incremento* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_instruccion_funcion: // instruccion_funcion
      case symbol_kind::S_call_instruction: // call_instruction
      case symbol_kind::S_instrucciones_vector: // instrucciones_vector
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_instruccion_if_cuerpo: // instruccion_if_cuerpo
      case symbol_kind::S_instruccion_while_cuerpo: // instruccion_while_cuerpo
      case symbol_kind::S_declaracion_for: // declaracion_for
      case symbol_kind::S_incremento_for: // incremento_for
      case symbol_kind::S_instruccion_for_cuerpo: // instruccion_for_cuerpo
        value.YY_MOVE_OR_COPY< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_for: // instruccion_for
        value.YY_MOVE_OR_COPY< instruction_for* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_if: // instruccion_if
        value.YY_MOVE_OR_COPY< instruction_if* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_return: // instruccion_return
        value.YY_MOVE_OR_COPY< instruction_return* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_while: // instruccion_while
        value.YY_MOVE_OR_COPY< instruction_while* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_inicio: // inicio
      case symbol_kind::S_list_func: // list_func
      case symbol_kind::S_list_inst_func: // list_inst_func
        value.YY_MOVE_OR_COPY< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cuerpo_if: // cuerpo_if
      case symbol_kind::S_list_elseif: // list_elseif
      case symbol_kind::S_list_else: // list_else
      case symbol_kind::S_cuerpo_while: // cuerpo_while
      case symbol_kind::S_cuerpo_for: // cuerpo_for
        value.YY_MOVE_OR_COPY< list_instruction_second* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_expresiones_printf: // lista_expresiones_printf
        value.YY_MOVE_OR_COPY< lista_expresiones* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dec_list: // dec_list
      case symbol_kind::S_func_list: // func_list
        value.YY_MOVE_OR_COPY< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LLAVEABRE: // LLAVEABRE
      case symbol_kind::S_LLAVECIERRA: // LLAVECIERRA
      case symbol_kind::S_RINT: // RINT
      case symbol_kind::S_RFLOAT: // RFLOAT
      case symbol_kind::S_RSTRING: // RSTRING
      case symbol_kind::S_RBOOL: // RBOOL
      case symbol_kind::S_RPRINTF: // RPRINTF
      case symbol_kind::S_IGUAL: // IGUAL
      case symbol_kind::S_PTCOMA: // PTCOMA
      case symbol_kind::S_OPSUMA: // OPSUMA
      case symbol_kind::S_OPRESTA: // OPRESTA
      case symbol_kind::S_OPMULTIPLICACION: // OPMULTIPLICACION
      case symbol_kind::S_OPDIVISION: // OPDIVISION
      case symbol_kind::S_OPMODULO: // OPMODULO
      case symbol_kind::S_PARABRE: // PARABRE
      case symbol_kind::S_PARCIERRA: // PARCIERRA
      case symbol_kind::S_TIPO_INTEGER: // TIPO_INTEGER
      case symbol_kind::S_TIPO_FLOAT: // TIPO_FLOAT
      case symbol_kind::S_TIPO_STRING: // TIPO_STRING
      case symbol_kind::S_TIPO_BOOL_TRUE: // TIPO_BOOL_TRUE
      case symbol_kind::S_TIPO_BOOL_FALSE: // TIPO_BOOL_FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_R_IF: // R_IF
      case symbol_kind::S_R_ELSE: // R_ELSE
      case symbol_kind::S_R_MAIN: // R_MAIN
      case symbol_kind::S_RVOID: // RVOID
      case symbol_kind::S_RAND: // RAND
      case symbol_kind::S_ROR: // ROR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_NOIGUAL: // NOIGUAL
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_MASMAS: // MASMAS
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_COMA: // COMA
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_PUNTO: // PUNTO
      case symbol_kind::S_RVECTOR: // RVECTOR
      case symbol_kind::S_CORABRE: // CORABRE
      case symbol_kind::S_CORCIERRA: // CORCIERRA
      case symbol_kind::S_RGET: // RGET
      case symbol_kind::S_RSIZE: // RSIZE
      case symbol_kind::S_RPUSHBACK: // RPUSHBACK
      case symbol_kind::S_RPUSHFRONT: // RPUSHFRONT
      case symbol_kind::S_RREMOVE: // RREMOVE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_otro_tipo_func: // otro_tipo_func
      case symbol_kind::S_tipo: // tipo
        value.move< TipoDato > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_expr: // call_expr
        value.move< call_exp* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_creation_struct: // creation_struct
        value.move< create_struct* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaracion_arreglo: // declaracion_arreglo
        value.move< create_vector* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaracion_sin_valor: // declaracion_sin_valor
        value.move< declaracion_sin_valor* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaracion: // declaracion
        value.move< declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_primitivo: // primitivo
      case symbol_kind::S_op_vector: // op_vector
      case symbol_kind::S_llamada_variable: // llamada_variable
        value.move< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_printf: // func_printf
        value.move< func_printf* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_incremento_instruccion: // incremento_instruccion
        value.move< incremento* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_instruccion_funcion: // instruccion_funcion
      case symbol_kind::S_call_instruction: // call_instruction
      case symbol_kind::S_instrucciones_vector: // instrucciones_vector
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_instruccion_if_cuerpo: // instruccion_if_cuerpo
      case symbol_kind::S_instruccion_while_cuerpo: // instruccion_while_cuerpo
      case symbol_kind::S_declaracion_for: // declaracion_for
      case symbol_kind::S_incremento_for: // incremento_for
      case symbol_kind::S_instruccion_for_cuerpo: // instruccion_for_cuerpo
        value.move< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_for: // instruccion_for
        value.move< instruction_for* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_if: // instruccion_if
        value.move< instruction_if* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_return: // instruccion_return
        value.move< instruction_return* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_while: // instruccion_while
        value.move< instruction_while* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_inicio: // inicio
      case symbol_kind::S_list_func: // list_func
      case symbol_kind::S_list_inst_func: // list_inst_func
        value.move< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cuerpo_if: // cuerpo_if
      case symbol_kind::S_list_elseif: // list_elseif
      case symbol_kind::S_list_else: // list_else
      case symbol_kind::S_cuerpo_while: // cuerpo_while
      case symbol_kind::S_cuerpo_for: // cuerpo_for
        value.move< list_instruction_second* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_expresiones_printf: // lista_expresiones_printf
        value.move< lista_expresiones* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dec_list: // dec_list
      case symbol_kind::S_func_list: // func_list
        value.move< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LLAVEABRE: // LLAVEABRE
      case symbol_kind::S_LLAVECIERRA: // LLAVECIERRA
      case symbol_kind::S_RINT: // RINT
      case symbol_kind::S_RFLOAT: // RFLOAT
      case symbol_kind::S_RSTRING: // RSTRING
      case symbol_kind::S_RBOOL: // RBOOL
      case symbol_kind::S_RPRINTF: // RPRINTF
      case symbol_kind::S_IGUAL: // IGUAL
      case symbol_kind::S_PTCOMA: // PTCOMA
      case symbol_kind::S_OPSUMA: // OPSUMA
      case symbol_kind::S_OPRESTA: // OPRESTA
      case symbol_kind::S_OPMULTIPLICACION: // OPMULTIPLICACION
      case symbol_kind::S_OPDIVISION: // OPDIVISION
      case symbol_kind::S_OPMODULO: // OPMODULO
      case symbol_kind::S_PARABRE: // PARABRE
      case symbol_kind::S_PARCIERRA: // PARCIERRA
      case symbol_kind::S_TIPO_INTEGER: // TIPO_INTEGER
      case symbol_kind::S_TIPO_FLOAT: // TIPO_FLOAT
      case symbol_kind::S_TIPO_STRING: // TIPO_STRING
      case symbol_kind::S_TIPO_BOOL_TRUE: // TIPO_BOOL_TRUE
      case symbol_kind::S_TIPO_BOOL_FALSE: // TIPO_BOOL_FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_R_IF: // R_IF
      case symbol_kind::S_R_ELSE: // R_ELSE
      case symbol_kind::S_R_MAIN: // R_MAIN
      case symbol_kind::S_RVOID: // RVOID
      case symbol_kind::S_RAND: // RAND
      case symbol_kind::S_ROR: // ROR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_NOIGUAL: // NOIGUAL
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_MASMAS: // MASMAS
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_COMA: // COMA
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_PUNTO: // PUNTO
      case symbol_kind::S_RVECTOR: // RVECTOR
      case symbol_kind::S_CORABRE: // CORABRE
      case symbol_kind::S_CORCIERRA: // CORCIERRA
      case symbol_kind::S_RGET: // RGET
      case symbol_kind::S_RSIZE: // RSIZE
      case symbol_kind::S_RPUSHBACK: // RPUSHBACK
      case symbol_kind::S_RPUSHFRONT: // RPUSHFRONT
      case symbol_kind::S_RREMOVE: // RREMOVE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_otro_tipo_func: // otro_tipo_func
      case symbol_kind::S_tipo: // tipo
        value.copy< TipoDato > (that.value);
        break;

      case symbol_kind::S_call_expr: // call_expr
        value.copy< call_exp* > (that.value);
        break;

      case symbol_kind::S_creation_struct: // creation_struct
        value.copy< create_struct* > (that.value);
        break;

      case symbol_kind::S_declaracion_arreglo: // declaracion_arreglo
        value.copy< create_vector* > (that.value);
        break;

      case symbol_kind::S_declaracion_sin_valor: // declaracion_sin_valor
        value.copy< declaracion_sin_valor* > (that.value);
        break;

      case symbol_kind::S_declaracion: // declaracion
        value.copy< declaration* > (that.value);
        break;

      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_primitivo: // primitivo
      case symbol_kind::S_op_vector: // op_vector
      case symbol_kind::S_llamada_variable: // llamada_variable
        value.copy< expression* > (that.value);
        break;

      case symbol_kind::S_func_printf: // func_printf
        value.copy< func_printf* > (that.value);
        break;

      case symbol_kind::S_incremento_instruccion: // incremento_instruccion
        value.copy< incremento* > (that.value);
        break;

      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_instruccion_funcion: // instruccion_funcion
      case symbol_kind::S_call_instruction: // call_instruction
      case symbol_kind::S_instrucciones_vector: // instrucciones_vector
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_instruccion_if_cuerpo: // instruccion_if_cuerpo
      case symbol_kind::S_instruccion_while_cuerpo: // instruccion_while_cuerpo
      case symbol_kind::S_declaracion_for: // declaracion_for
      case symbol_kind::S_incremento_for: // incremento_for
      case symbol_kind::S_instruccion_for_cuerpo: // instruccion_for_cuerpo
        value.copy< instruction* > (that.value);
        break;

      case symbol_kind::S_instruccion_for: // instruccion_for
        value.copy< instruction_for* > (that.value);
        break;

      case symbol_kind::S_instruccion_if: // instruccion_if
        value.copy< instruction_if* > (that.value);
        break;

      case symbol_kind::S_instruccion_return: // instruccion_return
        value.copy< instruction_return* > (that.value);
        break;

      case symbol_kind::S_instruccion_while: // instruccion_while
        value.copy< instruction_while* > (that.value);
        break;

      case symbol_kind::S_inicio: // inicio
      case symbol_kind::S_list_func: // list_func
      case symbol_kind::S_list_inst_func: // list_inst_func
        value.copy< list_instruction* > (that.value);
        break;

      case symbol_kind::S_cuerpo_if: // cuerpo_if
      case symbol_kind::S_list_elseif: // list_elseif
      case symbol_kind::S_list_else: // list_else
      case symbol_kind::S_cuerpo_while: // cuerpo_while
      case symbol_kind::S_cuerpo_for: // cuerpo_for
        value.copy< list_instruction_second* > (that.value);
        break;

      case symbol_kind::S_lista_expresiones_printf: // lista_expresiones_printf
        value.copy< lista_expresiones* > (that.value);
        break;

      case symbol_kind::S_dec_list: // dec_list
      case symbol_kind::S_func_list: // func_list
        value.copy< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_LLAVEABRE: // LLAVEABRE
      case symbol_kind::S_LLAVECIERRA: // LLAVECIERRA
      case symbol_kind::S_RINT: // RINT
      case symbol_kind::S_RFLOAT: // RFLOAT
      case symbol_kind::S_RSTRING: // RSTRING
      case symbol_kind::S_RBOOL: // RBOOL
      case symbol_kind::S_RPRINTF: // RPRINTF
      case symbol_kind::S_IGUAL: // IGUAL
      case symbol_kind::S_PTCOMA: // PTCOMA
      case symbol_kind::S_OPSUMA: // OPSUMA
      case symbol_kind::S_OPRESTA: // OPRESTA
      case symbol_kind::S_OPMULTIPLICACION: // OPMULTIPLICACION
      case symbol_kind::S_OPDIVISION: // OPDIVISION
      case symbol_kind::S_OPMODULO: // OPMODULO
      case symbol_kind::S_PARABRE: // PARABRE
      case symbol_kind::S_PARCIERRA: // PARCIERRA
      case symbol_kind::S_TIPO_INTEGER: // TIPO_INTEGER
      case symbol_kind::S_TIPO_FLOAT: // TIPO_FLOAT
      case symbol_kind::S_TIPO_STRING: // TIPO_STRING
      case symbol_kind::S_TIPO_BOOL_TRUE: // TIPO_BOOL_TRUE
      case symbol_kind::S_TIPO_BOOL_FALSE: // TIPO_BOOL_FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_R_IF: // R_IF
      case symbol_kind::S_R_ELSE: // R_ELSE
      case symbol_kind::S_R_MAIN: // R_MAIN
      case symbol_kind::S_RVOID: // RVOID
      case symbol_kind::S_RAND: // RAND
      case symbol_kind::S_ROR: // ROR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_NOIGUAL: // NOIGUAL
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_MASMAS: // MASMAS
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_COMA: // COMA
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_PUNTO: // PUNTO
      case symbol_kind::S_RVECTOR: // RVECTOR
      case symbol_kind::S_CORABRE: // CORABRE
      case symbol_kind::S_CORCIERRA: // CORCIERRA
      case symbol_kind::S_RGET: // RGET
      case symbol_kind::S_RSIZE: // RSIZE
      case symbol_kind::S_RPUSHBACK: // RPUSHBACK
      case symbol_kind::S_RPUSHFRONT: // RPUSHFRONT
      case symbol_kind::S_RREMOVE: // RREMOVE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_otro_tipo_func: // otro_tipo_func
      case symbol_kind::S_tipo: // tipo
        value.move< TipoDato > (that.value);
        break;

      case symbol_kind::S_call_expr: // call_expr
        value.move< call_exp* > (that.value);
        break;

      case symbol_kind::S_creation_struct: // creation_struct
        value.move< create_struct* > (that.value);
        break;

      case symbol_kind::S_declaracion_arreglo: // declaracion_arreglo
        value.move< create_vector* > (that.value);
        break;

      case symbol_kind::S_declaracion_sin_valor: // declaracion_sin_valor
        value.move< declaracion_sin_valor* > (that.value);
        break;

      case symbol_kind::S_declaracion: // declaracion
        value.move< declaration* > (that.value);
        break;

      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_primitivo: // primitivo
      case symbol_kind::S_op_vector: // op_vector
      case symbol_kind::S_llamada_variable: // llamada_variable
        value.move< expression* > (that.value);
        break;

      case symbol_kind::S_func_printf: // func_printf
        value.move< func_printf* > (that.value);
        break;

      case symbol_kind::S_incremento_instruccion: // incremento_instruccion
        value.move< incremento* > (that.value);
        break;

      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_instruccion_funcion: // instruccion_funcion
      case symbol_kind::S_call_instruction: // call_instruction
      case symbol_kind::S_instrucciones_vector: // instrucciones_vector
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_instruccion_if_cuerpo: // instruccion_if_cuerpo
      case symbol_kind::S_instruccion_while_cuerpo: // instruccion_while_cuerpo
      case symbol_kind::S_declaracion_for: // declaracion_for
      case symbol_kind::S_incremento_for: // incremento_for
      case symbol_kind::S_instruccion_for_cuerpo: // instruccion_for_cuerpo
        value.move< instruction* > (that.value);
        break;

      case symbol_kind::S_instruccion_for: // instruccion_for
        value.move< instruction_for* > (that.value);
        break;

      case symbol_kind::S_instruccion_if: // instruccion_if
        value.move< instruction_if* > (that.value);
        break;

      case symbol_kind::S_instruccion_return: // instruccion_return
        value.move< instruction_return* > (that.value);
        break;

      case symbol_kind::S_instruccion_while: // instruccion_while
        value.move< instruction_while* > (that.value);
        break;

      case symbol_kind::S_inicio: // inicio
      case symbol_kind::S_list_func: // list_func
      case symbol_kind::S_list_inst_func: // list_inst_func
        value.move< list_instruction* > (that.value);
        break;

      case symbol_kind::S_cuerpo_if: // cuerpo_if
      case symbol_kind::S_list_elseif: // list_elseif
      case symbol_kind::S_list_else: // list_else
      case symbol_kind::S_cuerpo_while: // cuerpo_while
      case symbol_kind::S_cuerpo_for: // cuerpo_for
        value.move< list_instruction_second* > (that.value);
        break;

      case symbol_kind::S_lista_expresiones_printf: // lista_expresiones_printf
        value.move< lista_expresiones* > (that.value);
        break;

      case symbol_kind::S_dec_list: // dec_list
      case symbol_kind::S_func_list: // func_list
        value.move< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_LLAVEABRE: // LLAVEABRE
      case symbol_kind::S_LLAVECIERRA: // LLAVECIERRA
      case symbol_kind::S_RINT: // RINT
      case symbol_kind::S_RFLOAT: // RFLOAT
      case symbol_kind::S_RSTRING: // RSTRING
      case symbol_kind::S_RBOOL: // RBOOL
      case symbol_kind::S_RPRINTF: // RPRINTF
      case symbol_kind::S_IGUAL: // IGUAL
      case symbol_kind::S_PTCOMA: // PTCOMA
      case symbol_kind::S_OPSUMA: // OPSUMA
      case symbol_kind::S_OPRESTA: // OPRESTA
      case symbol_kind::S_OPMULTIPLICACION: // OPMULTIPLICACION
      case symbol_kind::S_OPDIVISION: // OPDIVISION
      case symbol_kind::S_OPMODULO: // OPMODULO
      case symbol_kind::S_PARABRE: // PARABRE
      case symbol_kind::S_PARCIERRA: // PARCIERRA
      case symbol_kind::S_TIPO_INTEGER: // TIPO_INTEGER
      case symbol_kind::S_TIPO_FLOAT: // TIPO_FLOAT
      case symbol_kind::S_TIPO_STRING: // TIPO_STRING
      case symbol_kind::S_TIPO_BOOL_TRUE: // TIPO_BOOL_TRUE
      case symbol_kind::S_TIPO_BOOL_FALSE: // TIPO_BOOL_FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_R_IF: // R_IF
      case symbol_kind::S_R_ELSE: // R_ELSE
      case symbol_kind::S_R_MAIN: // R_MAIN
      case symbol_kind::S_RVOID: // RVOID
      case symbol_kind::S_RAND: // RAND
      case symbol_kind::S_ROR: // ROR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_NOIGUAL: // NOIGUAL
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_MASMAS: // MASMAS
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_COMA: // COMA
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_PUNTO: // PUNTO
      case symbol_kind::S_RVECTOR: // RVECTOR
      case symbol_kind::S_CORABRE: // CORABRE
      case symbol_kind::S_CORCIERRA: // CORCIERRA
      case symbol_kind::S_RGET: // RGET
      case symbol_kind::S_RSIZE: // RSIZE
      case symbol_kind::S_RPUSHBACK: // RPUSHBACK
      case symbol_kind::S_RPUSHFRONT: // RPUSHFRONT
      case symbol_kind::S_RREMOVE: // RREMOVE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, loc, ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_otro_tipo_func: // otro_tipo_func
      case symbol_kind::S_tipo: // tipo
        yylhs.value.emplace< TipoDato > ();
        break;

      case symbol_kind::S_call_expr: // call_expr
        yylhs.value.emplace< call_exp* > ();
        break;

      case symbol_kind::S_creation_struct: // creation_struct
        yylhs.value.emplace< create_struct* > ();
        break;

      case symbol_kind::S_declaracion_arreglo: // declaracion_arreglo
        yylhs.value.emplace< create_vector* > ();
        break;

      case symbol_kind::S_declaracion_sin_valor: // declaracion_sin_valor
        yylhs.value.emplace< declaracion_sin_valor* > ();
        break;

      case symbol_kind::S_declaracion: // declaracion
        yylhs.value.emplace< declaration* > ();
        break;

      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_primitivo: // primitivo
      case symbol_kind::S_op_vector: // op_vector
      case symbol_kind::S_llamada_variable: // llamada_variable
        yylhs.value.emplace< expression* > ();
        break;

      case symbol_kind::S_func_printf: // func_printf
        yylhs.value.emplace< func_printf* > ();
        break;

      case symbol_kind::S_incremento_instruccion: // incremento_instruccion
        yylhs.value.emplace< incremento* > ();
        break;

      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_instruccion_funcion: // instruccion_funcion
      case symbol_kind::S_call_instruction: // call_instruction
      case symbol_kind::S_instrucciones_vector: // instrucciones_vector
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_instruccion_if_cuerpo: // instruccion_if_cuerpo
      case symbol_kind::S_instruccion_while_cuerpo: // instruccion_while_cuerpo
      case symbol_kind::S_declaracion_for: // declaracion_for
      case symbol_kind::S_incremento_for: // incremento_for
      case symbol_kind::S_instruccion_for_cuerpo: // instruccion_for_cuerpo
        yylhs.value.emplace< instruction* > ();
        break;

      case symbol_kind::S_instruccion_for: // instruccion_for
        yylhs.value.emplace< instruction_for* > ();
        break;

      case symbol_kind::S_instruccion_if: // instruccion_if
        yylhs.value.emplace< instruction_if* > ();
        break;

      case symbol_kind::S_instruccion_return: // instruccion_return
        yylhs.value.emplace< instruction_return* > ();
        break;

      case symbol_kind::S_instruccion_while: // instruccion_while
        yylhs.value.emplace< instruction_while* > ();
        break;

      case symbol_kind::S_inicio: // inicio
      case symbol_kind::S_list_func: // list_func
      case symbol_kind::S_list_inst_func: // list_inst_func
        yylhs.value.emplace< list_instruction* > ();
        break;

      case symbol_kind::S_cuerpo_if: // cuerpo_if
      case symbol_kind::S_list_elseif: // list_elseif
      case symbol_kind::S_list_else: // list_else
      case symbol_kind::S_cuerpo_while: // cuerpo_while
      case symbol_kind::S_cuerpo_for: // cuerpo_for
        yylhs.value.emplace< list_instruction_second* > ();
        break;

      case symbol_kind::S_lista_expresiones_printf: // lista_expresiones_printf
        yylhs.value.emplace< lista_expresiones* > ();
        break;

      case symbol_kind::S_dec_list: // dec_list
      case symbol_kind::S_func_list: // func_list
        yylhs.value.emplace< map_struct_dec* > ();
        break;

      case symbol_kind::S_LLAVEABRE: // LLAVEABRE
      case symbol_kind::S_LLAVECIERRA: // LLAVECIERRA
      case symbol_kind::S_RINT: // RINT
      case symbol_kind::S_RFLOAT: // RFLOAT
      case symbol_kind::S_RSTRING: // RSTRING
      case symbol_kind::S_RBOOL: // RBOOL
      case symbol_kind::S_RPRINTF: // RPRINTF
      case symbol_kind::S_IGUAL: // IGUAL
      case symbol_kind::S_PTCOMA: // PTCOMA
      case symbol_kind::S_OPSUMA: // OPSUMA
      case symbol_kind::S_OPRESTA: // OPRESTA
      case symbol_kind::S_OPMULTIPLICACION: // OPMULTIPLICACION
      case symbol_kind::S_OPDIVISION: // OPDIVISION
      case symbol_kind::S_OPMODULO: // OPMODULO
      case symbol_kind::S_PARABRE: // PARABRE
      case symbol_kind::S_PARCIERRA: // PARCIERRA
      case symbol_kind::S_TIPO_INTEGER: // TIPO_INTEGER
      case symbol_kind::S_TIPO_FLOAT: // TIPO_FLOAT
      case symbol_kind::S_TIPO_STRING: // TIPO_STRING
      case symbol_kind::S_TIPO_BOOL_TRUE: // TIPO_BOOL_TRUE
      case symbol_kind::S_TIPO_BOOL_FALSE: // TIPO_BOOL_FALSE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_R_IF: // R_IF
      case symbol_kind::S_R_ELSE: // R_ELSE
      case symbol_kind::S_R_MAIN: // R_MAIN
      case symbol_kind::S_RVOID: // RVOID
      case symbol_kind::S_RAND: // RAND
      case symbol_kind::S_ROR: // ROR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_NOIGUAL: // NOIGUAL
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_MASMAS: // MASMAS
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_COMA: // COMA
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_PUNTO: // PUNTO
      case symbol_kind::S_RVECTOR: // RVECTOR
      case symbol_kind::S_CORABRE: // CORABRE
      case symbol_kind::S_CORCIERRA: // CORCIERRA
      case symbol_kind::S_RGET: // RGET
      case symbol_kind::S_RSIZE: // RSIZE
      case symbol_kind::S_RPUSHBACK: // RPUSHBACK
      case symbol_kind::S_RPUSHFRONT: // RPUSHFRONT
      case symbol_kind::S_RREMOVE: // RREMOVE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // inicio: list_func
#line 260 "parser.y"
                        {   
                            yylhs.value.as < list_instruction* > () = yystack_[0].value.as < list_instruction* > ();
                            ctx.Functions = yystack_[0].value.as < list_instruction* > ();
                        }
#line 1291 "parser.cpp"
    break;

  case 3: // list_func: list_func funcion
#line 265 "parser.y"
                                        { 
                                            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
                                        }
#line 1300 "parser.cpp"
    break;

  case 4: // list_func: funcion
#line 269 "parser.y"
                                        {
                                            yylhs.value.as < list_instruction* > () = new list_instruction();
                                            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                        }
#line 1309 "parser.cpp"
    break;

  case 5: // funcion: RINT ID PARABRE func_list PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA
#line 275 "parser.y"
                                                                                            {   yylhs.value.as < instruction* > () = new function(0,0,INTEGER,yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());         }
#line 1315 "parser.cpp"
    break;

  case 6: // funcion: RINT ID PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA
#line 276 "parser.y"
                                                                                            {   yylhs.value.as < instruction* > () = new function(0,0,INTEGER,yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());         }
#line 1321 "parser.cpp"
    break;

  case 7: // funcion: RINT R_MAIN PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA
#line 277 "parser.y"
                                                                                            {   
                                                                                                yylhs.value.as < instruction* > () = new func_main(0,0,INTEGER,yystack_[1].value.as < list_instruction* > ());
                                                                                                ctx.Main = yystack_[1].value.as < list_instruction* > ();
                                                                                            }
#line 1330 "parser.cpp"
    break;

  case 8: // funcion: RVOID ID PARABRE func_list PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA
#line 281 "parser.y"
                                                                                            {   yylhs.value.as < instruction* > () = new function(0,0,VOID,yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());    }
#line 1336 "parser.cpp"
    break;

  case 9: // funcion: RVOID ID PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA
#line 282 "parser.y"
                                                                                            {   yylhs.value.as < instruction* > () = new function(0,0,VOID,yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());    }
#line 1342 "parser.cpp"
    break;

  case 10: // funcion: RVOID R_MAIN PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA
#line 283 "parser.y"
                                                                                            {   
                                                                                                yylhs.value.as < instruction* > () = new func_main(0,0,INTEGER,yystack_[1].value.as < list_instruction* > ());
                                                                                                ctx.Main = yystack_[1].value.as < list_instruction* > ();
                                                                                            }
#line 1351 "parser.cpp"
    break;

  case 11: // funcion: otro_tipo_func ID PARABRE func_list PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA
#line 287 "parser.y"
                                                                                                      {   yylhs.value.as < instruction* > () = new function(0,0,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());         }
#line 1357 "parser.cpp"
    break;

  case 12: // funcion: otro_tipo_func ID PARABRE PARCIERRA LLAVEABRE list_inst_func LLAVECIERRA
#line 288 "parser.y"
                                                                                            {   yylhs.value.as < instruction* > () = new function(0,0,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());           }
#line 1363 "parser.cpp"
    break;

  case 13: // funcion: RSTRUCT ID LLAVEABRE dec_list LLAVECIERRA
#line 289 "parser.y"
                                                            { yylhs.value.as < instruction* > () = new declaracion_struct(0, 0, yystack_[1].value.as < map_struct_dec* > (), yystack_[3].value.as < std::string > ());      }
#line 1369 "parser.cpp"
    break;

  case 14: // dec_list: dec_list tipo ID PTCOMA
#line 294 "parser.y"
                                            {
                                                yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
                                                yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
                                            }
#line 1378 "parser.cpp"
    break;

  case 15: // dec_list: tipo ID PTCOMA
#line 298 "parser.y"
                                            {   
                                                yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
                                                yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
                                            }
#line 1387 "parser.cpp"
    break;

  case 16: // otro_tipo_func: RFLOAT
#line 303 "parser.y"
                                    {   yylhs.value.as < TipoDato > () = FLOAT;         }
#line 1393 "parser.cpp"
    break;

  case 17: // otro_tipo_func: RSTRING
#line 304 "parser.y"
                                    {   yylhs.value.as < TipoDato > () = STRING;        }
#line 1399 "parser.cpp"
    break;

  case 18: // otro_tipo_func: RBOOL
#line 305 "parser.y"
                                    {   yylhs.value.as < TipoDato > () = BOOL;          }
#line 1405 "parser.cpp"
    break;

  case 19: // func_list: func_list COMA tipo ID
#line 309 "parser.y"
                                        {
                                            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
                                            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
                                        }
#line 1414 "parser.cpp"
    break;

  case 20: // func_list: tipo ID
#line 313 "parser.y"
                                        {   
                                            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
                                            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (), yystack_[1].value.as < TipoDato > ());
                                        }
#line 1423 "parser.cpp"
    break;

  case 21: // list_inst_func: list_inst_func instruccion_funcion
#line 319 "parser.y"
                                                        { 
                                                            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                                            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
                                                        }
#line 1432 "parser.cpp"
    break;

  case 22: // list_inst_func: instruccion_funcion
#line 323 "parser.y"
                                                        {
                                                            yylhs.value.as < list_instruction* > () = new list_instruction();
                                                            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                                        }
#line 1441 "parser.cpp"
    break;

  case 23: // instruccion_funcion: instruccion_return PTCOMA
#line 329 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction_return* > () ;   }
#line 1447 "parser.cpp"
    break;

  case 24: // instruccion_funcion: declaracion PTCOMA
#line 330 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[1].value.as < declaration* > () ;   }
#line 1453 "parser.cpp"
    break;

  case 25: // instruccion_funcion: func_printf PTCOMA
#line 331 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[1].value.as < func_printf* > () ;   }
#line 1459 "parser.cpp"
    break;

  case 26: // instruccion_funcion: incremento_instruccion PTCOMA
#line 332 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[1].value.as < incremento* > () ;   }
#line 1465 "parser.cpp"
    break;

  case 27: // instruccion_funcion: asignacion PTCOMA
#line 333 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > () ;   }
#line 1471 "parser.cpp"
    break;

  case 28: // instruccion_funcion: declaracion_sin_valor PTCOMA
#line 334 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[1].value.as < declaracion_sin_valor* > () ;   }
#line 1477 "parser.cpp"
    break;

  case 29: // instruccion_funcion: instruccion_if
#line 335 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_if* > () ;   }
#line 1483 "parser.cpp"
    break;

  case 30: // instruccion_funcion: instruccion_while
#line 336 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_while* > () ;   }
#line 1489 "parser.cpp"
    break;

  case 31: // instruccion_funcion: instruccion_for
#line 337 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_for* > () ;   }
#line 1495 "parser.cpp"
    break;

  case 32: // instruccion_funcion: declaracion_arreglo
#line 338 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < create_vector* > () ;   }
#line 1501 "parser.cpp"
    break;

  case 33: // instruccion_funcion: creation_struct
#line 339 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < create_struct* > () ;   }
#line 1507 "parser.cpp"
    break;

  case 34: // instruccion_funcion: instrucciones_vector
#line 340 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > () ;   }
#line 1513 "parser.cpp"
    break;

  case 35: // instruccion_funcion: call_instruction
#line 341 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > () ;   }
#line 1519 "parser.cpp"
    break;

  case 36: // instruccion_return: RRETURN expresion
#line 344 "parser.y"
                                            { yylhs.value.as < instruction_return* > () = new instruction_return(0,0,yystack_[0].value.as < expression* > ()); }
#line 1525 "parser.cpp"
    break;

  case 37: // instruccion_return: RRETURN
#line 345 "parser.y"
                                            { yylhs.value.as < instruction_return* > () = new instruction_return(0,0,nullptr); }
#line 1531 "parser.cpp"
    break;

  case 38: // call_instruction: ID PARABRE lista_expresiones_printf PARCIERRA PTCOMA
#line 352 "parser.y"
                                                                                {   yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[4].value.as < std::string > (),yystack_[2].value.as < lista_expresiones* > ());          }
#line 1537 "parser.cpp"
    break;

  case 39: // call_instruction: ID PARABRE PARCIERRA PTCOMA
#line 353 "parser.y"
                                                                                {   yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[3].value.as < std::string > (),nullptr);     }
#line 1543 "parser.cpp"
    break;

  case 40: // call_instruction: ID PUNTO ID IGUAL expresion PTCOMA
#line 354 "parser.y"
                                                                                {   yylhs.value.as < instruction* > () = new instruction_asign_struct(0,0,yystack_[5].value.as < std::string > (),yystack_[3].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 1549 "parser.cpp"
    break;

  case 41: // instrucciones_vector: ID PUNTO RPUSHBACK PARABRE expresion PARCIERRA PTCOMA
#line 356 "parser.y"
                                                                                    {   yylhs.value.as < instruction* > () = new instruction_push_back(0,0,yystack_[6].value.as < std::string > (), yystack_[2].value.as < expression* > ());         }
#line 1555 "parser.cpp"
    break;

  case 42: // instrucciones_vector: ID PUNTO RPUSHFRONT PARABRE expresion PARCIERRA PTCOMA
#line 357 "parser.y"
                                                                                    {   yylhs.value.as < instruction* > () = new instruction_push_front(0,0,yystack_[6].value.as < std::string > (), yystack_[2].value.as < expression* > ());        }
#line 1561 "parser.cpp"
    break;

  case 43: // instrucciones_vector: ID PUNTO RREMOVE PARABRE expresion PARCIERRA PTCOMA
#line 358 "parser.y"
                                                                                    {   yylhs.value.as < instruction* > () = new instruction_vector_remove(0,0,yystack_[6].value.as < std::string > (), yystack_[2].value.as < expression* > ());     }
#line 1567 "parser.cpp"
    break;

  case 44: // declaracion_arreglo: RVECTOR MENOR tipo MAYOR ID PTCOMA
#line 361 "parser.y"
                                                                                                            {   yylhs.value.as < create_vector* > () = new create_vector(0, 0, yystack_[3].value.as < TipoDato > (), yystack_[1].value.as < std::string > (), nullptr);  }
#line 1573 "parser.cpp"
    break;

  case 45: // declaracion_arreglo: RVECTOR MENOR tipo MAYOR ID IGUAL CORABRE lista_expresiones_printf CORCIERRA PTCOMA
#line 362 "parser.y"
                                                                                                            {   yylhs.value.as < create_vector* > () = new create_vector(0, 0, yystack_[7].value.as < TipoDato > (), yystack_[5].value.as < std::string > (), yystack_[2].value.as < lista_expresiones* > ());  }
#line 1579 "parser.cpp"
    break;

  case 46: // declaracion_arreglo: RVECTOR MENOR tipo MAYOR ID IGUAL CORABRE CORCIERRA PTCOMA
#line 363 "parser.y"
                                                                                                            {   yylhs.value.as < create_vector* > () = new create_vector(0, 0, yystack_[6].value.as < TipoDato > (), yystack_[4].value.as < std::string > (), nullptr);  }
#line 1585 "parser.cpp"
    break;

  case 47: // creation_struct: RSTRUCT ID ID IGUAL LLAVEABRE lista_expresiones_printf LLAVECIERRA PTCOMA
#line 367 "parser.y"
                                                                                                    {
                                                                                                        yylhs.value.as < create_struct* > () = new create_struct(0,0,yystack_[6].value.as < std::string > (),yystack_[5].value.as < std::string > (),yystack_[2].value.as < lista_expresiones* > ());
                                                                                                    }
#line 1593 "parser.cpp"
    break;

  case 48: // creation_struct: RSTRUCT ID ID PTCOMA
#line 370 "parser.y"
                                                {   yylhs.value.as < create_struct* > () = new create_struct(0,0,yystack_[2].value.as < std::string > (),yystack_[1].value.as < std::string > (),nullptr);   }
#line 1599 "parser.cpp"
    break;

  case 49: // declaracion: tipo ID IGUAL expresion
#line 373 "parser.y"
                                              {  yylhs.value.as < declaration* > () = new declaration(0, 0, yystack_[2].value.as < std::string > (), yystack_[0].value.as < expression* > (), yystack_[3].value.as < TipoDato > ());    }
#line 1605 "parser.cpp"
    break;

  case 50: // tipo: RINT
#line 377 "parser.y"
                        {   yylhs.value.as < TipoDato > () = INTEGER; }
#line 1611 "parser.cpp"
    break;

  case 51: // tipo: RFLOAT
#line 378 "parser.y"
                        {   yylhs.value.as < TipoDato > () = FLOAT; }
#line 1617 "parser.cpp"
    break;

  case 52: // tipo: RSTRING
#line 379 "parser.y"
                        {   yylhs.value.as < TipoDato > () = STRING; }
#line 1623 "parser.cpp"
    break;

  case 53: // tipo: RBOOL
#line 380 "parser.y"
                        {   yylhs.value.as < TipoDato > () = BOOL; }
#line 1629 "parser.cpp"
    break;

  case 54: // expresion: expresion OPSUMA expresion
#line 383 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"      );  }
#line 1635 "parser.cpp"
    break;

  case 55: // expresion: expresion OPRESTA expresion
#line 384 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"      );  }
#line 1641 "parser.cpp"
    break;

  case 56: // expresion: expresion OPMULTIPLICACION expresion
#line 385 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"      );  }
#line 1647 "parser.cpp"
    break;

  case 57: // expresion: expresion OPDIVISION expresion
#line 386 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"      );  }
#line 1653 "parser.cpp"
    break;

  case 58: // expresion: expresion OPMODULO expresion
#line 387 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"      );  }
#line 1659 "parser.cpp"
    break;

  case 59: // expresion: expresion IGUAL IGUAL expresion
#line 388 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[3].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="     );  }
#line 1665 "parser.cpp"
    break;

  case 60: // expresion: expresion NOIGUAL expresion
#line 389 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="     );  }
#line 1671 "parser.cpp"
    break;

  case 61: // expresion: expresion MAYOR expresion
#line 390 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"      );  }
#line 1677 "parser.cpp"
    break;

  case 62: // expresion: expresion MENOR expresion
#line 391 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"      );  }
#line 1683 "parser.cpp"
    break;

  case 63: // expresion: expresion MAYOR IGUAL expresion
#line 392 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[3].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="     );  }
#line 1689 "parser.cpp"
    break;

  case 64: // expresion: expresion MENOR IGUAL expresion
#line 393 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[3].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="     );  }
#line 1695 "parser.cpp"
    break;

  case 65: // expresion: expresion RAND expresion
#line 394 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"     );  }
#line 1701 "parser.cpp"
    break;

  case 66: // expresion: expresion ROR expresion
#line 395 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"     );  }
#line 1707 "parser.cpp"
    break;

  case 67: // expresion: NOT expresion
#line 396 "parser.y"
                                                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[0].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!"      );  }
#line 1713 "parser.cpp"
    break;

  case 68: // expresion: MASMAS ID
#line 397 "parser.y"
                                                            { yylhs.value.as < expression* > () = new incremento_expression(0, 0, yystack_[0].value.as < std::string > (), 1, "++1");  }
#line 1719 "parser.cpp"
    break;

  case 69: // expresion: ID MASMAS
#line 398 "parser.y"
                                                            { yylhs.value.as < expression* > () = new incremento_expression(0, 0, yystack_[1].value.as < std::string > (), 2, "++2");  }
#line 1725 "parser.cpp"
    break;

  case 70: // expresion: PARABRE expresion PARCIERRA
#line 399 "parser.y"
                                                            { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > ();                                      }
#line 1731 "parser.cpp"
    break;

  case 71: // expresion: OPRESTA expresion
#line 400 "parser.y"
                                                            { yylhs.value.as < expression* > () = new negacion_unaria(0, 0, yystack_[0].value.as < expression* > ());           }
#line 1737 "parser.cpp"
    break;

  case 72: // expresion: RATOI PARABRE expresion PARCIERRA
#line 401 "parser.y"
                                                            { yylhs.value.as < expression* > () = new expr_atoi(0, 0, yystack_[1].value.as < expression* > ());                 }
#line 1743 "parser.cpp"
    break;

  case 73: // expresion: RATOF PARABRE expresion PARCIERRA
#line 402 "parser.y"
                                                            { yylhs.value.as < expression* > () = new expr_atof(0, 0, yystack_[1].value.as < expression* > ());                 }
#line 1749 "parser.cpp"
    break;

  case 74: // expresion: RIOTA PARABRE expresion PARCIERRA
#line 403 "parser.y"
                                                            { yylhs.value.as < expression* > () = new expr_iota(0, 0, yystack_[1].value.as < expression* > ());                 }
#line 1755 "parser.cpp"
    break;

  case 75: // expresion: op_vector
#line 404 "parser.y"
                                                            { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();                                      }
#line 1761 "parser.cpp"
    break;

  case 76: // expresion: primitivo
#line 405 "parser.y"
                                                            { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();                                      }
#line 1767 "parser.cpp"
    break;

  case 77: // expresion: RMEAN PARABRE ID PARCIERRA
#line 406 "parser.y"
                                                            { yylhs.value.as < expression* > () = new func_mean(0, 0, yystack_[1].value.as < std::string > ());                 }
#line 1773 "parser.cpp"
    break;

  case 78: // expresion: RMEDIAN PARABRE ID PARCIERRA
#line 407 "parser.y"
                                                            { yylhs.value.as < expression* > () = new func_median(0, 0, yystack_[1].value.as < std::string > ());               }
#line 1779 "parser.cpp"
    break;

  case 79: // expresion: RMODE PARABRE ID PARCIERRA
#line 408 "parser.y"
                                                            { yylhs.value.as < expression* > () = new func_moda(0, 0, yystack_[1].value.as < std::string > ());                 }
#line 1785 "parser.cpp"
    break;

  case 80: // expresion: call_expr
#line 409 "parser.y"
                                                            { yylhs.value.as < expression* > () = yystack_[0].value.as < call_exp* > ();                                      }
#line 1791 "parser.cpp"
    break;

  case 81: // call_expr: ID PARABRE lista_expresiones_printf PARCIERRA
#line 412 "parser.y"
                                                                {   yylhs.value.as < call_exp* > () = new call_exp(0, 0, yystack_[3].value.as < std::string > (), yystack_[1].value.as < lista_expresiones* > ());        }
#line 1797 "parser.cpp"
    break;

  case 82: // call_expr: ID PARABRE PARCIERRA
#line 413 "parser.y"
                                                                {   yylhs.value.as < call_exp* > () = new call_exp(0, 0, yystack_[2].value.as < std::string > (), nullptr);   }
#line 1803 "parser.cpp"
    break;

  case 83: // primitivo: TIPO_INTEGER
#line 416 "parser.y"
                                        {   
                                            primitive *tmp = new primitive(0, 0, INTEGER,"",    std::stoi(yystack_[0].value.as < std::string > ()),  0.0, false);
                                            yylhs.value.as < expression* > () = tmp ;
                                        }
#line 1812 "parser.cpp"
    break;

  case 84: // primitivo: TIPO_STRING
#line 420 "parser.y"
                                        {   std::string cadena = yystack_[0].value.as < std::string > ().erase(0,1);
                                            yylhs.value.as < expression* > () = new primitive(0,0,STRING, cadena.erase(cadena.length()-1,1),0,0.0, false);
                                        }
#line 1820 "parser.cpp"
    break;

  case 85: // primitivo: TIPO_FLOAT
#line 423 "parser.y"
                                        {   yylhs.value.as < expression* > () = new primitive(0, 0, FLOAT, "",     0,  std::stof(yystack_[0].value.as < std::string > ()),  false); }
#line 1826 "parser.cpp"
    break;

  case 86: // primitivo: TIPO_BOOL_TRUE
#line 424 "parser.y"
                                        {   yylhs.value.as < expression* > () = new primitive(0, 0, BOOL,  "",     0,  0.0,            true);  }
#line 1832 "parser.cpp"
    break;

  case 87: // primitivo: TIPO_BOOL_FALSE
#line 425 "parser.y"
                                        {   yylhs.value.as < expression* > () = new primitive(0, 0, BOOL,  "",     0,  0.0,            false); }
#line 1838 "parser.cpp"
    break;

  case 88: // primitivo: llamada_variable
#line 426 "parser.y"
                                        {   yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();                                                            }
#line 1844 "parser.cpp"
    break;

  case 89: // op_vector: ID CORABRE expresion CORCIERRA
#line 429 "parser.y"
                                                            {   yylhs.value.as < expression* > () = new vector_access(0, 0, yystack_[3].value.as < std::string > (), yystack_[1].value.as < expression* > ());           }
#line 1850 "parser.cpp"
    break;

  case 90: // op_vector: ID PUNTO RGET PARABRE expresion PARCIERRA
#line 430 "parser.y"
                                                            {   yylhs.value.as < expression* > () = new vector_access(0, 0, yystack_[5].value.as < std::string > (), yystack_[1].value.as < expression* > ());           }
#line 1856 "parser.cpp"
    break;

  case 91: // op_vector: ID PUNTO RSIZE PARABRE PARCIERRA
#line 431 "parser.y"
                                                            {   yylhs.value.as < expression* > () = new expr_size_vector(0, 0, yystack_[4].value.as < std::string > ());            }
#line 1862 "parser.cpp"
    break;

  case 92: // llamada_variable: ID
#line 434 "parser.y"
                                        {   yylhs.value.as < expression* > () = new llamada_variable(0, 0, yystack_[0].value.as < std::string > ());    }
#line 1868 "parser.cpp"
    break;

  case 93: // llamada_variable: ID PUNTO ID
#line 435 "parser.y"
                                        {   yylhs.value.as < expression* > () = new struct_access(0, 0, new llamada_variable(0,0,yystack_[2].value.as < std::string > ()), yystack_[0].value.as < std::string > ());   }
#line 1874 "parser.cpp"
    break;

  case 94: // func_printf: RPRINTF PARABRE lista_expresiones_printf PARCIERRA
#line 438 "parser.y"
                                                                    { yylhs.value.as < func_printf* > () = new func_printf(0,0, yystack_[1].value.as < lista_expresiones* > ());            }
#line 1880 "parser.cpp"
    break;

  case 95: // lista_expresiones_printf: lista_expresiones_printf COMA expresion
#line 441 "parser.y"
                                                                                { 
                                                                                    yystack_[2].value.as < lista_expresiones* > ()->newExpr(yystack_[0].value.as < expression* > ());
                                                                                    yylhs.value.as < lista_expresiones* > () = yystack_[2].value.as < lista_expresiones* > ();
                                                                                }
#line 1889 "parser.cpp"
    break;

  case 96: // lista_expresiones_printf: expresion
#line 445 "parser.y"
                                                                                {
                                                                                    yylhs.value.as < lista_expresiones* > () = new lista_expresiones();
                                                                                    yylhs.value.as < lista_expresiones* > ()->newExpr(yystack_[0].value.as < expression* > ());
                                                                                }
#line 1898 "parser.cpp"
    break;

  case 97: // incremento_instruccion: ID MASMAS
#line 451 "parser.y"
                                                         { yylhs.value.as < incremento* > () = new incremento(0,0, yystack_[1].value.as < std::string > ());  }
#line 1904 "parser.cpp"
    break;

  case 98: // incremento_instruccion: MASMAS ID
#line 452 "parser.y"
                                                         { yylhs.value.as < incremento* > () = new incremento(0,0, yystack_[0].value.as < std::string > ());  }
#line 1910 "parser.cpp"
    break;

  case 99: // asignacion: ID IGUAL expresion
#line 455 "parser.y"
                                                                { yylhs.value.as < instruction* > () = new asignacion_variable(0, 0, yystack_[2].value.as < std::string > (), yystack_[0].value.as < expression* > ());                   }
#line 1916 "parser.cpp"
    break;

  case 100: // asignacion: ID CORABRE expresion CORCIERRA IGUAL expresion
#line 456 "parser.y"
                                                                { yylhs.value.as < instruction* > () = new instruction_vector_asignacion(0, 0, yystack_[5].value.as < std::string > (), yystack_[3].value.as < expression* > (), yystack_[0].value.as < expression* > ());     }
#line 1922 "parser.cpp"
    break;

  case 101: // declaracion_sin_valor: tipo ID
#line 459 "parser.y"
                                                                { yylhs.value.as < declaracion_sin_valor* > () = new declaracion_sin_valor(0,0,yystack_[0].value.as < std::string > () , yystack_[1].value.as < TipoDato > ());  }
#line 1928 "parser.cpp"
    break;

  case 102: // instruccion_if: R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA list_elseif list_else
#line 462 "parser.y"
                                                                                                            {   yylhs.value.as < instruction_if* > () = new instruction_if(0,0,yystack_[6].value.as < expression* > (), yystack_[3].value.as < list_instruction_second* > (),yystack_[1].value.as < list_instruction_second* > (), yystack_[0].value.as < list_instruction_second* > ());}
#line 1934 "parser.cpp"
    break;

  case 103: // instruccion_if: R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA list_elseif
#line 463 "parser.y"
                                                                                                            {   yylhs.value.as < instruction_if* > () = new instruction_if(0,0,yystack_[5].value.as < expression* > (), yystack_[2].value.as < list_instruction_second* > (),yystack_[0].value.as < list_instruction_second* > (), nullptr);}
#line 1940 "parser.cpp"
    break;

  case 104: // instruccion_if: R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA list_else
#line 464 "parser.y"
                                                                                                            {   yylhs.value.as < instruction_if* > () = new instruction_if(0,0,yystack_[5].value.as < expression* > (), yystack_[2].value.as < list_instruction_second* > (),nullptr, yystack_[0].value.as < list_instruction_second* > ());}
#line 1946 "parser.cpp"
    break;

  case 105: // instruccion_if: R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA
#line 465 "parser.y"
                                                                                                            {   yylhs.value.as < instruction_if* > () = new instruction_if(0,0,yystack_[4].value.as < expression* > (), yystack_[1].value.as < list_instruction_second* > (),nullptr, nullptr);}
#line 1952 "parser.cpp"
    break;

  case 106: // cuerpo_if: cuerpo_if instruccion_if_cuerpo
#line 468 "parser.y"
                                                    { 
                                                        yystack_[1].value.as < list_instruction_second* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                                        yylhs.value.as < list_instruction_second* > () = yystack_[1].value.as < list_instruction_second* > ();
                                                    }
#line 1961 "parser.cpp"
    break;

  case 107: // cuerpo_if: instruccion_if_cuerpo
#line 472 "parser.y"
                                                    {
                                                        yylhs.value.as < list_instruction_second* > () = new list_instruction_second();
                                                        yylhs.value.as < list_instruction_second* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                                    }
#line 1970 "parser.cpp"
    break;

  case 108: // instruccion_if_cuerpo: func_printf PTCOMA
#line 478 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < func_printf* > ();                                }
#line 1976 "parser.cpp"
    break;

  case 109: // instruccion_if_cuerpo: instruccion_for
#line 479 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_for* > ();                                }
#line 1982 "parser.cpp"
    break;

  case 110: // instruccion_if_cuerpo: instruccion_if
#line 480 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_if* > ();                                }
#line 1988 "parser.cpp"
    break;

  case 111: // instruccion_if_cuerpo: incremento_instruccion PTCOMA
#line 481 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < incremento* > ();                                }
#line 1994 "parser.cpp"
    break;

  case 112: // instruccion_if_cuerpo: asignacion PTCOMA
#line 482 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();                                }
#line 2000 "parser.cpp"
    break;

  case 113: // instruccion_if_cuerpo: RBREAK PTCOMA
#line 483 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = new instruction_break(0,0);        }
#line 2006 "parser.cpp"
    break;

  case 114: // instruccion_if_cuerpo: RCONTINUE PTCOMA
#line 484 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = new instruction_continue(0,0);     }
#line 2012 "parser.cpp"
    break;

  case 115: // instruccion_if_cuerpo: instruccion_while
#line 485 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_while* > ();                                }
#line 2018 "parser.cpp"
    break;

  case 116: // instruccion_if_cuerpo: declaracion PTCOMA
#line 486 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < declaration* > ();                                }
#line 2024 "parser.cpp"
    break;

  case 117: // instruccion_if_cuerpo: declaracion_sin_valor PTCOMA
#line 487 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < declaracion_sin_valor* > ();                                }
#line 2030 "parser.cpp"
    break;

  case 118: // instruccion_if_cuerpo: creation_struct
#line 488 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < create_struct* > () ;   }
#line 2036 "parser.cpp"
    break;

  case 119: // instruccion_if_cuerpo: declaracion_arreglo
#line 489 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < create_vector* > () ;   }
#line 2042 "parser.cpp"
    break;

  case 120: // instruccion_if_cuerpo: instrucciones_vector
#line 490 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > () ;   }
#line 2048 "parser.cpp"
    break;

  case 121: // instruccion_if_cuerpo: instruccion_return PTCOMA
#line 491 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction_return* > () ;   }
#line 2054 "parser.cpp"
    break;

  case 122: // list_elseif: list_elseif R_ELSE R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA
#line 494 "parser.y"
                                                                                                        {
                                                                                                            yystack_[8].value.as < list_instruction_second* > ()->newInst(new instruction_if(0,0,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction_second* > (), nullptr, nullptr));
                                                                                                            yylhs.value.as < list_instruction_second* > () = yystack_[8].value.as < list_instruction_second* > ();
                                                                                                        }
#line 2063 "parser.cpp"
    break;

  case 123: // list_elseif: R_ELSE R_IF PARABRE expresion PARCIERRA LLAVEABRE cuerpo_if LLAVECIERRA
#line 498 "parser.y"
                                                                                                        {
                                                                                                            yylhs.value.as < list_instruction_second* > () = new list_instruction_second();
                                                                                                            yylhs.value.as < list_instruction_second* > ()->newInst(new instruction_if(0,0,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction_second* > (), nullptr, nullptr));
                                                                                                        }
#line 2072 "parser.cpp"
    break;

  case 124: // list_else: R_ELSE LLAVEABRE cuerpo_if LLAVECIERRA
#line 505 "parser.y"
                                                                                                         {   yylhs.value.as < list_instruction_second* > () = yystack_[1].value.as < list_instruction_second* > ();    }
#line 2078 "parser.cpp"
    break;

  case 125: // instruccion_while: RWHILE PARABRE expresion PARCIERRA LLAVEABRE cuerpo_while LLAVECIERRA
#line 508 "parser.y"
                                                                                                            {
                                                                                                                yylhs.value.as < instruction_while* > () = new instruction_while(0,0,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction_second* > ());
                                                                                                            }
#line 2086 "parser.cpp"
    break;

  case 126: // cuerpo_while: cuerpo_while instruccion_while_cuerpo
#line 513 "parser.y"
                                                                {  
                                                                    yystack_[1].value.as < list_instruction_second* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                                                    yylhs.value.as < list_instruction_second* > () = yystack_[1].value.as < list_instruction_second* > ();
                                                                }
#line 2095 "parser.cpp"
    break;

  case 127: // cuerpo_while: instruccion_while_cuerpo
#line 517 "parser.y"
                                                                {
                                                                    yylhs.value.as < list_instruction_second* > () = new list_instruction_second();
                                                                    yylhs.value.as < list_instruction_second* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                                                }
#line 2104 "parser.cpp"
    break;

  case 128: // instruccion_while_cuerpo: func_printf PTCOMA
#line 523 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[1].value.as < func_printf* > ();                                }
#line 2110 "parser.cpp"
    break;

  case 129: // instruccion_while_cuerpo: instruccion_for
#line 524 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_for* > ();                                }
#line 2116 "parser.cpp"
    break;

  case 130: // instruccion_while_cuerpo: instruccion_if
#line 525 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_if* > ();                                }
#line 2122 "parser.cpp"
    break;

  case 131: // instruccion_while_cuerpo: incremento_instruccion PTCOMA
#line 526 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[1].value.as < incremento* > ();                                }
#line 2128 "parser.cpp"
    break;

  case 132: // instruccion_while_cuerpo: asignacion PTCOMA
#line 527 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();                                }
#line 2134 "parser.cpp"
    break;

  case 133: // instruccion_while_cuerpo: RBREAK PTCOMA
#line 528 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = new instruction_break(0,0);        }
#line 2140 "parser.cpp"
    break;

  case 134: // instruccion_while_cuerpo: RCONTINUE PTCOMA
#line 529 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = new instruction_continue(0,0);     }
#line 2146 "parser.cpp"
    break;

  case 135: // instruccion_while_cuerpo: instruccion_while
#line 530 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_while* > ();                                }
#line 2152 "parser.cpp"
    break;

  case 136: // instruccion_while_cuerpo: declaracion PTCOMA
#line 531 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[1].value.as < declaration* > ();                                }
#line 2158 "parser.cpp"
    break;

  case 137: // instruccion_while_cuerpo: declaracion_sin_valor PTCOMA
#line 532 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[1].value.as < declaracion_sin_valor* > ();                                }
#line 2164 "parser.cpp"
    break;

  case 138: // instruccion_while_cuerpo: creation_struct
#line 533 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[0].value.as < create_struct* > () ;   }
#line 2170 "parser.cpp"
    break;

  case 139: // instruccion_while_cuerpo: declaracion_arreglo
#line 534 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[0].value.as < create_vector* > () ;   }
#line 2176 "parser.cpp"
    break;

  case 140: // instruccion_while_cuerpo: instrucciones_vector
#line 535 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > () ;   }
#line 2182 "parser.cpp"
    break;

  case 141: // instruccion_while_cuerpo: instruccion_return PTCOMA
#line 536 "parser.y"
                                                                    {   yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction_return* > () ;   }
#line 2188 "parser.cpp"
    break;

  case 142: // instruccion_for: RFOR PARABRE declaracion_for PTCOMA expresion PTCOMA incremento_for PARCIERRA LLAVEABRE cuerpo_for LLAVECIERRA
#line 539 "parser.y"
                                                                                                                                   { yylhs.value.as < instruction_for* > () = new instruction_for(0, 0, yystack_[8].value.as < instruction* > (), yystack_[6].value.as < expression* > (), yystack_[4].value.as < instruction* > (), yystack_[1].value.as < list_instruction_second* > ()); }
#line 2194 "parser.cpp"
    break;

  case 143: // declaracion_for: declaracion
#line 542 "parser.y"
                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < declaration* > ();    }
#line 2200 "parser.cpp"
    break;

  case 144: // declaracion_for: asignacion
#line 543 "parser.y"
                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > ();    }
#line 2206 "parser.cpp"
    break;

  case 145: // declaracion_for: declaracion_sin_valor
#line 544 "parser.y"
                                            {   yylhs.value.as < instruction* > () = yystack_[0].value.as < declaracion_sin_valor* > ();    }
#line 2212 "parser.cpp"
    break;

  case 146: // incremento_for: asignacion
#line 547 "parser.y"
                                            { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > ();    }
#line 2218 "parser.cpp"
    break;

  case 147: // incremento_for: incremento_instruccion
#line 548 "parser.y"
                                            { yylhs.value.as < instruction* > () = yystack_[0].value.as < incremento* > ();    }
#line 2224 "parser.cpp"
    break;

  case 148: // cuerpo_for: cuerpo_for instruccion_for_cuerpo
#line 551 "parser.y"
                                                        {  
                                                            yystack_[1].value.as < list_instruction_second* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                                            yylhs.value.as < list_instruction_second* > () = yystack_[1].value.as < list_instruction_second* > ();
                                                        }
#line 2233 "parser.cpp"
    break;

  case 149: // cuerpo_for: instruccion_for_cuerpo
#line 555 "parser.y"
                                                        {
                                                            yylhs.value.as < list_instruction_second* > () = new list_instruction_second();
                                                            yylhs.value.as < list_instruction_second* > ()->newInst(yystack_[0].value.as < instruction* > ());
                                                        }
#line 2242 "parser.cpp"
    break;

  case 150: // instruccion_for_cuerpo: func_printf PTCOMA
#line 561 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < func_printf* > ();                                }
#line 2248 "parser.cpp"
    break;

  case 151: // instruccion_for_cuerpo: instruccion_for
#line 562 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_for* > ();                                }
#line 2254 "parser.cpp"
    break;

  case 152: // instruccion_for_cuerpo: instruccion_if
#line 563 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_if* > ();                                }
#line 2260 "parser.cpp"
    break;

  case 153: // instruccion_for_cuerpo: incremento_instruccion PTCOMA
#line 564 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < incremento* > ();                                }
#line 2266 "parser.cpp"
    break;

  case 154: // instruccion_for_cuerpo: asignacion PTCOMA
#line 565 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();                                }
#line 2272 "parser.cpp"
    break;

  case 155: // instruccion_for_cuerpo: RBREAK PTCOMA
#line 566 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = new instruction_break(0,0);        }
#line 2278 "parser.cpp"
    break;

  case 156: // instruccion_for_cuerpo: RCONTINUE PTCOMA
#line 567 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = new instruction_continue(0,0);     }
#line 2284 "parser.cpp"
    break;

  case 157: // instruccion_for_cuerpo: instruccion_while
#line 568 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction_while* > ();                                }
#line 2290 "parser.cpp"
    break;

  case 158: // instruccion_for_cuerpo: declaracion PTCOMA
#line 569 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < declaration* > ();                                }
#line 2296 "parser.cpp"
    break;

  case 159: // instruccion_for_cuerpo: declaracion_sin_valor PTCOMA
#line 570 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[1].value.as < declaracion_sin_valor* > ();                                }
#line 2302 "parser.cpp"
    break;

  case 160: // instruccion_for_cuerpo: creation_struct
#line 571 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[0].value.as < create_struct* > () ;   }
#line 2308 "parser.cpp"
    break;

  case 161: // instruccion_for_cuerpo: declaracion_arreglo
#line 572 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[0].value.as < create_vector* > () ;   }
#line 2314 "parser.cpp"
    break;

  case 162: // instruccion_for_cuerpo: instrucciones_vector
#line 573 "parser.y"
                                                                {   yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > () ;   }
#line 2320 "parser.cpp"
    break;

  case 163: // instruccion_for_cuerpo: instruccion_return PTCOMA
#line 574 "parser.y"
                                                            {   yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction_return* > () ;   }
#line 2326 "parser.cpp"
    break;


#line 2330 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short Parser::yypact_ninf_ = -334;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
       7,   -18,  -334,  -334,  -334,    -2,    46,    10,     7,  -334,
      76,     9,    63,   124,   127,   144,  -334,  -334,   138,   313,
     141,   332,   153,   220,   337,  -334,  -334,  -334,  -334,   167,
      43,   156,   174,   179,    51,   180,   409,   161,   183,    56,
     981,   185,   220,  -334,   981,   981,   186,   981,  -334,   169,
     189,   981,   199,   187,   128,   193,   195,   196,   191,   194,
     204,  1153,   650,  -334,   210,  -334,  -334,  -334,  -334,   222,
     211,   225,   226,   228,   229,  -334,  -334,  -334,   981,   217,
     693,   706,   981,   749,   232,  -334,   762,   981,  1153,  1153,
    1058,  -334,    26,  1153,  1153,  1153,   200,  -334,   221,   220,
    1153,  1153,  -334,  -334,  -334,  -334,  -334,   152,  1153,   223,
     227,   233,   234,   236,   237,   240,  1513,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,   249,  -334,  -334,  -334,  -334,
     805,  -334,  -334,  -334,   818,  -334,  -334,  -334,   861,  1513,
     106,  1513,   250,   118,   252,   247,   248,   251,    50,  1187,
    1210,    -6,  -334,  -334,  -334,   258,    93,   245,   137,  1233,
    1085,  -334,    85,  1153,  1513,  -334,  1153,  1153,  1153,   255,
     257,   261,   263,  1153,  1153,  1153,  1153,  1153,   990,  1031,
    1153,  1153,  1153,  1153,  -334,  -334,  -334,  -334,  1153,  -334,
     265,  1153,  1153,  1153,  1153,   272,   285,   291,  1153,   296,
    -334,   278,  -334,  -334,   121,  -334,   290,   293,   360,  1256,
    1279,  1302,   297,   298,   299,  1153,   137,   137,  -334,  -334,
    -334,  1153,   448,  1153,   448,   765,   709,   821,  1513,  1513,
    -334,  1327,  1350,  1373,  1396,  1153,   874,   916,  1421,  1153,
     100,  -334,  1153,   305,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,   821,   821,   821,  -334,   314,   322,   323,  1513,    47,
     336,   340,   341,  -334,  -334,  -334,   342,   343,   345,   346,
     348,  -334,   449,  -334,  -334,  -334,   349,   350,   351,  -334,
    -334,  -334,   354,   357,   367,   368,   371,  -334,  -334,   492,
    -334,  -334,    30,    16,   277,  -334,  1444,  -334,  -334,  -334,
    -334,   112,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
     280,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,    20,  -334,  -334,   330,   372,  1112,  -334,     2,
     359,  -334,   386,  -334,   379,   -31,   874,   376,     4,  -334,
     939,  -334,   384,   516,  1153,   380,   387,   388,   391,  -334,
    -334,  -334,   393,   395,   396,   399,   400,  -334,  -334,  -334,
     559,  -334,  -334,  -334,  1467,  1153,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,  -334,   415,  1490,   874,   420,
     583,   874,  -334,   626,  -334
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,    16,    17,    18,     0,     0,     0,     2,     4,
       0,     0,     0,     0,     0,     0,     1,     3,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    22,     0,    35,    34,    32,    33,     0,
       0,     0,     0,     0,     0,    29,    30,    31,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,    83,    85,    84,    86,    87,    92,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    80,    76,    75,
      88,     6,    21,    23,    24,   101,    25,    26,    27,    28,
       0,    19,     7,     9,     0,    10,    14,    12,     0,    96,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,     0,     0,     0,    71,     0,
       0,    69,     0,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     8,    11,    94,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,    70,    82,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,     0,    61,     0,    62,    65,    66,    60,    49,    95,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,    89,    74,    72,    73,    77,    78,
      79,    59,    63,    64,    40,     0,     0,     0,   100,     0,
       0,     0,     0,   120,   119,   118,     0,     0,     0,     0,
       0,   110,     0,   107,   115,   109,     0,     0,     0,   140,
     139,   138,     0,     0,     0,     0,     0,   130,   135,     0,
     127,   129,     0,     0,     0,    44,     0,    91,    41,    42,
      43,     0,   113,   114,   121,   116,   108,   111,   112,   117,
     105,   106,   133,   134,   141,   136,   128,   131,   132,   137,
     125,   126,     0,   147,   146,     0,     0,     0,    90,     0,
     103,   104,     0,    47,     0,     0,     0,     0,     0,   102,
       0,    46,     0,     0,     0,     0,     0,     0,     0,   162,
     161,   160,     0,     0,     0,     0,     0,   152,   157,   151,
       0,   149,    45,   124,     0,     0,   155,   156,   163,   158,
     150,   153,   154,   159,   142,   148,     0,     0,     0,     0,
       0,     0,   123,     0,   122
  };

  const short
  Parser::yypgoto_[] =
  {
    -334,  -334,  -334,   417,  -334,  -334,    14,     8,   -37,  -149,
    -334,   -69,   -14,    41,   -88,     0,   -61,  -334,  -334,  -334,
    -334,    60,   -89,  -164,   -94,   -80,    69,  -333,  -254,  -334,
      96,    91,  -334,   139,    99,  -334,  -334,  -334,    70
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     7,     8,     9,    36,    10,    30,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   139,   117,   118,   119,
     120,    71,   140,    72,    73,    74,    75,   272,   273,   330,
     331,    76,   289,   290,    77,   155,   325,   360,   361
  };

  const short
  Parser::yytable_[] =
  {
     116,   143,   153,   343,    89,   336,    11,   336,   152,   188,
      16,    12,     1,     2,     3,     4,   154,   342,   311,    31,
     326,    31,    13,    37,    31,   122,    19,    14,   141,   337,
      89,   345,   148,   149,   150,    34,    49,     5,    39,   158,
     159,    93,    79,   122,   122,   380,   122,   164,   383,   122,
     144,     6,    80,    81,   322,    83,   188,    89,    91,    86,
     172,    41,   173,   174,   175,   176,   177,    93,    58,    46,
      15,   204,   268,   284,    52,   178,   179,   145,   146,   147,
      20,   180,   181,    42,   182,    91,   130,   262,   278,   311,
     134,    42,   301,   122,    93,   138,    42,   122,   195,   157,
      18,   122,   208,   199,   200,   209,   210,   211,   268,   205,
     294,   295,   216,   217,   218,   219,   220,   222,   224,   225,
     226,   227,   228,   262,   187,   284,   311,   229,   323,   311,
     231,   232,   233,   234,   206,   207,   190,   238,    89,   241,
     278,    21,   269,   285,    22,    90,   188,    23,   266,   282,
     293,   175,   176,   177,   251,    24,   270,   286,   188,    32,
     252,   188,   253,   145,   146,   147,    91,   263,   279,   160,
      40,    35,   268,    92,   258,    93,   354,    44,   269,   268,
      43,   296,    45,    47,   266,    50,    51,   262,    78,    82,
     161,   348,   270,    84,   262,   285,   354,   162,   324,   163,
      85,   282,    87,   263,    88,    25,    26,    27,    28,   286,
      94,   348,    95,    96,   268,    97,   268,   268,    98,   268,
     279,   123,   264,   280,   151,    25,    26,    27,    28,   262,
      99,   262,   262,   124,   262,   125,   126,   127,   335,   128,
     129,   131,   269,   136,   166,   156,   355,   165,   266,   269,
     167,   168,   352,   169,   170,   266,   270,   171,   264,   183,
     356,   189,   191,   270,   192,   193,   355,   263,   194,   198,
     201,   349,   352,   215,   263,   280,   230,   265,   281,   212,
     356,   213,   235,   364,   269,   214,   269,   269,   236,   269,
     266,   349,   266,   266,   237,   266,   267,   283,   270,   239,
     270,   270,   240,   270,   377,   271,   287,   242,   329,   263,
     243,   263,   263,   265,   263,   248,   249,   250,    25,    26,
      27,    28,   264,   297,   327,   298,   350,   274,   288,   264,
     281,    29,   267,   299,   300,   275,   291,    25,    26,    27,
      28,   271,    25,    26,    27,    28,   350,   302,   332,   283,
      33,   303,   304,   305,   306,    38,   307,   308,   287,   309,
     312,   313,   314,   274,   264,   315,   264,   264,   316,   264,
     172,   275,   173,   174,   175,   176,   177,   265,   317,   318,
     288,   351,   319,   333,   265,   178,   179,   338,   291,   340,
     341,   180,   181,   344,   182,   362,   267,   365,   366,   367,
     353,   351,   368,   267,   369,   271,   370,   371,   244,   357,
     372,   373,   271,    48,    25,    26,    27,    28,   378,   265,
     353,   265,   265,   381,   265,    17,   339,   274,   321,   357,
     375,   358,     0,     0,   274,   275,     0,     0,   267,   359,
     267,   267,   275,   267,     0,     0,     0,   271,     0,   271,
     271,   358,   271,   310,    25,    26,    27,    28,    53,   359,
     173,   174,   175,   176,   177,     0,     0,     0,     0,   274,
       0,   274,   274,   259,   274,     0,    55,   275,     0,   275,
     275,     0,   275,     0,    56,    57,   260,    58,   261,     0,
       0,     0,     0,    59,     0,    60,   320,    25,    26,    27,
      28,    53,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,    55,
     363,    25,    26,    27,    28,    53,     0,    56,    57,   276,
      58,   277,     0,     0,     0,     0,    59,     0,    60,     0,
     259,     0,     0,    55,     0,     0,    61,     0,     0,     0,
       0,    56,    57,   260,    58,   261,     0,     0,     0,     0,
      59,     0,    60,   374,    25,    26,    27,    28,    53,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,    55,   382,    25,    26,
      27,    28,    53,     0,    56,    57,   346,    58,   347,     0,
       0,     0,     0,    59,     0,    60,     0,   259,     0,     0,
      55,     0,     0,    61,     0,     0,     0,     0,    56,    57,
     260,    58,   261,     0,     0,     0,     0,    59,     0,    60,
     384,    25,    26,    27,    28,    53,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,    55,   121,    25,    26,    27,    28,    53,
       0,    56,    57,   260,    58,   261,     0,     0,     0,     0,
      59,     0,    60,     0,    54,     0,     0,    55,     0,     0,
      61,     0,     0,     0,     0,    56,    57,     0,    58,     0,
       0,     0,     0,     0,    59,     0,    60,   132,    25,    26,
      27,    28,    53,     0,    61,     0,     0,     0,     0,     0,
     133,    25,    26,    27,    28,    53,     0,    54,     0,   172,
      55,   173,   174,   175,   176,   177,     0,     0,    56,    57,
      54,    58,     0,    55,   178,   179,     0,    59,     0,    60,
     180,    56,    57,   182,    58,     0,     0,    61,     0,     0,
      59,     0,    60,   135,    25,    26,    27,    28,    53,     0,
      61,     0,     0,     0,     0,     0,   137,    25,    26,    27,
      28,    53,     0,    54,     0,   172,    55,   173,   174,   175,
     176,   177,     0,     0,    56,    57,    54,    58,     0,    55,
     178,   179,     0,    59,     0,    60,     0,    56,    57,   182,
      58,     0,     0,    61,     0,     0,    59,     0,    60,   184,
      25,    26,    27,    28,    53,     0,    61,     0,     0,     0,
       0,     0,   185,    25,    26,    27,    28,    53,     0,    54,
       0,     0,    55,   173,   174,   175,   176,   177,     0,     0,
      56,    57,    54,    58,     0,    55,   178,   179,     0,    59,
       0,    60,     0,    56,    57,     0,    58,     0,     0,    61,
       0,     0,    59,     0,    60,   186,    25,    26,    27,    28,
      53,     0,    61,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    53,     0,    54,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,    56,    57,   259,    58,
       0,    55,     0,     0,     0,    59,     0,    60,     0,    56,
      57,   260,    58,   261,     0,    61,     0,     0,    59,     0,
      60,    25,    26,    27,    28,    53,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,    55,    25,    26,    27,    28,    53,     0,
       0,    56,    57,   276,    58,   277,     0,     0,     0,     0,
      59,     0,    60,   259,     0,     0,    55,     0,     0,     0,
      61,     0,     0,     0,    56,    57,   346,    58,   347,     0,
       0,     0,     0,    59,     0,    60,    25,    26,    27,    28,
      53,     0,     0,    61,     0,     0,     0,     0,     0,     0,
     221,     0,     0,   100,     0,    54,     0,   101,    55,   102,
     103,   104,   105,   106,   107,     0,    56,    57,     0,    58,
       0,     0,     0,   108,     0,    59,     0,    60,   109,     0,
       0,   110,   111,   112,     0,    61,     0,     0,     0,     0,
       0,   223,     0,     0,   100,   113,   114,   115,   101,     0,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,   109,
       0,   100,   110,   111,   112,   101,   142,   102,   103,   104,
     105,   106,   107,     0,     0,     0,   113,   114,   115,     0,
       0,   108,     0,     0,     0,     0,   109,     0,   100,   110,
     111,   112,   101,   203,   102,   103,   104,   105,   106,   107,
       0,     0,     0,   113,   114,   115,     0,     0,   108,     0,
       0,     0,     0,   109,     0,   100,   110,   111,   112,   101,
       0,   102,   103,   104,   105,   106,   107,     0,     0,     0,
     113,   114,   115,     0,     0,   108,     0,     0,     0,     0,
     109,     0,     0,   110,   111,   112,     0,     0,     0,     0,
     334,     0,     0,     0,     0,     0,   100,   113,   114,   115,
     101,     0,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,   109,     0,     0,   110,   111,   112,   172,     0,   173,
     174,   175,   176,   177,     0,   196,     0,     0,   113,   114,
     115,     0,   178,   179,     0,     0,     0,     0,   180,   181,
     172,   182,   173,   174,   175,   176,   177,     0,   197,     0,
       0,     0,     0,     0,     0,   178,   179,     0,     0,     0,
       0,   180,   181,   172,   182,   173,   174,   175,   176,   177,
       0,   202,     0,     0,     0,     0,     0,     0,   178,   179,
       0,     0,     0,     0,   180,   181,   172,   182,   173,   174,
     175,   176,   177,     0,   245,     0,     0,     0,     0,     0,
       0,   178,   179,     0,     0,     0,     0,   180,   181,   172,
     182,   173,   174,   175,   176,   177,     0,   246,     0,     0,
       0,     0,     0,     0,   178,   179,     0,     0,     0,     0,
     180,   181,   172,   182,   173,   174,   175,   176,   177,     0,
     247,     0,     0,     0,     0,     0,     0,   178,   179,     0,
       0,     0,     0,   180,   181,     0,   182,   172,   254,   173,
     174,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,     0,   178,   179,     0,     0,     0,     0,   180,   181,
     172,   182,   173,   174,   175,   176,   177,     0,   255,     0,
       0,     0,     0,     0,     0,   178,   179,     0,     0,     0,
       0,   180,   181,   172,   182,   173,   174,   175,   176,   177,
       0,   256,     0,     0,     0,     0,     0,     0,   178,   179,
       0,     0,     0,     0,   180,   181,   172,   182,   173,   174,
     175,   176,   177,     0,   257,     0,     0,     0,     0,     0,
       0,   178,   179,     0,     0,     0,     0,   180,   181,     0,
     182,   172,   292,   173,   174,   175,   176,   177,     0,     0,
       0,     0,     0,     0,     0,     0,   178,   179,     0,     0,
       0,     0,   180,   181,   172,   182,   173,   174,   175,   176,
     177,     0,   328,     0,     0,     0,     0,     0,     0,   178,
     179,     0,     0,     0,     0,   180,   181,   172,   182,   173,
     174,   175,   176,   177,     0,   376,     0,     0,     0,     0,
       0,     0,   178,   179,     0,     0,     0,     0,   180,   181,
     172,   182,   173,   174,   175,   176,   177,     0,   379,     0,
       0,     0,     0,     0,     0,   178,   179,     0,     0,     0,
       0,   180,   181,   172,   182,   173,   174,   175,   176,   177,
       0,     0,     0,     0,     0,     0,     0,     0,   178,   179,
       0,     0,     0,     0,   180,   181,     0,   182
  };

  const short
  Parser::yycheck_[] =
  {
      61,    90,    96,   336,    10,     3,    24,     3,    96,    40,
       0,    29,     5,     6,     7,     8,    96,    48,   272,    19,
       4,    21,    24,    23,    24,    62,    17,    29,    89,    27,
      10,    27,    93,    94,    95,    21,    36,    30,    24,   100,
     101,    47,    42,    80,    81,   378,    83,   108,   381,    86,
      24,    44,    44,    45,    24,    47,    40,    10,    38,    51,
      10,    18,    12,    13,    14,    15,    16,    47,    38,    18,
      24,   160,   236,   237,    18,    25,    26,    51,    52,    53,
      17,    31,    32,    40,    34,    38,    78,   236,   237,   343,
      82,    40,    45,   130,    47,    87,    40,   134,    48,    99,
      24,   138,   163,    10,    11,   166,   167,   168,   272,    24,
      10,    11,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   272,    18,   289,   380,   188,   292,   383,
     191,   192,   193,   194,    49,    50,    18,   198,    10,    18,
     289,    17,   236,   237,    17,    17,    40,     3,   236,   237,
     239,    14,    15,    16,   215,    17,   236,   237,    40,    18,
     221,    40,   223,    51,    52,    53,    38,   236,   237,    17,
       3,    18,   336,    45,   235,    47,   340,     3,   272,   343,
      24,   242,     3,     3,   272,    24,     3,   336,     3,     3,
      38,   340,   272,    24,   343,   289,   360,    45,   292,    47,
      11,   289,     3,   272,    17,     5,     6,     7,     8,   289,
      17,   360,    17,    17,   378,    24,   380,   381,    24,   383,
     289,    11,   236,   237,    24,     5,     6,     7,     8,   378,
      26,   380,   381,    11,   383,    24,    11,    11,   327,    11,
      11,    24,   336,    11,    17,    24,   340,    24,   336,   343,
      17,    17,   340,    17,    17,   343,   336,    17,   272,    10,
     340,    11,    10,   343,    17,    17,   360,   336,    17,    11,
      25,   340,   360,    10,   343,   289,    11,   236,   237,    24,
     360,    24,    10,   344,   378,    24,   380,   381,     3,   383,
     378,   360,   380,   381,     3,   383,   236,   237,   378,     3,
     380,   381,    24,   383,   365,   236,   237,    17,    28,   378,
      17,   380,   381,   272,   383,    18,    18,    18,     5,     6,
       7,     8,   336,    18,    47,    11,   340,   236,   237,   343,
     289,    18,   272,    11,    11,   236,   237,     5,     6,     7,
       8,   272,     5,     6,     7,     8,   360,    11,    18,   289,
      18,    11,    11,    11,    11,    18,    11,    11,   289,    11,
      11,    11,    11,   272,   378,    11,   380,   381,    11,   383,
      10,   272,    12,    13,    14,    15,    16,   336,    11,    11,
     289,   340,    11,    11,   343,    25,    26,    28,   289,     3,
      11,    31,    32,    17,    34,    11,   336,    17,    11,    11,
     340,   360,    11,   343,    11,   336,    11,    11,    48,   340,
      11,    11,   343,     4,     5,     6,     7,     8,     3,   378,
     360,   380,   381,     3,   383,     8,   330,   336,   289,   360,
     360,   340,    -1,    -1,   343,   336,    -1,    -1,   378,   340,
     380,   381,   343,   383,    -1,    -1,    -1,   378,    -1,   380,
     381,   360,   383,     4,     5,     6,     7,     8,     9,   360,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,   378,
      -1,   380,   381,    24,   383,    -1,    27,   378,    -1,   380,
     381,    -1,   383,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    46,     4,     5,     6,     7,
       8,     9,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    27,
       4,     5,     6,     7,     8,     9,    -1,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    44,    -1,    46,    -1,
      24,    -1,    -1,    27,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    46,     4,     5,     6,     7,     8,     9,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    27,     4,     5,     6,
       7,     8,     9,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    46,    -1,    24,    -1,    -1,
      27,    -1,    -1,    54,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    46,
       4,     5,     6,     7,     8,     9,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    27,     4,     5,     6,     7,     8,     9,
      -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    46,    -1,    24,    -1,    -1,    27,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    35,    36,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    46,     4,     5,     6,
       7,     8,     9,    -1,    54,    -1,    -1,    -1,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    24,    -1,    10,
      27,    12,    13,    14,    15,    16,    -1,    -1,    35,    36,
      24,    38,    -1,    27,    25,    26,    -1,    44,    -1,    46,
      31,    35,    36,    34,    38,    -1,    -1,    54,    -1,    -1,
      44,    -1,    46,     4,     5,     6,     7,     8,     9,    -1,
      54,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    24,    -1,    10,    27,    12,    13,    14,
      15,    16,    -1,    -1,    35,    36,    24,    38,    -1,    27,
      25,    26,    -1,    44,    -1,    46,    -1,    35,    36,    34,
      38,    -1,    -1,    54,    -1,    -1,    44,    -1,    46,     4,
       5,     6,     7,     8,     9,    -1,    54,    -1,    -1,    -1,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,    24,
      -1,    -1,    27,    12,    13,    14,    15,    16,    -1,    -1,
      35,    36,    24,    38,    -1,    27,    25,    26,    -1,    44,
      -1,    46,    -1,    35,    36,    -1,    38,    -1,    -1,    54,
      -1,    -1,    44,    -1,    46,     4,     5,     6,     7,     8,
       9,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    -1,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    24,    38,
      -1,    27,    -1,    -1,    -1,    44,    -1,    46,    -1,    35,
      36,    37,    38,    39,    -1,    54,    -1,    -1,    44,    -1,
      46,     5,     6,     7,     8,     9,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    27,     5,     6,     7,     8,     9,    -1,
      -1,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    46,    24,    -1,    -1,    27,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    46,     5,     6,     7,     8,
       9,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    13,    -1,    24,    -1,    17,    27,    19,
      20,    21,    22,    23,    24,    -1,    35,    36,    -1,    38,
      -1,    -1,    -1,    33,    -1,    44,    -1,    46,    38,    -1,
      -1,    41,    42,    43,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    13,    55,    56,    57,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    38,
      -1,    13,    41,    42,    43,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    55,    56,    57,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    38,    -1,    13,    41,
      42,    43,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    55,    56,    57,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    38,    -1,    13,    41,    42,    43,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      55,    56,    57,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    13,    55,    56,    57,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    43,    10,    -1,    12,
      13,    14,    15,    16,    -1,    18,    -1,    -1,    55,    56,
      57,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      10,    34,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    31,    32,    10,    34,    12,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    32,    10,    34,    12,    13,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    10,
      34,    12,    13,    14,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    10,    34,    12,    13,    14,    15,    16,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    31,    32,    -1,    34,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      10,    34,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    31,    32,    10,    34,    12,    13,    14,    15,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    32,    10,    34,    12,    13,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,
      34,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    10,    34,    12,    13,    14,    15,
      16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    31,    32,    10,    34,    12,
      13,    14,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      10,    34,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    31,    32,    10,    34,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    32,    -1,    34
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     5,     6,     7,     8,    30,    44,    59,    60,    61,
      63,    24,    29,    24,    29,    24,     0,    61,    24,    17,
      17,    17,    17,     3,    17,     5,     6,     7,     8,    18,
      64,    73,    18,    18,    64,    18,    62,    73,    18,    64,
       3,    18,    40,    24,     3,     3,    18,     3,     4,    73,
      24,     3,    18,     9,    24,    27,    35,    36,    38,    44,
      46,    54,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    79,    81,    82,    83,    84,    89,    92,     3,    73,
      65,    65,     3,    65,    24,    11,    65,     3,    17,    10,
      17,    38,    45,    47,    17,    17,    17,    24,    24,    26,
      13,    17,    19,    20,    21,    22,    23,    24,    33,    38,
      41,    42,    43,    55,    56,    57,    74,    75,    76,    77,
      78,     4,    66,    11,    11,    24,    11,    11,    11,    11,
      65,    24,     4,     4,    65,     4,    11,     4,    65,    74,
      80,    74,    18,    80,    24,    51,    52,    53,    74,    74,
      74,    24,    72,    82,    83,    93,    24,    73,    74,    74,
      17,    38,    45,    47,    74,    24,    17,    17,    17,    17,
      17,    17,    10,    12,    13,    14,    15,    16,    25,    26,
      31,    32,    34,    10,     4,     4,     4,    18,    40,    11,
      18,    10,    17,    17,    17,    48,    18,    18,    11,    10,
      11,    25,    18,    18,    80,    24,    49,    50,    74,    74,
      74,    74,    24,    24,    24,    10,    74,    74,    74,    74,
      74,    10,    74,    10,    74,    74,    74,    74,    74,    74,
      11,    74,    74,    74,    74,    10,     3,     3,    74,     3,
      24,    18,    17,    17,    48,    18,    18,    18,    18,    18,
      18,    74,    74,    74,    11,    18,    18,    18,    74,    24,
      37,    39,    67,    69,    70,    71,    72,    79,    81,    82,
      83,    84,    85,    86,    89,    92,    37,    39,    67,    69,
      70,    71,    72,    79,    81,    82,    83,    84,    89,    90,
      91,    92,    11,    80,    10,    11,    74,    18,    11,    11,
      11,    45,    11,    11,    11,    11,    11,    11,    11,    11,
       4,    86,    11,    11,    11,    11,    11,    11,    11,    11,
       4,    91,    24,    81,    82,    94,     4,    47,    18,    28,
      87,    88,    18,    11,    48,    80,     3,    27,    28,    88,
       3,    11,    48,    85,    17,    27,    37,    39,    67,    69,
      70,    71,    72,    79,    81,    82,    83,    84,    89,    92,
      95,    96,    11,     4,    74,    17,    11,    11,    11,    11,
      11,    11,    11,    11,     4,    96,    18,    74,     3,    18,
      85,     3,     4,    85,     4
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    68,    68,
      68,    69,    69,    69,    70,    70,    70,    71,    71,    72,
      73,    73,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    78,    78,    79,    80,    80,    81,    81,    82,
      82,    83,    84,    84,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    88,    89,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     8,     7,     7,     8,     7,
       7,     8,     7,     5,     4,     3,     1,     1,     1,     4,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     5,     4,
       6,     7,     7,     7,     6,    10,     9,     8,     4,     4,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     4,     4,     3,     3,     2,     2,     2,
       3,     2,     4,     4,     4,     1,     1,     4,     4,     4,
       1,     4,     3,     1,     1,     1,     1,     1,     1,     4,
       6,     5,     1,     3,     4,     3,     1,     2,     2,     3,
       6,     2,     9,     8,     8,     7,     2,     1,     2,     1,
       1,     2,     2,     2,     2,     1,     2,     2,     1,     1,
       1,     2,     9,     8,     4,     7,     2,     1,     2,     1,
       1,     2,     2,     2,     2,     1,     2,     2,     1,     1,
       1,     2,    11,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       1,     1,     1,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "LLAVEABRE", "LLAVECIERRA", "RINT",
  "RFLOAT", "RSTRING", "RBOOL", "RPRINTF", "IGUAL", "PTCOMA", "OPSUMA",
  "OPRESTA", "OPMULTIPLICACION", "OPDIVISION", "OPMODULO", "PARABRE",
  "PARCIERRA", "TIPO_INTEGER", "TIPO_FLOAT", "TIPO_STRING",
  "TIPO_BOOL_TRUE", "TIPO_BOOL_FALSE", "ID", "MAYOR", "MENOR", "R_IF",
  "R_ELSE", "R_MAIN", "RVOID", "RAND", "ROR", "NOT", "NOIGUAL", "RWHILE",
  "RFOR", "RBREAK", "MASMAS", "RCONTINUE", "COMA", "RIOTA", "RATOI",
  "RATOF", "RSTRUCT", "PUNTO", "RVECTOR", "CORABRE", "CORCIERRA", "RGET",
  "RSIZE", "RPUSHBACK", "RPUSHFRONT", "RREMOVE", "RRETURN", "RMEAN",
  "RMEDIAN", "RMODE", "$accept", "inicio", "list_func", "funcion",
  "dec_list", "otro_tipo_func", "func_list", "list_inst_func",
  "instruccion_funcion", "instruccion_return", "call_instruction",
  "instrucciones_vector", "declaracion_arreglo", "creation_struct",
  "declaracion", "tipo", "expresion", "call_expr", "primitivo",
  "op_vector", "llamada_variable", "func_printf",
  "lista_expresiones_printf", "incremento_instruccion", "asignacion",
  "declaracion_sin_valor", "instruccion_if", "cuerpo_if",
  "instruccion_if_cuerpo", "list_elseif", "list_else", "instruccion_while",
  "cuerpo_while", "instruccion_while_cuerpo", "instruccion_for",
  "declaracion_for", "incremento_for", "cuerpo_for",
  "instruccion_for_cuerpo", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   260,   260,   265,   269,   275,   276,   277,   281,   282,
     283,   287,   288,   289,   294,   298,   303,   304,   305,   309,
     313,   319,   323,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   344,   345,   352,   353,
     354,   356,   357,   358,   361,   362,   363,   367,   370,   373,
     377,   378,   379,   380,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   412,   413,   416,   420,   423,   424,   425,   426,   429,
     430,   431,   434,   435,   438,   441,   445,   451,   452,   455,
     456,   459,   462,   463,   464,   465,   468,   472,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   494,   498,   505,   508,   513,   517,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   539,   542,   543,   544,   547,   548,   551,   555,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 3281 "parser.cpp"

#line 577 "parser.y"



void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
    ctx.erroresEncontrados  = true;
    std::string contenido = "";
    contenido += m;
    error_analisis *ero = new error_analisis(l.begin.line, l.begin.column,2, contenido);
    ctx.lista_errores.push_back(ero);
}

