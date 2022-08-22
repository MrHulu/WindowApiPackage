#include "WinSystemMemoryStatusInfoUtil.h"

WinSystemMemoryStatusInfoUtil::WinSystemMemoryStatusInfoUtil()
{

}

ulonglong WinSystemMemoryStatusInfoUtil::GetSystemCache() const
{
    auto info = __GetPreformanceInfo();
    return info.SystemCache * info.PageSize;
}

MEMORYSTATUSEX WinSystemMemoryStatusInfoUtil::__GetMemotryStatus() const
{
    MEMORYSTATUSEX status = {0};
    status.dwLength = sizeof(status);
    if (GlobalMemoryStatusEx(&status))
        return status;
    else
        throw GetLastError();
}

PERFORMANCE_INFORMATION WinSystemMemoryStatusInfoUtil::__GetPreformanceInfo() const
{
    PERFORMANCE_INFORMATION info = {0};
    if (GetPerformanceInfo(&info, sizeof(info)))
        return info;
    else
        throw GetLastError();
}
