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
    void on_comboBox_activated(int index);
    void on_comboBox_2_activated(int index);
    void on_checkBox_toggled(bool checked);
    void on_checkBox_2_toggled(bool checked);
    void on_comboBox_3_activated(const QString &arg1);
    void on_pushButton_2_clicked();
    void on_checkBox_3_toggled(bool checked);
    void on_checkBox_4_toggled(bool checked);
    void on_checkBox_5_toggled(bool checked);
    void on_checkBox_6_toggled(bool checked);
private slots:
    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;
    int selection;


};

#endif // MAINWINDOW_H
