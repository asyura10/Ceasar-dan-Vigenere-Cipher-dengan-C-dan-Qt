#include "caesargui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CaesarGUI w;
    w.show();
    return a.exec();
}
