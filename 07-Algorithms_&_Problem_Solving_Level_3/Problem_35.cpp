#include <iostream>
#include <string>
using namespace std;


string ReadStirng() {
    string S;
    cout << "Please Enter Your String?\n";
    getline(cin, S);
    return S;
}
/*
string StringWords(string S) {
    for (short i = 0; i < S.length(); i++) {
        if (S[i] == ' ')
            S[i] = '\n';
    }
    return S;
}
*/
/*
void StringWordsArray(string S) {
    string arr[100];
    int WordIndex = 0;
    for (short i = 0; i < S.length(); i++) {
        if (S[i] == ' ') {
            WordIndex++;
            continue;
        }
       arr[WordIndex] += S[i];
    }
    for (short i = 0; i < WordIndex +1; i++) {
        cout << arr[i] << endl;
    }

}
*/
/*
void PrintWordInLine(string S) {
    for (short i = 0; i < S.length(); i++) {
        if (S[i] == ' ') {
            cout << endl;
            continue;
        }
        cout << S[i];
    }
}
*/

void PrintEachWordInString(string S) {
    string delim = " ";
    string sWord = "";
    short pos = 0;
    while ((pos = S.find(delim)) != std::string::npos) {
        sWord = S.substr(0, pos);
        if (sWord != "")
            cout << sWord << endl;

        S.erase(0, pos + delim.length());
    }

    if (S != "") {
        cout << S << endl; // Print Last Word
    }

}

int main()
{
    string S = ReadStirng();
    cout << "\nYour String Words are:\n";
    PrintEachWordInString(S);
    //cout << StringWords(S);
   // StringWordsArray(S);
   // PrintWordInLine(S);
}
