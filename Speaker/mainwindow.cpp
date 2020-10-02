#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <cstdlib>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioSpanish->click(); // default
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SpeakButton_clicked()
{
    fout.open("/tmp/speak.txt");

    if (ui->radioSpanish->isChecked())
        lang = "spanish";
    else if (ui->radioEnglish->isChecked())
        lang = "english";

    QString qstring = ui->LineInput->text();
    std::string str_input = qstring.toStdString();
    fout << str_input;
    fout.close();

    std::string cmd = "festival --language " + lang + " --tts /tmp/speak.txt";
    system(cmd.c_str());
}

void MainWindow::on_ClearButton_clicked()
{
    ui->LineInput->clear();
}
