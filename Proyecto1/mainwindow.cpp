#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "parserctx.cpp"
#include "QProcess"
#include <iostream>
#include <string>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <fstream>
#include <QDesktopServices>
#include "Environment/generator_code.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget_2->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    limpiar();
    environment *GlobalEnv = new environment(nullptr, "globalEnv");
    asttree *Root = new asttree();

    ui->textEdit->setText("");
    OCL2Proyecto1::ParserCtx analizador;
    analizador.Analizar(ui->plainTextEdit->toPlainText().toStdString());



    if(analizador.erroresEncontrados == true){
        QMessageBox *msg = new QMessageBox();
        msg->setText("Análisis terminado con errores\nNo se ejecutará ninguna acción");
        msg->exec();
        std::cout<<"Errores encontrados: " <<analizador.lista_errores.size()<<std::endl;
        ui->textEdit->setText("");
        ui->textEdit_2->setText("");
        ui->textEdit_4->setText("");
        ui->textEdit_5->setText("");
        presentarErrores(analizador.lista_errores, Root);
    }else{
       /*if(analizador.Functions != nullptr)
       {
           //std::cout<<analizador.Functions->ListInst.size()<<std::endl;
          analizador.Functions->ejecutar2(GlobalEnv, Root);
          Root->errores.clear();
       }
       Root->errores.clear();
        analizador.Main->ejecutar(GlobalEnv, Root);
        std::string salidaConsola = formatearCadena(analizador.Main->cadenaPrint);

        ui->textEdit->setText(QString::fromStdString(salidaConsola));
        if(Root->erroresSemanticos>0){
            presentarErrores(*new QVector<error_analisis*> , Root);
        }
        */
        generator_code *GeneratorC3D = new generator_code();
        analizador.Main->traducir(GlobalEnv, Root, GeneratorC3D);
        if(Root->erroresSemanticos>0){
            presentarErrores(*new QVector<error_analisis*> , Root);
        }
        GeneratorC3D->MainCode = true;
        GeneratorC3D->GenerateFinalCode();
        ui->textEdit->setText(QString::fromStdString(GeneratorC3D->FinalCode));
        //this->presentarTablaSimbolos(Root);
    }
}

void MainWindow::presentarTablaSimbolos(asttree *tree){
    if(tree->cadenaTab != ""){
        std::string htmlCadena = "<html><head></head><body><center>";
        htmlCadena += "<h2 margin=\"25\"><font color=\"#3C369A\">Reporte de Tabla de símbolos</font></h2></br></br>";
        htmlCadena += tree->cadenaTab;
        htmlCadena += "</center></body></html>";
        ui->textEdit_5->setHtml(QString::fromStdString(htmlCadena));
    }
}

