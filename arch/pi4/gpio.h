// Raspberry Pi 4 B configuration
#ifndef GPIO_MAP
#define GPIO_MAP

// GPIO Pin map to ADC
#define ADC_00  7
#define ADC_01  0
#define ADC_02  2
#define ADC_03  3
#define ADC_04  21
#define ADC_05  22
#define ADC_06  23
#define ADC_07  24
#define ADC_08  25
#define ADC_09  1
#define ADC_10  4
#define ADC_11  5

// Declare variables (eg. CS and RD) and associate each of them to a Raspberry PI I/O Pin.
#define CS 15
#define CONVST 30
#define RD 8
#define BUSY 6

// Declare variables (eg. nb2 and ob3) and associate each of them to a Raspberry PI I/O Pin.
#define nb1 10
#define nb2 11
#define nb3 31
#define nb4 26
#define ob1 27
#define ob2 28
#define ob3 29

#else
#error GPIO_MAP defined, remove addational GPIO mapping header files
#endif
