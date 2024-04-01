#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

struct stUser {
    string UserName;
    string Password;
    int Permissions;
    bool DeletedMark = false;
};
struct stClient {
    string AccountName;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool DeletedMark = false;
};

stUser CurrentUser;
const string UsersFile = "Users.txt";
const string ClientsFile = "Clients.txt";

void Login();
void ShowMainMenue();
void ShowMangeUsersMenue();
void GoBackToMainMenue();
void ShowTransctionsScreen();

enum enMainManueOptions { Show = 1, Add = 2, Deleter = 3, Update = 4, Find = 5, Transations = 6, ManageUsers = 7,Exit = 8 };
enum enTransactions { Deposit = 1, Withdraw = 2, TotalBalance = 3, MainMenue = 4 };
enum enUsersManueOptions {eShowUsers = 1, eAddUser = 2, eDeleteUser = 3,eUpdateUser = 4, eFindUser = 5, eMenue = 6};
enum enMainMenuePermissions {eAll = -1 , pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClients = 8 , pFindClient = 16, pTransactions = 32, pManageUsers = 64};

bool CheckAccessPermission(enMainMenuePermissions Premission);
void ShowAccessDenidMessage();

short ReadMainMenueoption() {
    short Action = 0;
    do {
        cout << "Chose what do you want do: [1 to 8]? ";
        cin >> Action;
    } while (Action <= 0 || Action > 8);
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

short ReadUsersManueOptions() {
    short Action = 0;
    do {
        cout << "Chose what do you want do: [1 to 6]? ";
        cin >> Action;
    } while (Action <= 0 || Action > 6);
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
    if (!CheckAccessPermission(enMainMenuePermissions::pListClients)) {
        ShowAccessDenidMessage();
        GoBackToMainMenue();
        return;
    }
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
    if (!CheckAccessPermission(enMainMenuePermissions::pAddNewClient)) {
        ShowAccessDenidMessage();
        GoBackToMainMenue();
        return;
    }
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
    }
    else {
        cout << "\nClient With Account Name (" << AccountName << ") is Not Found!";
        return false;
    }
}

void ShowDeleteClientScreen() {
    if (!CheckAccessPermission(enMainMenuePermissions::pDeleteClient)) {
        ShowAccessDenidMessage();
        GoBackToMainMenue();
        return;
    }
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
    }
    else {
        cout << "\nClient With Account Name (" << AccountName << ") is Not Found!";
        return false;
    }

}

void ShowUpdateClientScreen() {
    if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClients)) {
        ShowAccessDenidMessage();
        GoBackToMainMenue();
        return;
    }
    cout << "\n---------------------------------\n";
    cout << "\tUpdate Clients Screen";
    cout << "\n---------------------------------\n";
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    string AccountName = ReadClientAccountName();
    UpdateClientByAccountName(AccountName, vClients);
}

void ShowFindClientScreen() {
    if (!CheckAccessPermission(enMainMenuePermissions::pFindClient)) {
        ShowAccessDenidMessage();
        GoBackToMainMenue();
        return;
    }
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
/*
void ShowEndScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n---------------------------------\n";
}
*/


bool DepositClientAmount(string AccountName, double Amount, vector<stClient>& vClients) {
    char Answer = 'N';
    cout << "\n\nAre You Sure You Want Perform this transation? Y/N ? ";
    cin >> Answer;
    if (toupper(Answer) == 'Y') {
        for (stClient& C : vClients) {
            if (C.AccountName == AccountName) {
                C.AccountBalance += Amount;
                SaveClientDataToFile(ClientsFile, vClients);
                cout << "\n\nDone Successully. New balance is : " << C.AccountBalance;
                return true;
            }
        }
    }
    return false;
}

void ShowDepositScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n---------------------------------\n";
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    string AccountName = ReadClientAccountName();
    stClient Client;
    while (!FindClientByAccountName(AccountName, vClients, Client)) {
        cout << "\nClient with [" << AccountName << "] does not exist.\n";
        AccountName = ReadClientAccountName();
    }
    PrintClientCard(Client);
    double Amount = 0;
    cout << "\nPlease Enter Deposit Amount? ";
    cin >> Amount;
    DepositClientAmount(AccountName, Amount, vClients);
}

void ShowWithdrawScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n---------------------------------\n";
    vector<stClient> vClients = ImportDataFromFile(ClientsFile);
    string AccountName = ReadClientAccountName();
    stClient Client;
    while (!FindClientByAccountName(AccountName, vClients, Client)) {
        cout << "\nClient with [" << AccountName << "] does not exist.\n";
        AccountName = ReadClientAccountName();
    }
    PrintClientCard(Client);
    double Amount = 0;
    cout << "\nPlease Enter Deposit Amount? ";
    cin >> Amount;
    DepositClientAmount(AccountName, Amount * -1, vClients);
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
    if (!CheckAccessPermission(enMainMenuePermissions::pTransactions)) {
        ShowAccessDenidMessage();
        GoBackToMainMenue();
        return;
    }
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
    case ManageUsers:
        system("cls");
        ShowMangeUsersMenue();
    case Exit:
        system("cls");
        Login();
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
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "========================================\n";
    PerfromMainMenueOption((enMainManueOptions)ReadMainMenueoption());
}

string ConvertUserRecordToLine(stUser User,string Separetor = "#//#") {

    string Line = "";
    Line += User.UserName + Separetor;
    Line += User.Password + Separetor;
    Line += to_string(User.Permissions);

    return Line;
}

stUser ConvertUserLineToRecord(string Line, string Separetor = "#//#") {

    stUser User;
    vector<string> vUserData;

    vUserData = SplitLine(Line, Separetor);

    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);

    return User;
}

vector<stUser> ImportUsersDataFromFile(string FileName) {
    fstream MyFile;
    string Line;
    stUser User;
    vector<stUser> vUsers;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {
        while (getline(MyFile, Line)) {
            User = ConvertUserLineToRecord(Line);
            vUsers.push_back(User);
        }
        MyFile.close();
    }

    return vUsers;
    
}

bool FindUserByUsernameAndPassword(string Username, string Password, stUser& User) {

    vector<stUser> vUsers = ImportUsersDataFromFile(UsersFile);

    for (stUser U : vUsers) {

        if (U.UserName == Username && U.Password == Password) {
            User = U;
            return true;
        }

    }

    return false;
}

bool LoadUserInfo(string Username, string Password) {
    if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
        return true;
    else
        return false;

}

void PrintUsersRecordLine(stUser User) {
    cout << "| " << setw(15) << left << User.UserName;
    cout << "| " << setw(10) << left << User.Password;
    cout << "| " << setw(40) << left << User.Permissions;
}

void ShowListUsersScreen() {
    vector<stUser> vUsers = ImportUsersDataFromFile(UsersFile);
    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") Users(s).\n\n";
    cout << "________________________________________________";
    cout << "________________________________________________\n\n";
    cout << "| " << setw(15) << left << "Username";
    cout << "| " << setw(10) << left << "Password";
    cout << "| " << setw(40) << left << "Permission";
    cout << "\n________________________________________________";
    cout << "________________________________________________\n\n";
    if (vUsers.size() == 0) {
        cout << "\t\t\t\tNo Users Available In The System!\n\n";
    }
    else {
        for (stUser U : vUsers) {
            PrintUsersRecordLine(U);
            cout << endl;
        }
    }
    cout << "________________________________________________";
    cout << "________________________________________________\n";
}

bool UserExistsByUsername(string Username, string UserFileName) {

    vector<stUser> vUsers = ImportUsersDataFromFile(UsersFile);

    for (stUser U : vUsers) {
        if (U.UserName == Username)
            return true;
    }

    return false;
}

