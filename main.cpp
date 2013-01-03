#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();
    w.grabKeyboard();
    w.grabMouse();

    //test
    return a.exec();
}
