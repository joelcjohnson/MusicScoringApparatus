#include <QApplication>
#include <include/sequencer.h>
#include <include/mainwindow.h>

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
