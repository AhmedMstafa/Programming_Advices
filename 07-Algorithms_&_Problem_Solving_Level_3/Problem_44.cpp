#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
string TransformPucuationToSpace(string S1) {
    
    for (short i = 0; i < S1.length(); i++) {
        if ((int)S1[i] < 65 && (int)S1[i] > 32) {
            S1[i] = char(32);
        }
    }
    return S1;
}

vector<string> SplitString(string S1, string Delim ) {
    vector<string> vString;
    string Word = " ";
    short pos = 0;
    while ((pos = S1.find(Delim)) != string::npos) {
        Word = S1.substr(0, pos);
        if (Word != " ")
            vString.push_back(Word);

        S1.erase(0, (pos + Delim.length()));
    }

    if (S1 != " ")
        vString.push_back(S1);

    return vString;
}

string JoinString(vector<string> vString, string Delim) {
    string S1 = "";
    for (string& Word : vString) {
        if (Word != "")
            S1 += Word + Delim;
    }
    return S1.substr(0, (S1.length() - Delim.length()));
}

string RemovePunctuationsFromStirng(string S1) {
    S1 = TransformPucuationToSpace(S1);
    vector<string> vString = SplitString(S1, " ");
    S1 = JoinString(vString, " ");
    return S1;
}
*/

string RemovePunctuationsFromString(string S1) {
    string S2 = "";
    for (short i = 0; i < S1.length(); i++) {
        if (!ispunct(S1[i])) {
            S2 += S1[i];
        }
    }
    return S2;
}


int main()
{
    string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.\n";
    cout << "Original String:\n";
    cout << S1 << endl;
    cout << "\nPauncuations Removed:\n";
    cout << RemovePunctuationsFromString(S1) << endl;
}
