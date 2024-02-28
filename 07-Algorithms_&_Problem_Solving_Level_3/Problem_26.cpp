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

char ToUpper(char C) {
    if ((int)C < 97 || (int)C > 122)
        return C;
    return char((int)C - 32);
}

string ConvertStringToUpper(string Text ) {
    for (short i = 0; i < Text.length(); i++) {
        Text[i] = ToUpper(Text[i]);
        }
    return Text;
}

string ConvertStringLower(string Text) {
    for (short i = 0; i < Text.length(); i++) {
        Text[i] = ToLower(Text[i]);
    }
    return Text;
}


int main()
{
    string Text = ReadString();
    cout << endl;
   Text =  ConvertStringToUpper(Text);
    cout << "String After Upper: \n";
    cout << Text << endl << endl;
    cout << "String After Lower: \n";
    Text = ConvertStringLower(Text);
    cout << Text << endl;
}