#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QLineEdit *le1 = new QLineEdit("Text 1");
    QLabel *lbl1 = new QLabel("Text edit &1");
    lbl1->setBuddy(le1);
    QHBoxLayout *h_box_layout1 = new QHBoxLayout;
    h_box_layout1->addWidget(lbl1);
    h_box_layout1->addWidget(le1);

    QLineEdit *le2 = new QLineEdit("Text 2");
    QLabel *lbl2 = new QLabel("Text edit &2");
    lbl2->setBuddy(le2);
    QHBoxLayout *h_box_layout2 = new QHBoxLayout;
    h_box_layout2->addWidget(lbl2);
    h_box_layout2->addWidget(le2);

    QPushButton *b_ok = new QPushButton("&Ok");
    QPushButton *b_cancel = new QPushButton("&Cancel");
    QHBoxLayout *h_box_layout3 = new QHBoxLayout;
    h_box_layout3->addStretch();
    h_box_layout3->addWidget(b_ok);
    h_box_layout3->addWidget(b_cancel);

    QVBoxLayout *v_box_layout = new QVBoxLayout;
    v_box_layout->addLayout(h_box_layout1);
    v_box_layout->addLayout(h_box_layout2);
    v_box_layout->addLayout(h_box_layout3);

    setLayout(v_box_layout);
}

MainWindow::~MainWindow()
{
}

