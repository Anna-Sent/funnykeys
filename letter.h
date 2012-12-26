#ifndef LETTER_H
#define LETTER_H

#include <QKeyEvent>
#include <QPixmap>

class Letter
{
private:
    int _counter;
    QPixmap _image;
    QList<QString> _imageFileNames;
    int _key;
    QString _letter;
    static QPixmap *_nullImage;

public:
    Letter(int key, QString letter);
    bool isCatched(QKeyEvent *) const;
    const QPixmap &image();
};

#endif // LETTER_H
