#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "sequencer.h"
void MainWindow::on_pushButton_clicked()
{
        sequencer();
        ui->lineEdit->setText("File Named");

}

extern QString filename;
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

        filename = arg1;


}
