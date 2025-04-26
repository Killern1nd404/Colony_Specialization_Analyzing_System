#include "AnalyzingSystem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnalyzingSystem w;
    w.show();
    return a.exec();
}
