#include <iostream>
#include <string>
using namespace std;

string ReadString() {
    string S;
    cout << "Please Enter Your String?\n";
    getline(cin, S);
    return S;
}

bool IsVowel(char C) {
    C = tolower(C);
    return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o') || (C == 'u'));
}

short ContVowelsLetters(string S) {
    short Count = 0;
    for (short i = 0; i < S.length(); i++) {
        if (IsVowel(S[i]))
            Count++;
    }
    return Count;
}

int main()
{
    string S = ReadString();
    cout << "\nNumber of vowels is: " << ContVowelsLetters(S) << endl;
}
