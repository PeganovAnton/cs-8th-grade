#include <QApplication>
#include <QLabel>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QLabel lbl;
    lbl.setText("I am the Widget!");
    lbl.setGeometry(200, 200, 300, 150);
    lbl.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont arial_black("Arial Black", 12);
    lbl.setFont(arial_black);
    lbl.show();
    return app.exec();
}
