#include "include/mythread.h"
#include <QtCore>
#include <QDebug>
#include <iostream>
#include <fstream>
#include "include/MainWindow.h"
#include "ui_mainwindow.h"
#include "include/sequencer.h"
#include <wiringPi.h>
#include <include/gpio_mapping.h>
#include <QString>
#include <QObject>

Mythread::Mythread()
{

}

void Mythread::run()
{
    int i = 0;
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
