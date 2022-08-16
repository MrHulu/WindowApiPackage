#include "WinSystemDisplayInfoUtil.h"


WinSystemDisplayInfoUtil::WinSystemDisplayInfoUtil()
{

    m_monitorInfo.cbSize = sizeof(m_monitorInfo);
    m_devMode.dmSize = sizeof(m_devMode);
    m_devMode.dmDriverExtra = 0;

    auto hMonitor = MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTONEAREST);
    GetMonitorInfo(hMonitor, &m_monitorInfo);
    EnumDisplaySettings(m_monitorInfo.szDevice, ENUM_CURRENT_SETTINGS, &m_devMode);
}

float WinSystemDisplayInfoUtil::ScaleAndLayout() noexcept
{
    auto w = m_monitorInfo.rcMonitor.right - m_monitorInfo.rcMonitor.left;
    return LandScapeResolution() / w;
}

int WinSystemDisplayInfoUtil::LandScapeResolution() noexcept
{
    return m_devMode.dmPelsWidth;
}

int WinSystemDisplayInfoUtil::PortraitResolution() noexcept
{
    return m_devMode.dmPelsHeight;
}

bool WinSystemDisplayInfoUtil::DisplayOrientation() noexcept
{
    auto w = LandScapeResolution();
    auto h = PortraitResolution();
    return (w >= h) ? true : false;
}
