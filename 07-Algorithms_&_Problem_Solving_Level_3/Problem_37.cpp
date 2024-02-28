#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString() {
    string S;
    cout << "Please Enter Your String?\n";
    getline(cin, S);
    return S;
}

vector<string> SplitStirng(string S,string Delim) {
    vector<string> vWords;
    string sWord = "";
    short pos = 0;
    while ((pos = S.find(Delim)) != std::string::npos) {
        sWord = S.substr(0, pos);
        if (sWord != "")
            vWords.push_back(sWord);
        S.erase(0, pos + Delim.length());
    }
    if (S != "")
        vWords.push_back(S);
    return vWords;
}
void PrintVectorTokens(vector<string> &V) {
    for (string &Word : V) {
        cout << Word << endl;
    }
}
int main()
{
    string S = ReadString();
    vector<string> Tokens = SplitStirng(S, " ");
    cout << "Tokens = " << Tokens.size() << endl;
    PrintVectorTokens(Tokens);

}
