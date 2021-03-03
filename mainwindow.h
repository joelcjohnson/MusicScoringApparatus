#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_EnterKeyButton_clicked();


private slots:

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
