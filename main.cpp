#include "mainwindow.h"
#include <QApplication>
#include <sequencer.h>

using namespace std;
QString filename = "null";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