int ReadPrmissionsToSet() {

    int Permissions = 0;
    char Answer = 'N';

    cout << "\nDo you want to give full access? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y') {
        return -1;
    }

    cout << "\nDo you want to give access to : \n";

    cout << "\nShow Client List? y/n ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {
        Permissions += enMainMenuePermissions::pListClients;
    }

    cout << "\Add Client List? y/n ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {
        Permissions += enMainMenuePermissions::pAddNewClient;
    }


    cout << "\nDelete Client List? y/n ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {
        Permissions += enMainMenuePermissions::pDeleteClient;
    }

    cout << "\nUpdate Client List? y/n ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {
        Permissions += enMainMenuePermissions::pUpdateClients;
    }

    cout << "\nFind Client List? y/n ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {
        Permissions += enMainMenuePermissions::pFindClient;
    }

    cout << "\nTransations? y/n ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {
        Permissions += enMainMenuePermissions::pTransactions;
    }

    cout << "\nManage Users? y/n ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {
        Permissions += enMainMenuePermissions::pManageUsers;
    }

    return Permissions;
}

stUser ReadNewUser() {
    stUser User;
    cout << "Enter User Name? ";
    getline(cin >> ws, User.UserName);
    while (UserExistsByUsername(User.UserName, UsersFile))
    {
        cout << "\nUser with [" << User.UserName << "] already exists, Enter another Account Name ? ";
        getline(cin >> ws, User.UserName);
    }
    cout << "Enter Password? ";
    getline(cin, User.Password);

    cout << "Enter Permissions? ";
    User.Permissions = ReadPrmissionsToSet();

    return User;
}

void AddNewUser() {
    stUser User;
    User = ReadNewUser();
    ExportDataToFile(UsersFile, ConvertUserRecordToLine(User));
}

void AddNewUsers() {
    char AddMore = 'Y';
    do {
        cout << "Adding New User:\n\n";
        AddNewUser();

        cout << "\nUser Added Successfully, do you want to add more Users? Y/N?  ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

void ShowAddUsersScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tAdd New User Screen";
    cout << "\n---------------------------------\n";
    AddNewUsers();
}

void PrintUserCard(stUser User) {
    cout << "Username    : " << User.UserName << endl;
    cout << "Password    : " << User.Password << endl;
    cout << "Permissions : " << User.Permissions << endl;

}

bool MarkUserForDeleteByAccountName(string Username, vector<stUser>& vUsers) {
    for (stUser& U : vUsers) {
        if ( U.UserName == Username) {
            U.DeletedMark = true;
            return true;
        }
    }
    return false;
}

void SaveUserDataToFile(string FileName, vector<stUser> vUsers) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string Line;
    if (MyFile.is_open()) {
        for (stUser User : vUsers) {
            if (!User.DeletedMark) {
                Line = ConvertUserRecordToLine(User);
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }

}

bool FindUserByUsername(string Username, vector<stUser> Users, stUser& User) {

    vector<stUser> vUsers = ImportUsersDataFromFile(UsersFile);

    for (stUser U : vUsers) {

        if (U.UserName == Username) {
            User = U;
            return true;
        }

    }

    return false;
}

bool DeleteUserByAccountName(string Username, vector<stUser>& vUsers) {
    stUser User;
    char Answer = 'N';
    if (FindUserByUsername(Username, vUsers, User)) {
        PrintUserCard(User);

        cout << "\n\nAre You Sure You Want Delete This User? Y/N? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            MarkUserForDeleteByAccountName(Username, vUsers);
            SaveUserDataToFile(UsersFile, vUsers);
            vUsers = ImportUsersDataFromFile(UsersFile);

            cout << "\n\nUser Deleted Successfully.";
            return true;
        }
    }
    else {
        cout << "\nUser With Account Name (" << Username << ") is Not Found!";
        return false;
    }
}

void ShowDeleteUserScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tDelete User Screen";
    cout << "\n---------------------------------\n";
    vector<stUser>vUsers = ImportUsersDataFromFile(UsersFile);
    string Username;
    cout << "Enter Username? ";
    cin >> ws >> Username;
    DeleteUserByAccountName(Username, vUsers);
}

