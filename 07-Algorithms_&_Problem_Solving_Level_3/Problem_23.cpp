#include <iostream>
#include <string>
using namespace std;


string ReadString() {
    string S = " ";
    cout << "Please Enter a Text: " << endl;
    getline(cin, S);
    return S;
}

void PrintFirstLetter(string Text) {
    bool isFirstLetter = true;

    for (short i = 0; i < Text.length(); i++) {
        if (Text[i] != ' ' && isFirstLetter)
            cout << Text[i] << '\n';
        isFirstLetter = (Text[i] == ' ' ? true : false);
    }
}

int main()
{
    string Text = ReadString();
    PrintFirstLetter(Text);
}
