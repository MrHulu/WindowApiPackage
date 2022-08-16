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
     *  @param programPath 需要启用开机自启动的程序的绝对路径
     *  @return 返回结果
     *   -- true 表示成功
     *   -- false 表示失败
     *  @note 参数programName不能带有后缀 .exe
     */
    bool BootUpEnabled(std::string programName, std::string programPath) noexcept;

    /**
     *  @brief 取消开机自启动
     *  @param programName 需要取消开机自启动的程序名称
     *  @return 返回结果
     *   -- true 表示成功
     *   -- false 表示失败
     *  @note 参数programName不能带有后缀 .exe
     */
    bool BootUpDisabled(std::string programName) noexcept;

    //-------------------------------------------------------------------
    // 查询注册表的值
    //-------------------------------------------------------------------

    /**
     *  @brief 通过HKEY句柄查询注册表的值
     *  @param key 打开的一个 HKEY 句柄
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string QueryRegValueFromHKey(HKEY key, const char* name) noexcept;

    /**
     *  @brief 通过标准项名和子项路径名查询注册表的值
     *  @param keyType 指定一个标准项名
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string QueryRegValueFromPath(HKEY keyType, std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询CLASSES_ROOT项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string QueryClasses_RootRegValueFromPath(std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询CURRENT_USER项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string QueryCurrent_UserRegValueFromPath(std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询LOCAL_MACHINE项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string QueryLocal_MachineRegValueFromPath(std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询USERS项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string QueryUsersRegValueFromPath(std::string path, const char* name) noexcept;

    /**
     *  @brief 通过子项路径名查询CURRENT_CONFIG项注册表的值
     *  @param path 子项路径名
     *  @param name 需要查询的值对应的注册表的键
     *  @return 返回查询到注册表的值
     */
    std::string QueryCurrent_ConfigRegValueFromPath(std::string path, const char* name) noexcept;

    //-------------------------------------------------------------------
    // 修改注册表的值
    //-------------------------------------------------------------------

    /**
     *  @brief 通过HKEY句柄修改注册表的值
     *  @param key 打开的一个 HKEY 句柄
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void SetRegValueFromHKey(HKEY key, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过标准项名和子项路径名修改注册表的值
     *  @param keyType 指定一个标准项名
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void SetRegValueFromPath(HKEY keyType, std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改CLASSES_ROOT注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void SetClasses_RootRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改CURRENT_USER注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void SetCurrent_UserRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改LOCAL_MACHINE注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void SetLocal_MachineRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改USER注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void SetUsersRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

    /**
     *  @brief 通过子项路径名修改CURRENT_CONFIG注册表的值
     *  @param path 子项路径名
     *  @param name 需要修改的值对应的注册表的键
     *  @param value 需要修改的值
     */
    void SetCurrent_ConfigRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

private:
    HKEY __GetRegHkey(HKEY regType, const char* regPath);
};
