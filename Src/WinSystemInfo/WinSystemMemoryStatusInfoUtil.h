#pragma once

#include <windows.h>
#include <psapi.h>

using ulonglong = unsigned long long;
using uint = unsigned int;

class WinSystemMemoryStatusInfoUtil
{
public:
    WinSystemMemoryStatusInfoUtil();

    /**
    * @brief 获取系统当前缓存大小
    * @return 返回系统当前缓存的字节数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    ulonglong GetSystemCacheSize() const;

    /**
    * @brief 获取分页内核池中内存大小
    * @return 返回分页内核池中的字节数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    ulonglong GetKernelPageSize() const;

    /**
    * @brief 获取非分页内核池中内存大小
    * @return 返回非分页内核池中的字节数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    ulonglong GetKernelNonPageSize() const;

    /**
    * @brief 获取当前系统打开的句柄数量
    * @return 返回句柄数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    uint GetCurrentHandleCount() const;

    /**
    * @brief 获取当前系统的进程数量
    * @return 返回进程数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    uint GetCurrentProcessCount() const;

    /**
    * @brief 获取当前系统的线程数量
    * @return 返回线程数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    uint GetCurrentThreadCount() const;

    /**
    * @brief 获取当前内存使用率
    * @return 返回当前内存使用大小占整个内存大小的百分比
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    uint GetMemoryUsege() const;

    /**
    * @brief 获取物理总内存大小
    * @return 返回物理总内存字节数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    ulonglong GetPhysicalTotalMemorySize() const;

    /**
    * @brief 获取物理可用的内存大小
    * @return 返回物理可用内存字节数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    ulonglong GetPhysicalAvailableMemorySize() const;

    /**
    * @brief 获取虚拟总内存大小
    * @return 返回虚拟总内存字节数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    ulonglong GetVirtualTotalMemorySize() const;

    /**
    * @brief 获取虚拟可用的内存大小
    * @return 返回虚拟可用内存字节数量
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    */
    ulonglong GetVirtualAvailableMemorySize() const;

private:
    MEMORYSTATUSEX __GetMemotryStatus() const;
    PERFORMANCE_INFORMATION __GetPreformanceInfo() const;
};

