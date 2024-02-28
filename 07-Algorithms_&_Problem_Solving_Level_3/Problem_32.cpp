#include <iostream>
#include <string>
using namespace std;

char ReadChar() {
    char C; 
    cout << "Please Enter a Character?\n";
    cin >> C;
    return C;
}

bool IsVowel(char C) {
    C = tolower(C);
    return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o') || (C == 'u'));
}


int main()
{
    char C = ReadChar();
    if (IsVowel(C)) {
        cout << "\nYes Letter \'" << C << "\' is vowel\n";
    }
    else {
        cout << "\nNo Letter \'" << C << "\' is Not vowel\n";
    }

    system("pause>0");
}
