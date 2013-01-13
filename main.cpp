#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

#ifdef Q_OS_LINUX
    w.showMaximized();
#else
    w.showFullScreen();
#endif

    return a.exec();
}
