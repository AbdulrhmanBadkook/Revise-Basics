#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include<iomanip>
class clsShowCurrencyList:protected clsScreen
{
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(10) << left << Currency.CurrencyCode();
		cout << "| " << setw(35) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:
	static void LoadCurrencyData() {
		vector <clsCurrency> VcurrencyData = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencies";
		string SubTitle = "\t    (" + to_string(VcurrencyData.size()) + ") Record(s).";

		_DrawHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(30) << left << "Currency Country";
		cout << "| " << setw(10) << left << "Code";
		cout << "| " << setw(35) << left << "Name";
		cout << "| " << setw(10) << left << "Rate/(1$)";
		if (VcurrencyData.size()==0)
		{
			cout << "\t\t\t\tNo Currency data available";
		}
		else{
		for (clsCurrency cr :VcurrencyData)
		{
			_PrintCurrencyRecordLine(cr); cout << "\n";
		}
		}


	}


};

