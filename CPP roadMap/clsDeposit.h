#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;
class clsDeposit : protected clsScreen
{
public:
 static void Deposit(){
	_DrawHeader("Deposit Screen\n");
	cout << "Enter Your Account number ";
	string Account_Number = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(Account_Number))
	{
		cout << "Re-Enter Your Account number (Not Found)";
		Account_Number = clsInputValidate::ReadString();
	}
	clsBankClient client = clsBankClient::Find(Account_Number);
	client.Print();
	cout << "Do you Want to deposit ? [y] / [n]";
	char input = clsInputValidate::read_char();
	if (input == 'y' || input == 'Y')
	{
		cout << "Enter deposit amount : ";
		int des = clsInputValidate::ReadIntNumberBetween(1, 1000000);
		client.deposit(des);
		cout << "Done :)\n";
		cout << "New Balance = " << client.AccountBalance;

	}
	else
		cout << "Unacceptable \n";
	}
};

