#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

const string ClientsFile = "Clients.txt";

void ShowMainMenue();

void ShowTransctionsScreen();

enum enMainManueOptions { Show = 1, Add = 2, Deleter = 3, Update = 4, Find = 5, Transations = 6,Exit= 7 };
enum enTransactions { Deposit = 1, Withdraw = 2, TotalBalance =3, MainMenue = 4 };


struct stClient {
    string AccountName;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool DeletedMark = false;
};

short ReadMainMenueoption() {
    short Action = 0;
    do {
        cout << "Chose what do you want do: [1 to 7]? ";
        cin >> Action;
    } while (Action <= 0 || Action > 7);
    return Action;
}


short ReadTransactionsMenueOption() {
    short Action = 0;
    do {
        cout << "Chose what do you want do: [1 to 4]? ";
        cin >> Action;
    } while (Action <= 0 || Action > 4);
    return Action;
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
        vClinet.push_back(Line);
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


void PrintClientRecordLine(stClient Client) {
    cout << "| " << setw(15) << left << Client.AccountName;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientScreen() {
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    cout << "\n\t\t\t\t\tClinet List (" << vClients.size() << ") Client(s).\n\n";
    cout << "________________________________________________";
    cout << "________________________________________________\n\n";
    cout << "| " << setw(15) << left << "Account Number";
    cout << "| " << setw(10) << left << "Pin Code";
    cout << "| " << setw(40) << left << "Client Name";
    cout << "| " << setw(12) << left << "Phone";
    cout << "| " << setw(12) << left << "Balance";
    cout << "\n________________________________________________";
    cout << "________________________________________________\n\n";
    if (vClients.size() == 0) {
        cout << "\t\t\t\tNo Clients Available In The System!\n\n";
    }
    else {
        for (stClient Client : vClients) {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    }
    cout << "________________________________________________";
    cout << "________________________________________________\n";
}


string ConvertRecordToString(stClient Client, string Separator = "#//#") {
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


bool ClientExistsByAccountName(string AccountName, string FileName) {
    vector<stClient> vClients = ImportDataFromFile(FileName);
    for (stClient C : vClients) {
        if (C.AccountName == AccountName) {
            return true;
        }
    }
    return false;
}

stClient ReadNewClient() {
    stClient Client;
    cout << "Enter Account Name? ";
    getline(cin >> ws, Client.AccountName);
    while (ClientExistsByAccountName(Client.AccountName, ClientsFile))
    {
        cout << "\nClient with [" << Client.AccountName << "] already exists, Enter another Account Name ? ";
        getline(cin >> ws, Client.AccountName);

    }
    cout << "Enter Pin Code? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance? ";
    cin >> Client.AccountBalance;
    return Client;
}

void  AddNewClient() {
    stClient Client;
    Client = ReadNewClient();
    ExportDataToFile(ClientsFile, ConvertRecordToString(Client));
}

void AddNewClients() {
    char AddMore = 'Y';
    do {
        cout << "Adding New Client:\n\n";
        AddNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N?  ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

void ShowAddNewClientsScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n---------------------------------\n";
    AddNewClients();
}


string ReadClientAccountName() {
    string AccountName;
    cout << "\nPlease Enter Client Account Name: ";
    getline(cin >> ws, AccountName);
    return AccountName;
}

bool FindClientByAccountName(string AccountName, vector<stClient>& vClients, stClient& Client) {
    for (stClient& C : vClients) {
        if (C.AccountName == AccountName) {
            Client = C;
            return true;
        }
    }

    return false;
}

void PrintClientCard(stClient Client) {
    cout << "Account Name  : " << Client.AccountName << endl;
    cout << "Pin Code      : " << Client.PinCode << endl;
    cout << "Name          : " << Client.Name << endl;
    cout << "Phone         : " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;

}

bool MarkClientForDeleteByAccountName(string AccountName, vector<stClient>& vClients) {
    for (stClient& C : vClients) {
        if (C.AccountName == AccountName) {
            C.DeletedMark = true;
            return true;
        }
    }
    return false;
}

void SaveClientDataToFile(string FileName, vector<stClient> vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string Line;
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

bool DeleteClientByAccountName(string AccountName, vector<stClient>& vClients) {
    stClient Client;
    char Answer = 'N';
    if (FindClientByAccountName(AccountName, vClients, Client)) {
        PrintClientCard(Client);

        cout << "\n\nAre You Sure You Want Delete This Client? Y/N? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            MarkClientForDeleteByAccountName(AccountName, vClients);
            SaveClientDataToFile(ClientsFile, vClients);

            vClients = ImportDataFromFile(ClientsFile);

            cout << "\n\nClinet Deleted Successfully.";
            return true;
        }
        else {
            cout << "\nClient With Account Name (" << AccountName << ") is Not Found!";
            return false;
        }
    }
}

void ShowDeleteClientScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tDelete Clients Screen";
    cout << "\n---------------------------------\n";
    vector<stClient>vClients = ImportDataFromFile(ClientsFile);
    string AccountName = ReadClientAccountName();
    DeleteClientByAccountName(AccountName, vClients);
}



stClient ChangeClientRecord(string AccountName) {
    stClient Client;
    Client.AccountName = AccountName;
    cout << "\n\nEnter Pin Code? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance? ";
    cin >> Client.AccountBalance;
    return Client;
}

bool UpdateClientByAccountName(string AccountName, vector<stClient>& vClients) {
    stClient Client;
    char Answer = 'N';

    if (FindClientByAccountName(AccountName, vClients, Client)) {
        PrintClientCard(Client);

        cout << "\n\nAre You Sure You Want Update This Client? Y/N? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            for (stClient& C : vClients) {
                if (C.AccountName == AccountName) {
                    C = ChangeClientRecord(AccountName);
                    break;
                }
            }
            SaveClientDataToFile(ClientsFile, vClients);


            cout << "\n\nClinet Updated Successfully.";
            return true;
        }
        else {
            cout << "\nClient With Account Name (" << AccountName << ") is Not Found!";
            return false;
        }
    }

}

void ShowUpdateClientScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tUpdate Clients Screen";
    cout << "\n---------------------------------\n";
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    string AccountName = ReadClientAccountName();
    UpdateClientByAccountName(AccountName, vClients);
}



void ShowFindClientScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tFind Clients Screen";
    cout << "\n---------------------------------\n";
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    stClient Client;
    string AccountName = ReadClientAccountName();
    if (FindClientByAccountName(AccountName, vClients, Client)) {
        PrintClientCard(Client);
    }
    else {
        cout << "\nClient With Account Name (" << AccountName << ") is Not Found!";
    }
}


void ShowEndScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n---------------------------------\n";
}


bool DepositClientAmount(string AccountName, vector<stClient> &vClients, double AccountBalance) {
    double NewAmount;
    char Answer = 'N';
    cout << "\nPlease Enter Deposit Amount? ";
    cin >> NewAmount;
    cout << "\n\nAre You Sure You Want Perform this transation? Y/N ? ";
    cin >> Answer;
    if (toupper(Answer) == 'Y') {
    for (stClient& C : vClients) {
        if (C.AccountName == AccountName) {
            C.AccountBalance += NewAmount;
            return true;
        }
    }
    }
    return false;
}

void DepositClientAmountByAccountName(string AccountName,vector<stClient>& vClients) {
    stClient Client;
    while (!FindClientByAccountName(AccountName, vClients, Client)) {
        cout << "\nClient with [" << AccountName << "] does not exist.\n";
        AccountName = ReadClientAccountName();
      }
    PrintClientCard(Client);
    DepositClientAmount(AccountName, vClients,Client.AccountBalance);
    SaveClientDataToFile(ClientsFile, vClients);
}

void ShowDepositScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n---------------------------------\n";
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    string AccountName = ReadClientAccountName();
    DepositClientAmountByAccountName(AccountName, vClients);
}

bool WithdrawClientAmount(string AccountName, vector<stClient>& vClients, double AccountBalance) {
    double NewAmount;
    char Answer = 'N';
    cout << "\nPlease Enter Deposit Amount? ";
    cin >> NewAmount;
    cout << "\n\nAre You Sure You Want Perform this transation? Y/N ? ";
    cin >> Answer;
    if (toupper(Answer) == 'Y') {
        for (stClient& C : vClients) {
            if (C.AccountName == AccountName) {
                C.AccountBalance -= NewAmount;
                return true;
            }
        }
    }
    return false;
}

