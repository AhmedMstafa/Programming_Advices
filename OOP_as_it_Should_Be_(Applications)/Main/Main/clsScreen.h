#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
public:



    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate());
        cout << "\n\t\t\t\t\tUser: " << CURRENT_USER.UserName;
        cout << "\n\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permissions)
    {
        if (!CURRENT_USER.CheckAccessPermission(Permissions))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }

};