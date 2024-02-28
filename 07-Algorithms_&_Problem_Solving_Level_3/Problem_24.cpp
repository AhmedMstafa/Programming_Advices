#include <iostream>
#include <string>
using namespace std;

string ReadString() {
    string S;
    cout << "Please Enter Your String? \n";
    getline(cin, S);
    return S;
}

char ToUpper(char C) {
    if ((int)C < 97 || (int)C > 122)
        return C;
    return char((int)C - 32);
}

string ConvertStringUpperFirstLetter(string &Text) {
    bool IsFirstLetter = true;
    for (short i = 0; i < Text.length(); i++) {
        if (IsFirstLetter && Text[i] != ' ') {
            Text[i] = ToUpper(Text[i]);
        }
        Text[i] == ' ' ? IsFirstLetter = true : IsFirstLetter = false;
    }
    return Text;
}

int main()
{
    string Text = ReadString();
    cout <<  endl;
    ConvertStringUpperFirstLetter(Text);
    cout << endl << Text << endl;
}
