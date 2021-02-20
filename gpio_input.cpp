#include <iostream>
#include <string>
#include <gpio_input.h>
#include <wiringPi.h>

using namespace std;
extern int volume;
extern const int CONVST = 16;

gpio_input::gpio_input()
{
 wiringPiSetup();


    pinMode(CONVST,OUTPUT);
    digitalWrite(CONVST,HIGH);

    const int ADC_00 = 7;   //declares ADC output/ Pi Inputs
    const int ADC_01 = 0;
    const int ADC_02 = 2;
    const int ADC_03 = 3;
    const int ADC_04 = 21;
    const int ADC_05 = 22;
    const int ADC_06 = 23;
    const int ADC_07 = 24;
    const int ADC_08 = 25;
    const int ADC_09 = 1;
    const int ADC_10 = 4;
    const int ADC_11 = 5;

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

    bool ADCIn[12]; //sets all values in the array to 0
        for (int i=0;i<12;i++){
            ADCIn[i] = 0;
    }

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

    //prints The read ADC input bool array values
    for (int i=0;i<12;i++){
       //cout << "ADC " << i << " = " << ADCIn[i] << endl;
}

    //turn binary array into decimal integer
    int decimal = ADCIn[0]*1 + ADCIn[1]*2 + ADCIn[2]*4 +ADCIn[3]*8 +ADCIn[4]*16 +ADCIn[5]*32 +ADCIn[6]*64 +ADCIn[7]*128 +ADCIn[8]*256 +ADCIn[9]*512 +ADCIn[10]*1024 +ADCIn[11]*2048;
       //cout << "decimal Value = " << decimal << endl;

       volume = decimal;


    digitalWrite(CONVST,LOW);
}
