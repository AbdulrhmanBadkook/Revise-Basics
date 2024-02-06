#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsBankClient.h"

using namespace std;
 class clsTotalBalance
{
	 static void _PrintBalanceFormat(clsBankClient c)
	 {

		 cout << "| " << setw(15) << left << c.AccountNumber();
		 cout << "| " << setw(20) << left << c.FullName();
		 cout << "| " << setw(12) << left << c.AccountBalance;

	 }
public:
	static void showBalance() {


		vector<clsBankClient> cli = clsBankClient::GetClientList();
		cout << "\t\t\t\tThere Are [" << cli.size() << " ]" << "Clients \n\n\n";

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (cli.size() == 0)
		{
			cout << "No Client in the system\n";
		}
		else
		{

			for (clsBankClient& client : cli)
			{
				

				_PrintBalanceFormat(client);
				cout << "\n";

			}

		}

	}
};

