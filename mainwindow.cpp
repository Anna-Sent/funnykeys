#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _terminateCounter(0)
{
    _ui->setupUi(this);
    _letters.append(Letter(Qt::Key_A, QString::fromUtf8("ф")));
    _letters.append(Letter(Qt::Key_B, QString::fromUtf8("и")));
    _letters.append(Letter(Qt::Key_C, QString::fromUtf8("с")));
    _letters.append(Letter(Qt::Key_D, QString::fromUtf8("в")));
    _letters.append(Letter(Qt::Key_E, QString::fromUtf8("у")));
    _letters.append(Letter(Qt::Key_F, QString::fromUtf8("а")));
    _letters.append(Letter(Qt::Key_G, QString::fromUtf8("п")));
    _letters.append(Letter(Qt::Key_H, QString::fromUtf8("р")));
    _letters.append(Letter(Qt::Key_I, QString::fromUtf8("ш")));
    _letters.append(Letter(Qt::Key_J, QString::fromUtf8("о")));
    _letters.append(Letter(Qt::Key_K, QString::fromUtf8("л")));
    _letters.append(Letter(Qt::Key_L, QString::fromUtf8("д")));
    _letters.append(Letter(Qt::Key_M, QString::fromUtf8("ь")));
    _letters.append(Letter(Qt::Key_N, QString::fromUtf8("т")));
    _letters.append(Letter(Qt::Key_O, QString::fromUtf8("щ")));
    _letters.append(Letter(Qt::Key_P, QString::fromUtf8("з")));
    _letters.append(Letter(Qt::Key_Q, QString::fromUtf8("й")));
    _letters.append(Letter(Qt::Key_R, QString::fromUtf8("к")));
    _letters.append(Letter(Qt::Key_S, QString::fromUtf8("ы")));
    _letters.append(Letter(Qt::Key_T, QString::fromUtf8("е")));
    _letters.append(Letter(Qt::Key_U, QString::fromUtf8("г")));
    _letters.append(Letter(Qt::Key_V, QString::fromUtf8("м")));
    _letters.append(Letter(Qt::Key_W, QString::fromUtf8("ц")));
    _letters.append(Letter(Qt::Key_X, QString::fromUtf8("ч")));
    _letters.append(Letter(Qt::Key_Y, QString::fromUtf8("н")));
    _letters.append(Letter(Qt::Key_Z, QString::fromUtf8("я")));
    _letters.append(Letter(Qt::Key_BraceLeft, QString::fromUtf8("х")));
    _letters.append(Letter(Qt::Key_BraceRight, QString::fromUtf8("ъ")));
    _letters.append(Letter(Qt::Key_Semicolon, QString::fromUtf8("ж")));
    _letters.append(Letter(Qt::Key_Apostrophe, QString::fromUtf8("э")));
    _letters.append(Letter(Qt::Key_Comma, QString::fromUtf8("б")));
    _letters.append(Letter(Qt::Key_Period, QString::fromUtf8("ю")));
}

int MainWindow::_terminateSequence[] = { Qt::Key_E, Qt::Key_X, Qt::Key_I, Qt::Key_T };

void MainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    grabKeyboard();
    grabMouse();

    for (int i = 0; i < _letters.size(); ++i)
    {
        if (_letters[i].isCatched(keyEvent))
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

    if (keyEvent->key() == _terminateSequence[_terminateCounter])
    {
        _terminateCounter++;
        if (_terminateCounter * sizeof(int) == sizeof(_terminateSequence))
        {
            QApplication::quit();
        }
    }
    else
    {
        _terminateCounter = 0;
    }
}

MainWindow::~MainWindow()
{
    delete _ui;
}
