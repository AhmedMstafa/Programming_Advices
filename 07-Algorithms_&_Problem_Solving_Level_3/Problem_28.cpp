#include <iostream>
#include <string>
using namespace std;

string ReadString() {
    string S;
    cout << "Please Enter Your String?\n";
    getline(cin, S);
    return S;
}


char InvertLetterCase(char C) {
    return isupper(C) ? tolower(C) : toupper(C);
}

string InvertStringLetterCase(string Text) {
    for (char i = 0; i < Text.length(); i++) {
        Text[i] = InvertLetterCase(Text[i]);
    }
    return Text;
}


int main()
{
    string S = ReadString();
    cout << S << endl;
    cout << "\nString after Inverting All Letters Case:\n";
    S = InvertStringLetterCase(S);
    cout << S << endl;
    return 0;
}
