#include <iostream>
#include <string>
using namespace std;

string ReadString() {
    string S;
    cout << "Please Enter Your String? \n";
    getline(cin, S);
    return S;
}

char ToLower(char C) {
    if ((int)C < 65 || (int)C > 90)
        return C;
    return char((int)C + 32);
}

string ConvertStringLowerFirstLetter(string& Text) {
    bool IsFirstLetter = true;
    for (short i = 0; i < Text.length(); i++) {
        if (IsFirstLetter && Text[i] != ' ') {
            Text[i] = ToLower(Text[i]);
        }
        Text[i] == ' ' ? IsFirstLetter = true : IsFirstLetter = false;
    }
    return Text;
}

int main()
{
    string Text = ReadString();
    cout << endl;
    ConvertStringLowerFirstLetter(Text);
    cout << endl << Text << endl;
}
