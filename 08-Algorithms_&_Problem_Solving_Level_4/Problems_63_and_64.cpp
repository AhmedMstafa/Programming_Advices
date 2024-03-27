#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

string ReadStringDate(string Message) {
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

vector<string> SplitString(string Date, string Separator = "/") {
    vector<string> vString;
    short Pos = 0;
    string Num = "";

    while ((Pos = Date.find(Separator)) != std::string::npos) {
        Num = Date.substr(0, Pos);

        if (Num != "")
            vString.push_back(Num);

        Date.erase(0, (Pos + Separator.length()));
    }

    if (Date != "");
      vString.push_back(Date);

    return vString;
}

stDate StringToDate(string StringDate) {
    stDate Date;
    vector<string> vDate;

    vDate = SplitString(StringDate, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString(stDate Date) {
    string TextDate;

    TextDate = to_string(Date.Day) + "/";
    TextDate += to_string(Date.Month) + "/";
    TextDate += to_string(Date.Year) ;

    return TextDate;

}

int main() {

    string StringDate = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    stDate Date = StringToDate(StringDate);

    cout << "\nDay:" << Date.Day << endl;
    cout << "Month:" << Date.Month << endl;
    cout << "Year:" << Date.Year  << endl;

    cout << "\nYou Entered: " << DateToString(Date) << endl;

    return 0;
}