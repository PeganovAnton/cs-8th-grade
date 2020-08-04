#ifndef PARENTWIDGET_H
#define PARENTWIDGET_H
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class SignalSlotExampleWidget: public QWidget
{
    Q_OBJECT
private:
    QLineEdit *le;
    QPushButton *pb;
    QLabel *lbl;
public:
    SignalSlotExampleWidget();
public slots:
    void slotButtonPressed();
    void slotSelf(int);
signals:
    void signalSelf(int);
};

#endif // PARENTWIDGET_H
