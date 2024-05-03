#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;

class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separetor = "#//#")
	{
		vector<string> vString = clsString::Split(Line, Separetor);

		return clsCurrency(enMode::UpdateMode, vString[0], vString[1], vString[2], stof(vString[3]));
	}

	static vector<clsCurrency> _LoadCurrencyObjecFromFile()
	{
		vector<clsCurrency> vCurrency;

		fstream MyFile;
		MyFile.open("../../db/Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				vCurrency.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrency;
	}

	static string _ConvertCurrencyObjecToLine(clsCurrency Currency, string Separetor = "#//#")
	{
		string Line = "";

		Line += Currency.Country() + Separetor;
		Line += Currency.CurrencyName() + Separetor;
		Line += Currency.CurrencyCode() + Separetor;
		Line += to_string(Currency.Rate());

		return Line;
	}

	void _SaveCurrencyObjectToFile(vector<clsCurrency> vCurrecy)
	{
		fstream MyFile;
		MyFile.open("../../db/Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsCurrency C : vCurrecy)
			{
				Line = _ConvertCurrencyObjecToLine(C);
				MyFile << Line << endl;
			}

			MyFile.close();
		}
	}

	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	void _Update()
	{
		vector<clsCurrency> vCurrency = _LoadCurrencyObjecFromFile();

		for (clsCurrency& C : vCurrency)
		{
			if (C.Country() == Country())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyObjectToFile(vCurrency);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyName, string CurrencyCode, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyName = CurrencyName;
		_CurrencyCode = CurrencyCode;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRete)
	{
		_Rate = NewRete;
		_Update();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("../../db/Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}

		return _GetEmptyObject();

	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("../../db/Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency	Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}

		return _GetEmptyObject();

	}

	static bool IsCurrencyExist(string CurrnecyCode)
	{
		return !clsCurrency::FindByCode(CurrnecyCode).IsEmpty();
	}

	static vector<clsCurrency> GetCurrenceisList()
	{
		return _LoadCurrencyObjecFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = this->ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)AmountInUSD * Currency2.Rate();
	}
};