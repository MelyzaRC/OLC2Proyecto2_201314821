QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AST/asttree.cpp \
    AST/node.cpp \
    Environment/environment.cpp \
    Environment/func_symbol.cpp \
    Environment/symbol.cpp \
    Error/error.cpp \
    Error/error_analisis.cpp \
    Expression/call_exp.cpp \
    Expression/expr_atof.cpp \
    Expression/expr_atoi.cpp \
    Expression/expr_iota.cpp \
    Expression/expr_size_vector.cpp \
    Expression/func_mean.cpp \
    Expression/func_median.cpp \
    Expression/func_moda.cpp \
    Expression/incremento_expression.cpp \
    Expression/lista_expresiones.cpp \
    Expression/llamada_variable.cpp \
    Expression/map_struct_dec.cpp \
    Expression/negacion_unaria.cpp \
    Expression/operation.cpp \
    Expression/primitive.cpp \
    Expression/struct_access.cpp \
    Expression/vector_access.cpp \
    Instruction/asignacion_variable.cpp \
    Instruction/call_inst.cpp \
    Instruction/create_struct.cpp \
    Instruction/create_vector.cpp \
    Instruction/declaracion_sin_valor.cpp \
    Instruction/declaracion_struct.cpp \
    Instruction/declaration.cpp \
    Instruction/func_main.cpp \
    Instruction/func_printf.cpp \
    Instruction/function.cpp \
    Instruction/incremento.cpp \
    Instruction/instruction_asign_struct.cpp \
    Instruction/instruction_break.cpp \
    Instruction/instruction_continue.cpp \
    Instruction/instruction_for.cpp \
    Instruction/instruction_if.cpp \
    Instruction/instruction_push_back.cpp \
    Instruction/instruction_push_front.cpp \
    Instruction/instruction_return.cpp \
    Instruction/instruction_vector_asignacion.cpp \
    Instruction/instruction_vector_remove.cpp \
    Instruction/instruction_while.cpp \
    Instruction/list_instruction.cpp \
    Instruction/list_instruction_second.cpp \
    Interface/expression.cpp \
    Interface/instruction.cpp \
    main.cpp \
    mainwindow.cpp \
    parser.cpp \
    parserctx.cpp

HEADERS += \
    AST/asttree.hpp \
    AST/node.hpp \
    Environment/environment.hpp \
    Environment/func_symbol.hpp \
    Environment/symbol.hpp \
    Environment/type.hpp \
    Error/error.hpp \
    Error/error_analisis.hpp \
    Error/type_error.hpp \
    Expression/call_exp.hpp \
    Expression/expr_atof.hpp \
    Expression/expr_atoi.hpp \
    Expression/expr_iota.hpp \
    Expression/expr_size_vector.hpp \
    Expression/func_mean.hpp \
    Expression/func_median.hpp \
    Expression/func_moda.hpp \
    Expression/incremento_expression.hpp \
    Expression/lista_expresiones.hpp \
    Expression/llamada_variable.hpp \
    Expression/map_struct_dec.hpp \
    Expression/negacion_unaria.hpp \
    Expression/operation.hpp \
    Expression/primitive.hpp \
    Expression/struct_access.hpp \
    Expression/vector_access.hpp \
    Instruction/asignacion_variable.hpp \
    Instruction/create_struct.hpp \
    Instruction/create_vector.hpp \
    Instruction/declaracion_sin_valor.hpp \
    Instruction/declaracion_struct.hpp \
    Instruction/declaration.hpp \
    Instruction/func_main.hpp \
    Instruction/func_printf.hpp \
    Instruction/function.hpp \
    Instruction/incremento.hpp \
    Instruction/instruction_asign_struct.hpp \
    Instruction/instruction_break.hpp \
    Instruction/instruction_continue.hpp \
    Instruction/instruction_for.hpp \
    Instruction/instruction_if.hpp \
    Instruction/instruction_push_back.hpp \
    Instruction/instruction_push_front.hpp \
    Instruction/instruction_return.hpp \
    Instruction/instruction_vector_asignacion.hpp \
    Instruction/instruction_vector_remove.hpp \
    Instruction/instruction_while.hpp \
    Instruction/list_instruction.hpp \
    Instruction/list_instruction_second.hpp \
    Instruction/type_instruction.hpp \
    Interface/expression.hpp \
    Interface/instruction.hpp \
    location.hh \
    mainwindow.h \
    parser.hpp \
    parserctx.hpp \
    position.hh \
    stack.hh

FORMS += \
    mainwindow.ui

RC_ICONS = icono_app.ico



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
