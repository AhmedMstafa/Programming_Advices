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

void PrintVowels(string S) {
    for (short i = 0; i < S.length(); i++) {
        if (IsVowel(S[i]))
            printf("%c   ", S[i]);
    }
    cout << endl;
}

int main()
{
    string S = ReadString();
    PrintVowels(S);
}
