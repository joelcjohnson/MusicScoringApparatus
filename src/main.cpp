#include <QApplication>
#include <include/MainWindow.h>

/*
 * Initialize the GPIO upfront since wiringpi doesn't release
 * the gpio until program is closed.
 */
int initialize_gpio(){
    //not implemented a.t.m.
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* Our main funtion initialises the mainwindow object for our user input.
     * Whether or not the sequecer is being used depends now now depends on
     * the mainwindow. Therefore the sequencer is called by the mainwindow.
     */
    MainWindow w;
    w.show();
    return a.exec();
}
