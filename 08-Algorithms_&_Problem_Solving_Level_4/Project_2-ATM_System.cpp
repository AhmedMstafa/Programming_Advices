#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool DeletedMark = false;
};

enum enMainMenueOptions { QuickWithdraw = 1, NormalWithdraw = 2, Deposit = 3, CheckBalance = 4, Logout = 5 };
enum enWithdrawOptions { Twenty = 1, Fifty = 2, Onehundred = 3, Twohundred = 4, Fourhundred = 5, Sixhundred = 6, Eghithundred = 7, Onethousand = 8, Exit = 9 };

const string CLIENTS_FILE = "../../Project_1_Bank_Extension_2/Project_1_Bank_Extension_2/Clients.txt";

stClient CURRENT_CLIENT;

void GoBackToMainMenue();
void ShowMainMenueScreen();

short ReadMainMenueOption()
{
	short Option = 0;
	do {
		cout << "Choose what do you want to do? [1 to 5]? ";
		cin >> Option;
	} while (Option < 1 && Option > 5);
	return Option;
}

short ReadWithdrawOption()
{
	short Option = 0;
	do {
		cout << "Choose what to withdraw from[1] to [8] ? ";
		cin >> Option;
	} while (Option < 1 && Option > 9);
	return Option;
}

vector<string> SplitString(string S1, string Separetor = "#//#")
{
	vector<string> vString;
	string Word = "";
	short pos = 0;

	while ((pos = S1.find(Separetor)) != string::npos)
	{
		Word = S1.substr(0, pos);

		if (Word != "")
			vString.push_back(Word);

		S1.erase(0, (pos + Separetor.length()));
	}

	if (S1 != "")
		vString.push_back(S1);

	return vString;
}

stClient ConvertClientLineToRecord(string Line, string Separetor = "#//#")
{
	stClient Client;
	vector<string> vString;
	vString = SplitString(Line, Separetor);

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

string ConvertClientRecordToLine(stClient Client, string Separetor = "#//#")
{
	string Line = "";

	Line += Client.AccountNumber + Separetor;
	Line += Client.PinCode + Separetor;
	Line += Client.Name + Separetor;
	Line += Client.Phone + Separetor;
	Line += to_string(Client.AccountBalance);

	return Line;

}

void SaveClinetsDataToFile(string FileName, vector<stClient> vClients)
{
	fstream MyFile;
	string Line;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {
		for (stClient C : vClients) {

			if (!C.DeletedMark) {
				Line = ConvertClientRecordToLine(C);
				MyFile << Line << endl;
			}


		}
		MyFile.close();
	}
}

vector<stClient> ImportClientsFromFile(string FileName)
{
	fstream MyFile;
	string Line;
	stClient Client;
	vector<stClient> vClients;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		while (getline(MyFile, Line)) {
			Client = ConvertClientLineToRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;

}

bool FindClinetByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client)
{
	vector<stClient> vClinets = ImportClientsFromFile(CLIENTS_FILE);

	for (stClient C : vClinets) {
		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode) {
			Client = C;
			return true;
		}
	}

	return false;
}

void Login()
{
	bool LoginFaild = false;
	string AccountNumber, PinCode;

	do {
		system("cls");
		cout << "\n______________________________\n";
		cout << "\n\tLogin Screen";
		cout << "\n______________________________\n";

		if (LoginFaild)
			cout << "\nWrong AccountNumber/PinCode!\n";


		cout << "\nEnter Account Number? ";
		cin >> ws >> AccountNumber;
		cout << "\nEnter Pin Code? ";
		cin >> PinCode;

		LoginFaild = !FindClinetByAccountNumberAndPinCode(AccountNumber, PinCode, CURRENT_CLIENT);


	} while (LoginFaild);
	ShowMainMenueScreen();
}

void PrintClientBalance(double ClientBalance) {
	cout << "Your Balance is " <<
		ClientBalance << endl;
}

void ShowClientBalanceScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tCheck Balance Screen\n";
	cout << "===========================================\n";
	PrintClientBalance(CURRENT_CLIENT.AccountBalance);
}

