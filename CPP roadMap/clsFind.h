#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsFind :protected clsScreen


{
    static void _Print(clsBankClient& c)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << c.FirstName;
        cout << "\nLastName    : " << c.LastName;
        cout << "\nFull Name   : " << c.FullName();
        cout << "\nEmail       : " << c.Email;
        cout << "\nPhone       : " << c.Phone;
        cout << "\nAcc. Number : " << c.AccountNumber();
        cout << "\nPassword    : " << c.PinCode;
        cout << "\nBalance     : " << c.AccountBalance;
        cout << "\n___________________\n";

    }
public:
    static void Find(){
    _DrawHeader("\t\Find Page");
    cout << "Enter Your Account number ";
    string Account_Number = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(Account_Number))
    {
        cout << "Not found re enter Account Number \n";
        Account_Number = clsInputValidate::ReadString();
    }
    clsBankClient client = clsBankClient::Find(Account_Number);
    cout << "Found :)"<<endl;
    _Print(client);
    }

};

