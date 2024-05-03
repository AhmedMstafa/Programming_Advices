#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyCalculator : protected clsScreen
{
	static clsCurrency GetCurrency(string Message)
	{
		string Code = "";
		cout << Message << endl;
		Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "\nCurrency is Not Extist , Please Enter Another Code: ";
			Code = clsInputValidate::ReadString();
		}
		return clsCurrency::FindByCode(Code);
	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange : ";
		float Amount = 0;
		Amount = clsInputValidate::ReadNumber<float>();
		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card: ")
	{
		cout << "\n" << Title << "\n";
		cout << "\n___________________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n___________________________\n";
	}

	static void _PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1);

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to: \n";

		_PrintCurrencyCard(Currency2);

		float AmountInCurrency2 = Currency1.ConvertOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();

	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		_DrawScreenHeader("  Update Currency Screen");

		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			clsCurrency CurrencyFrom = GetCurrency("\nPlsease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = GetCurrency("\nPlsease Enter Currency2 Code: ");
			float Amount = 0;
			Amount = _ReadAmount();

			_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;
		}
	}

};