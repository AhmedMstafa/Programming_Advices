#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsCurrenciesList : protected clsScreen
{

private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:
	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenceisList();

		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t  (" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t__________________________________________________";
		cout << "__________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(30) << "Country";
		cout << "| " << setw(8) << left << "Code";
		cout << "| " << setw(45) << left << "Name";
		cout << "| " << setw(10) << left << "Rate/(1$)\n";
		cout << setw(8) << left << "" << "\n\t__________________________________________________";
		cout << "__________________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
			cout << setw(8) << "" << "\nNo Currencies Found In The System!\n";
		else
			for (clsCurrency C : vCurrencies)
			{
				_PrintCurrencyRecordLine(C);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t__________________________________________________";
		cout << "__________________________________________________\n" << endl;
	}
};