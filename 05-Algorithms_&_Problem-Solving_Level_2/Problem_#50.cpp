#include <iostream>
using namespace std;

float ReadNumber() {
    float Number = 0;
    cout << "Please Enter a Nubmer: ";
    cin >> Number;
    return Number;
}


float MySqrt(float Number) {
    return pow(Number, 0.5);
}



int main()
{
    float Number = ReadNumber();
    cout << "My Sqrt Result : " << MySqrt(Number) << endl;
    cout << "C++ Sqrt Result : " << sqrt(Number) << endl;

    return 0;
}
