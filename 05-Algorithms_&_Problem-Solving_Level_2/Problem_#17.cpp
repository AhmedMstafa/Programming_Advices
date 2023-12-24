#include <iostream>
using namespace std;

string Print3Letters(string Message)
{
    string Password = " ";
    do
    {
        cout << Message << endl;
        cin >> Password;
    } while (Password.length() < 3);
    return Password;
}


void GuessPassword(string Password)
{
    int counter = 0;
    string word = "";

    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int x = 65; x <= 90; x++) {
                word += char(i);
                word += char(j);
                word += char(x);
                counter++;
                cout << "Trial [" << counter << "] : " << word << endl;
                if (word == Password) {
                    cout << "\n";
                    cout << "Password is " << word << "\n";
                    cout << "Found of ter " << counter << " Triall(s)\n";
                    return;
                }
                else {
                    word = "";
                }
            }
        }
    }
}

int main()
{
    GuessPassword(Print3Letters("Please Enter 3 Letters Password Capital? "));
    return 0;
}
