#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"
#include "letter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *keyEvent);

private:
    Ui::MainWindow *_ui;
    QList<Letter> _letters;
    static int _terminateSequence[];
    int _terminateCounter;
};

#endif
