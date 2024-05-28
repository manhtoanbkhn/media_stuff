#include "image_handler.h"
#include <QDebug>


ImageHandler::ImageHandler(QObject *parent)
    : QObject{parent}
{}


QImage ImageHandler::resizeImage(const QImage& image, const QSize& targetSize) {
    if (image.isNull()) return QImage();
    return image.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}


QImage ImageHandler::resizeImage(const QString& imagePath, const QSize& targetSize) {
    QImage image(imagePath);
    return resizeImage(image, targetSize);
}
