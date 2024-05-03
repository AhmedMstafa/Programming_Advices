#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "clsString.h";
#include "clsDate.h"
using namespace std;

class clsBankClient : public clsPerson
{

private:
	enum enMode { EmptyMode = 1, UpdateMode = 2, AddMode = 3 };

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	enMode _Mode;

	bool _MarkedForDeleted = false;

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertLineToObjec(string Line, string Seperator = "#//#")
	{
		vector<string> vClient = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));
	}

	static string _ConvertObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string Line = "";

		Line += Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client.AccountNumber() + Seperator;
		Line += Client.PinCode + Seperator;
		Line += to_string(Client.AccountBalance);

		return Line;
	}

	static vector<clsBankClient> _LoadDataFromFile()
	{

		fstream MyFile;
		vector<clsBankClient> vClients;

		MyFile.open("../../db/Clients.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToObjec(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("../../db/Clients.txt", ios::out); // Write Mode

		if (MyFile.is_open())
		{
			string Line;
			for (clsBankClient C : vClients)
			{
				if (C._MarkedForDeleted == false)
				{
					Line = _ConvertObjectToLine(C);
					MyFile << Line << endl;
				}

			}
			MyFile.close();

		}

	}

	void _Update()
	{
		vector<clsBankClient> vClients = _LoadDataFromFile();

		for (clsBankClient& Client : vClients)
		{
			if (Client.AccountNumber() == _AccountNumber)
			{
				Client = *this;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);
	}

	static void _AddLineDataToFile(string Line)
	{
		fstream MyFile;

		MyFile.open("../../db/Clients.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;

			MyFile.close();
		}

	}

	void _AddNew() {
		_AddLineDataToFile(_ConvertObjectToLine(*this));
	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Separetor = "#//#")
	{
		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Separetor;
		TransferLogRecord += AccountNumber() + Separetor;
		TransferLogRecord += DestinationClient.AccountNumber() + Separetor;
		TransferLogRecord += to_string(Amount) + Separetor;
		TransferLogRecord += to_string(AccountBalance) + Separetor;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Separetor;
		TransferLogRecord += UserName;

		return TransferLogRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string DataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);
		fstream MyFile;
		MyFile.open("../../db/TransferLog.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}
	}

	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertLineToTrnsferLogRecord(string Line, string Separetor = "#//#")
	{
		stTransferLogRecord TransferLog;

		vector<string> vString = clsString::Split(Line, Separetor);

		TransferLog.DateTime = vString[0];
		TransferLog.SourceAccountNumber = vString[1];
		TransferLog.DestinationAccountNumber = vString[2];
		TransferLog.Amount = stof(vString[3]);
		TransferLog.SrcBalaceAfter = stof(vString[4]);
		TransferLog.desBalanceAfter = stof(vString[5]);
		TransferLog.UserName = vString[6];

		return TransferLog;
	}


public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float SrcBalaceAfter;
		float desBalanceAfter;
		string UserName;
	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	void GetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = GetAccountBalance)) double AccountBalance;

	/*
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n________________________";
		cout << "\nFirst Name      : " << FirstName;
		cout << "\nLast Name       : " << LastName;
		cout << "\nFull Name       : " << FullName();
		cout << "\nEmail           : " << Email;
		cout << "\nPhone           : " << Phone;
		cout << "\nAccountNumber   : " << _AccountNumber;
		cout << "\nPassword        : " << _PinCode ;
		cout << "\nAccount Balance : " << _AccountBalance;
		cout << "\n________________________\n";

		cout << endl;
	}
	*/

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		vector<clsBankClient> vClients;

		MyFile.open("../../db/Clients.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToObjec(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();

	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		vector<clsBankClient> vClients;

		MyFile.open("../../db/Clients.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToObjec(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();

	}

	static bool IsClientExist(string AccountNumber)
	{
		return !clsBankClient::Find(AccountNumber).IsEmpty();
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddMode, "", "", "", "", AccountNumber, "", 0);
	}

	enum enSaveResults { svSaveSucceded = 1, svFaildEmptyObject = 2, svFalidAccountNumberExists = 3 };

	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDeleted = true;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadDataFromFile();
	}

	static double GetTotalBalances()
	{
		double TotalBalance = 0;

		vector<clsBankClient> vClients = _LoadDataFromFile();

		for (clsBankClient C : vClients)
		{
			TotalBalance += C.AccountBalance;
		}

		return TotalBalance;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount <= _AccountBalance)
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}

		return false;

	}

	bool Transfer(float Amount, clsBankClient& DestinationClient)
	{
		if (this->Withdraw(Amount))
		{
			DestinationClient.Deposit(Amount);
			_RegisterTransferLog(Amount, DestinationClient, CURRENT_USER.UserName);
			return true;
		}
	}

	static vector<stTransferLogRecord> GetTransferLogList()
	{
		vector<stTransferLogRecord> vTransferLogs;
		fstream MyFile;
		MyFile.open("../../db/TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			stTransferLogRecord TransferLog;
			while (getline(MyFile, Line))
			{
				TransferLog = _ConvertLineToTrnsferLogRecord(Line);
				vTransferLogs.push_back(TransferLog);
			}

			MyFile.close();
		}

		return vTransferLogs;
	}

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:

			return svFaildEmptyObject;

			break;
		case clsBankClient::UpdateMode:

			_Update();
			return svSaveSucceded;

			break;
		case clsBankClient::AddMode:

			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return svFalidAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return svSaveSucceded;
			}

			break;
		}
	}

};