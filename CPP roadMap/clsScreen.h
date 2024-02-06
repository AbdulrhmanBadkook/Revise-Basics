#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include"clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawHeader(string Title, string SubTitle = "")
    {
        clsDate date = clsDate::GetSystemDate();
        string d = clsDate::DateToString(date);
        string Name=current.UserName;
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
      
        cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\t\t\t\t\t\t\t" << d << "\n\t\t\t\t\t\t\t" << "UserName : " << Name<<endl;
        
    }

    static bool show_access_status(clsUser::enPermissions Permission)
    {

        if (!current.Check_permission(Permission))
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
    static void current_Date() {

        clsDate::GetSystemDate();
    }

};