void DepositClientAmount(stClient& CurrentClient, double Amount)
{
	if (CurrentClient.AccountBalance < Amount * -1 && Amount < 0) {
		cout << "\nThe amount exceeds your balance, make another choice.\n";
		return;
	}

	vector<stClient> vClients = ImportClientsFromFile(CLIENTS_FILE);
	char Answer = 'N';

	cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y') {

		CurrentClient.AccountBalance += Amount;

		for (stClient& C : vClients) {
			if (C.AccountNumber == CurrentClient.AccountNumber
				&&
				C.PinCode == CurrentClient.PinCode) {
				C = CurrentClient;
			}
		}

		SaveClinetsDataToFile(CLIENTS_FILE, vClients);

		cout << "\nDone Successfully. New balance is: " <<
			(int)CURRENT_CLIENT.AccountBalance << endl;
	}

}

void PerformWithdrawOption(enWithdrawOptions ClientWithdrawOption)
{
	switch (ClientWithdrawOption)
	{
	case Twenty:
		DepositClientAmount(CURRENT_CLIENT, 20 * -1);
		break;
	case Fifty:
		DepositClientAmount(CURRENT_CLIENT, 50 * -1);
		break;
	case Onehundred:
		DepositClientAmount(CURRENT_CLIENT, 100 * -1);
		break;
	case Twohundred:
		DepositClientAmount(CURRENT_CLIENT, 200 * -1);
		break;
	case Fourhundred:
		DepositClientAmount(CURRENT_CLIENT, 400 * -1);
		break;
	case Sixhundred:
		DepositClientAmount(CURRENT_CLIENT, 600 * -1);
		break;
	case Eghithundred:
		DepositClientAmount(CURRENT_CLIENT, 800 * -1);
		break;
	case Onethousand:
		DepositClientAmount(CURRENT_CLIENT, 1000 * -1);
		break;
	case Exit:
		GoBackToMainMenue();
		break;
	}
}

void ShowQuickWithdrawScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tQuick Withdraw\n";
	cout << "===========================================\n";
	cout << "\t[1] 20      [2] 50\n";
	cout << "\t[3] 100     [4] 200\n";
	cout << "\t[5] 400     [6] 600\n";
	cout << "\t[7] 800     [8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "===========================================\n";
	PrintClientBalance(CURRENT_CLIENT.AccountBalance);
	PerformWithdrawOption((enWithdrawOptions)ReadWithdrawOption());
}

int ReadNumberMultipleOf(short Multiple)
{
	int Number = 0;
	do
	{
		cout << "\nEnter an amount multiple of " <<
			Multiple << "'s ? ";
		cin >> Number;
	} while (!(!(Number % Multiple) && Number >= 5));

	return Number;
}

void ShowNormalWithdrawScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tNormal Withdraw Screen\n";
	cout << "===========================================\n";

	int WithdrawAmount = ReadNumberMultipleOf(5);
	DepositClientAmount(CURRENT_CLIENT, WithdrawAmount * -1);
}

int ReadPositiveAmount()
{
	int Number = 0;

	do
	{
		cout << "\nEnter a positive Amount? ";
		cin >> Number;
	} while (Number < 0);

	return Number;
}

void ShowDepositScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tDeposit Screen\n";
	cout << "===========================================\n";

	int DeposintAmount = ReadPositiveAmount();

	DepositClientAmount(CURRENT_CLIENT, DeposintAmount);
}

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...\n";
	system("pause>0");
	ShowMainMenueScreen();
}

void PerformMainMenueOption(enMainMenueOptions ClientMenueOption)
{
	switch (ClientMenueOption)
	{
	case QuickWithdraw:
		ShowQuickWithdrawScreen();
		GoBackToMainMenue();
		break;
	case NormalWithdraw:
		ShowNormalWithdrawScreen();
		GoBackToMainMenue();
		break;
	case Deposit:
		ShowDepositScreen();
		GoBackToMainMenue();
		break;
	case CheckBalance:
		ShowClientBalanceScreen();
		GoBackToMainMenue();
		break;
	case Logout:
		Login();
		break;
	}
}

void ShowMainMenueScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tATM Main Manue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance..\n";
	cout << "\t[5] Logout.\n";
	cout << "===========================================\n";

	PerformMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

int main() {
	Login();
	return 0;
}