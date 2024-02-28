#include <iostream>
#include <string> 
using namespace std;

string ReadString() {
    string S;
    cout << "Please Enter Your String\n";
    getline(cin, S);
    return S;
}

char ReadChar() {
    char C;
    cout << "Please Enter Your Char\n";
    cin >> C;
    return C;
}


short CountLetters(string S, char C,bool ItSameCase = true) {
    short Count = 0;
    for (short i = 0; i < S.length(); i++) {
        ItSameCase ? S[i] == C ? Count++ : NULL: towlower(S[i]) == towlower(C) ? Count++: NULL ;
    }
    return Count;
}



int main()
{
    string S = ReadString();
    cout << endl;
    char C = ReadChar();
    cout << endl;
    cout << "Letter \'" << C << "\' Count = " << CountLetters(S, C) << endl;
    cout << "Letter \'" << C << "\' Or \'M\' Count = " << CountLetters(S, C,false) << endl;



}
