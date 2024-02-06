#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsTrans.h"
#include"clsDeposit.h"
#include"clsWithDraw.h"
#include"clsTotalBalance.h"
#include "clsTransfer.h"
#include "clsTransferHistory.h"
using namespace std;

class clsTrans : protected clsScreen
	
{
	static void _PrintTransactionMenu() {
		system("cls");
		_DrawHeader("\t\tTransaction Menu");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
	//	clsTrans::preformeTransMenu();
	}
enum enTransMenue { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, enTransfer = 4,TransferLog=5,eShowMainMenue = 6 };


static void _Deposit() {

	clsDeposit::Deposit();

	
}

static void _WithDraw() {

	clsWithDraw::WithDraw();
}
static void _BalanceScreen() {

	
	clsTotalBalance::showBalance();

}

static void _TransferScreen() {


	clsTransfer::ShowTransferScreen();

}
static void _TransferHistory() {


	clsTransferHistory::ShowTransferLogScreen();
		
}

static void _BackToMain() {


	cout << "Back to main ";

}

static void _GoBackToTransactionsMenue()
{
	 
	cout << "\n\nPress any key to go back to Transactions Menue...";
	system("pause>0");
	_PrintTransactionMenu();
	
}












public:
	
	static void preformeTransMenu() {
		_PrintTransactionMenu();
	cout << "Choose option [1] - [6]: ";
	short c=clsInputValidate::ReadIntNumberBetween(1, 6);
	switch (c)
	{
	case clsTrans::eDeposit:
		system("cls");
		_Deposit();
		
		_GoBackToTransactionsMenue();
		break;
	case clsTrans::eWithdraw:
		system("cls");
		_WithDraw();
		
		_GoBackToTransactionsMenue();
		break;
	case clsTrans::eShowTotalBalance:
		system("cls");
		_BalanceScreen();
		
		
		_GoBackToTransactionsMenue();
		break;

	case clsTrans::enTransfer:
		system("cls");
		_TransferScreen();
		_GoBackToTransactionsMenue();
		break;
	case clsTrans::TransferLog:
		system("cls");
		_TransferHistory();
		_GoBackToTransactionsMenue();
		
		break;
	case clsTrans::eShowMainMenue:
		
		
		
		break;
	default:
		break;
	}


	}

	
	

	
};

