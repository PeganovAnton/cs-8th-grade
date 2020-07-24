#include <cstddef>
#include <QApplication>
#include <parentwidget.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    ParentWidget pw;
    pw.move(100, 200);
    pw.show();
    return app.exec();
}
