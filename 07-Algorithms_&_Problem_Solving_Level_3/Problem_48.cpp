#include <iostream>
#include <string>
#include <iomanip>>
#include <vector>
#include <fstream>
using namespace std;

const string ClientsFile = "Clients.txt";

struct stClient {
	string AccountNumber = "";
	string PinCode = "";
	string ClinetName = "";
	string Phone = "";
	double Balance = 0;
};

stClient ReadClintData() {
	stClient Client;
	cout << "Enter Account Number:";
	getline(cin >> ws , Client.AccountNumber);
	cout << "Enter PinCode:";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Clint Name:";
	getline(cin >> ws, Client.ClinetName);
	cout << "Enter Phone:";
	getline(cin >> ws, Client.Phone);
	cout << "Enter Balance:";
	cin >> Client.Balance;
	return Client;
}

string ConvertClintDataToString(stClient ClientData, string sepatrator = "#//") {
	string ClientRecord;
	ClientRecord += ClientData.AccountNumber + sepatrator;
	ClientRecord += ClientData.PinCode + sepatrator;
	ClientRecord += ClientData.ClinetName + sepatrator;
	ClientRecord += ClientData.Phone + sepatrator;
	ClientRecord += to_string(ClientData.Balance);

	return ClientRecord;
}

void AddRecordToFile(string FileName, string Record) {
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {
		MyFile << Record << endl;

		MyFile.close();
	}
}

void AddNewClient() {
	string NewClinet = ConvertClintDataToString(ReadClintData());
	AddRecordToFile(ClientsFile, NewClinet);
}


vector<string> SpilceString(string S1 ,string sepatrator = "#//") {
	vector<string> vClientData;
	string Word = "";
	short pos = 0;
	while ((pos = S1.find(sepatrator)) != string::npos) {
		Word = S1.substr(0, pos);
		if (Word != "") {
			vClientData.push_back(Word);
		}

		S1.erase(0, (pos + (sepatrator.length())));

	}

	if (S1 != "") {
		vClientData.push_back(S1);
	}

	return vClientData;
}

stClient ConvertLineToRecord(string Line, string seperator = "#//") {
	vector<string> vClient;
	stClient  stClientData;
	vClient = SpilceString(Line);
	stClientData.AccountNumber = vClient[0];
	stClientData.PinCode = vClient[1];
	stClientData.ClinetName = vClient[2];
	stClientData.Phone = vClient[3];
	stClientData.Balance = stod(vClient[4]);
	return stClientData;
}

vector<stClient> ImportDataFromFile(string FileName) {
	fstream MyFile;
	stClient Clinet;
	vector<stClient> vClients;
	string Line;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {

	while (getline(MyFile, Line)) {
		Clinet = ConvertLineToRecord(Line);
		vClients.push_back(Clinet);
	}
		MyFile.close();
	}

	return vClients;

}


void PrintClientRecord(stClient Clinet) {
	cout << "| "  << setw(15) << left << Clinet.AccountNumber;
	cout << "| "  << setw(10) << left << Clinet.PinCode;
	cout << "| "  << setw(40) << left << Clinet.ClinetName;
	cout << "| "  << setw(12) << left << Clinet.Phone;
	cout << "| "  << setw(12) << left << Clinet.Balance;
}

void PrintAllClinetsData(vector<stClient> vClients) {
	cout << "\n\t\t\t\t\tClinet List(" << vClients.size() << ") Clinets(s).";
	cout << "\n__________________________________________________________";
	cout << "_____________________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Clinet Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n__________________________________________________________";
	cout << "_____________________________________________________\n" << endl;

	for (stClient& Client : vClients) {
		PrintClientRecord(Client);
		cout << endl;
	}
}






void AddClients() {
	char AddMore = 'Y';
	while (toupper(AddMore) == 'Y') {
		system("cls");
		AddNewClient();
		cout << "\n\nDo Your Want Add More Clients?Y/N ";
		cin >> AddMore;
	}
	
}


int main()
{
	AddClients();
	vector<stClient> vClients = ImportDataFromFile(ClientsFile);
	PrintAllClinetsData(vClients);
}