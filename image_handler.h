#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QObject>
#include <QImage>

class ImageHandler : public QObject
{
    Q_OBJECT
public:
    explicit ImageHandler(QObject *parent = nullptr);

    QImage resizeImage(const QImage& image, const QSize& targetSize);
    QImage resizeImage(const QString& imagePath, const QSize& targetSize);


signals:
};

#endif // IMAGEHANDLER_H
