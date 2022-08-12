#pragma once

#include <windows.h>
#include <string>

class WinRegUtil
{
public:
    WinRegUtil() {}
    ~WinRegUtil() {}


    /*** 开机自启动 ***/
    // 启用
    bool bootUpEnabled(std::string programName) noexcept;
    // 取消
    bool bootUpDisabled(std::string programName) noexcept;

    /*** 查询注册表的值 ***/
    std::string queryRegValueFromHKey(HKEY key, const char* name) noexcept;
    std::string queryRegValueFromPath(HKEY keyType, std::string path, const char* name) noexcept;
    std::string queryClasses_RootRegValueFromPath(std::string path, const char* name) noexcept;
    std::string queryCurrent_UserRegValueFromPath(std::string path, const char* name) noexcept;
    std::string queryLocal_MachineRegValueFromPath(std::string path, const char* name) noexcept;
    std::string queryUsersRegValueFromPath(std::string path, const char* name) noexcept;
    std::string queryCurrent_ConfigRegValueFromPath(std::string path, const char* name) noexcept;

    /*** 修改注册表 ***/
    void setRegValueFromHKey(HKEY key, const char* name, const char* value) noexcept;
    void setRegValueFromPath(HKEY keyType, std::string path, const char* name, const char* value) noexcept;
    void setClasses_RootRegValueFromPath(std::string path, const char* name, const char* value) noexcept;
    void setCurrent_UserRegValueFromPath(std::string path, const char* name, const char* value) noexcept;
    void setLocal_MachineRegValueFromPath(std::string path, const char* name, const char* value) noexcept;
    void setUsersRegValueFromPath(std::string path, const char* name, const char* value) noexcept;
    void setCurrent_ConfigRegValueFromPath(std::string path, const char* name, const char* value) noexcept;

private:
    HKEY getRegHkey(HKEY regType, const char* regPath);
};

inline std::string WinRegUtil::queryClasses_RootRegValueFromPath(std::string path, const char *name) noexcept
{ return queryRegValueFromPath(HKEY_CLASSES_ROOT, path, name); }

inline std::string WinRegUtil::queryCurrent_UserRegValueFromPath(std::string path, const char *name) noexcept
{ return queryRegValueFromPath(HKEY_CURRENT_USER, path, name); }

inline std::string WinRegUtil::queryLocal_MachineRegValueFromPath(std::string path, const char *name) noexcept
{ return queryRegValueFromPath(HKEY_LOCAL_MACHINE, path, name); }

inline std::string WinRegUtil::queryUsersRegValueFromPath(std::string path, const char *name) noexcept
{ return queryRegValueFromPath(HKEY_USERS, path, name); }

inline std::string WinRegUtil::queryCurrent_ConfigRegValueFromPath(std::string path, const char *name) noexcept
{ return queryRegValueFromPath(HKEY_CURRENT_CONFIG, path, name); }

inline void WinRegUtil::setClasses_RootRegValueFromPath(std::string path, const char *name, const char* value) noexcept
{  setRegValueFromPath(HKEY_CLASSES_ROOT, path, name, value); }

inline void WinRegUtil::setCurrent_UserRegValueFromPath(std::string path, const char *name, const char* value) noexcept
{  setRegValueFromPath(HKEY_CURRENT_USER, path, name, value); }

inline void WinRegUtil::setLocal_MachineRegValueFromPath(std::string path, const char *name, const char* value) noexcept
{  setRegValueFromPath(HKEY_LOCAL_MACHINE, path, name, value); }

inline void WinRegUtil::setUsersRegValueFromPath(std::string path, const char *name, const char* value) noexcept
{  setRegValueFromPath(HKEY_USERS, path, name, value); }

inline void WinRegUtil::setCurrent_ConfigRegValueFromPath(std::string path, const char *name, const char* value) noexcept
{  setRegValueFromPath(HKEY_CURRENT_CONFIG, path, name, value); }

