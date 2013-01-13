#include <QDir>

#include "letter.h"

SimpleLetter::SimpleLetter(int key, QString letter) : _key(key), _letter(letter)
{
}

bool SimpleLetter::isCatched(QKeyEvent *keyEvent) const
{
    return
            QString::compare(_letter, keyEvent->text(), Qt::CaseInsensitive) == 0
            || _key == keyEvent->key();
}

QPixmap *PictureLetter::_nullImage = NULL;

PictureLetter::PictureLetter(int key, QString letter) : SimpleLetter(key, letter), _counter(0)
{
    if (_nullImage == NULL)
    {
        _nullImage = new QPixmap();
    }

    QDir dir("alphabet_cards/" + _letter);
    if (dir.exists())
    {
        dir.setFilter(QDir::Files);
        dir.setSorting(QDir::Name);
        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            _imageFileNames.append(dir.absoluteFilePath(fileInfo.fileName()));
        }
    }
}

const QPixmap &PictureLetter::image()
{
    int imageCount = _imageFileNames.size();
    if (imageCount > 0)
    {
        _image.load(_imageFileNames[_counter]);
        _counter = (_counter + 1) % imageCount;
        return _image;
    }
    else
    {
        return *_nullImage;
    }
}
