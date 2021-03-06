#ifndef CALCULATORMAINWINDOW_H
#define CALCULATORMAINWINDOW_H

#include <QLCDNumber>
#include <QPushButton>
#include <QSignalMapper>
#include <QWidget>

class CalculatorMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorMainWindow(QWidget *parent = nullptr);
    ~CalculatorMainWindow();
private:
    int m_sum, m_next_number;
    void createWidgets();
private :
    //Цифровые кнопки
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_0;
    QPushButton *pushButtonPlus;
    QPushButton *pushButtonC;
    QLCDNumber *lcdNumber;

    QSignalMapper *signal_mapper;
  private slots:
    void slotClear();  // Обработка нажатия кнопки сброса
    void slotButtonPressed(int p_num);  // Нажатие цифровой кнопки
    void slotPlusEqual();  // Обработка кнопки суммирования вывода результата
};
#endif // CALCULATORMAINWINDOW_H
