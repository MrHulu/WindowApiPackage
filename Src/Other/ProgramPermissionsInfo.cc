#include "ProgramPermissionsInfo.h"

#include <Windows.h>
#include <stdexcept>
#include <string>

bool ProgramPermissionsInfo::IsRunAsAdmin() const
{
    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    PSID AdministratorsGroup;

    if( AllocateAndInitializeSid(
        &NtAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
         DOMAIN_ALIAS_RID_ADMINS,
         0, 0, 0, 0, 0, 0,
            &AdministratorsGroup))
    {
        BOOL isAdmin ;
        CheckTokenMembership(NULL, AdministratorsGroup, &isAdmin);
        FreeSid(AdministratorsGroup);
        return isAdmin;
    }
    else
        throw std::runtime_error( std::string(__FUNCTION__) + std::string("AllocateAndInitializeSid is fail "));

}
