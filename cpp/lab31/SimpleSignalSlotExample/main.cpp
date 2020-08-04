#include <cstddef>
#include <QApplication>
#include <signalslotexamplewidget.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    SignalSlotExampleWidget pw;
    pw.move(100, 200);
    pw.show();
    return app.exec();
}
