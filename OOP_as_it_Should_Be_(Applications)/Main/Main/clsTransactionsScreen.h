#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactions : protected clsScreen
{
private:

	enum enTransactionMenueOptions {
		eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eTransfer = 4
		, eTransferLog = 5, eShowMainMenue = 6
	};

	static short _ReadTransactionMenueOption()
	{
		cout << setw(37) << "" << "Choose What do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "\nPlease Enter Number Between 1 and 6 : ");
		return Choice;
	}

	static void _GoBackToTransactionsScreen()
	{
		cout << "\n\nPress Any Key To Go Back Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit Screen Will Be Here...";
		clsDeposit::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw Screen Will Be Here.";
		clsWithdraw::ShowWithdrawScreen();

	}

	static void _ShowTransferScreen()
	{
		//cout << "\nTransfer Screen will be here..";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\nTransfer Log Screen Will be here.";
		clsTransferLogScreen::ShowTransFferLogScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		//cout << "\nTotal Balance Screen Will Be Here.";
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _PerformTransactionsMenueOption(enTransactionMenueOptions TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		case enTransactionMenueOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsScreen();
			break;
		case enTransactionMenueOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsScreen();
			break;
		case enTransactionMenueOptions::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsScreen();
			break;
		case enTransactionMenueOptions::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsScreen();
			break;
		case enTransactionMenueOptions::eTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsScreen();
			break;
		case enTransactionMenueOptions::eShowMainMenue:
		{
			// Main Scrren Will handle it >_* 
		}

		}
	}

public:

	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("\t Transactions Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "============================================\n";

		cout << setw(37) << left << "" << "\t [1] Deposit.\n";
		cout << setw(37) << left << "" << "\t [2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t [3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t [4] Transfer.\n";
		cout << setw(37) << left << "" << "\t [5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t [6] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformTransactionsMenueOption((enTransactionMenueOptions)_ReadTransactionMenueOption());
	}
};