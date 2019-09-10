#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QPainter>
#include <QFile>
static const QSize SIZE_SCREEN_SHOT = QSize(1600, 900);
static const QSize SIZE_HIRES_ICON = QSize(512, 512);
static const QSize SIZE_DAY_DREAM_360 = QSize(4096, 4096);
static const QSize SIZE_FEATURE_GRAPHIC = QSize(1024, 500);
static const QSize SIZE_TV_BANNER = QSize(1280, 720);
static const QSize SIZE_PROMO_GRAPHIC = QSize(180, 120);
static const QColor DEFAULT_COLOR = QColor(179, 217, 255);
static const QColor DEFAULT_TEXT_COLOR = QColor(255, 255, 255);
class AppManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString appName MEMBER m_appName NOTIFY appNameChanged)
    QString m_appName = "";
public:
    explicit AppManager(QObject *parent = nullptr);
    Q_INVOKABLE void generateAndroidStoreImages();
private:
    void gen_ScreenShot(QSize imgSize, QString patternName = "");
    void gen_HiresIcon(QSize imgSize, QString patternName = "");
    void gen_Daydream360(QSize imgSize, QString patternName = "");
    void gen_FeatureGraphic(QSize imgSize, QString patternName = "");
    void gen_PromoGraphic(QSize imgSize, QString patternName = "");
    void gen_TVBanner(QSize imgSize, QString patternName = "");

    QImage createEmptyImage(QSize imgSize, QColor imgColor, QColor textColor);
    QImage createImageWithPattern(QString PatternName, QString fileName, QColor textColor);
    void saveImageFile(QImage image, QString fileName);
signals:
    void appNameChanged();
public slots:
};

#endif // APPMANAGER_H