void MainWindow::presentarErrores(QVector<error_analisis*> lista, asttree *tree){
    std::string htmlCadena = "<html><head></head><body><center>";
    htmlCadena += "<h2 margin=\"25\"><font color=\"#3C369A\">Reporte de errores</font></h2></br></br>";
    //ERRORES LEXICOS
    htmlCadena += "</br><table>";
    htmlCadena += "<tr><td colspan=\"4\" bgcolor=\"#4942B4\"><center><font color=\"#FFFFFF\"><h2 margin=\"25\">Errores léxicos</h2></font></center></td></tr>";
    htmlCadena += "<tr>";
    htmlCadena += "<td width=\"75\" bgcolor=\"#BCB8F4\"><center><b>Línea</b></center></td>";
    htmlCadena += "<td width=\"75\" bgcolor=\"#BCB8F4\"><center><b>Columna</b></center></td>";
    htmlCadena += "<td width=\"75\" bgcolor=\"#BCB8F4\"><center><b>Tipo</b></center></td>";
    htmlCadena += "<td width=\"250\" bgcolor=\"#BCB8F4\"><center><b>Descripción</b></center></td>";
    htmlCadena += "</tr>";
    if(lista.size()>0){
        for(int i = 0; i<lista.size(); i++){
            if(lista.value(i)->tipo == 1){ //1 = error lexico

            }
        }
    }
    htmlCadena += "</table></br></br>";
    //ERRORES SINTACTICOS
    htmlCadena += "</br><table>";
    htmlCadena += "<tr><td colspan=\"4\" bgcolor=\"#7C42B4\"><center><font color=\"#FFFFFF\"><h2 margin=\"25\">Errores sintácticos</h2></font></center></td></tr>";
    htmlCadena += "<tr>";
    htmlCadena += "<td width=\"75\" bgcolor=\"#C18BF4\"><center><b>Línea</b></center></td>";
    htmlCadena += "<td width=\"75\" bgcolor=\"#C18BF4\"><center><b>Columna</b></center></td>";
    htmlCadena += "<td width=\"75\" bgcolor=\"#C18BF4\"><center><b>Tipo</b></center></td>";
    htmlCadena += "<td width=\"250\" bgcolor=\"#C18BF4\"><center><b>Descripción</b></center></td>";
    htmlCadena += "</tr>";
    if(lista.size()>0){
        for(int i = 0; i<lista.size(); i++){
            if(lista.value(i)->tipo == 2){ //2 = error sintactico
                htmlCadena +=  "<tr>";
                htmlCadena +=  "<td width=\"100\">";
                htmlCadena +=  std::to_string(lista.value(i)->Line);
                htmlCadena +=  "</td>";
                htmlCadena +=  "<td width=\"100\">";
                htmlCadena +=  std::to_string(lista.value(i)->Col);
                htmlCadena +=  "</td>";
                htmlCadena +=  "<td width=\"100\">";
                htmlCadena +=  "SINTÁCTICO";
                htmlCadena +=  "</td>";
                htmlCadena +=  "<td width=\"500\">";
                htmlCadena +=  lista.value(i)->contenido;
                htmlCadena +=  "</td>";
                htmlCadena += "</tr>";
            }
        }
    }
    htmlCadena += "</table></br></br>";

    //ERRORES SEMANTICOS
    htmlCadena += "</br><table>";
    htmlCadena += "<tr><td colspan=\"4\" bgcolor=\"#CC11E9\"><center><font color=\"#FFFFFF\"><h2 margin=\"25\">Errores semánticos</h2></font></center></td></tr>";
    htmlCadena += "<tr>";
    htmlCadena += "<td width=\"75\" bgcolor=\"#EA94F8\"><center><b>Línea</b></center></td>";
    htmlCadena += "<td width=\"75\" bgcolor=\"#EA94F8\"><center><b>Columna</b></center></td>";
    htmlCadena += "<td width=\"75\" bgcolor=\"#EA94F8\"><center><b>Tipo</b></center></td>";
    htmlCadena += "<td width=\"250\" bgcolor=\"#EA94F8\"><center><b>Descripción</b></center></td>";
    htmlCadena += "</tr>";
    if(tree->errores.size()>0){
        for(int i = 0; i<tree->errores.size(); i++){
            if(tree->errores.value(i).tipo == 3){
                htmlCadena +=  "<tr>";
                htmlCadena +=  "<td width=\"100\"><center>";
                htmlCadena +=  std::to_string(tree->errores.value(i).Line);
                htmlCadena +=  "</center></td>";
                htmlCadena +=  "<td width=\"100\"><center>";
                htmlCadena +=  std::to_string(tree->errores.value(i).Col);
                htmlCadena +=  "</center></td>";
                htmlCadena +=  "<td width=\"100\">";
                htmlCadena +=  "<center>SEMÁNTICO</center>";
                htmlCadena +=  "</td>";
                htmlCadena +=  "<td width=\"500\">";
                htmlCadena +=  tree->errores.value(i).contenido;
                htmlCadena +=  "</td>";
                htmlCadena += "</tr>";
            }
        }
    }
    htmlCadena += "</table></br></br>";
    //FIN TIPOS ERROR
    htmlCadena += "</center></body></html>";
    ui->textEdit_4->setHtml(QString::fromStdString(htmlCadena));
}

void MainWindow::limpiar(){
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->textEdit_4->setText("");
    ui->textEdit_5->setText("");
}


