#include "WinRegUtil.h"

#include <string>

using namespace std;

bool WinRegUtil::BootUpEnabled(std::string programName, std::string programPath) noexcept
try{
    // 检查是否已自启动
    string path = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    auto value = QueryCurrent_UserRegValueFromPath(path, programName.c_str());
    if(programPath != value) {
        // 未启动则设置自启动
        auto hkey = __GetRegHkey(HKEY_CURRENT_USER, path.c_str());
        SetRegValueFromHKey(hkey, programName.c_str(), programPath.c_str());
    }
    return true;

}catch(const char* e){
    return false;
}

bool WinRegUtil::BootUpDisabled(std::string programName) noexcept
try{
    string path = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    auto hKey = __GetRegHkey(HKEY_CURRENT_USER, path.c_str());
    RegDeleteValue(hKey, programName.c_str());
    RegCloseKey(hKey);
    return true;

}catch(const char* e){
    return false;
}

std::string WinRegUtil::QueryRegValueFromHKey(HKEY key, const char *name) noexcept
{
    TCHAR value[MAX_PATH] = {};
    DWORD len = MAX_PATH;
    RegGetValue(key, nullptr, name, REG_SZ, 0, value, &len);
    RegCloseKey(key);
    return value;
}

std::string WinRegUtil::QueryRegValueFromPath(HKEY keyType, std::string path, const char* name) noexcept
try{
    auto hkey = __GetRegHkey(keyType, path.c_str());
    auto value = QueryRegValueFromHKey(hkey, name);
    RegCloseKey(hkey);
    return value;
}catch(const char* e){
    return nullptr;
}

void WinRegUtil::SetRegValueFromHKey(HKEY key, const char *name, const char *value) noexcept
{
    auto len = (lstrlen(value) + 1) * sizeof(TCHAR);
    RegSetValueEx(key, name, 0, REG_SZ, (LPBYTE)value, len);
    RegCloseKey(key);
}

void WinRegUtil::SetRegValueFromPath(HKEY keyType, std::string path, const char *name, const char *value) noexcept
try{
    auto hkey = __GetRegHkey(keyType, path.c_str());
    SetRegValueFromHKey(hkey, name, value);
    RegCloseKey(hkey);
}catch(const char* e){ }

HKEY WinRegUtil::__GetRegHkey(HKEY regType, const char *regPath)
{
    HKEY hKey;
    auto ret = RegOpenKeyEx(regType, regPath, 0, KEY_ALL_ACCESS, &hKey);
    if(ret == ERROR_SUCCESS)
        return hKey;
    else
        throw "open Reg fail";
}

std::string WinRegUtil::QueryClasses_RootRegValueFromPath(std::string path, const char *name) noexcept
{
    return QueryRegValueFromPath(HKEY_CLASSES_ROOT, path, name);
}

std::string WinRegUtil::QueryCurrent_UserRegValueFromPath(std::string path, const char *name) noexcept
{
    return QueryRegValueFromPath(HKEY_CURRENT_USER, path, name);
}

std::string WinRegUtil::QueryLocal_MachineRegValueFromPath(std::string path, const char *name) noexcept
{
    return QueryRegValueFromPath(HKEY_LOCAL_MACHINE, path, name);
}

std::string WinRegUtil::QueryUsersRegValueFromPath(std::string path, const char *name) noexcept
{
    return QueryRegValueFromPath(HKEY_USERS, path, name);
}

std::string WinRegUtil::QueryCurrent_ConfigRegValueFromPath(std::string path, const char *name) noexcept
{
    return QueryRegValueFromPath(HKEY_CURRENT_CONFIG, path, name);
}

void WinRegUtil::SetClasses_RootRegValueFromPath(std::string path, const char *name, const char *value) noexcept
{
    SetRegValueFromPath(HKEY_CLASSES_ROOT, path, name, value);
}

void WinRegUtil::SetCurrent_UserRegValueFromPath(std::string path, const char *name, const char *value) noexcept
{
    SetRegValueFromPath(HKEY_CURRENT_USER, path, name, value);
}

void WinRegUtil::SetLocal_MachineRegValueFromPath(std::string path, const char *name, const char *value) noexcept
{
    SetRegValueFromPath(HKEY_LOCAL_MACHINE, path, name, value);
}

void WinRegUtil::SetUsersRegValueFromPath(std::string path, const char *name, const char *value) noexcept
{
    SetRegValueFromPath(HKEY_USERS, path, name, value);
}

void WinRegUtil::SetCurrent_ConfigRegValueFromPath(std::string path, const char *name, const char *value) noexcept
{
    SetRegValueFromPath(HKEY_CURRENT_CONFIG, path, name, value);
}
