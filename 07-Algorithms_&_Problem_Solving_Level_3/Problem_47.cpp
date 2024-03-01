#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct stClient {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};


stClient ReadClientData() {
    stClient Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}


string ConvertRecordToLine(stClient Clinet, string Sepaltor) {
    string sRecord = "";
    sRecord += Clinet.AccountNumber + Sepaltor;
    sRecord += Clinet.PinCode + Sepaltor;
    sRecord += Clinet.Name + Sepaltor;
    sRecord += Clinet.Phone + Sepaltor;
    sRecord += to_string(Clinet.AccountBalance);

    return sRecord;
}

void SaveRecord(string ClientRecord) {
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::out | ios::app);

    if (MyFile.is_open()) {
        MyFile << ClientRecord << endl ;
        MyFile.close();
    }
}

void ShowRecord() {
    fstream MyFile;
    string Line = "";
    MyFile.open(ClientsFileName, ios::in);
    if (MyFile.is_open()) {
        while (getline(MyFile, Line)) {
            cout << Line << endl;
        }
    }
}



void AddRecordsToFile() {
    char AddMoreRecords = 'Y';
    stClient ClientData;
    string ClientRecord;
    while (toupper(AddMoreRecords)) {
        system("cls");
        cout << "Adding New Clinet:\n\n";
        ClientData = ReadClientData();
        ClientRecord = ConvertRecordToLine(ClientData, "//#");
        SaveRecord(ClientRecord);
        cout << "Are Your Need To Add More Records?Y/N ";
        cin >> AddMoreRecords;
        cin.ignore(1,'\n');
    }
    ShowRecord();
}

int main()
{
    AddRecordsToFile();
    
}
