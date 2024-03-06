#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
const string ClientsFile = "Clients.txt";

struct stClient {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double Balance = 0;
};

stClient ReadClientData() {
    stClient Client;
    cout << "Enter Account Name ";
    getline(cin, Client.AccountNumber);
    cout << "Enter Pin Code ";
    getline(cin, Client.PinCode);
    cout << "Enter Name ";
    getline(cin, Client.Name);
    cout << "Enter Phoen ";
    getline(cin, Client.Phone);
    cout << "Enter Balance ";
    cin >> Client.Balance;

    return Client;
}

string ConvertRecordToString(stClient Client,string Separetor = "#//#") {
    string ClinetData = "";
    ClinetData += Client.AccountNumber + Separetor;
    ClinetData += Client.PinCode + Separetor;
    ClinetData += Client.Name + Separetor;
    ClinetData += Client.Phone + Separetor;
    ClinetData += to_string(Client.Balance);

    return ClinetData;
}

void ExportDataToFile(string FileName, string Data) {
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << Data << endl;

        MyFile.close();
    }
}

void AddNewClient() {
    stClient Client = ReadClientData();
    ExportDataToFile(ClientsFile,ConvertRecordToString(Client));
}

void AddClients() {
    char AddMore = 'Y';
    
    while (toupper(AddMore) == 'Y') {
        system("cls");
        AddNewClient();

        cout << "Do You Need To Add More Client?Y/N";
        cin >> AddMore;
    }
}

/**********/

vector<string> SplitString(string S1, string Separetor = "#//#") {
    vector<string> vClient;
    string Word = "";
    short pos = 0;
    
     while((pos = S1.find(Separetor)) != string::npos) {
        Word = S1.substr(0, pos);
        if (Word != "") {
            vClient.push_back(Word);
        }

        S1.erase(0, (pos + (Separetor.length())));
    }

    if (S1 != "") {
        vClient.push_back(S1);
    }

    return vClient;
}

stClient ConvertStringToRecord(string Line, string Separetor = "#//#") {
    stClient Client;
    vector<string> vClinet = SplitString(Line, Separetor);
    Client.AccountNumber = vClinet[0];
    Client.PinCode = vClinet[1];
    Client.Name = vClinet[2];
    Client.Phone = vClinet[3];
    Client.Balance = stod(vClinet[4]);

    return Client;
}

vector<stClient> ImportDataFromFile(string FileName) {
    vector<stClient> Client;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    string Line;
    if (MyFile.is_open()) {
        while (getline(MyFile, Line)) {
            Client.push_back(ConvertStringToRecord(Line));
        }
        MyFile.close();
    }

    return Client;
}

void PrintClientRecord(stClient Clinet) {
    cout << "| " << setw(15) << left << Clinet.AccountNumber;
    cout << "| " << setw(10) << left << Clinet.PinCode;
    cout << "| " << setw(40) << left << Clinet.Name;
    cout << "| " << setw(12) << left << Clinet.Phone;
    cout << "| " << setw(12) << left << Clinet.Balance;
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

void PrintClinets() {
    vector<stClient> vClinets = ImportDataFromFile(ClientsFile);
    PrintAllClinetsData(vClinets);
}

/***********/

string ReadClientNumber() {
    string AccountNumber = "";
    cout << "Please Enter Account Number? ";
    getline(cin >> ws, AccountNumber);
    return AccountNumber;
}

void PrintClientCard(stClient Client) {
    cout << endl;
    cout << "\nThe Follwing are the client details: \n\n";
    cout << "Account Number: " << Client.AccountNumber << endl;
    cout << "Pin Code      : " << Client.PinCode << endl;
    cout << "Name          : " << Client.Name << endl;
    cout << "Phone         : " << Client.Phone << endl;
    cout << "Account Balance: " << Client.Balance << endl;
    cout << '\n';
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client) {
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);

    for (stClient& C : vClients) {
        if (AccountNumber == C.AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
   
}


void FindClient() {
    string AccountNumber = ReadClientNumber();
    stClient Client;

    if (FindClientByAccountNumber(AccountNumber, Client)) {
        PrintClientCard(Client);
    }
    else {
        cout << endl;
        cout << "Client with Account Number (" << AccountNumber;
        cout << ") Not Found!" << endl;
    }


 
}

/**********/


int main()
{
 //   AddClients();
    PrintClinets();
    FindClient();
}
