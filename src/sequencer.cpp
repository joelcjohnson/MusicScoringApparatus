#include <iostream>
#include <fstream>
#include <string>
#include <include/sequencer.h>
#include <include/gpio_input.h>
#include <include/gpio_output.h>
#include <include/writefile.h>
#include <wiringPi.h>
#include "include/mainwindow.h"
#include <QApplication>

using namespace std;        //for 'iostream' and 'string' above


int volume = 0;             //Integer to hold the volume measured
int notevalue;              //holds note variable
int octavevalue;            //holds ocatave varrible
const int CONVST = 16;      //

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

    notevalue = 1;      //start collecting with note 1
    octavevalue = 1;    //start collecting on ocatve 1

    // Declare variables (eg. CS and RD) and associate each of them to a Raspberry PI I/O Pin.
    const int RESET = 15;       //GPIO.15  -note for wriringpi version 2.52
    const int CONVST = 30;      //GPIO.30
    const int RD = 8;           //GPIO.8
    const int BUSY = 6;         //GPIO.6

    // Tell the Raspberry PI whether the I/O pins set to variables above will be 
	//    Output pins or Input pins.
    pinMode(RESET,OUTPUT);      //ADC Reset active low
    pinMode(RD,OUTPUT);         //ADC read active low
    pinMode(BUSY,INPUT);        //ADC BUS is ready, 0 means yes
    pinMode(CONVST,OUTPUT);     //ADC convert active low

	/* Initialize the Output Signals (pins) to LOW or HIGH (logical '0' or logical '1')
	/  These are the lines that set up (or control) the ADC and tell it when to take 
	/  snapshots of the voltage on its input. 
    */    
    digitalWrite(RESET,LOW);
    delay(20);
    digitalWrite(RESET,HIGH);


	//  Loop through the code in the 'for' loop.
	//  Note that the timestamp test ( '>-1' ) is always true, so the loop will go 
	//  on indefinitely. 
    for (timestamp = 0;timestamp<=84;timestamp++){

        digitalWrite(CONVST,HIGH);
        digitalWrite(CONVST,LOW);

        gpio_output();          //output object for telling MUX what note/octave we want.

        // see if the ADC is busy doing an Analog-to-Digital conversion (BUSY == 1).
		// when it is no longer busy (BUSY==0), break out of the while loop.
        while(1){
            if (digitalRead(BUSY)==0){break;}
        }

        digitalWrite(RD,LOW);   // Tell the ADC to take a snapshot of the voltage on its input
        gpio_input();           //input object reads volume from ADC
        digitalWrite(RD,HIGH);  // return the Read (RD) line to HIGH when done

        writefile(notevalue,octavevalue,volume,timestamp);            //writefile object writes to ourfile.
        	

        notevalue++;                    // Go to the next note.  (Increment the note selector lines, change the note MUXs)
        if (notevalue == 13){           // See if the note is incremented past a 'B' note.  If yes, then ...
            octavevalue++;              // Go to the next octave.
            if (octavevalue == 8){      // Check if incremented past 7th octave
                octavevalue = 1;}       // If yes, then set the octave value to 1;
            notevalue = 1;}             // notevalue back to '1' (the 'C' note) 

}


}
