#include "WinSystemDisplayInfoUtil.h"


WinSystemDisplayInfoUtil::WinSystemDisplayInfoUtil()
{

}

float WinSystemDisplayInfoUtil::ScaleAndLayout()  noexcept
{
    auto monitorInfo = __GetMonitorInfo();
    auto w = monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left;
    return LandScapeResolution() / w;
}

int WinSystemDisplayInfoUtil::LandScapeResolution() noexcept
{
    return __GetDevMode().dmPelsWidth;
}

int WinSystemDisplayInfoUtil::PortraitResolution() noexcept
{
    return __GetDevMode().dmPelsHeight;
}

bool WinSystemDisplayInfoUtil::DisplayOrientation() noexcept
{
    auto devMode = __GetDevMode();
    auto w = devMode.dmPelsWidth;
    auto h = devMode.dmPelsHeight;
    return (w >= h) ? true : false;
}

MONITORINFOEX WinSystemDisplayInfoUtil::__GetMonitorInfo()
{
    MONITORINFOEX monitorInfo;
    monitorInfo.cbSize = sizeof(monitorInfo);
    auto hMonitor = MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTONEAREST);
    GetMonitorInfo(hMonitor, &monitorInfo);
    return monitorInfo;
}

DEVMODE WinSystemDisplayInfoUtil::__GetDevMode()
{
    DEVMODE devMode;
    devMode.dmSize = sizeof(devMode);
    devMode.dmDriverExtra = 0;
    EnumDisplaySettings(__GetMonitorInfo().szDevice, ENUM_CURRENT_SETTINGS, &devMode);
    return devMode;
}
