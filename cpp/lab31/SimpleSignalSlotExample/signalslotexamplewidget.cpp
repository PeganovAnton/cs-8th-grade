#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextStream>

#include "signalslotexamplewidget.h"


SignalSlotExampleWidget::SignalSlotExampleWidget(): QWidget()
{
  lbl = new QLabel(this);
  lbl->setGeometry(50, 0, 100, 30);
  lbl->setText("TextLabel");

  pb = new QPushButton(this);
  pb->setGeometry(50, 50, 100, 30);
  pb->setText("PushButton");

  le = new QLineEdit(this);
  le->setGeometry(50, 100, 100, 30);
  le->setText("LineEdit");
  le->selectAll();

  setGeometry(x(), y(), 300, 150);
  setWindowTitle("Parent Widget Example");

  connect(pb, SIGNAL(clicked()), this, SLOT(slotButtonPressed()));
  connect(this, SIGNAL(signalSelf(int)), this, SLOT(slotSelf(int)));
}


void SignalSlotExampleWidget::slotButtonPressed()
{
    le->setText("Button pressed");
    emit signalSelf(10);
}


void SignalSlotExampleWidget::slotSelf(int n)
{
    QString text_num;
    QTextStream ts(&text_num);
    ts << n;
    lbl->setText(text_num);
}
