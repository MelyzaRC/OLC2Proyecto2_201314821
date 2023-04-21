#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "AST/asttree.hpp"
#include <QFile>
#include <QTextStream>
#include <QMainWindow>
#include "Error/error_analisis.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void limpiar();
    std::string formatearCadena(std::string cadena);
    void presentarErrores(QVector<error_analisis*> lista, asttree *tree);
    void presentarTablaSimbolos(asttree *tree);
    void copiar();
    ~MainWindow();
    std::string urlArchivo;

private slots:
    void on_pushButton_clicked();

    void on_plainTextEdit_textChanged();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_actionSalir_triggered();

    void on_actionAcerca_de_triggered();

    void on_actionManuales_triggered();

    void on_actionAbrir_triggered();

    void on_actionGuardar_triggered();

    void on_actionLimpiar_triggered();

    void on_actionVer_errores_triggered();

    void on_actionVer_tabla_de_s_mbolos_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
