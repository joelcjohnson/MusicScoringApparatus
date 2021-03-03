#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sequencer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;    //destroys object when done
}

/*
    Since we need to have some control over collecting information
    pushing this button starts the allocation of data

    (currently the number of samples taken is dependent on a variable in
    the sequener this button can only start the data allocation and not end it.)

    In the future this will be enterchanged with a start and end button.
*/
void MainWindow::on_EnterKeyButton_clicked()
{
    ui->EnterKeyButton->setDisabled("");    //This disables the Enter key when selected
    sequencer();                            //Runs the sequencer file
    ui->lineEdit->setText("File Saved");    //Changes the textbox to display "File Saved"
    ui->lineEdit->setReadOnly("");          //This disable the ability to write in the textbox
}

/*
    This funtion sets our user inputed string as the name of our .txt file
    This updates everytime the text changes in the text box...
*/
extern QString filename;
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
        filename = arg1;
        //arg1 is a QString value that the text box outputs.

}





