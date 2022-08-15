#pragma once

#include <windows.h>
#include <string>

class WinRegUtil
{
public:
    WinRegUtil() {}
    ~WinRegUtil() {}

    //-------------------------------------------------------------------
    // 开机启动
    //-------------------------------------------------------------------

    /**
     *  @brief 启用开机自启动
     *  @param programName 需要启用开机自启动的程序名称
     *  @return 返回结果
     *   -- true 表示成功
     *   -- false 表示失败
     *  @note 参数programName不能带有后缀 .exe
     */
    bool bootUpEnabled(std::string programName) noexcept;

    /**
     *  @brief 取消开机自启动
     *  @param programName 需要取消开机自启动的程序名称
     *  @return 返回结果
     *   -- true 表示成功
     *   -- false 表示失败
     *  @note 参数programName不能带有后缀 .exe
     */
    bool bootUpDisabled(std::string programName) noexcept;

    //-------------------------------------------------------------------
    // 查询注册表的值
    //-------------------------------------------------------------------

    /**
     *  @brief 通过HKEY句柄查询注册表的值
     *  @param key 打开的一个 HKEY 句柄
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string queryRegValueFromHKey(HKEY key, const char* name) noexcept;

    /**
     *  @brief 通过标准项名和子项路径名查询注册表的值
     *  @param keyType 指定一个标准项名
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string queryRegValueFromPath(HKEY keyType, std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询CLASSES_ROOT项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string queryClasses_RootRegValueFromPath(std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询CURRENT_USER项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string queryCurrent_UserRegValueFromPath(std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询LOCAL_MACHINE项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string queryLocal_MachineRegValueFromPath(std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询USERS项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string queryUsersRegValueFromPath(std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询CURRENT_CONFIG项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string queryCurrent_ConfigRegValueFromPath(std::string path, const char* name) noexcept;

    //-------------------------------------------------------------------
    // 修改注册表的值
    //-------------------------------------------------------------------

    /**
     *  @brief 通过HKEY句柄修改注册表的值
     *  @param key 打开的一个 HKEY 句柄
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void setRegValueFromHKey(HKEY key, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过标准项名和子项路径名修改注册表的值
     *  @param keyType 指定一个标准项名
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void setRegValueFromPath(HKEY keyType, std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改CLASSES_ROOT注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void setClasses_RootRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改CURRENT_USER注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void setCurrent_UserRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改LOCAL_MACHINE注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void setLocal_MachineRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改USER注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void setUsersRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改CURRENT_CONFIG注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void setCurrent_ConfigRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

private:
    HKEY getRegHkey(HKEY regType, const char* regPath);
};
