#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <include/writefile.h>
#include <wiringPi.h>
#include "include/mainwindow.h"
#include <QApplication>
#include <QApplication>

int writefile(int timestamp,int volume, int notevalue, int octavevalue, QString filename);


#endif // WRITEFILE_H
