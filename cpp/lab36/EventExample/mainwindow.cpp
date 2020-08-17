#include <QVBoxLayout>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    createUi();
}


MainWindow::~MainWindow()
{
}


void MainWindow::createUi()
{
    QVBoxLayout *lMainLayout = new QVBoxLayout;
    QWidget *central_widget = new QWidget(this);
    setCentralWidget(central_widget);
    central_widget->setLayout(lMainLayout);

    iconizedLineEdit = new IconizedLineEdit;
    iconizedLineEdit->setPlaceholderText("Click to open file");
    iconizedLineEdit->setIconPixmap(QPixmap(":/images/Folder.png"));
    iconizedLineEdit->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);
    lMainLayout->addWidget(iconizedLineEdit);

    iconizedLineEdit_2 = new IconizedLineEdit;
    iconizedLineEdit_2->setPlaceholderText("Enter IP address");
    iconizedLineEdit_2->setIconPixmap(QPixmap(":/images/Checkmark.png"));
    iconizedLineEdit_2->setIconVisibility(IconizedLineEdit::IconAlwaysVisible);
    lMainLayout->addWidget(iconizedLineEdit_2);

    iconizedLineEdit_3 = new IconizedLineEdit;
    iconizedLineEdit_3->setPlaceholderText("");
    iconizedLineEdit_3->setIconPixmap(QPixmap(":/images/Questions.png"));
    iconizedLineEdit_3->setIconVisibility(IconizedLineEdit::IconVisibleOnTextPresence);
    lMainLayout->addWidget(iconizedLineEdit_3);

    iconizedLineEdit_4 = new IconizedLineEdit;
    iconizedLineEdit_4->setPlaceholderText("Cannot be empty...");
    iconizedLineEdit_4->setIconPixmap(QPixmap(":/images/Warning.png"));
    iconizedLineEdit_4->setIconVisibility(IconizedLineEdit::IconVisibleOnEmptyText);
    lMainLayout->addWidget(iconizedLineEdit_4);

    iconizedLineEdit_5 = new IconizedLineEdit;
    iconizedLineEdit_5->setPlaceholderText("Clearable");
    iconizedLineEdit_5->setIconPixmap(QPixmap(":/images/X.png"));
    iconizedLineEdit_5->setIconVisibility(IconizedLineEdit::IconVisibleOnTextPresence);
    lMainLayout->addWidget(iconizedLineEdit_5);
    iconizedLineEdit_5->setIconClickable(true);
    connect(iconizedLineEdit_5, SIGNAL(iconPressed()), iconizedLineEdit_5, SLOT(slotClear()));
}
