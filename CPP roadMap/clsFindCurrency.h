#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsShowCurrencyList.h"
class clsFindCurrency:protected clsScreen
{

	enum enFindBy { code = 1, country = 2 };
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "___________________________________________\n";
		cout << "Country : " << Currency.Country()<<endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Name    : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$): " << Currency.Rate() << endl;
		cout << "___________________________________________\n";
	}
	static void _FindByCode() {
		cout << "Enter country code : ";
		string cod = clsInputValidate::ReadString();
		clsCurrency code=clsCurrency::FindByCode(cod);
		cout << "\n\n";
		_PrintCurrencyCard(code);

	}
	static void _FindByCountry() {
		cout << "Enter country name : ";
		string con = clsInputValidate::ReadString();
		clsCurrency country=clsCurrency::FindByCountry(con);
		cout << "\n\n";
		_PrintCurrencyCard(country);

	}






public:




	static void FindBy() {
		_DrawHeader("\t\tFind Currency");
		cout << "Find By : [1] code or [2] country ? ";
		short selection = clsInputValidate::ReadIntNumberBetween(1, 2, "invalide Number please enter 1 or 2   ");
		switch (selection)
		{
		case clsFindCurrency::code:
			_FindByCode();
			break;
		case clsFindCurrency::country:
			_FindByCountry();
			break;
		default:
			break;
		}
	}




};

