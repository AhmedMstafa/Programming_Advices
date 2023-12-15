
#include <iostream>
using namespace std;


int ReadIntNumberInRangeUsingWhile(int From, int To) {
    int Number;
    do {
        cout << "Please enter a number between " << From << " and " << To << endl;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;

}

int main()
{
    cout << "\n The Number You Enterd is: " << ReadIntNumberInRangeUsingWhile(10, 20) << endl;
}

