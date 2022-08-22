#pragma once

#include <windows.h>
#include <psapi.h>

using ulonglong = unsigned long long;

class WinSystemMemoryStatusInfoUtil
{
public:
    WinSystemMemoryStatusInfoUtil();

    /**
    * @brief 获取系统当前缓存大小
    * @return 返回系统当前缓存的字节数量
    */
    ulonglong GetSystemCache() const;

private:
    MEMORYSTATUSEX __GetMemotryStatus() const;
    PERFORMANCE_INFORMATION __GetPreformanceInfo() const;
};

