#pragma once
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsScreen.h"
class clsUpdateCurrencyRate : protected clsScreen

{
private:

    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadDblNumber();
        return NewRate;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
    static clsCurrency read(string msg) {
        string CurrencyCode = "";

        cout << "\nPlease Enter Currency "<<msg<<" ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        return Currency;

    }
public:

    static void ShowUpdateCurrencyRateScreen()
    {

        _DrawHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency.UpdateRate(_ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);


        }

    }


    static void CurrencyChanage() {
        char a = 'y';
        while (a == 'y' || a =='Y') {
        clsCurrency c1 = read("1");
        clsCurrency c2 = read("2");
        
        cout << "Enter Amount You want to exchange : ";
        double amount = clsInputValidate::ReadIntNumber();
        if (c1.Rate() >= 1)
        {
            //dollar bigger than currency 1
            float r1 = amount / c1.Rate();
            cout << "\nInDollar : " << r1<<endl;
            cout << "After Exchange = (from) "<<c1.CurrencyName()<< "  (To)  " <<c2.CurrencyName() << " = " << r1 * c2.Rate();
        }
        else if (c1.Rate() <= 1)
        {
            //dollar smaller than currency 1
            float r2 = amount / c1.Rate();
            cout << "\nInDollar : " << r2 << endl;
            cout << "After Exchange = (from) " << c1.CurrencyName() << "  (To)  " << c2.CurrencyName() << " = " <<r2 * c2.Rate();
        }
        cout << "\n\nDo you want to perform more ? ";
        cin >> a;
        }
    }
};

