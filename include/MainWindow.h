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

signals:

public slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_comboBox_Octave_activated(int index);
    void on_comboBox_Note_activated(int index);
    void on_checkBox_Octave_toggled(bool checked);
    void on_checkBox_Note_toggled(bool checked);
    void on_comboBox_Samples_activated(const QString &arg1);
    void on_pushButton_TakeSamples_clicked();
    void on_checkBox_TurtleMode_toggled(bool checked);
    void on_checkBox_RD_toggled(bool checked);
    void on_checkBox_CS_toggled(bool checked);
    void on_checkBox_CONVST_toggled(bool checked);
    void on_pushButton_Start_clicked();
private slots:



    void on_pushButton_Stop_clicked();

private:
    Ui::MainWindow *ui;
    int selection;


};

#endif // MAINWINDOW_H
