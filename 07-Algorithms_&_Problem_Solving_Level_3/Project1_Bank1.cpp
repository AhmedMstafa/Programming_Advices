#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

const string ClientsFile = "Clients.txt";

enum enClientAction { Show = 1, Add = 2, Deleter = 3, Update = 4, Find = 5, Exit = 6 };

struct stClient {
    string AccountName;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool DeletedMark = false;
};

short ReadClientAction(){
    short Action = 0;
    do {
        cout << "Chose what do you want do: [1 to 6]? ";
        cin >> Action;
    } while (Action <= 0 || Action > 6);
    return Action;
}

/***************/

void ShowClinetsTable(short NumberOfClients) {
    cout << "\n\t\t\t\t\tClinet List (" << NumberOfClients << ") Client(s).\n\n";
    cout << "________________________________________________";
    cout << "________________________________________________\n\n";
    cout << "| " << setw(15) << left << "Account Number";
    cout << "| " << setw(10) << left << "Pin Code";
    cout << "| " << setw(40) << left << "Client Name";
    cout << "| " << setw(12) << left << "Phone";
    cout << "| " << setw(12) << left << "Balance";
    cout << "\n________________________________________________";
    cout << "________________________________________________\n\n";
}

vector<string>  SplitLine(string Line, string Sepatator = "#//#") {
    vector<string> vClinet;
    string Word;
    short pos = 0;
    while ((pos = Line.find(Sepatator)) != string::npos) {
        Word = Line.substr(0, pos);
        if (Word != "") {
            vClinet.push_back(Word);
        }

        Line.erase(0, (pos + Sepatator.length()));
    }
    if (Line != "") {
        vClinet.push_back(Word);
    }
    return vClinet;
}

stClient ConvertLineToRecord(vector<string> LineSpleted) {
    stClient Client;

    Client.AccountName = LineSpleted[0];
    Client.PinCode = LineSpleted[1];
    Client.Name = LineSpleted[2];
    Client.Phone = LineSpleted[3];
    Client.AccountBalance = stod(LineSpleted[4]);

    return Client;
}

vector<stClient> ImportDataFromFile(string FileName) {
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    string Line;
    vector<stClient> vClinets;
    stClient Client;

    if (MyFile.is_open()) {
        while (getline(MyFile, Line)) {
            Client = ConvertLineToRecord(SplitLine(Line));
            vClinets.push_back(Client);
        }
        MyFile.close();
    }
    return vClinets;
}

void ShowAllClientData(vector<stClient> vClients) {
    for (stClient Client :  vClients) {
        cout << "| " << setw(15) << left << Client.AccountName;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(40) << left << Client.Name;
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(12) << left << Client.AccountBalance ;
        cout << endl;
    }
    cout << "________________________________________________";
    cout << "________________________________________________\n";
}

void ShowClients() {
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    system("cls");
    ShowClinetsTable(vClients.size());
    ShowAllClientData(vClients);
}

/*******/

stClient ReadClient() {
    stClient Client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountName);
    cout << "Enter Pin Code? ";
    getline(cin , Client.PinCode);

    cout << "Enter Name? ";
    getline(cin , Client.Name);

    cout << "Enter Phone? ";
    getline(cin , Client.Phone);

    cout << "Account Balance? ";
    cin >> Client.AccountBalance;
    return Client;
}

string ConvertRecordToString(stClient Client ,string Separator = "#//#") {
    string Line = "";
    Line += Client.AccountName + Separator;
    Line += Client.PinCode + Separator;
    Line += Client.Name + Separator;
    Line += Client.Phone + Separator;
    Line += to_string(Client.AccountBalance);
    return Line;
}

void ExportDataToFile(string FileName, string DataLine) {
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open()) {
        MyFile << DataLine << endl;

        MyFile.close();
    }
}

void AddNewClient() {
    stClient Clinet = ReadClient();
    ExportDataToFile(ClientsFile, ConvertRecordToString(Clinet));
}


string ReadAccountName();

bool IsFoundInClinetsLis(string AccountName, stClient& Client);

void AddClinets() {
    char AddMore = 'Y';
    string AccountName;
    stClient Client;
    while (AddMore == 'Y' || AddMore == 'y') {
        system("cls");
        cout << "\n----------------------------------------\n";
        cout << "           Add New Client Screen   ";
        cout << "\n----------------------------------------\n";
        AccountName = ReadAccountName();
        if (!IsFoundInClinetsLis(AccountName, Client)) {
        cout << "Adding New Client: \n\n";
        AddNewClient();
        cout << "Client Added Successfully,\n";
        }
        else {
            cout << "Client with [" << AccountName << "] already Exists,";
            cout << "Enter another Account Number \n\n";
        }
        cout << "do you want to add more clients? Y/N? ";
        cin >> ws >> AddMore;
    }
}

/*******/

string ReadAccountName() {
    string AccountName;
    cout << "Plsease Enter Account Number? ";
    getline(cin >> ws, AccountName);
    return AccountName;
}

bool FindClient(string AccountName, stClient &Client,vector<stClient> &vClients) {
    for (stClient& C : vClients) {
        if (AccountName == C.AccountName) {
            Client = C;

            return true;
        }
    }
    return false;
}

void PrintClinetData(stClient Client) {
    cout << "\n-------------------------------------\n";
    cout << "Account Number: " << Client.AccountName << endl;
    cout << "Pin Code      : " << Client.PinCode << endl;
    cout << "Name          : " << Client.Name << endl;
    cout << "Phone         : " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
    cout << "-------------------------------------\n";

}

