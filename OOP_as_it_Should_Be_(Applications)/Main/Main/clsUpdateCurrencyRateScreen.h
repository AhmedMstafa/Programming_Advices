#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateCurrency : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card: ";
		cout << "\n___________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n___________________________\n";
	}

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = clsInputValidate::ReadNumber<float>();
		return NewRate;
	}

public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("  Update Currency Screen");

		cout << "\nPlease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code Not Fond , Enter Another one: ";
			string CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrency(Currency1);

		cout << "\nAre you suer you want update the rate of this Currency y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\nUpdate Currency Rate: ";
			cout << "\n_______________________\n";

			Currency1.UpdateRate(_ReadRate());

			cout << "\nCurrency Updated Successfully :-)\n";

			_PrintCurrency(Currency1);
		}
		else
		{
			cout << "\nUpdated Currency are Canceld!\n";
		}

	}
};