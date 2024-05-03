#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrency : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card: ";
		cout << "\n___________________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n___________________________\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found! :-(\n";
			_PrintCurrency(Currency);
		}

	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("  Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country : ";
		short Ansewer = clsInputValidate::ReadNumberBetween<short>(1, 2, "\nPlease Enter Number Between 1 and 2 : ");

		if (Ansewer == 1)
		{
			cout << "\nPlease Enter CurrencyCode: ";
			string Code = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(Code);
			_ShowResults(Currency);
		}
		else
		{
			cout << "\nPlease Enter Country Name: ";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}

	}
};