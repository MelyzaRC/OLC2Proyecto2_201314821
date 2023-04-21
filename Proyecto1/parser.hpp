// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 37 "parser.y"

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
    
    



#line 114 "parser.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 243 "parser.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // otro_tipo_func
      // tipo
      char dummy1[sizeof (TipoDato)];

      // call_expr
      char dummy2[sizeof (call_exp*)];

      // creation_struct
      char dummy3[sizeof (create_struct*)];

      // declaracion_arreglo
      char dummy4[sizeof (create_vector*)];

      // declaracion_sin_valor
      char dummy5[sizeof (declaracion_sin_valor*)];

      // declaracion
      char dummy6[sizeof (declaration*)];

      // expresion
      // primitivo
      // op_vector
      // llamada_variable
      char dummy7[sizeof (expression*)];

      // func_printf
      char dummy8[sizeof (func_printf*)];

      // incremento_instruccion
      char dummy9[sizeof (incremento*)];

      // funcion
      // instruccion_funcion
      // call_instruction
      // instrucciones_vector
      // asignacion
      // instruccion_if_cuerpo
      // instruccion_while_cuerpo
      // declaracion_for
      // incremento_for
      // instruccion_for_cuerpo
      char dummy10[sizeof (instruction*)];

      // instruccion_for
      char dummy11[sizeof (instruction_for*)];

      // instruccion_if
      char dummy12[sizeof (instruction_if*)];

      // instruccion_return
      char dummy13[sizeof (instruction_return*)];

      // instruccion_while
      char dummy14[sizeof (instruction_while*)];

      // inicio
      // list_func
      // list_inst_func
      char dummy15[sizeof (list_instruction*)];

      // cuerpo_if
      // list_elseif
      // list_else
      // cuerpo_while
      // cuerpo_for
      char dummy16[sizeof (list_instruction_second*)];

      // lista_expresiones_printf
      char dummy17[sizeof (lista_expresiones*)];

      // dec_list
      // func_list
      char dummy18[sizeof (map_struct_dec*)];

      // LLAVEABRE
      // LLAVECIERRA
      // RINT
      // RFLOAT
      // RSTRING
      // RBOOL
      // RPRINTF
      // IGUAL
      // PTCOMA
      // OPSUMA
      // OPRESTA
      // OPMULTIPLICACION
      // OPDIVISION
      // OPMODULO
      // PARABRE
      // PARCIERRA
      // TIPO_INTEGER
      // TIPO_FLOAT
      // TIPO_STRING
      // TIPO_BOOL_TRUE
      // TIPO_BOOL_FALSE
      // ID
      // MAYOR
      // MENOR
      // R_IF
      // R_ELSE
      // R_MAIN
      // RVOID
      // RAND
      // ROR
      // NOT
      // NOIGUAL
      // RWHILE
      // RFOR
      // RBREAK
      // MASMAS
      // RCONTINUE
      // COMA
      // RIOTA
      // RATOI
      // RATOF
      // RSTRUCT
      // PUNTO
      // RVECTOR
      // CORABRE
      // CORCIERRA
      // RGET
      // RSIZE
      // RPUSHBACK
      // RPUSHFRONT
      // RREMOVE
      // RRETURN
      // RMEAN
      // RMEDIAN
      // RMODE
      char dummy19[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // END
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    LLAVEABRE = 258,               // LLAVEABRE
    LLAVECIERRA = 259,             // LLAVECIERRA
    RINT = 260,                    // RINT
    RFLOAT = 261,                  // RFLOAT
    RSTRING = 262,                 // RSTRING
    RBOOL = 263,                   // RBOOL
    RPRINTF = 264,                 // RPRINTF
    IGUAL = 265,                   // IGUAL
    PTCOMA = 266,                  // PTCOMA
    OPSUMA = 267,                  // OPSUMA
    OPRESTA = 268,                 // OPRESTA
    OPMULTIPLICACION = 269,        // OPMULTIPLICACION
    OPDIVISION = 270,              // OPDIVISION
    OPMODULO = 271,                // OPMODULO
    PARABRE = 272,                 // PARABRE
    PARCIERRA = 273,               // PARCIERRA
    TIPO_INTEGER = 274,            // TIPO_INTEGER
    TIPO_FLOAT = 275,              // TIPO_FLOAT
    TIPO_STRING = 276,             // TIPO_STRING
    TIPO_BOOL_TRUE = 277,          // TIPO_BOOL_TRUE
    TIPO_BOOL_FALSE = 278,         // TIPO_BOOL_FALSE
    ID = 279,                      // ID
    MAYOR = 280,                   // MAYOR
    MENOR = 281,                   // MENOR
    R_IF = 282,                    // R_IF
    R_ELSE = 283,                  // R_ELSE
    R_MAIN = 284,                  // R_MAIN
    RVOID = 285,                   // RVOID
    RAND = 286,                    // RAND
    ROR = 287,                     // ROR
    NOT = 288,                     // NOT
    NOIGUAL = 289,                 // NOIGUAL
    RWHILE = 290,                  // RWHILE
    RFOR = 291,                    // RFOR
    RBREAK = 292,                  // RBREAK
    MASMAS = 293,                  // MASMAS
    RCONTINUE = 294,               // RCONTINUE
    COMA = 295,                    // COMA
    RIOTA = 296,                   // RIOTA
    RATOI = 297,                   // RATOI
    RATOF = 298,                   // RATOF
    RSTRUCT = 299,                 // RSTRUCT
    PUNTO = 300,                   // PUNTO
    RVECTOR = 301,                 // RVECTOR
    CORABRE = 302,                 // CORABRE
    CORCIERRA = 303,               // CORCIERRA
    RGET = 304,                    // RGET
    RSIZE = 305,                   // RSIZE
    RPUSHBACK = 306,               // RPUSHBACK
    RPUSHFRONT = 307,              // RPUSHFRONT
    RREMOVE = 308,                 // RREMOVE
    RRETURN = 309,                 // RRETURN
    RMEAN = 310,                   // RMEAN
    RMEDIAN = 311,                 // RMEDIAN
    RMODE = 312                    // RMODE
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 58, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_LLAVEABRE = 3,                         // LLAVEABRE
        S_LLAVECIERRA = 4,                       // LLAVECIERRA
        S_RINT = 5,                              // RINT
        S_RFLOAT = 6,                            // RFLOAT
        S_RSTRING = 7,                           // RSTRING
        S_RBOOL = 8,                             // RBOOL
        S_RPRINTF = 9,                           // RPRINTF
        S_IGUAL = 10,                            // IGUAL
        S_PTCOMA = 11,                           // PTCOMA
        S_OPSUMA = 12,                           // OPSUMA
        S_OPRESTA = 13,                          // OPRESTA
        S_OPMULTIPLICACION = 14,                 // OPMULTIPLICACION
        S_OPDIVISION = 15,                       // OPDIVISION
        S_OPMODULO = 16,                         // OPMODULO
        S_PARABRE = 17,                          // PARABRE
        S_PARCIERRA = 18,                        // PARCIERRA
        S_TIPO_INTEGER = 19,                     // TIPO_INTEGER
        S_TIPO_FLOAT = 20,                       // TIPO_FLOAT
        S_TIPO_STRING = 21,                      // TIPO_STRING
        S_TIPO_BOOL_TRUE = 22,                   // TIPO_BOOL_TRUE
        S_TIPO_BOOL_FALSE = 23,                  // TIPO_BOOL_FALSE
        S_ID = 24,                               // ID
        S_MAYOR = 25,                            // MAYOR
        S_MENOR = 26,                            // MENOR
        S_R_IF = 27,                             // R_IF
        S_R_ELSE = 28,                           // R_ELSE
        S_R_MAIN = 29,                           // R_MAIN
        S_RVOID = 30,                            // RVOID
        S_RAND = 31,                             // RAND
        S_ROR = 32,                              // ROR
        S_NOT = 33,                              // NOT
        S_NOIGUAL = 34,                          // NOIGUAL
        S_RWHILE = 35,                           // RWHILE
        S_RFOR = 36,                             // RFOR
        S_RBREAK = 37,                           // RBREAK
        S_MASMAS = 38,                           // MASMAS
        S_RCONTINUE = 39,                        // RCONTINUE
        S_COMA = 40,                             // COMA
        S_RIOTA = 41,                            // RIOTA
        S_RATOI = 42,                            // RATOI
        S_RATOF = 43,                            // RATOF
        S_RSTRUCT = 44,                          // RSTRUCT
        S_PUNTO = 45,                            // PUNTO
        S_RVECTOR = 46,                          // RVECTOR
        S_CORABRE = 47,                          // CORABRE
        S_CORCIERRA = 48,                        // CORCIERRA
        S_RGET = 49,                             // RGET
        S_RSIZE = 50,                            // RSIZE
        S_RPUSHBACK = 51,                        // RPUSHBACK
        S_RPUSHFRONT = 52,                       // RPUSHFRONT
        S_RREMOVE = 53,                          // RREMOVE
        S_RRETURN = 54,                          // RRETURN
        S_RMEAN = 55,                            // RMEAN
        S_RMEDIAN = 56,                          // RMEDIAN
        S_RMODE = 57,                            // RMODE
        S_YYACCEPT = 58,                         // $accept
        S_inicio = 59,                           // inicio
        S_list_func = 60,                        // list_func
        S_funcion = 61,                          // funcion
        S_dec_list = 62,                         // dec_list
        S_otro_tipo_func = 63,                   // otro_tipo_func
        S_func_list = 64,                        // func_list
        S_list_inst_func = 65,                   // list_inst_func
        S_instruccion_funcion = 66,              // instruccion_funcion
        S_instruccion_return = 67,               // instruccion_return
        S_call_instruction = 68,                 // call_instruction
        S_instrucciones_vector = 69,             // instrucciones_vector
        S_declaracion_arreglo = 70,              // declaracion_arreglo
        S_creation_struct = 71,                  // creation_struct
        S_declaracion = 72,                      // declaracion
        S_tipo = 73,                             // tipo
        S_expresion = 74,                        // expresion
        S_call_expr = 75,                        // call_expr
        S_primitivo = 76,                        // primitivo
        S_op_vector = 77,                        // op_vector
        S_llamada_variable = 78,                 // llamada_variable
        S_func_printf = 79,                      // func_printf
        S_lista_expresiones_printf = 80,         // lista_expresiones_printf
        S_incremento_instruccion = 81,           // incremento_instruccion
        S_asignacion = 82,                       // asignacion
        S_declaracion_sin_valor = 83,            // declaracion_sin_valor
        S_instruccion_if = 84,                   // instruccion_if
        S_cuerpo_if = 85,                        // cuerpo_if
        S_instruccion_if_cuerpo = 86,            // instruccion_if_cuerpo
        S_list_elseif = 87,                      // list_elseif
        S_list_else = 88,                        // list_else
        S_instruccion_while = 89,                // instruccion_while
        S_cuerpo_while = 90,                     // cuerpo_while
        S_instruccion_while_cuerpo = 91,         // instruccion_while_cuerpo
        S_instruccion_for = 92,                  // instruccion_for
        S_declaracion_for = 93,                  // declaracion_for
        S_incremento_for = 94,                   // incremento_for
        S_cuerpo_for = 95,                       // cuerpo_for
        S_instruccion_for_cuerpo = 96            // instruccion_for_cuerpo
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_otro_tipo_func: // otro_tipo_func
      case symbol_kind::S_tipo: // tipo
        value.move< TipoDato > (std::move (that.value));
        break;

      case symbol_kind::S_call_expr: // call_expr
        value.move< call_exp* > (std::move (that.value));
        break;

      case symbol_kind::S_creation_struct: // creation_struct
        value.move< create_struct* > (std::move (that.value));
        break;

      case symbol_kind::S_declaracion_arreglo: // declaracion_arreglo
        value.move< create_vector* > (std::move (that.value));
        break;

      case symbol_kind::S_declaracion_sin_valor: // declaracion_sin_valor
        value.move< declaracion_sin_valor* > (std::move (that.value));
        break;

      case symbol_kind::S_declaracion: // declaracion
        value.move< declaration* > (std::move (that.value));
        break;

      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_primitivo: // primitivo
      case symbol_kind::S_op_vector: // op_vector
      case symbol_kind::S_llamada_variable: // llamada_variable
        value.move< expression* > (std::move (that.value));
        break;

      case symbol_kind::S_func_printf: // func_printf
        value.move< func_printf* > (std::move (that.value));
        break;

      case symbol_kind::S_incremento_instruccion: // incremento_instruccion
        value.move< incremento* > (std::move (that.value));
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
        value.move< instruction* > (std::move (that.value));
        break;

      case symbol_kind::S_instruccion_for: // instruccion_for
        value.move< instruction_for* > (std::move (that.value));
        break;

      case symbol_kind::S_instruccion_if: // instruccion_if
        value.move< instruction_if* > (std::move (that.value));
        break;

      case symbol_kind::S_instruccion_return: // instruccion_return
        value.move< instruction_return* > (std::move (that.value));
        break;

      case symbol_kind::S_instruccion_while: // instruccion_while
        value.move< instruction_while* > (std::move (that.value));
        break;

      case symbol_kind::S_inicio: // inicio
      case symbol_kind::S_list_func: // list_func
      case symbol_kind::S_list_inst_func: // list_inst_func
        value.move< list_instruction* > (std::move (that.value));
        break;

      case symbol_kind::S_cuerpo_if: // cuerpo_if
      case symbol_kind::S_list_elseif: // list_elseif
      case symbol_kind::S_list_else: // list_else
      case symbol_kind::S_cuerpo_while: // cuerpo_while
      case symbol_kind::S_cuerpo_for: // cuerpo_for
        value.move< list_instruction_second* > (std::move (that.value));
        break;

      case symbol_kind::S_lista_expresiones_printf: // lista_expresiones_printf
        value.move< lista_expresiones* > (std::move (that.value));
        break;

      case symbol_kind::S_dec_list: // dec_list
      case symbol_kind::S_func_list: // func_list
        value.move< map_struct_dec* > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TipoDato&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TipoDato& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, call_exp*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const call_exp*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, create_struct*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const create_struct*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, create_vector*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const create_vector*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, declaracion_sin_valor*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const declaracion_sin_valor*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, declaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const declaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, expression*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const expression*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, func_printf*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const func_printf*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, incremento*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const incremento*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, instruction*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const instruction*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, instruction_for*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const instruction_for*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, instruction_if*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const instruction_if*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, instruction_return*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const instruction_return*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, instruction_while*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const instruction_while*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, list_instruction*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const list_instruction*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, list_instruction_second*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const list_instruction_second*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, lista_expresiones*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const lista_expresiones*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, map_struct_dec*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const map_struct_dec*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_otro_tipo_func: // otro_tipo_func
      case symbol_kind::S_tipo: // tipo
        value.template destroy< TipoDato > ();
        break;

      case symbol_kind::S_call_expr: // call_expr
        value.template destroy< call_exp* > ();
        break;

      case symbol_kind::S_creation_struct: // creation_struct
        value.template destroy< create_struct* > ();
        break;

      case symbol_kind::S_declaracion_arreglo: // declaracion_arreglo
        value.template destroy< create_vector* > ();
        break;

      case symbol_kind::S_declaracion_sin_valor: // declaracion_sin_valor
        value.template destroy< declaracion_sin_valor* > ();
        break;

      case symbol_kind::S_declaracion: // declaracion
        value.template destroy< declaration* > ();
        break;

      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_primitivo: // primitivo
      case symbol_kind::S_op_vector: // op_vector
      case symbol_kind::S_llamada_variable: // llamada_variable
        value.template destroy< expression* > ();
        break;

      case symbol_kind::S_func_printf: // func_printf
        value.template destroy< func_printf* > ();
        break;

      case symbol_kind::S_incremento_instruccion: // incremento_instruccion
        value.template destroy< incremento* > ();
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
        value.template destroy< instruction* > ();
        break;

      case symbol_kind::S_instruccion_for: // instruccion_for
        value.template destroy< instruction_for* > ();
        break;

      case symbol_kind::S_instruccion_if: // instruccion_if
        value.template destroy< instruction_if* > ();
        break;

      case symbol_kind::S_instruccion_return: // instruccion_return
        value.template destroy< instruction_return* > ();
        break;

      case symbol_kind::S_instruccion_while: // instruccion_while
        value.template destroy< instruction_while* > ();
        break;

      case symbol_kind::S_inicio: // inicio
      case symbol_kind::S_list_func: // list_func
      case symbol_kind::S_list_inst_func: // list_inst_func
        value.template destroy< list_instruction* > ();
        break;

      case symbol_kind::S_cuerpo_if: // cuerpo_if
      case symbol_kind::S_list_elseif: // list_elseif
      case symbol_kind::S_list_else: // list_else
      case symbol_kind::S_cuerpo_while: // cuerpo_while
      case symbol_kind::S_cuerpo_for: // cuerpo_for
        value.template destroy< list_instruction_second* > ();
        break;

      case symbol_kind::S_lista_expresiones_printf: // lista_expresiones_printf
        value.template destroy< lista_expresiones* > ();
        break;

      case symbol_kind::S_dec_list: // dec_list
      case symbol_kind::S_func_list: // func_list
        value.template destroy< map_struct_dec* > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    Parser (void *scanner_yyarg, yy::location& loc_yyarg, class OCL2Proyecto1::ParserCtx & ctx_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LLAVEABRE (std::string v, location_type l)
      {
        return symbol_type (token::LLAVEABRE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LLAVEABRE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LLAVEABRE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LLAVECIERRA (std::string v, location_type l)
      {
        return symbol_type (token::LLAVECIERRA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LLAVECIERRA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LLAVECIERRA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RINT (std::string v, location_type l)
      {
        return symbol_type (token::RINT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RINT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RINT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RFLOAT (std::string v, location_type l)
      {
        return symbol_type (token::RFLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RFLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RFLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSTRING (std::string v, location_type l)
      {
        return symbol_type (token::RSTRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSTRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RSTRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBOOL (std::string v, location_type l)
      {
        return symbol_type (token::RBOOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBOOL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RBOOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPRINTF (std::string v, location_type l)
      {
        return symbol_type (token::RPRINTF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPRINTF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RPRINTF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IGUAL (std::string v, location_type l)
      {
        return symbol_type (token::IGUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IGUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IGUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PTCOMA (std::string v, location_type l)
      {
        return symbol_type (token::PTCOMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PTCOMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PTCOMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPSUMA (std::string v, location_type l)
      {
        return symbol_type (token::OPSUMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPSUMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OPSUMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPRESTA (std::string v, location_type l)
      {
        return symbol_type (token::OPRESTA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPRESTA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OPRESTA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPMULTIPLICACION (std::string v, location_type l)
      {
        return symbol_type (token::OPMULTIPLICACION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPMULTIPLICACION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OPMULTIPLICACION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPDIVISION (std::string v, location_type l)
      {
        return symbol_type (token::OPDIVISION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPDIVISION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OPDIVISION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPMODULO (std::string v, location_type l)
      {
        return symbol_type (token::OPMODULO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OPMODULO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OPMODULO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARABRE (std::string v, location_type l)
      {
        return symbol_type (token::PARABRE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PARABRE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PARABRE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARCIERRA (std::string v, location_type l)
      {
        return symbol_type (token::PARCIERRA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PARCIERRA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PARCIERRA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIPO_INTEGER (std::string v, location_type l)
      {
        return symbol_type (token::TIPO_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TIPO_INTEGER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TIPO_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIPO_FLOAT (std::string v, location_type l)
      {
        return symbol_type (token::TIPO_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TIPO_FLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TIPO_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIPO_STRING (std::string v, location_type l)
      {
        return symbol_type (token::TIPO_STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TIPO_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TIPO_STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIPO_BOOL_TRUE (std::string v, location_type l)
      {
        return symbol_type (token::TIPO_BOOL_TRUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TIPO_BOOL_TRUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TIPO_BOOL_TRUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIPO_BOOL_FALSE (std::string v, location_type l)
      {
        return symbol_type (token::TIPO_BOOL_FALSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TIPO_BOOL_FALSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TIPO_BOOL_FALSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAYOR (std::string v, location_type l)
      {
        return symbol_type (token::MAYOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MAYOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MAYOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENOR (std::string v, location_type l)
      {
        return symbol_type (token::MENOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MENOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MENOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R_IF (std::string v, location_type l)
      {
        return symbol_type (token::R_IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_R_IF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::R_IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R_ELSE (std::string v, location_type l)
      {
        return symbol_type (token::R_ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_R_ELSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::R_ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R_MAIN (std::string v, location_type l)
      {
        return symbol_type (token::R_MAIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_R_MAIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::R_MAIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RVOID (std::string v, location_type l)
      {
        return symbol_type (token::RVOID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RVOID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RVOID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RAND (std::string v, location_type l)
      {
        return symbol_type (token::RAND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RAND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RAND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ROR (std::string v, location_type l)
      {
        return symbol_type (token::ROR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ROR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ROR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (std::string v, location_type l)
      {
        return symbol_type (token::NOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOIGUAL (std::string v, location_type l)
      {
        return symbol_type (token::NOIGUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOIGUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NOIGUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RWHILE (std::string v, location_type l)
      {
        return symbol_type (token::RWHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RWHILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RWHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RFOR (std::string v, location_type l)
      {
        return symbol_type (token::RFOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RFOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RFOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBREAK (std::string v, location_type l)
      {
        return symbol_type (token::RBREAK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBREAK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RBREAK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MASMAS (std::string v, location_type l)
      {
        return symbol_type (token::MASMAS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MASMAS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MASMAS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCONTINUE (std::string v, location_type l)
      {
        return symbol_type (token::RCONTINUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RCONTINUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RCONTINUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMA (std::string v, location_type l)
      {
        return symbol_type (token::COMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::COMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIOTA (std::string v, location_type l)
      {
        return symbol_type (token::RIOTA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RIOTA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RIOTA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RATOI (std::string v, location_type l)
      {
        return symbol_type (token::RATOI, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RATOI (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RATOI, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RATOF (std::string v, location_type l)
      {
        return symbol_type (token::RATOF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RATOF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RATOF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSTRUCT (std::string v, location_type l)
      {
        return symbol_type (token::RSTRUCT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSTRUCT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RSTRUCT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUNTO (std::string v, location_type l)
      {
        return symbol_type (token::PUNTO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PUNTO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PUNTO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RVECTOR (std::string v, location_type l)
      {
        return symbol_type (token::RVECTOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RVECTOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RVECTOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CORABRE (std::string v, location_type l)
      {
        return symbol_type (token::CORABRE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CORABRE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CORABRE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CORCIERRA (std::string v, location_type l)
      {
        return symbol_type (token::CORCIERRA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CORCIERRA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CORCIERRA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RGET (std::string v, location_type l)
      {
        return symbol_type (token::RGET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RGET (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RGET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSIZE (std::string v, location_type l)
      {
        return symbol_type (token::RSIZE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSIZE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RSIZE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPUSHBACK (std::string v, location_type l)
      {
        return symbol_type (token::RPUSHBACK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPUSHBACK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RPUSHBACK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPUSHFRONT (std::string v, location_type l)
      {
        return symbol_type (token::RPUSHFRONT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPUSHFRONT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RPUSHFRONT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RREMOVE (std::string v, location_type l)
      {
        return symbol_type (token::RREMOVE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RREMOVE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RREMOVE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RRETURN (std::string v, location_type l)
      {
        return symbol_type (token::RRETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RRETURN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RRETURN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMEAN (std::string v, location_type l)
      {
        return symbol_type (token::RMEAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMEAN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RMEAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMEDIAN (std::string v, location_type l)
      {
        return symbol_type (token::RMEDIAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMEDIAN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RMEDIAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMODE (std::string v, location_type l)
      {
        return symbol_type (token::RMODE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMODE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RMODE, v, l);
      }
#endif


    class context
    {
    public:
      context (const Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      const location_type& location () const { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 1547,     ///< Last index in yytable_.
      yynnts_ = 39,  ///< Number of nonterminal symbols.
      yyfinal_ = 16 ///< Termination state number.
    };


    // User arguments.
    void *scanner;
    yy::location& loc;
    class OCL2Proyecto1::ParserCtx & ctx;

  };

  inline
  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
    };
    // Last valid token kind.
    const int code_max = 312;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_otro_tipo_func: // otro_tipo_func
      case symbol_kind::S_tipo: // tipo
        value.copy< TipoDato > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_call_expr: // call_expr
        value.copy< call_exp* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_creation_struct: // creation_struct
        value.copy< create_struct* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaracion_arreglo: // declaracion_arreglo
        value.copy< create_vector* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaracion_sin_valor: // declaracion_sin_valor
        value.copy< declaracion_sin_valor* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaracion: // declaracion
        value.copy< declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_primitivo: // primitivo
      case symbol_kind::S_op_vector: // op_vector
      case symbol_kind::S_llamada_variable: // llamada_variable
        value.copy< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_printf: // func_printf
        value.copy< func_printf* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_incremento_instruccion: // incremento_instruccion
        value.copy< incremento* > (YY_MOVE (that.value));
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
        value.copy< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_for: // instruccion_for
        value.copy< instruction_for* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_if: // instruccion_if
        value.copy< instruction_if* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_return: // instruccion_return
        value.copy< instruction_return* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruccion_while: // instruccion_while
        value.copy< instruction_while* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_inicio: // inicio
      case symbol_kind::S_list_func: // list_func
      case symbol_kind::S_list_inst_func: // list_inst_func
        value.copy< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cuerpo_if: // cuerpo_if
      case symbol_kind::S_list_elseif: // list_elseif
      case symbol_kind::S_list_else: // list_else
      case symbol_kind::S_cuerpo_while: // cuerpo_while
      case symbol_kind::S_cuerpo_for: // cuerpo_for
        value.copy< list_instruction_second* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lista_expresiones_printf: // lista_expresiones_printf
        value.copy< lista_expresiones* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dec_list: // dec_list
      case symbol_kind::S_func_list: // func_list
        value.copy< map_struct_dec* > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_otro_tipo_func: // otro_tipo_func
      case symbol_kind::S_tipo: // tipo
        value.move< TipoDato > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_call_expr: // call_expr
        value.move< call_exp* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_creation_struct: // creation_struct
        value.move< create_struct* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaracion_arreglo: // declaracion_arreglo
        value.move< create_vector* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaracion_sin_valor: // declaracion_sin_valor
        value.move< declaracion_sin_valor* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaracion: // declaracion
        value.move< declaration* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_primitivo: // primitivo
      case symbol_kind::S_op_vector: // op_vector
      case symbol_kind::S_llamada_variable: // llamada_variable
        value.move< expression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_func_printf: // func_printf
        value.move< func_printf* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_incremento_instruccion: // incremento_instruccion
        value.move< incremento* > (YY_MOVE (s.value));
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
        value.move< instruction* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instruccion_for: // instruccion_for
        value.move< instruction_for* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instruccion_if: // instruccion_if
        value.move< instruction_if* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instruccion_return: // instruccion_return
        value.move< instruction_return* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instruccion_while: // instruccion_while
        value.move< instruction_while* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_inicio: // inicio
      case symbol_kind::S_list_func: // list_func
      case symbol_kind::S_list_inst_func: // list_inst_func
        value.move< list_instruction* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cuerpo_if: // cuerpo_if
      case symbol_kind::S_list_elseif: // list_elseif
      case symbol_kind::S_list_else: // list_else
      case symbol_kind::S_cuerpo_while: // cuerpo_while
      case symbol_kind::S_cuerpo_for: // cuerpo_for
        value.move< list_instruction_second* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_lista_expresiones_printf: // lista_expresiones_printf
        value.move< lista_expresiones* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dec_list: // dec_list
      case symbol_kind::S_func_list: // func_list
        value.move< map_struct_dec* > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

} // yy
#line 3246 "parser.hpp"




#endif // !YY_YY_PARSER_HPP_INCLUDED
