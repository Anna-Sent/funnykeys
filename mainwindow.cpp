#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _terminateCounter(0)
{
    _ui->setupUi(this);
    _letters.append(PictureLetter(Qt::Key_A, QString::fromUtf8("ф")));
    _letters.append(PictureLetter(Qt::Key_B, QString::fromUtf8("и")));
    _letters.append(PictureLetter(Qt::Key_C, QString::fromUtf8("с")));
    _letters.append(PictureLetter(Qt::Key_D, QString::fromUtf8("в")));
    _letters.append(PictureLetter(Qt::Key_E, QString::fromUtf8("у")));
    _letters.append(PictureLetter(Qt::Key_F, QString::fromUtf8("а")));
    _letters.append(PictureLetter(Qt::Key_G, QString::fromUtf8("п")));
    _letters.append(PictureLetter(Qt::Key_H, QString::fromUtf8("р")));
    _letters.append(PictureLetter(Qt::Key_I, QString::fromUtf8("ш")));
    _letters.append(PictureLetter(Qt::Key_J, QString::fromUtf8("о")));
    _letters.append(PictureLetter(Qt::Key_K, QString::fromUtf8("л")));
    _letters.append(PictureLetter(Qt::Key_L, QString::fromUtf8("д")));
    _letters.append(PictureLetter(Qt::Key_M, QString::fromUtf8("ь")));
    _letters.append(PictureLetter(Qt::Key_N, QString::fromUtf8("т")));
    _letters.append(PictureLetter(Qt::Key_O, QString::fromUtf8("щ")));
    _letters.append(PictureLetter(Qt::Key_P, QString::fromUtf8("з")));
    _letters.append(PictureLetter(Qt::Key_Q, QString::fromUtf8("й")));
    _letters.append(PictureLetter(Qt::Key_R, QString::fromUtf8("к")));
    _letters.append(PictureLetter(Qt::Key_S, QString::fromUtf8("ы")));
    _letters.append(PictureLetter(Qt::Key_T, QString::fromUtf8("е")));
    _letters.append(PictureLetter(Qt::Key_U, QString::fromUtf8("г")));
    _letters.append(PictureLetter(Qt::Key_V, QString::fromUtf8("м")));
    _letters.append(PictureLetter(Qt::Key_W, QString::fromUtf8("ц")));
    _letters.append(PictureLetter(Qt::Key_X, QString::fromUtf8("ч")));
    _letters.append(PictureLetter(Qt::Key_Y, QString::fromUtf8("н")));
    _letters.append(PictureLetter(Qt::Key_Z, QString::fromUtf8("я")));
    _letters.append(PictureLetter(Qt::Key_BraceLeft, QString::fromUtf8("х")));
    _letters.append(PictureLetter(Qt::Key_BraceRight, QString::fromUtf8("ъ")));
    _letters.append(PictureLetter(Qt::Key_Semicolon, QString::fromUtf8("ж")));
    _letters.append(PictureLetter(Qt::Key_Apostrophe, QString::fromUtf8("э")));
    _letters.append(PictureLetter(Qt::Key_Comma, QString::fromUtf8("б")));
    _letters.append(PictureLetter(Qt::Key_Period, QString::fromUtf8("ю")));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
}

SimpleLetter MainWindow::_terminateSequence[] = {
    SimpleLetter(Qt::Key_E, QString::fromUtf8("у")),
    SimpleLetter(Qt::Key_X, QString::fromUtf8("ч")),
    SimpleLetter(Qt::Key_I, QString::fromUtf8("ш")),
    SimpleLetter(Qt::Key_T, QString::fromUtf8("е"))
};

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //grabKeyboard();
    //grabMouse();

    for (int i = 0; i < _letters.size(); ++i)
    {
        if (_letters[i].isCatched(event))
        {
            QPixmap image = _letters[i].image();
            if (image.isNull())
            {
                _ui->label->setPixmap(image);
            }
            else
            {
                if (_ui->label->height() > _ui->label->width())
                {
                    _ui->label->setPixmap(image.scaledToWidth(_ui->label->width()));
                }
                else
                {
                    _ui->label->setPixmap(image.scaledToHeight(_ui->label->height()));
                }
            }

            break;
        }
    }

    if (_terminateSequence[_terminateCounter].isCatched(event))
    {
        _terminateCounter++;
        if (_terminateCounter * sizeof(SimpleLetter) == sizeof(_terminateSequence))
        {
            QApplication::quit();
        }
    }
    else
    {
        _terminateCounter = 0;
    }

#ifdef Q_OS_LINUX
    if (event->key() == Qt::Key_F11)
    {
        if (isMaximized())
        {
            showFullScreen();
        }
        else
        {
            showMaximized();
        }
    }
#endif
}

void MainWindow::keyReleaseEvent(QKeyEvent *)
{
    //grabKeyboard();
    //grabMouse();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    //grabKeyboard();
    //grabMouse();
}

void MainWindow::mouseMoveEvent(QMouseEvent *)
{
    //grabKeyboard();
    //grabMouse();
}

void MainWindow::mousePressEvent(QMouseEvent *)
{
    if (!isActiveWindow())
    {
        activateWindow();
    }

    //grabKeyboard();
    //grabMouse();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    //grabKeyboard();
    //grabMouse();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    grabKeyboard();
    grabMouse();
}

void MainWindow::showEvent(QShowEvent *)
{
    //grabKeyboard();
    //grabMouse();
}

MainWindow::~MainWindow()
{
    delete _ui;
}
