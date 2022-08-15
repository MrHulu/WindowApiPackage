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

float WinSystemDisplayInfoUtil::scaleAndLayout() noexcept
{
    auto w = m_monitorInfo.rcMonitor.right - m_monitorInfo.rcMonitor.left;
    return landScapeResolution() / w;
}

int WinSystemDisplayInfoUtil::landScapeResolution() noexcept
{
    return m_devMode.dmPelsWidth;
}

int WinSystemDisplayInfoUtil::portraitResolution() noexcept
{
    return m_devMode.dmPelsHeight;
}

bool WinSystemDisplayInfoUtil::displayOrientation() noexcept
{
    auto w = landScapeResolution();
    auto h = portraitResolution();
    return (w >= h) ? true : false;
}
