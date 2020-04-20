#include "AppManager.h"
#include <QStandardPaths>
#include <QDebug>

static const QString FILE_EXT = ".png";
static const QString NAME_SCREEN_SHOT = "ScreenShot1600x900";
static const QString NAME_HIRES_ICON = "HiresIcon512x512";
static const QString NAME_DAY_DREAM_360 = "Daydream3604096x4096";
static const QString NAME_FEATURE_GRAPHIC = "FeatureGraphic1024x500";
static const QString NAME_TV_BANNER = "PromoGraphic180x120";
static const QString NAME_PROMO_GRAPHIC = "TVBanner1280x720";

AppManager::AppManager(QObject *parent) : QObject(parent)
{

}

void AppManager::generateAndroidStoreImages()
{
    QString patName = "Pattern1";
    gen_ScreenShot(SIZE_SCREEN_SHOT, patName);
    gen_HiresIcon(SIZE_HIRES_ICON, patName);
    gen_Daydream360(SIZE_DAY_DREAM_360, patName);
    gen_FeatureGraphic(SIZE_FEATURE_GRAPHIC, patName);
    gen_PromoGraphic(SIZE_PROMO_GRAPHIC, patName);
    gen_TVBanner(SIZE_TV_BANNER, patName);

}

void AppManager::_generateIOSstoreImages()
{

}

void AppManager::gen_ScreenShot(QSize imgSize, QString patternName)
{
    if(patternName != ""){
        QImage newImg = createImageWithPattern(patternName, NAME_SCREEN_SHOT, DEFAULT_COLOR);
        QString fileName = NAME_SCREEN_SHOT + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }else{
        QImage newImg = createEmptyImage(imgSize, DEFAULT_COLOR, DEFAULT_TEXT_COLOR);
        QString fileName = NAME_SCREEN_SHOT + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }

}

void AppManager::gen_HiresIcon(QSize imgSize, QString patternName)
{
    if(patternName != ""){
        QImage newImg = createImageWithPattern(patternName, NAME_HIRES_ICON, DEFAULT_COLOR);
        QString fileName = NAME_HIRES_ICON + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }else{
        QImage newImg = createEmptyImage(imgSize, DEFAULT_COLOR, DEFAULT_TEXT_COLOR);
        QString fileName = NAME_HIRES_ICON + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }
}

void AppManager::gen_Daydream360(QSize imgSize, QString patternName)
{
    if(patternName != ""){
        QImage newImg = createImageWithPattern(patternName, NAME_DAY_DREAM_360, DEFAULT_COLOR);
        QString fileName = NAME_DAY_DREAM_360 + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }else{
        QImage newImg = createEmptyImage(imgSize, DEFAULT_COLOR, DEFAULT_TEXT_COLOR);
        QString fileName = NAME_DAY_DREAM_360 + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }
}

void AppManager::gen_FeatureGraphic(QSize imgSize, QString patternName)
{
    if(patternName != ""){
        QImage newImg = createImageWithPattern(patternName, NAME_FEATURE_GRAPHIC, DEFAULT_COLOR);
        QString fileName = NAME_FEATURE_GRAPHIC + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }else{
        QImage newImg = createEmptyImage(imgSize, DEFAULT_COLOR, DEFAULT_TEXT_COLOR);
        QString fileName = NAME_FEATURE_GRAPHIC + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }
}

void AppManager::gen_PromoGraphic(QSize imgSize, QString patternName)
{
    if(patternName != ""){
        QImage newImg = createImageWithPattern(patternName, NAME_PROMO_GRAPHIC, DEFAULT_COLOR);
        QString fileName = NAME_PROMO_GRAPHIC + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }else{
        QImage newImg = createEmptyImage(imgSize, DEFAULT_COLOR, DEFAULT_TEXT_COLOR);
        QString fileName = NAME_PROMO_GRAPHIC + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }
}

void AppManager::gen_TVBanner(QSize imgSize, QString patternName)
{
    if(patternName != ""){
        QImage newImg = createImageWithPattern(patternName, NAME_TV_BANNER, DEFAULT_COLOR);
        QString fileName = NAME_TV_BANNER + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }else{
        QImage newImg =  createEmptyImage(imgSize, DEFAULT_COLOR, DEFAULT_TEXT_COLOR);
        QString fileName = NAME_TV_BANNER + QString::number(imgSize.width()) + "x" + QString::number(imgSize.height()) + FILE_EXT;
        saveImageFile(newImg, fileName);
    }
}

QImage AppManager::createEmptyImage(QSize imgSize, QColor imgColor, QColor textColor)
{
    QImage image = QImage(imgSize, QImage::Format_ARGB32);
    image.fill(imgColor);
    QPainter painter;
    painter.begin(&image);

    QFont font = painter.font();
    font.setPixelSize(imgSize.width() / 4);

    const QRect rectangle = QRect(0, 0, imgSize.width(), imgSize.height());
    QPen pen = painter.pen();
    pen.setColor(textColor);

    painter.setFont(font);
    painter.setPen(pen);

    painter.drawText(rectangle, Qt::AlignCenter, m_appName);

    painter.end();

    return image;
}

QImage AppManager::createImageWithPattern(QString PatternName, QString fileName, QColor textColor)
{
    qDebug() << QStandardPaths::ApplicationsLocation;
    QString patternPath = ":/Patterns/" + PatternName + "/" + fileName + FILE_EXT;
    qDebug() << patternPath;
    QFile file(patternPath);
    qDebug() << file.fileName() << "   " << file.exists();
    QImage image = QImage(patternPath);

    QPainter painter;
    painter.begin(&image);

    QFont font = painter.font();
    if(image.width() > image.height()){
        font.setPixelSize(image.height() / 4);
    }else{
        font.setPixelSize(image.width() / 4);
    }


    const QRect rectangle = QRect(0, 0, image.width(), image.height());
    QPen pen = painter.pen();
    pen.setColor(textColor);

    painter.setFont(font);
    painter.setPen(pen);

    painter.drawText(rectangle, Qt::AlignCenter, m_appName);

    painter.end();

    return image;
}

void AppManager::saveImageFile(QImage image, QString fileName)
{
    image.save(fileName, "PNG");
}
