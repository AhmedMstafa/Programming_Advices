#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct sData {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    bool AccountBalance = 0;
};

sData ReadData() {
    sData ClintData;
    cout << "Enter Account Number?";
    getline(cin, ClintData.AccountNumber);
    cout << "Enter PinCode?";
    getline(cin, ClintData.PinCode);
    cout << "Enter Name?";
    getline(cin, ClintData.Name);
    cout << "Enter Phone?";
    getline(cin, ClintData.Phone);
    cout << "Enter Account Balance?";
    cin >> ClintData.AccountBalance;
    return ClintData;
}

string OneLineDataRecord(sData ClintData,string Seperator) {
    string stClientRecord = "";
    stClientRecord += ClintData.AccountNumber + Seperator;
    stClientRecord += ClintData.PinCode + Seperator;
    stClientRecord += ClintData.Name + Seperator;
    stClientRecord += to_string(ClintData.AccountBalance);
    return stClientRecord;
}

int main()
{
    sData ClintDataRecord = ReadData();
    cout << "\n Clint Rrcord for Saving is:\n";
    cout << OneLineDataRecord(ClintDataRecord, "//#");
}
