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
extern bool running;

/*  PURPOSE of this object
/   To control the Note Multiplexors and the Octave Multiplexor on the Analog MUX card
/   To communicate with the ADC: tell it when to take a snapshot of the voltage on its
/   input; listen to the ADC, it will say when it is busy or not; send to the ADC the 
/   proper sequence of commands, at the proper time, for it to take snapshots.
/   To sequence through all the notes of each octave - C1 to B1, then C2 to B2, etc.
/   and after going through all notes & octaves, to start the process over again.
*/
int timestamp = 0;
extern QString filename;

sequencer::sequencer()
{
    wiringPiSetup();    // enable the Raspberry PI to interface with its I/O pins


    notevalue = 1;
    octavevalue = 1;

    // Declare variables (eg. CS and RD) and associate each of them to a Raspberry PI I/O Pin.
    const int RESET = 15;

    const int CS = 8;
    const int RD = 9;
    const int BUSY = 6;

    // Tell the Raspberry PI whether the I/O pins set to variables above will be 
    
	//    Output pins or Input pins.
    pinMode(RESET,OUTPUT);
    pinMode(CS,OUTPUT);
    pinMode(RD,OUTPUT);
    pinMode(BUSY,INPUT);

	/* Initialize the Output Signals (pins) to LOW or HIGH (logical '0' or logical '1')

	/  These are the lines that set up (or control) the ADC and tell it when to take 

	/  snapshots of the voltage on its input. 

    */    
    digitalWrite(RESET,LOW);
    digitalWrite(RESET,HIGH);
    digitalWrite(CS,LOW);


	//  Loop through the code in the 'for' loop.

	//  Note that the timestamp test ( '>-1' ) is always true, so the loop will go 

	//  on indefinitely. 
    for (timestamp = 0;timestamp<=84;timestamp++){

        gpio_output();
        // see if the ADC is busy doing an Analog-to-Digital conversion (BUSY == 1).
		// when it is no longer busy (BUSY==0), break out of the while loop.
        while(1){
            if (digitalRead(BUSY)==0){break;}
        }
        // Tell the ADC to take a snapshot of the voltage on its input. 
        digitalWrite(RD,LOW);
        gpio_input();
        digitalWrite(RD,HIGH); // return the Read (RD) line to HIGH when done

        writefile();

        	

        notevalue++;                    // Go to the next note.  (Increment the note selector lines, change the note MUXs)
        if (notevalue == 13){           // See if the note is incremented past a 'B' note.  If yes, then ...
            octavevalue++;              // Go to the next octave.
            if (octavevalue == 8){      // Check if incremented past 7th octave
                octavevalue = 1;}       // If yes, then set the octave value to 1;
            notevalue = 1;}             // notevalue back to '1' (the 'C' note) 
		

		

		

    //cout << "Hello sequencer!" << endl;

}


}
