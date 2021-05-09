#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QtCore>

class Mythread :public QThread
{
public:
    Mythread();
    void run();
    bool running;
    QString filename;
    int samples;
    int notevalue;
    int octavevalue;
    int timestamp;
    bool slow;
    int selection;

};

#endif // MYTHREAD_H
