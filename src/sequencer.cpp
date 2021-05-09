#include <iostream>
#include <fstream>
#include <string>
#include <include/sequencer.h>
#include <include/gpio_input.h>
#include <include/gpio_output.h>
#include <include/writefile.h>
#include <wiringPi.h>
#include "include/MainWindow.h"
#include <QApplication>
#include <include/gpio_mapping.h>

using namespace std;        //for 'iostream' and 'string' above
int volume = 0;             //Integer to hold the volume measured

/*  PURPOSE of this object
/   To control the Note Multiplexors and the Octave Multiplexor on the Analog MUX card
/   To communicate with the ADC: tell it when to take a snapshot of the voltage on its
/   input; listen to the ADC, it will say when it is busy or not; send to the ADC the 
/   proper sequence of commands, at the proper time, for it to take snapshots.
/   To sequence through all the notes of each octave - C1 to B1, then C2 to B2, etc.
/   and after going through all notes & octaves, to start the process over again.
*/

int sequencer(int notevalue, int octavevalue, int timestamp, QString filename, bool slow)
{
    wiringPiSetup();    // enable the Raspberry PI to interface with its I/O pins

    // Tell the Raspberry PI whether the I/O pins set to variables above will be
    //    Output pins or Input pins.
    pinMode(CS,OUTPUT);         //ADC Reset active low
    pinMode(RD,OUTPUT);         //ADC read active low
    pinMode(BUSY,INPUT);        //ADC BUS is ready, 0 means yes
    pinMode(CONVST,OUTPUT);     //ADC convert active low

	/* Initialize the Output Signals (pins) to LOW or HIGH (logical '0' or logical '1')
	/  These are the lines that set up (or control) the ADC and tell it when to take 
	/  snapshots of the voltage on its input. 
    */    
    digitalWrite(CS,LOW);

        gpio_output(notevalue,octavevalue);     //output object for telling MUX what note/octave we want.

        digitalWrite(RD,LOW);                   // Tell the ADC to take a snapshot of the voltage on its input

        if(slow){delay(1000);}
        digitalWrite(CONVST,LOW);
        delayMicroseconds(1);
        if(slow){delay(1000);}
        digitalWrite(CONVST,HIGH);
        //while(1){                               // see if the ADC is busy doing an Analog-to-Digital conversion (BUSY == 1).
        //    if (digitalRead(BUSY)>0){break;}    // when it is no longer busy (BUSY==0), break out of the while loop.
        //}
        if(slow){delay(1000);}
        volume = gpio_input();  //input object reads volume from ADC
        digitalWrite(RD,HIGH);  // return the Read (RD) line to HIGH when done
        if(slow){delay(1000);}

        writefile(timestamp,volume,notevalue,octavevalue,filename);//writefile object writes to ourfile.

        return 0;
}
