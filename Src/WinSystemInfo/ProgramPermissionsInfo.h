#pragma once


class ProgramPermissionsInfo
{
public:
    ProgramPermissionsInfo(){}

    /**
    * @brief  判断当前程序是否有管理员权限
    * @return 返回是否管理员权限的结果
    * @warning 该函数会抛出std::runtime_error的异常，请注意捕获，捕获后调用GetLastError()以获取更多的错误信息
    **/
    bool IsRunAsAdmin() const;
};

