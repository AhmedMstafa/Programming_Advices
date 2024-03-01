#include <iostream>
#include <string>
using namespace std;

/*
string ReplaceString1(string S1, string OriginalWord, string NewWrod) {
    short FirstPic = S1.find(OriginalWord);
    short ThirdPic = OriginalWord.length();
    return S1.substr(0, FirstPic) + NewWrod + S1.substr((FirstPic + ThirdPic), (S1.length() - ThirdPic + NewWrod.length()));
}


string ReplaceString2(string S1, string OriginalWord, string NewWrod) {
    short pos = 0;
    string S2 = "";
    string Word = "";
    while ((pos = S1.find(OriginalWord)) != string::npos) {
        Word = S1.substr(0, pos);
        if (Word != "") {
            S2 += Word + NewWrod;
        }
        S1.erase(0, (pos + OriginalWord.length()));
    }

    if (S1 != "")
        S2 += S1;

    return S2;
}
*/


string  RepalceWordInStirngUsingBuitInFunction(string S1, string StringToReplace, string sReplace) {
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos) {
        S1 = S1.replace(pos, StringToReplace.length(), sReplace);
        pos = S1.find(StringToReplace);
    }

    return S1;
}


int main()
{
    string S1 = "Welcom To Jordan , Jordan is a nice country\n";
    cout << "\nOriginal String\n";
    cout << S1 << endl;
    cout << "\nString After Replace:\n";
    cout << RepalceWordInStirngUsingBuitInFunction(S1, "Jordan", "USA");

}