#pragma once
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsShowCurrencyList.h"
#include "clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h" 
#include<iomanip>
class ClsCurrencyEx :protected clsScreen
{
	enum currency_mode { list = 1, find = 2, update = 3, claculator = 4, main = 5 };

    static void _PrintCurrenyMenu() {
        system("cls");
        _DrawHeader("\t\tCurrency Exchange Menu");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Claculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
      
    }
    static void _BackToCurrency() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Menu...\n";
        system("pause>0");
        _PrintCurrenyMenu();
    }
    static void _CurrencyList() {

        clsShowCurrencyList::LoadCurrencyData();

    }

    static void _FindCurrency() {

        clsFindCurrency::FindBy();

    }
    static void _UpdateCurrency() {

        clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();

    }
    static void _Calculator() {

        clsUpdateCurrencyRate::CurrencyChanage();

    }
    static void _BackToMain() {

        cout << "Back to main";

    }
    static void _ReadCurrencyMenu() {

        cout << "What Do you want to do ? [1 - 5 ]";
        short selection = clsInputValidate::ReadIntNumberBetween(1, 5, "invalide Number please enter from : 1 to : 5   ");

        switch (selection)
        {
        case ClsCurrencyEx::list:
            system("cls");
            _CurrencyList();
            _BackToCurrency();
            break;
        case ClsCurrencyEx::find:
            system("cls");
            _FindCurrency();
            _BackToCurrency();
            break;
        case ClsCurrencyEx::update:
            system("cls");
            _UpdateCurrency();
            _BackToCurrency();
            break;
        case ClsCurrencyEx::claculator:
            system("cls");
            _Calculator();
            _BackToCurrency();
            break;
        case ClsCurrencyEx::main:
            system("cls");
            _BackToMain();
            _BackToCurrency();
            break;
        default:
            break;
        }


    }
public:
  

    static void ShowMenu() {
        _PrintCurrenyMenu();
        _ReadCurrencyMenu();



    }


};

