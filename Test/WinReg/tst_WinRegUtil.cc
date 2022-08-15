#include <QtTest>
#include <QFileInfo>
#include <QCoreApplication>

// add necessary includes here"
#include "WinReg/WinRegUtil.h"
#include <iostream>

class tst_WinRegUtil : public QObject
{
    Q_OBJECT
public:
    tst_WinRegUtil() { }
    ~tst_WinRegUtil() override { }

private slots:
    void test_bootUp();
};


void tst_WinRegUtil::test_bootUp()
{
    auto path = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    WinRegUtil winRegUtil;

    auto ret = winRegUtil.bootUpEnabled("HuluMan", QCoreApplication::applicationFilePath().toStdString());
    QVERIFY(ret);

    auto value = winRegUtil.queryCurrent_UserRegValueFromPath(path, "HuluMan");
    QFileInfo target(QString::fromStdString(value));
    QFileInfo source(QCoreApplication::applicationFilePath());
    QCOMPARE(target.absoluteFilePath(), source.absoluteFilePath());

    ret = winRegUtil.bootUpDisabled("HuluMan");
    QVERIFY(ret);

    value = winRegUtil.queryCurrent_UserRegValueFromPath(path, "HuluMan");
    QCOMPARE(value, "");
}




QTEST_MAIN(tst_WinRegUtil)

#include "tst_WinRegUtil.moc"
