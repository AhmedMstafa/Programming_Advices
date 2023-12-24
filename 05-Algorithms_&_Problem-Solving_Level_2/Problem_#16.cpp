#include <iostream>
using namespace std;


void PrintAllWordsAAAToZZZ()
{
    cout << "\n";
    string word = " ";
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int x = 65; x <= 90; x++) {
                word += char(j);
                word += char(i);
                word += char(x);
                 
                cout << word << endl;

                word = " ";
            }
        }
    }
}



int main()
{
    PrintAllWordsAAAToZZZ();
    return 0;
}
