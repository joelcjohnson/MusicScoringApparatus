#include <include/gpio_input.h>
#include <include/gpio_mapping.h>
#include <wiringPi.h>


/*  PURPOSE of this object.  
/   To tell the Raspberry PI which of its I/O pins are inputs.
/   To initialize those inputs to either logical '0's or '1's  (LOW or HIGH).
/   To read the values on the input pins.  
*/
int gpio_input()
{
    // Tell the Raspberry PI that the I/O pins set to variables above will be Input pins.
    pinMode(ADC_00,INPUT);  //sets ADC outputs as raspberry pi inputs
    pinMode(ADC_01,INPUT);
    pinMode(ADC_02,INPUT);
    pinMode(ADC_03,INPUT);
    pinMode(ADC_04,INPUT);
    pinMode(ADC_05,INPUT);
    pinMode(ADC_06,INPUT);
    pinMode(ADC_07,INPUT);
    pinMode(ADC_08,INPUT);
    pinMode(ADC_09,INPUT);
    pinMode(ADC_10,INPUT);
    pinMode(ADC_11,INPUT);

    /*  Explanation: The output of the ADC (its 12 most significant bits) will be connected to
    /   (or wired to) the 12 I/O pins above (pins 7, 0, 2, 3, etc.).  When the Raspberry PI
    /   reads what is on the 12 I/O pins (either a '0' or a '1' on each pin), it is reading the
    /   12-bit output of the ADC.  It then puts those 12 values (of '0's and '1's) into the 12
    /   integer variables declared above (ADC_00, ADC_01, etc.)
    */

    bool ADCIn[12]; //declare an array ro hold the ADC inputs

    /*  Read the values on each of the Raspberry PI's input pins (whether a logical '0' or a
    /	logical '1', and put those values into the appropriate place in the ADCIn array. The
    /   values on the PI's input pins come from the ADC - the 12 bits of data from the ADC.
    */
    //  Initialize the 12-bit 'ADCIn' array, so it is all 0s
    ADCIn[0] = digitalRead(ADC_00); //phyisicaly reading the values of the input lines
    ADCIn[1] = digitalRead(ADC_01);
    ADCIn[2] = digitalRead(ADC_02);
    ADCIn[3] = digitalRead(ADC_03);
    ADCIn[4] = digitalRead(ADC_04);
    ADCIn[5] = digitalRead(ADC_05);
    ADCIn[6] = digitalRead(ADC_06);
    ADCIn[7] = digitalRead(ADC_07);
    ADCIn[8] = digitalRead(ADC_08);
    ADCIn[9] = digitalRead(ADC_09);
    ADCIn[10] = digitalRead(ADC_10);
    ADCIn[11] = digitalRead(ADC_11);

    //turn binary array into decimal integer
    int decimal = ADCIn[0]*1 + ADCIn[1]*2 + ADCIn[2]*4 +ADCIn[3]*8
                 +ADCIn[4]*16 +ADCIn[5]*32 +ADCIn[6]*64 +ADCIn[7]*128
                 +ADCIn[8]*256 +ADCIn[9]*512 +ADCIn[10]*1024 +ADCIn[11]*2048;


    return decimal;  //returns the decimal value of the volume
}
