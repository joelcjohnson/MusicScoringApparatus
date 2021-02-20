#include <iostream>
#include <fstream>
#include <string>
#include <sequencer.h>
#include <gpio_input.h>
#include <gpio_output.h>
#include <writefile.h>
#include <wiringPi.h>
#include "mainwindow.h"
#include <QApplication>

using namespace std;

int volume = 0;
int notevalue;
int octavevalue;
const int CONVST = 16;
int timestamp = 0;
extern QString filename;

sequencer::sequencer()
{
    wiringPiSetup();


    notevalue = 1;
    octavevalue = 1;

    const int RESET = 15;

    const int CS = 8;
    const int RD = 9;
    const int BUSY = 6;

    pinMode(RESET,OUTPUT);
    pinMode(CS,OUTPUT);
    pinMode(RD,OUTPUT);
    pinMode(BUSY,INPUT);

    digitalWrite(RESET,LOW);
    digitalWrite(RESET,HIGH);
    digitalWrite(CS,LOW);

    while(filename.toStdString() == "null"){
    }

    for (timestamp = 0;timestamp<20;timestamp++){

        gpio_output();
        while(1){
            if (digitalRead(BUSY)==0){break;}
        }
        digitalWrite(RD,LOW);
        gpio_input();
        digitalWrite(RD,HIGH);

        writefile();

        notevalue++;
        if (notevalue == 13){
            octavevalue++;
            if (octavevalue == 8){
                octavevalue = 1;}
            notevalue = 1;}


    //cout << "Hello sequencer!" << endl;

}


}
