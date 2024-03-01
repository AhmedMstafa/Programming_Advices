#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDataRecord {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

vector<string> SplitString(string S1, string Sepaletor) {
    vector<string> vString;
    string Word = "";
    short pos = 0;
    while ((pos = S1.find(Sepaletor)) != string::npos) {
        Word = S1.substr(0, pos);
        if (Word != "")
            vString.push_back(Word);

        S1.erase(0, (pos + Sepaletor.length()));
    }

    if (S1 != "")
        vString.push_back(S1);

    return vString;
}

stDataRecord ConvertLineToRecord(string Line,string Sepaletor) {
    vector<string> vString = SplitString(Line,Sepaletor);
    stDataRecord ClintData;
    ClintData.AccountNumber = vString.at(0);
    ClintData.PinCode = vString.at(1);
    ClintData.Name = vString.at(2);
    ClintData.Phone = vString.at(3);
    ClintData.AccountBalance = stod(vString.at(4));
    return ClintData;
}

void PrintData(stDataRecord stClintData) {

    cout << "Account Number: " << stClintData.AccountNumber << endl;
    cout << "Pin Code      : " << stClintData.PinCode << endl;
    cout << "Name          : " << stClintData.Name << endl;
    cout << "Phone         : " << stClintData.Phone << endl;
    cout << "Account Balance: " << stClintData.AccountBalance << endl;
    cout << endl;

}

int main()
{
    string LineRecord = "A150#//1234#//Ahmed Mostafa Mansour#//079999#//5270.0000";
    stDataRecord vDataRecord = ConvertLineToRecord(LineRecord, "#//");
    cout << "\nLine Record is:\n" << LineRecord << endl;
    cout << "\nThe following is the extracted clint record:\n\n";
    PrintData(vDataRecord);
}
