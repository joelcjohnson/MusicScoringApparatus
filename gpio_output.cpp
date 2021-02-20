#include <iostream>
#include <string>
#include <gpio_output.h>
#include <wiringPi.h>

using namespace std;
extern int notevalue;
extern int octavevalue;

gpio_output::gpio_output()
{
    wiringPiSetup();
    //cout << "Hello gpio output!" << endl;

    int binaryNum1[4];
    int i = 0;
    int n = notevalue;
    while(n > 0){
        binaryNum1[i] = n%2;
        n=n/2;
        i++;
   }
    int binaryNum2[3];
    i = 0;
    n = octavevalue;
    while(n > 0){
        binaryNum2[i] = n%2;
        n=n/2;
        i++;
   }

    const int nb1 = 10;
    const int nb2 = 11;
    const int nb3 = 31;
    const int nb4 = 26;
    const int ob1 = 27;
    const int ob2 = 28;
    const int ob3 = 29;

    pinMode(nb1,OUTPUT);
    pinMode(nb2,OUTPUT);
    pinMode(nb3,OUTPUT);
    pinMode(nb4,OUTPUT);
    pinMode(ob1,OUTPUT);
    pinMode(ob2,OUTPUT);
    pinMode(ob3,OUTPUT);

    if (binaryNum1[0]==true){ digitalWrite(nb1,HIGH); }else{ digitalWrite(nb1,LOW); }
    if (binaryNum1[1]==true){ digitalWrite(nb2,HIGH); }else{ digitalWrite(nb2,LOW); }
    if (binaryNum1[2]==true){ digitalWrite(nb3,HIGH); }else{ digitalWrite(nb3,LOW); }
    if (binaryNum1[3]==true){ digitalWrite(nb4,HIGH); }else{ digitalWrite(nb4,LOW); }
    if (binaryNum2[0]==true){ digitalWrite(ob1,HIGH); }else{ digitalWrite(ob1,LOW); }
    if (binaryNum2[1]==true){ digitalWrite(ob2,HIGH); }else{ digitalWrite(ob2,LOW); }
    if (binaryNum2[2]==true){ digitalWrite(ob3,HIGH); }else{ digitalWrite(ob3,LOW); }



}


