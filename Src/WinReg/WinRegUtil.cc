#include "WinRegUtil.h"

#include <string>

using namespace std;

bool WinRegUtil::bootUpEnabled(std::string programName) noexcept
try{
    // 获取程序绝对路径
    TCHAR exePath[MAX_PATH];
    GetModuleFileName(nullptr, exePath, MAX_PATH);

    // 检查是否已自启动
    string path = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    auto value = queryCurrent_UserRegValueFromPath(path, programName.c_str());
    if(exePath != value) {
        // 未启动则设置自启动
        auto hkey = getRegHkey(HKEY_CURRENT_USER, path.c_str());
        setRegValueFromHKey(hkey, programName.c_str(), exePath);
    }
    return true;

}catch(const char* e){
    return false;
}

bool WinRegUtil::bootUpDisabled(std::string programName) noexcept
try{
    string path = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    auto hKey = getRegHkey(HKEY_CURRENT_USER, path.c_str());
    RegDeleteValue(hKey, programName.c_str());
    RegCloseKey(hKey);
    return true;

}catch(const char* e){
    return false;
}

std::string WinRegUtil::queryRegValueFromHKey(HKEY key, const char *name) noexcept
{
    TCHAR value[MAX_PATH] = {};
    DWORD len = MAX_PATH;
    RegGetValue(key, nullptr, name, REG_SZ, 0, value, &len);
    RegCloseKey(key);
    return value;
}

std::string WinRegUtil::queryRegValueFromPath(HKEY keyType, std::string path, const char* name) noexcept
try{
    auto hkey = getRegHkey(keyType, path.c_str());
    auto value = queryRegValueFromHKey(hkey, name);
    RegCloseKey(hkey);
    return value;
}catch(const char* e){
    return nullptr;
}

void WinRegUtil::setRegValueFromHKey(HKEY key, const char *name, const char *value) noexcept
{
    auto len = (lstrlen(value) + 1) * sizeof(TCHAR);
    RegSetValueEx(key, name, 0, REG_SZ, (LPBYTE)value, len);
    RegCloseKey(key);
}

void WinRegUtil::setRegValueFromPath(HKEY keyType, std::string path, const char *name, const char *value) noexcept
try{
    auto hkey = getRegHkey(keyType, path.c_str());
    setRegValueFromHKey(hkey, name, value);
    RegCloseKey(hkey);
}catch(const char* e){ }

HKEY WinRegUtil::getRegHkey(HKEY regType, const char *regPath)
{
    HKEY hKey;
    auto ret = RegOpenKeyEx(regType, regPath, 0, KEY_ALL_ACCESS, &hKey);
    if(ret == ERROR_SUCCESS)
        return hKey;
    else
        throw "open Reg fail";
}
