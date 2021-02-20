#include <iostream>
#include <fstream>
#include <string>
#include <writefile.h>
#include <wiringPi.h>
#include "mainwindow.h"
#include <QApplication>

using namespace std;

extern int notevalue;
extern int octavevalue;
extern int volume;
extern int timestamp;
extern QString filename;

writefile::writefile()
{
    std::ofstream file (filename.toStdString(), std::ios::app);

    char note1;
    char note2;

    if (notevalue == 12){note1 = 'B';note2 = ' ';}
    if (notevalue == 11){note1 = 'A';note2 = '#';}
    if (notevalue == 10){note1 = 'A';note2 = ' ';}
    if (notevalue ==  9){note1 = 'G';note2 = '#';}
    if (notevalue ==  8){note1 = 'G';note2 = ' ';}
    if (notevalue ==  6){note1 = 'F';note2 = '#';}
    if (notevalue ==  7){note1 = 'F';note2 = ' ';}
    if (notevalue ==  5){note1 = 'E';note2 = ' ';}
    if (notevalue ==  4){note1 = 'D';note2 = '#';}
    if (notevalue ==  3){note1 = 'D';note2 = ' ';}
    if (notevalue ==  2){note1 = 'C';note2 = '#';}
    if (notevalue ==  1){note1 = 'C';note2 = ' ';}
    file << note1 << note2 << " " << octavevalue << " " << volume << " " << timestamp << endl;

}
