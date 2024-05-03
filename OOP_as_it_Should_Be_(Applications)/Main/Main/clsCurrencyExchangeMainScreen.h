#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum enCurrencyMenueOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrency = 3, eCurrencyCalculator = 4, eMainMenue = 5 };

	static short _ReadCurrencyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]: ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 5, "\nPlease Enter Number between 1 and 5");
		return Choice;
	}

	static void _GoBackToCurrencyExchangeScreen()
	{
		cout << "\nPress Any key to go back Currency Menue..\n";
		system("pause>0");
		ShowCurrenciesMenue();
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nList Currencies Screen Will be here..";
		clsCurrenciesList::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will be here..";
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyScreen()
	{
		//cout << "\nUpdate Currency Screen Will be here..";
		clsUpdateCurrency::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator Screen Will be here..";
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyMenueOptions(enCurrencyMenueOptions CurrencyMenueOption)
	{
		switch (CurrencyMenueOption)
		{
		case enCurrencyMenueOptions::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case enCurrencyMenueOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case enCurrencyMenueOptions::eUpdateCurrency:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case enCurrencyMenueOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case enCurrencyMenueOptions::eMainMenue:
		{
			// Main Menue Will Be Handl it  >_
		}

		}
	}

public:
	static void ShowCurrenciesMenue()
	{
		system("cls");
		_DrawScreenHeader("  Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "=================================================\n";
		cout << setw(37) << left << "" << "\t\t Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "=================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "=================================================\n";
		_PerformCurrencyMenueOptions((enCurrencyMenueOptions)_ReadCurrencyMenueOption());
	}
};