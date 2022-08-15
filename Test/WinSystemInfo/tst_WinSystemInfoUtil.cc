#include <QtTest>
#include <QFileInfo>

// add necessary includes here
#include "WinSystemInfo/WinSystemDisplayInfoUtil.h"
#include <iostream>

class tst_WinSystemInfoUtil : public QObject
{
    Q_OBJECT
public:
    tst_WinSystemInfoUtil() { }
    ~tst_WinSystemInfoUtil() override { }

private slots:
    void query_systemDisplayInfo();
};


void tst_WinSystemInfoUtil::query_systemDisplayInfo()
{
    WinSystemDisplayInfoUtil displayInfo;
    int scaleAndLayoutPre = floor(displayInfo.scaleAndLayout() * 100);
    bool orientation = displayInfo.displayOrientation();

    qDebug() << QString("缩放与布局：%1%").arg(scaleAndLayoutPre);
    qDebug() << QString("显示分辨率：%1 x %2").arg(displayInfo.landScapeResolution()).arg(displayInfo.portraitResolution());
    qDebug() << QString("显示方向：%1").arg(orientation ? "横行" : "纵向");
}




QTEST_MAIN(tst_WinSystemInfoUtil)

#include "tst_WinSystemInfoUtil.moc"