stUser ChangeUserRecord(string Username) {
    stUser User;
    User.UserName = Username;
    cout << "\n\nEnter Passowrd? ";
    getline(cin >> ws, User.Password);
    User.Permissions = ReadPrmissionsToSet();
    return User;
}

bool UpdateUserByAccountName(string Username, vector<stUser>& vUsers) {
    stUser User;
    char Answer = 'N';

    if (FindUserByUsername(Username, vUsers, User)) {
        PrintUserCard(User);

        cout << "\n\nAre You Sure You Want Update This User? Y/N? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            for (stUser& U : vUsers) {
                if (U.UserName == Username) {
                    U = ChangeUserRecord(Username);
                    break;
                }
            }
            SaveUserDataToFile(UsersFile, vUsers);


            cout << "\n\nUser Updated Successfully.";
            return true;
        }
    }
    else {
        cout << "\nUser With Username (" << Username << ") is Not Found!";
        return false;
    }

}

void ShowUpdateUsersScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tUpdate Users Screen";
    cout << "\n---------------------------------\n";
    vector<stUser>vUsers = ImportUsersDataFromFile(UsersFile);
    string Username;
    cout << "Enter Username? ";
    cin >> ws >> Username;
    UpdateUserByAccountName(Username, vUsers);
}

void ShowFindUsersScreen() {
    cout << "\n---------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n---------------------------------\n";
    vector<stUser>vUsers = ImportUsersDataFromFile(UsersFile);
    string Username;
    stUser User;
    cout << "Enter Username? ";
    cin >> ws >> Username;
    if (FindUserByUsername(Username, vUsers, User)) {
        PrintUserCard(User);
    }
    else {
        cout << "\nUser With Username (" << Username << ") is Not Found!";
    }
}

bool CheckAccessPermission(enMainMenuePermissions Permission) {
    if (CurrentUser.Permissions == enMainMenuePermissions::eAll)
        return true;
    if ((Permission & CurrentUser.Permissions) == Permission)
        return true;
    else
        return false;
}

void ShowAccessDenidMessage() {
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";
}

void GoBackToManageUsers() {
    cout << "\n\nPress any key to go back to Main menue...";
    system("pause");
    ShowMangeUsersMenue();
}

void PerfromManageUsersMenueOption(enUsersManueOptions UserMinueOption) {
    switch (UserMinueOption)
    {
    case eShowUsers:
        system("cls");
        ShowListUsersScreen();
        GoBackToManageUsers();
        break;
    case eAddUser:
        system("cls");
        ShowAddUsersScreen();
        GoBackToManageUsers();
        break;
    case eDeleteUser:
        system("cls");
        ShowDeleteUserScreen();
        GoBackToManageUsers();
        break;
    case eUpdateUser:
        system("cls");
        ShowUpdateUsersScreen();
        GoBackToManageUsers();
        break;
    case eFindUser:
        system("cls");
        ShowFindUsersScreen();
        GoBackToManageUsers();
        break;
    case eMenue:
        system("cls");
        ShowMainMenue();
        break;
    default:
        break;
    }
}

void ShowMangeUsersMenue() {
    if (!CheckAccessPermission(enMainMenuePermissions::pManageUsers)) {
        ShowAccessDenidMessage();
        GoBackToMainMenue();
        return;
    }
    system("cls");
    cout << "========================================\n";
    cout << "\tManage Users Menue Screen\n";
    cout << "========================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "========================================\n";
    PerfromManageUsersMenueOption((enUsersManueOptions)ReadUsersManueOptions());
}

void Login() {
    bool LoginFaild = false;

    string Username, Password;

    do {
        system("cls");
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";
        if (LoginFaild) {
            cout << "Invalid Username/Password!\n";
        }
        cout << "Enter Username? ";
        cin >> ws >> Username;
        cout << "Enter Password? ";
        cin >> Password;
        LoginFaild = !LoadUserInfo(Username, Password);
    } while (LoginFaild);

    ShowMainMenue();
}

int main()
{
    Login();
    system("pause");
    return 0;
}