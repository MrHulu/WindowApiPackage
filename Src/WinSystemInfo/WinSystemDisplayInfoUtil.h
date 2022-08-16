#pragma once

#include <windows.h>

class WinSystemDisplayInfoUtil
{
public:
    WinSystemDisplayInfoUtil();

    //-------------------------------------------------------------------
    // Windows 系统的显示信息
    //-------------------------------------------------------------------

    /**
     *  @brief Scale Layout 查询缩放与布局的值
     *  @return 返回缩放与布局的值
     */
    float ScaleAndLayout() noexcept;

    /**
     *  @brief 查询横向的分辨率大小/显示器横向物理长度
     *  @return 返回横向的分辨率大小/显示器横向物理长度
     */
    int LandScapeResolution() noexcept;

    /**
     *  @brief 查询纵向的分辨率大小/显示器纵向物理长度
     *  @return 返回纵向的分辨率大小/显示器纵向物理长度
     */
    int PortraitResolution() noexcept;

    /**
     *  @brief 查询显示的方向
     *  @return 返回显示方向
     *   -- true 横向
     *   -- false 纵向
     */
    bool DisplayOrientation() noexcept;

private:
    MONITORINFOEX m_monitorInfo;
    DEVMODE m_devMode;
};

