#include <iostream>
using namespace std;


int ReadNumber() {
    int Number = 0;
    cout << "Please Enter a Number: ";
    cin >> Number;
    return Number;
}

int MyAbs(int Number) {
    if (Number < 0)
        return Number * -1;
    else
        return Number;
}



int main()
{
    int Number = ReadNumber();
    cout << "My abs Result : " << MyAbs(Number) << "\n";
    cout << "C++ abs Result : " << abs(Number) << endl;
}