//FORMATEAR CADENA DE SALIDA SUSTITUYENDO CARACTERES DE ESCAPE
//ESTE METODO SE APLICA A LA CADENA DE SALIDA A CONSOLA POSTERIOR AL ANALISIS Y
//ANTES DE MANDAR A IMPRIMIR AL PLAIN TEXT EDIT
std::string  MainWindow::formatearCadena(std::string cadena){
    //SALTOS DE LINEA
    std::string salto = "\\n";
    std::string saltoReplace = "\n";
    //COMILLAS
    std::string comilla = "\\\"";
    std::string comillaReplace = "\"";
    //TABULADORES
    std::string tabulador = "\\t";
    std::string tabuladorReplace = "      ";

    size_t pos;
    while ((pos = cadena.find(salto)) != std::string::npos) {
        cadena.replace(pos, 2, saltoReplace);
    }
    while ((pos = cadena.find(comilla)) != std::string::npos) {
        cadena.replace(pos, 2, comillaReplace);
    }
    while ((pos = cadena.find(tabulador)) != std::string::npos) {
        cadena.replace(pos, 2, tabuladorReplace);
    }
    return cadena;
}


void MainWindow::on_plainTextEdit_textChanged()
{
}

void MainWindow::on_actionSalir_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "OLC2", "¿Desea salir de la aplicación?",
                                   QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }

}


void MainWindow::on_actionAcerca_de_triggered()
{
    std::string acerca_de = "Melyza Alejandra Rodriguez Contreras";
    acerca_de += "\n201314821";
    acerca_de += "\n2593602600101@ingenieria.usac.edu.gt";
    acerca_de += "\n\nProyecto 2";
    acerca_de += "\nLaboratorio de Organización de Lenguajes y Compiladores 2";
    acerca_de += "\nPrimer Semestre, 2023";
    QMessageBox::information(this,"OLC2", QString::fromStdString(acerca_de), QMessageBox::Ok);
}


void MainWindow::on_actionManuales_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "OLC2", "¿Desea abrir el navegador?",
                                   QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QString link = "https://github.com/MelyzaRC/OLC2Proyecto1#readme";
        QDesktopServices::openUrl(QUrl(link));
    }



}


void MainWindow::on_actionAbrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                "OLC2 - Abrir archivo miniOLC",
                "C:\\Users\\mlzdr\\OneDrive\\Escritorio\\COMPILADORES\\OLC2Proyecto1\\OLC2Proyecto1\\Proyecto1\\Utilidades",
                "Archivoc miniOLC (*.minc)");
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if(file.open(QFile::ReadOnly)){
            ui->plainTextEdit->setPlainText(file.readAll());
            urlArchivo = fileName.toStdString();
            ui->label_2->setText(QString::fromStdString(urlArchivo));
        }
    }
}


void MainWindow::on_actionGuardar_triggered()
{
    if(urlArchivo == ""){
        //Guardar como nuevo archivo
        QString path = QDir::currentPath();
            QString filename = QFileDialog::getSaveFileName(this, tr("Guardar archivo .minc"), path, tr("Archivos MINC (*.minc)"));
            if(filename.isEmpty())
                return;
            QFile file(filename);
            if(!file.open(QFile::WriteOnly | QFile::Text)){
                return;
            }
            QTextStream out(&file);
            out << ui->plainTextEdit->toPlainText();
            file.flush();
            file.close();
            urlArchivo = filename.toStdString();
            ui->label_2->setText(QString::fromStdString(urlArchivo));
            QMessageBox::information(this,"OLC2", "Archivo guardado", QMessageBox::Ok);
    }else{
        //Sobreescribir archivo
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "OLC2", "¿Desea guardar el archivo?",
                                       QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            std::ofstream file;
            file.open(urlArchivo);
            file << ui->plainTextEdit->toPlainText().toStdString();
            file.close();
            QMessageBox::information(this,"OLC2", "Archivo guardado", QMessageBox::Ok);
        } else {
            //regresa al editor
        }

    }
}


void MainWindow::on_actionLimpiar_triggered()
{
    ui->plainTextEdit->clear();
    urlArchivo = "";
    ui->label_2->setText("");
    limpiar();
}


void MainWindow::on_actionVer_errores_triggered()
{
     ui->tabWidget_2->setCurrentIndex(1);
}


void MainWindow::on_actionVer_tabla_de_s_mbolos_triggered()
{
    ui->tabWidget_2->setCurrentIndex(3);
}



void MainWindow::copiar( )
{
  QClipboard *clipboard = QApplication::clipboard( );
  QString alPortapapeles = ui->textEdit->toPlainText();
  clipboard->setText( alPortapapeles );
}

void MainWindow::on_pushButton_2_clicked()
{
    this->copiar();
    QMessageBox::information(this,"OLC2", "Texto copiado al portapapeles", QMessageBox::Ok);
}

