#include "quizzdesign.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    quizzdesign w;
    w.show();
    return a.exec();
}
