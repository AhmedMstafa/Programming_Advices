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
    string StringDate;

    StringDate = to_string(Date.Day) + "/";
    StringDate += to_string(Date.Month) + "/";
    StringDate += to_string(Date.Year);

    return StringDate;

}

string ReplaceWordInString(string S1, string StringToReplace, string StringReplaceTo) {
    short pos = S1.find(StringToReplace);

    while (pos != string::npos) {
        S1 = S1.replace(pos, StringToReplace.length(), StringReplaceTo);
        pos = S1.find(StringToReplace);
    }

    return S1;
}

string FromatDate(stDate Date, string DateFromat = "dd/mm/yyyy") {

    string FormattedDateString = "";

    FormattedDateString = ReplaceWordInString(DateFromat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

int main() {

    string StringDate = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    stDate Date = StringToDate(StringDate);


    cout <<"\n"<< FromatDate(Date, "yyyy/dd/mm" ) << endl;
    cout <<"\n"<< FromatDate(Date, "mm/dd/yyyy" ) << endl;
    cout <<"\n"<< FromatDate(Date, "dd/mm/yyyy" ) << endl;
    cout <<"\n"<< FromatDate(Date, "dd-mm-yyyy" ) << endl;
    cout <<"\n"<< FromatDate(Date, "dd-mm-yyyy" ) << endl;

    cout << "\n" << FromatDate(Date, "Day:dd, Month:mm, Year:yyyy") << endl;

    return 0;
}