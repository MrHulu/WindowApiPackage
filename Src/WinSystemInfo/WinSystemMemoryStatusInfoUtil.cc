#include "WinSystemMemoryStatusInfoUtil.h"
#include <stdexcept>

WinSystemMemoryStatusInfoUtil::WinSystemMemoryStatusInfoUtil()
{

}

ulonglong WinSystemMemoryStatusInfoUtil::GetSystemCacheSize() const
{
    auto info = __GetPreformanceInfo();
    return info.SystemCache * info.PageSize;
}

ulonglong WinSystemMemoryStatusInfoUtil::GetKernelPageSize() const
{
    auto info = __GetPreformanceInfo();
    return info.KernelPaged * info.PageSize;
}

ulonglong WinSystemMemoryStatusInfoUtil::GetKernelNonPageSize() const
{
    auto info = __GetPreformanceInfo();
    return info.KernelNonpaged * info.PageSize;
}

uint WinSystemMemoryStatusInfoUtil::GetCurrentHandleCount() const
{
    auto info = __GetPreformanceInfo();
    return info.HandleCount;
}

uint WinSystemMemoryStatusInfoUtil::GetCurrentProcessCount() const
{
    auto info = __GetPreformanceInfo();
    return info.ProcessCount;
}

uint WinSystemMemoryStatusInfoUtil::GetCurrentThreadCount() const
{
    auto info = __GetPreformanceInfo();
    return info.ThreadCount;
}

uint WinSystemMemoryStatusInfoUtil::GetMemoryUsege() const
{
    auto status = __GetMemotryStatus();
    return status.dwMemoryLoad;
}

MEMORYSTATUSEX WinSystemMemoryStatusInfoUtil::__GetMemotryStatus() const
{
    MEMORYSTATUSEX status = {0};
    status.dwLength = sizeof(status);
    if (GlobalMemoryStatusEx(&status))
        return status;
    else
        throw std::runtime_error("GlobalMemoryStatusEx call failure");
}

PERFORMANCE_INFORMATION WinSystemMemoryStatusInfoUtil::__GetPreformanceInfo() const
{
    PERFORMANCE_INFORMATION info = {0};
    if (GetPerformanceInfo(&info, sizeof(info)))
        return info;
    else
        throw std::runtime_error("GetPerformanceInfo call failure");
}
