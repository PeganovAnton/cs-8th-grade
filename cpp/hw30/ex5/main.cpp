#include <QDebug>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>


int main(int argc, char **argv)
{
    if (argc != 3)
        qDebug() << "Usage: app path_to_input_file path_to_output_file\n";
    QString ifn(argv[1]);
    QString ofn(argv[2]);
    QFile inp_file(ifn);
    if (!inp_file.open(QIODevice::ReadOnly)){
        qDebug() << "Unable to open file '" + ifn << "'\n";
    }
    QString text = inp_file.readAll();
    inp_file.close();
    QStringList words = text.split(", ");
    QStringList::iterator i;
    for(i = words.begin(); i != words.end(); ++i)
        if (i->isLower())
            *i = i->toUpper();
        else if (i->isUpper())
            *i = i->toLower();
    QFile out_file(ofn);
    if (!out_file.open(QIODevice::WriteOnly))
        qDebug() << "Unable to open file '" + ofn << "'\n";
    QTextStream out(&out_file);
    out << words.join("; ");
    out.flush();
    out_file.close();
}
