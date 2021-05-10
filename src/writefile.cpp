#include "include/writefile.h"

int writefile(int timestamp,int volume, int notevalue, int octavevalue, QString filename)
{
    /*  Takes the Qstring of our filename and converts it to a std string format,
        then creates a file with that name.. the std::ios::app prevents the file from being
        overwritten everytime we open it. which is good because we open it evry single time we write a new sample.
    */
    std::ofstream ourfile(filename.toStdString(), std::ios::app);

    char note1;     //This char is for the letter of the note.
    char note2;     //This char is for the octave of the note.

    // Convert the octavevalue and notevalue into somthing we can easily read... chars will do the trick
    if (notevalue == 11){note1 = 'B';note2 = ' ';}
    if (notevalue == 10){note1 = 'A';note2 = '#';}
    if (notevalue ==  9){note1 = 'A';note2 = ' ';}
    if (notevalue ==  8){note1 = 'G';note2 = '#';}
    if (notevalue ==  7){note1 = 'G';note2 = ' ';}
    if (notevalue ==  6){note1 = 'F';note2 = '#';}
    if (notevalue ==  5){note1 = 'F';note2 = ' ';}
    if (notevalue ==  4){note1 = 'E';note2 = ' ';}
    if (notevalue ==  3){note1 = 'D';note2 = '#';}
    if (notevalue ==  2){note1 = 'D';note2 = ' ';}
    if (notevalue ==  1){note1 = 'C';note2 = '#';}
    if (notevalue ==  0){note1 = 'C';note2 = ' ';}

    /*  This line of code writes what we are recording in real time to the text document we named
        notice how I list the order note volume then timestamp.. later this will be different but now this is fine.
    */
    ourfile << note1 << note2 << " " << octavevalue+1 << " " << volume << " " << timestamp << std::endl;
    std::cout << note1 << note2 << " " << octavevalue+1 << " " << volume << " " << timestamp << std::endl;

    return 0;
}
