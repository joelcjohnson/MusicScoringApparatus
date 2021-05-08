#include "include/MainWindow.h"
#include "ui_mainwindow.h"
#include "include/sequencer.h"
#include <wiringPi.h>
#include <include/gpio_mapping.h>
#include <QString>
#include <QObject>
QString filename;
int samples;
int notevalue;
int octavevalue;
int timestamp;
bool slow;
bool running;
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox_Octave->setDisabled("");
    ui->comboBox_Note->setDisabled("");
    selection = 0;
    samples = 1;
    octavevalue = 0;
    notevalue = 0;
    slow = 0;
}

MainWindow::~MainWindow()
{
    delete ui;    //destroys object when done
}

/*
    This funtion sets ouoctavevaluer user inputed string as the name of our .txt file
    This updates everytime the text changes in the text box...
*/

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
        filename = arg1;
        //arg1 is a QString value that the text box outputs.

}
void MainWindow::on_checkBox_TurtleMode_toggled(bool checked)
{
    slow = checked;
}
void MainWindow::on_checkBox_Octave_toggled(bool checked)
{
    if (checked == 1){
        ui->comboBox_Octave->setEnabled("");
        if (selection==0){selection = 2;}
        else if (selection==1){selection = 3;}

    }
    else{
        ui->comboBox_Octave->setDisabled("");
        if (selection==2){selection = 0;}
        else if (selection==3){selection = 1;}
    }
}
void MainWindow::on_checkBox_Note_toggled(bool checked)
{
    if (checked == 1){
        ui->comboBox_Note->setEnabled("");
        if (selection==0){selection = 1;}
        else if (selection==2){selection = 3;}
    }
    else{
        ui->comboBox_Note->setDisabled("");
        if (selection==1){selection = 0;}
        else if (selection==3){selection = 2;}
    }
}


void MainWindow::on_comboBox_Octave_activated(int index)
{
    octavevalue = index;
}
void MainWindow::on_comboBox_Note_activated(int index)
{
    notevalue = index;
}
void MainWindow::on_comboBox_Samples_activated(const QString &arg1)
{
    samples = arg1.split(" ")[0].toInt();
}

void MainWindow::on_pushButton_TakeSamples_clicked()
{
    timestamp = 0;
    for (int i=0; i< samples;i++){
        sequencer(notevalue,octavevalue,timestamp,filename,slow);
        if(selection == 0){
            notevalue++;                    // Go to the next note.  (Increment the note selector lines, change the note MUXs)
            if (notevalue == 12){           // See if the note is incremented past a 'B' note.  If yes, then ...
                octavevalue++;              // Go to the next octave.
                if (octavevalue == 7){      // Check if incremented past 7th octave
                    octavevalue = 0;}       // If yes, then set the octave value to 1;
                notevalue = 0;}
        }
        else if(selection == 1){
           octavevalue++;              // Go to the next octave.
           if (octavevalue == 7){      // Check if incremented past 7th octave
               octavevalue = 0;}

        }
        else if(selection == 2){
            notevalue++;                    // Go to the next note.  (Increment the note selector lines, change the note MUXs)
            if (notevalue == 12){           // See if the note is incremented past a 'B' note.  If yes, then ...
                notevalue = 0;}
        }

        timestamp++;
    }
}




void MainWindow::on_checkBox_RD_toggled(bool checked)//RD
{
    wiringPiSetup();    // enable the Raspberry PI to interface with its I/O pins
    pinMode(RD,OUTPUT);  //ADC read active low
    if (checked==1){
        digitalWrite(RD,LOW);
    }
    else{
        digitalWrite(RD,HIGH);
    }

}

void MainWindow::on_checkBox_CS_toggled(bool checked)//CS
{
    wiringPiSetup();    // enable the Raspberry PI to interface with its I/O pins
    pinMode(CS,OUTPUT);      //ADC Reset active low
    if (checked==1){
        digitalWrite(CS,HIGH);
    }
    else{
        digitalWrite(CS,LOW);
    }
}

void MainWindow::on_checkBox_CONVST_toggled(bool checked)//CONVST
{
    pinMode(CONVST,OUTPUT);
    if (checked==1){
        digitalWrite(CONVST,LOW);
    }
    else{
        digitalWrite(CONVST,HIGH);
    }
}

void MainWindow::on_pushButton_Start_clicked()
{
    timestamp = 0;
    running=1;
    while(running==1){
        sequencer(notevalue,octavevalue,timestamp,filename,slow);
        if(selection == 0){
            notevalue++;                    // Go to the next note.  (Increment the note selector lines, change the note MUXs)
            if (notevalue == 12){           // See if the note is incremented past a 'B' note.  If yes, then ...
                octavevalue++;              // Go to the next octave.
                if (octavevalue == 7){      // Check if incremented past 7th octave
                    octavevalue = 0;}       // If yes, then set the octave value to 1;
                notevalue = 0;}
        }
        else if(selection == 1){
           octavevalue++;              // Go to the next octave.
           if (octavevalue == 7){      // Check if incremented past 7th octave
               octavevalue = 0;}

        }
        else if(selection == 2){
            notevalue++;                    // Go to the next note.  (Increment the note selector lines, change the note MUXs)
            if (notevalue == 12){           // See if the note is incremented past a 'B' note.  If yes, then ...
                notevalue = 0;}
        }

        timestamp++;
    }
}



void MainWindow::on_pushButton_Stop_clicked()
{
    running=0;
}