void WithdrawClientAmountByAccountName(string AccountName, vector<stClient>& vClients) {
    stClient Client;
    while (!FindClientByAccountName(AccountName, vClients, Client)) {
        cout << "\nClient with [" << AccountName << "] does not exist.\n";
        AccountName = ReadClientAccountName();
    }
    PrintClientCard(Client);
    WithdrawClientAmount(AccountName, vClients, Client.AccountBalance);
    SaveClientDataToFile(ClientsFile, vClients);
}

void ShowWithdrawScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n---------------------------------\n";
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    string AccountName = ReadClientAccountName();
    WithdrawClientAmountByAccountName(AccountName, vClients);
}

void PrintAllCliensBalance(stClient Client) {
    cout << "| " << setw(20) << left << Client.AccountName;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowBalanceList() {
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    double TotalBalance = 0;
    cout << "\n\t\t\t\t\tBalace List (" << vClients.size() << ") Client(s).\n\n";
    cout << "________________________________________________";
    cout << "________________________________________________\n\n";
    cout << "| " << setw(20) << left << "Account Number";
    cout << "| " << setw(40) << left << "Client Name";
    cout << "| " << setw(12) << left << "Balance";
    cout << "\n________________________________________________";
    cout << "________________________________________________\n\n";
    if (vClients.size() == 0) {
        cout << "\t\t\t\tNo Clients Available In The System!\n\n";
    }
    else {
        for (stClient Client : vClients) {
            TotalBalance += Client.AccountBalance;
            PrintAllCliensBalance(Client);
            cout << endl;
        }
    }
    cout << "________________________________________________";
    cout << "________________________________________________\n";
    cout << "\n\t\t\t\t\tTotal Balances =" << TotalBalance << endl;
}


void GoBackToTransationsMenue() {
    cout << "\n\nPress any key to go back to Transations menue...";
    system("pause");
    ShowTransctionsScreen();
}


void PerfromTransactionsMenueOption(enTransactions TransactionOption) {

    switch (TransactionOption)
    {
    case Deposit:
        system("cls");
        ShowDepositScreen();
        GoBackToTransationsMenue();
        break;
    case Withdraw:
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransationsMenue();
        break;
    case TotalBalance:
        system("cls");
        ShowBalanceList();
        GoBackToTransationsMenue();
        break;
    case MainMenue:
        ShowMainMenue();
        break;
    default:
        break;
    }
}


void ShowTransctionsScreen() {
        system("cls");
        cout << "========================================\n";
        cout << "\t\tTransactions Menue Screen\n";
        cout << "========================================\n";
        cout << "\t[1] Deposit.\n";
        cout << "\t[2] Withdraw.\n";
        cout << "\t[3] Total Balance.\n";
        cout << "\t[4] Main Menue.\n";;
        cout << "========================================\n";
        PerfromTransactionsMenueOption((enTransactions)ReadTransactionsMenueOption());

}




void GoBackToMainMenue() {
    cout << "\n\nPress any key to go back to Main menue...";
    system("pause");
    ShowMainMenue();
}

void PerfromMainMenueOption(enMainManueOptions MainMinueOption) {

    switch (MainMinueOption)
    {
    case Show:
        system("cls");
        ShowAllClientScreen();
        GoBackToMainMenue();
        break;
    case Add:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;
    case Deleter:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;
    case Update:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;
    case Find:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;
    case Transations:
        system("cls");
        ShowTransctionsScreen();
        GoBackToMainMenue();
        break;
    case Exit:
        system("cls");
        ShowEndScreen();
        break;
    }
}

void ShowMainMenue() {
    system("cls");
    cout << "========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transations.\n";
    cout << "\t[7] Exit.\n";
    cout << "========================================\n";
    PerfromMainMenueOption((enMainManueOptions)ReadMainMenueoption());
}

int main()
{
    ShowMainMenue();
    system("pause");
    return 0;
}