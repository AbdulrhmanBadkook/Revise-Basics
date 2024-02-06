#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;
class clsWithDraw:protected clsScreen
{
public:
	static void WithDraw() {

		_DrawHeader("WithDraw Screen\n");
		cout << "Enter Your Account number ";
		string Account_Number = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(Account_Number))
		{
			cout << "Re-Enter Your Account number (Not Found)";
			Account_Number = clsInputValidate::ReadString();
		}
		clsBankClient client = clsBankClient::Find(Account_Number);
		client.Print();
		cout << "Do you Want to WithDraw ? [y] / [n]";
		char input = clsInputValidate::read_char();
		if (input == 'y' || input == 'Y')
		{
			cout << "Enter WithDraw amount : ";
			int withdraw = clsInputValidate::ReadIntNumberBetween(1, 1000000);
			if (withdraw > client.AccountBalance)
			{
				cout << "sorry you have execced you account balance ";
			}
			else {
				client.Withdraw(withdraw);
				cout << "Done :)\n";
				cout << "New Balance = " << client.AccountBalance;
			}

		}
	}
};

