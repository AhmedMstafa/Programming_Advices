#include <iostream>
#include <string>
using namespace std;

/*
char ToUpper(char C) {
    if ((int)C < 65 || (int)C > 90)
        return C;
    return char((int)C + 32);
}

char ToLower(char C) {
    if ((int)C < 97 || (int)C > 122)
        return C;
    return char((int)C - 32);
}

char InvertCharcterCase(char C) {
    return ToUpper(C) == C ? ToLower(C) : ToUpper(C);
}
*/

char InvertLetterCase(char C) {
    return isupper(C) ? tolower(C) : toupper(C);
}

int main()
{
    char Character;
    cout << "Please Enter a Character?\n";
    cin >> Character;
    cout << endl << "Char After invertin case\n";
    Character = InvertLetterCase(Character);
    cout << Character << endl;
}
