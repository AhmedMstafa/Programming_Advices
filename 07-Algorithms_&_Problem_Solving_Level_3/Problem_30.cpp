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


short CountLetters(string S,char C) {
    short Count = 0;
    for (short i = 0; i < S.length(); i++) {
        if (S[i] == C)
            Count++;
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

}
