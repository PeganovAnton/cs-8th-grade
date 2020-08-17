#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "iconizedlineedit.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void createUi();
private:
    IconizedLineEdit *iconizedLineEdit;
    IconizedLineEdit *iconizedLineEdit_2;
    IconizedLineEdit *iconizedLineEdit_3;
    IconizedLineEdit *iconizedLineEdit_4;
    IconizedLineEdit *iconizedLineEdit_5;
};
#endif // MAINWINDOW_H
