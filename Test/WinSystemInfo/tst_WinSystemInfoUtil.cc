#include <QtTest>
#include <QFileInfo>

// add necessary includes here
#include "WinSystemInfo/WinSystemDisplayInfoUtil.h"
#include <iostream>
#include <tlhelp32.h>
#include <psapi.h>

class tst_WinSystemInfoUtil : public QObject
{
    Q_OBJECT
public:
    tst_WinSystemInfoUtil() { }
    ~tst_WinSystemInfoUtil() override { }

private slots:
    void query_systemDisplayInfo();
    void query_systemMemoryStatusInfo();
};


void tst_WinSystemInfoUtil::query_systemDisplayInfo()
{
    WinSystemDisplayInfoUtil displayInfo;
    int scaleAndLayoutPre = floor(displayInfo.ScaleAndLayout() * 100);
    bool orientation = displayInfo.DisplayOrientation();

    qDebug() << QString("缩放与布局：%1%").arg(scaleAndLayoutPre);
    qDebug() << QString("显示分辨率：%1 x %2").arg(displayInfo.LandScapeResolution()).arg(displayInfo.PortraitResolution());
    qDebug() << QString("显示方向：%1").arg(orientation ? "横行" : "纵向");
}

void tst_WinSystemInfoUtil::query_systemMemoryStatusInfo()
{
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    qDebug()<< "处理器数量: " <<systemInfo.dwNumberOfProcessors;

    //auto pid = 31604;
    //auto hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    auto nMB = 1024 * 1024;
    PERFORMANCE_INFORMATION info = {0};
    QVERIFY( GetPerformanceInfo(&info, sizeof(info)) );
    qDebug() << QString("系统缓存内存量 %1").arg(info.SystemCache * info.PageSize / nMB);
    qDebug() << QString("实际物理内存量 %1").arg(info.PhysicalTotal * info.PageSize / nMB);
    qDebug() << QString("可用物理内存量 %1").arg(info.PhysicalAvailable * info.PageSize / nMB);
    qDebug() << QString("OK分页内核池中的内存 %1").arg(info.KernelPaged * info.PageSize / nMB / 1024.0);
    qDebug() << QString("OK非分页内核池中的内存 %1").arg(info.KernelNonpaged * info.PageSize / nMB / 1024.0);
    qDebug() << QString("OK当前打开的句柄数 %1").arg(info.HandleCount );
    qDebug() << QString("OK当前进程数 %1").arg(info.ProcessCount );
    qDebug() << QString("OK当前线程数 %1").arg(info.ThreadCount );
    qDebug() << QString("-----------");
    qDebug() << QString("CommitTotal %1").arg(info.CommitTotal * info.PageSize / nMB);
    qDebug() << QString("CommitLimit %1").arg(info.CommitLimit * info.PageSize / nMB);
    qDebug() << QString("CommitPeak %1").arg(info.CommitPeak * info.PageSize / nMB);

    MEMORYSTATUSEX stMem = {0};
    stMem.dwLength = sizeof(stMem);
    GlobalMemoryStatusEx(&stMem);
    qDebug() << QString("OK内存使用率 %1%").arg(stMem.dwMemoryLoad);
    qDebug() << QString("OK物理内存(内存使用量) %1").arg(stMem.ullTotalPhys / nMB / 1024.0);
    qDebug() << QString("物理可用内存 %1").arg(stMem.ullAvailPhys / nMB / 1024.0);
    qDebug() << QString("OK内存使用中 %1").arg(stMem.ullTotalPhys / nMB / 1024.0 * stMem.dwMemoryLoad / 100);
    qDebug() << QString("虚拟内存 %1").arg(stMem.ullTotalVirtual  / nMB / 1024.0 );
    qDebug() << QString("OK文件总内存 %1").arg(stMem.ullTotalPageFile / nMB / 1024.0);
    qDebug() << QString("OK文件已提交内存 %1").arg(stMem.ullTotalPageFile / nMB / 1024.0 - stMem.ullAvailPageFile / nMB / 1024.0);
    qDebug() << QString("OK文件剩余内存 %1").arg(stMem.ullAvailPageFile / nMB / 1024.0);

}




QTEST_MAIN(tst_WinSystemInfoUtil)

#include "tst_WinSystemInfoUtil.moc"
