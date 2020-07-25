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
    // Строка для ввода текста
    QLineEdit *le1 = new QLineEdit("Text 1");
    // Символ & обозначает комбинацию клавиш, с помощью которой можно переключиться на виджет
    // Чтобы переключение сработало для `lbl1` нужно задать приятеля (buddy)
    QLabel *lbl1 = new QLabel("Text edit &1");
    // Теперь при нажатии комбинации клавиш Alt + 1 фокус будет устанавливаться на виджете `le1`.
    lbl1->setBuddy(le1);
    // Класс, позволяющий организовать горизонтальное размещение виджетов.
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

    // Класс, позволяющий организовать вертикальное размещение виджетов
    QVBoxLayout *v_box_layout = new QVBoxLayout;
    v_box_layout->addLayout(h_box_layout1);
    v_box_layout->addLayout(h_box_layout2);
    v_box_layout->addLayout(h_box_layout3);

    // Задаем размещение текущего виджета
    setLayout(v_box_layout);
}

MainWindow::~MainWindow()
{
}

