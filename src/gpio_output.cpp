#include <iostream>
#include <string>
#include <include/gpio_output.h>
#include <wiringPi.h>

using namespace std;        //for 'iostream' and 'string' above
extern int notevalue;
extern int octavevalue;
/*  PURPOSE of this object.
/   To tell the Raspberry PI which of its I/O pins are outputs.
/   To initialize those outputs to either logical '0's or '1's  (LOW or HIGH).
/   To change the value of the outputs, allowing the Raspberry PI to control the 
/   Music Scoring Apparatus - to control its Analog Multiplexors and its ADC.
*/

gpio_output::gpio_output()
{
    wiringPiSetup();
    //cout << "Hello gpio output!" << endl;

    // Initialize binaryNum1, an array which will contain the 4-bit Note Selector lines
    int binaryNum1[4];
    int i = 0;
    int n = notevalue;
    while(n > 0){
        binaryNum1[i] = n%2;
        n=n/2;
        i++;
   }
    // Initialize binaryNum2, an array which will contain the 3-bit Octave Selector lines
    int binaryNum2[3];
    i = 0;
    n = octavevalue;
    while(n > 0){
        binaryNum2[i] = n%2;
        n=n/2;
        i++;
   }
    // Declare variables (eg. nb2 and ob3) and associate each of them to a Raspberry PI I/O Pin.
    const int nb1 = 10;
    const int nb2 = 11;
    const int nb3 = 31;
    const int nb4 = 26;
    const int ob1 = 27;
    const int ob2 = 28;
    const int ob3 = 29;

    // Tell the Raspberry PI that the I/O pins set to variables above will be Output pins.
    pinMode(nb1,OUTPUT);
    pinMode(nb2,OUTPUT);
    pinMode(nb3,OUTPUT);
    pinMode(nb4,OUTPUT);
    pinMode(ob1,OUTPUT);
    pinMode(ob2,OUTPUT);
    pinMode(ob3,OUTPUT);

    /* Set the output pins to the values in the binaryNum1 and binaryNum2 arrays
	/  corresponding to the Note Selector Lines (4) and the Octave Selector Lines (3)
	/  A LOW value here is a logical '0';  a HIGH value here is a logical '1'
	*/
    if (binaryNum1[0]==true){ digitalWrite(nb1,HIGH); }else{ digitalWrite(nb1,LOW); }
    if (binaryNum1[1]==true){ digitalWrite(nb2,HIGH); }else{ digitalWrite(nb2,LOW); }
    if (binaryNum1[2]==true){ digitalWrite(nb3,HIGH); }else{ digitalWrite(nb3,LOW); }
    if (binaryNum1[3]==true){ digitalWrite(nb4,HIGH); }else{ digitalWrite(nb4,LOW); }
    if (binaryNum2[0]==true){ digitalWrite(ob1,HIGH); }else{ digitalWrite(ob1,LOW); }
    if (binaryNum2[1]==true){ digitalWrite(ob2,HIGH); }else{ digitalWrite(ob2,LOW); }
    if (binaryNum2[2]==true){ digitalWrite(ob3,HIGH); }else{ digitalWrite(ob3,LOW); }



}


