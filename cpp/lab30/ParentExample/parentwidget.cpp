#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include "parentwidget.h"


ParentWidget::ParentWidget(): QWidget()
{
  QLabel *lbl = new QLabel(this);
  lbl->setGeometry(50, 0, 100, 30);
  lbl->setText("TextLabel");

  QPushButton *pb = new QPushButton(this);
  pb->setGeometry(50, 50, 100, 30);
  pb->setText("PushButton");

  QLineEdit *le = new QLineEdit(this);
  le->setGeometry(50, 100, 100, 30);
  le->setText("LineEdit");
  le->selectAll();

  setGeometry(x(), y(), 300, 150);
  setWindowTitle("Parent Widget Example");
}
