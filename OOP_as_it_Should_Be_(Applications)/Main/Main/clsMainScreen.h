#pragma once 
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{

private:

	enum enMainMenueOptions
	{
		eListClients = 1, eAddClient = 2, eDeleteClient = 3, eUpdteClient = 4,
		eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLoginRegiser = 8, eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << ""
			<< "Choose What do you Wnat to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 10, "\nPlease Enter Number Between 1 and 10");
		return Choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << "\n\nPress Any Key To Go Back Mani Menue..";
		system("pause>0");
		ShowMainMenueScreen();
	}

	static void _ShowAllClientsScreen()
	{
		//cout << "\nList Client Screen Will be Here.";
		clsListClients::ShowClientsScreen();
	}

	static void _ShowAddClientsScreen()
	{
		//cout << "\nAdd Clinets Screen Will be Here.";
		clsAddNewClient::ShowAddNewClientsScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen Will be Here.";
		clsDeleteClient::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClinetScreen()
	{
		//cout << "\nUpdate Cleint Screen Will be Here.";
		clsUpdateClient::ShowUpdateClientScreen();

	}

	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will be Here.";
		clsFindClient::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen()
	{
		//cout << "\nTransactions Screen Will be Here.";
		clsTransactions::ShowTransactionsMenue();
	}

	static void _ShowManageUsersScreen()
	{
		//cout << "\nManage Users Screen Will be Here.";
		clsManageUsers::ShowManageUsersMenue();
	}

	static void _ShowLoginResiterScreen()
	{
		//cout << "\nLogin Register Screen Will be Here...";
		clsLoginRegisterScreen::ShowLoginRegisterScreen();

	}

	static void _ShowCurrencyExchangeScreen()
	{
		//cout << "\nCurrency Exchange Screen Will be here.\n";
		clsCurrencyExchangeScreen::ShowCurrenciesMenue();
	}

	static void _Logout()
	{
		CURRENT_USER = clsUser::Find("", "");
	}

	static void _PerformMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eAddClient:
			system("cls");
			_ShowAddClientsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eUpdteClient:
			system("cls");
			_ShowUpdateClinetScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eTransactions:
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eLoginRegiser:
			system("cls");
			_ShowLoginResiterScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eExit:
			system("cls");
			_Logout();
			break;
		}
	}

public:

	static void ShowMainMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Clients.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Cleints.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Cleint.\n";
		cout << setw(37) << left << "" << "\t[5] Find Clinet.\n";
		cout << setw(37) << left << "" << "\t[6] Transtactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout\n";
		cout << setw(37) << left << "" << "============================================\n";
		_PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}

};