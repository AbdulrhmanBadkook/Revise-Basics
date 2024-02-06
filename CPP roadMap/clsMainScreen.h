#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsClientScreen.h";
#include"clsDelete.h"
#include "clsAddNew.h"
#include "clsUpdate.h"
#include"clsFind.h"
#include"clsTrans.h"
#include"ClsManageMenu.h"
#include"clsHistoryOfLogin.h"
#include"ClsCurrencyEx.h"
#include<iomanip>
#include"Global.h"

using namespace std;
class clsMainScreen:protected clsScreen

	//each screen = class 
{
	enum system_menu { show = 1, addn = 2, del = 3, upd = 4, fnd = 5, transaction = 6, manage = 7, history = 8,currency = 9,ext=10 };
    static void _MainMenu() {
        system("cls");
        _DrawHeader("\t\tMainScreen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

    }
    static void _BackToMain() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";
        system("pause>0");
        ShowMenu();
    }
    
    static void _ShowAll() {

        clsClientScreen::ShowClientsList();

    }
    static void _AddNew() {

        clsAddNew::ShowAddNewClientScreen();

    }
    static void _DeleteClient() {

        clsDelete::ShowDeleteClientScreen();

    }
    static void _UpdateClient() {

        clsUpdate::ShowUpdateClientScreen();

    }
    static void _FindClient() {

        clsFind::Find();

    }
    static void _Trans() {
       
        
        clsTrans::preformeTransMenu();

    }
    static void _Manage() { 

        ClsManageMenu::ShowManageUsersMenue();

    }
    static void _HistoryOfLogin() {

       
        clsHistoryOfLogin::ShowLoginRegisterScreen();
        

    }
    static void _Currency() {


        ClsCurrencyEx::ShowMenu();

    }
    static void _Exit() {

        current = clsUser::Find("", "");
       
    }

    static void _readMenu() {

        cout << "What Do you want to do ? [1 - 10 ]";
        short selection = clsInputValidate::ReadIntNumberBetween(1, 10, "invalide Number please enter from : 1 to : 10   ");
        switch (selection)
        {
        case show:

            system("cls");
            _ShowAll();
           
            _BackToMain();
            break;
        case addn:

            system("cls");
            _AddNew();
          
            _BackToMain();
            break;
        case del:

            system("cls");
            _DeleteClient();
           
            _BackToMain();
            break;
        case upd:

            system("cls");
            _UpdateClient();
           
            _BackToMain();
            break;
        case fnd:
            system("cls");
            _FindClient();
           
            _BackToMain();
            break;
        case transaction:

            system("cls");
            _Trans();
           _BackToMain();
            
            break;
        case manage:

            system("cls");
            _Manage();
           
           _BackToMain();
            break;
        case history:
            system("cls");
            _HistoryOfLogin();
            _BackToMain();
            break;
        case currency:
            system("cls");
            _Currency();
            _BackToMain();
            break;
        case ext:
            system("cls");
            _Exit();
           
            

            break;
        default:
            break;
        }



    }

public:
    static void ShowMenu() {
        _MainMenu();
        _readMenu();



    }

    

};

