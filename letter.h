#ifndef LETTER_H
#define LETTER_H

#include <QKeyEvent>
#include <QPixmap>

class SimpleLetter
{
protected:
    int _key;
    QString _letter;

public:
    SimpleLetter(int key, QString letter);
    bool isCatched(QKeyEvent *) const;
};

class PictureLetter : public SimpleLetter
{
private:
    int _counter;
    QPixmap _image;
    QList<QString> _imageFileNames;
    static QPixmap *_nullImage;

public:
    PictureLetter(int key, QString letter);
    const QPixmap &image();
};

#endif // LETTER_H
