#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QLCDNumber>

#include "calculatormainwindow.h"

CalculatorMainWindow::CalculatorMainWindow(QWidget *parent)
    : QWidget(parent)
{
    resize(300, 500);
    setWindowTitle("Simple Calculator");
    createWidgets();
}

CalculatorMainWindow::~CalculatorMainWindow()
{
}

void CalculatorMainWindow::createWidgets()
{
    QGridLayout *lCalcLayout = new QGridLayout ;
    setLayout(lCalcLayout);

    lcdNumber = new QLCDNumber ;
    pushButtonC = new QPushButton("C");
    pushButtonP = new QPushButton("+");

    pushButton_1 = new QPushButton("1");
    pushButton_2 = new QPushButton("2");
    pushButton_3 = new QPushButton("3");
    pushButtonM = new QPushButton("-");

    pushButton_4 = new QPushButton("4");
    pushButton_5 = new QPushButton("5");
    pushButton_6 = new QPushButton("6");
    pushButtonUM = new QPushButton("*");

    pushButton_7 = new QPushButton("7");
    pushButton_8 = new QPushButton("8");
    pushButton_9 = new QPushButton("9");
    pushButtonDEL = new QPushButton("/");

    pushButton_0 = new QPushButton("0");
    pushButtonSTE = new QPushButton("^");
    pushButtonFC = new QPushButton(QChar(0x221A));
    pushButtonRAV = new QPushButton("=");

    lCalcLayout->addWidget(lcdNumber, 0, 0, 1, 2);
    lCalcLayout->addWidget(pushButtonC, 0, 2);
    lCalcLayout->addWidget(pushButtonP, 0, 3);

    lCalcLayout->addWidget(pushButton_1, 1, 0);
    lCalcLayout->addWidget(pushButton_2, 1, 1);
    lCalcLayout->addWidget(pushButton_3, 1, 2);
    lCalcLayout->addWidget(pushButtonM, 1, 3);

    lCalcLayout->addWidget(pushButton_4, 2, 0);
    lCalcLayout->addWidget(pushButton_5, 2, 1);
    lCalcLayout->addWidget(pushButton_6, 2, 2);
    lCalcLayout->addWidget(pushButtonUM, 2, 3);

    lCalcLayout->addWidget(pushButton_7, 3, 0);
    lCalcLayout->addWidget(pushButton_8, 3, 1);
    lCalcLayout->addWidget(pushButton_9, 3, 2);
    lCalcLayout->addWidget(pushButtonDEL, 3, 3);

    lCalcLayout->addWidget(pushButton_0, 4, 0);
    lCalcLayout->addWidget(pushButtonFC, 4, 1);
    lCalcLayout->addWidget(pushButtonSTE, 4, 2);
    lCalcLayout->addWidget(pushButtonRAV, 4, 3);

    pushButton_0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButton_9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    pushButtonP->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonM->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonUM->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonDEL->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonSTE->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonFC->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonC->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    pushButtonRAV->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    qDebug() << lCalcLayout->rowStretch(0) << " ";
    qDebug() << lCalcLayout->rowStretch(1) << " ";
    qDebug() << lCalcLayout->rowStretch(2) << " ";
    qDebug() << lCalcLayout->rowStretch(3) << " ";
    qDebug() << lCalcLayout->rowStretch(4) << " ";
}