bool MarkDeletedClient(string AccountName, vector<stClient>& vClients) {
    for (stClient& C : vClients) {
        if (AccountName == C.AccountName) {
            C.DeletedMark = true;

            return true;
        }
    }
    return false;
}

void UpdateClinetsFile(string FileName, vector<stClient> vClients) {
    fstream MyFile;
    string Line;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open()) {
        for (stClient Client : vClients) {
            if (!Client.DeletedMark) {
            Line = ConvertRecordToString(Client);
            MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
}

void DeleteClinetByAccountNumber(string AccountName, vector<stClient>& vClients) {
    stClient Client;
    char Answer = 'N';

    if (FindClient(AccountName, Client, vClients)) {
        cout << "\nThe Following are the client details:\n";
        PrintClinetData(Client);
        MarkDeletedClient(AccountName, vClients);
        cout << "\nAre you Sure you want Delete this Client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            UpdateClinetsFile(ClientsFile, vClients);
            cout << "\nClient Delete Successfully,\n";
        }
    }
    else {
        cout << "\nClient With Account Number (" << AccountName;
        cout << ") is Not Found!\n";
    }


}


void DeleteClient() {
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    system("cls");
    cout << "\n----------------------------------------\n";
    cout << "           Delete Client Screen   ";
    cout << "\n----------------------------------------\n";
    string AccountName = ReadAccountName();
    DeleteClinetByAccountNumber(AccountName, vClients);
}

/*************/

bool IsFoundInClinetsLis(string AccountName, stClient &Client) {
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    for (stClient& C : vClients) {
        if (C.AccountName == AccountName) {
            Client = C;
            return true;
        }
    }
    return false;
}

void FindClinetByAccountNumber(string AccountName) {
    stClient Client;

    if (IsFoundInClinetsLis(AccountName, Client)) {
        cout << "\nThe Following are the client details:\n";
        PrintClinetData(Client);
     
    }
    else {
        cout << "\nClient With Account Number (" << AccountName;
        cout << ") is Not Found!\n";
    }

}

void FindClient() {
    system("cls");
    cout << "\n----------------------------------------\n";
    cout << "           Find Client Screen   ";
    cout << "\n----------------------------------------\n";
    string AccountName = ReadAccountName();
    FindClinetByAccountNumber(AccountName);

}


/*************/


bool UpdatClientData(string AccountName,stClient Client, vector<stClient>& vClients) {
    for (stClient& C : vClients) {
        if (AccountName == C.AccountName) {
            C = Client;
            return true;
        }
    }
    return false;
}

/***********/

stClient ReadNewData(string AccountName) {
    stClient Client;
    cout << "\n-------------------------------------\n";
    cout << "Account Number: " << AccountName << endl;
    Client.AccountName = AccountName;
    cout << "Pin Code      : " ;
    getline(cin >> ws,Client.PinCode );
    cout << "Name          : " ;
    getline(cin , Client.Name);
    cout << "Phone         : " ;
    getline(cin, Client.Phone);
    cout << "Account Balance: ";
    cin >> Client.AccountBalance;
    cout << "-------------------------------------\n";
    return Client;
}

bool UpdatClientData(string AccountName, vector<stClient> &vClinet) {
    stClient  Client = ReadNewData(AccountName);
    for (stClient &C : vClinet) {
        if (AccountName == C.AccountName) {
            C = Client;
            return true;
        }
    }
    return false;
}


void UpdateClinetByAccountName(string AccountName, vector<stClient>& vClients) {
    stClient Clinet;

    if (FindClient(AccountName, Clinet,vClients)) {
        cout << "\nThe Following are the client details:\n";

        UpdatClientData(AccountName, vClients);
        UpdateClinetsFile(ClientsFile, vClients);
        cout << "\nClient Updated Successfully,\n";


    }
    else {
        cout << "\nClient With Account Number (" << AccountName;
        cout << ") is Not Found!\n";
    }
}

void UpdateClient() {
    vector<stClient> vClinets = ImportDataFromFile(ClientsFile);
    system("cls");
    cout << "\n----------------------------------------\n";
    cout << "           Update Client Screen   ";
    cout << "\n----------------------------------------\n";
    string AccountName = ReadAccountName();
    UpdateClinetByAccountName(AccountName, vClinets);
}


/***********/

void ExitApp() {
    exit(0);
}



void ClientAction(short Action) {

    switch (enClientAction(Action))
    {
    case Show:
        ShowClients();
        break;
    case Add:
        AddClinets();
        break;
    case Deleter:
        DeleteClient();
        break;
    case Update:
        UpdateClient();
        break;
    case Find:
        FindClient();
        break;
    case Exit:
        ExitApp();
        break;
    default:
        ShowClients();
        break;
    }
}

void PrinMainMenue() {
    short Action;
    system("cls");
    cout << "========================================\n";
    cout <<  "           Main Menue Screen\n";
    cout << "========================================\n";
    cout <<  "       [1] Show Client List.\n";
    cout <<  "       [2] Add New Client.\n";
    cout <<  "       [3] Delete Client.\n";
    cout <<  "       [4] Update Client.\n";
    cout <<  "       [5] Find Client.\n";
    cout <<  "       [6] Exit.\n";
    cout << "========================================\n";
    Action = ReadClientAction();
    ClientAction(Action);
    system("pause");
    PrinMainMenue();
}

int main()
{
    PrinMainMenue();
}
