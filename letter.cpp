#include <QDir>

#include "letter.h"

QPixmap *Letter::_nullImage = NULL;

Letter::Letter(int key, QString letter) : _counter(0), _key(key), _letter(letter)
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

bool Letter::isCatched(QKeyEvent *keyEvent) const
{
    return
            QString::compare(_letter, keyEvent->text(), Qt::CaseInsensitive) == 0
            || _key == keyEvent->key();
}

const QPixmap &Letter::image()
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
