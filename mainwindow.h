#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"linklist.h"
#include"queue.h"
#include"string.h"
using namespace std;
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     linklist<string> food,vege,cloth;
     queue<string> good,good1;

private slots:
    void on_ADD_clicked();

    void on_Display_clicked();

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_dis_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
