#include <iostream>
using namespace std;

float ReadNumber() {
    float Number = 0;
    cout << "Please Enter a Nubmer: ";
    cin >> Number;
    return Number;
}


float GetFractionPart(float Number) {
    return Number - int(Number);
}

int MyCeil(float Number) {
 
    float FractionPart = GetFractionPart(Number);
    if (abs(FractionPart) >= 0) {

        if (Number > 0)
            return int(Number) + 1;
        else
            return int(Number);
    }
    else {
        return Number;
    }
}



int main()
{
    float Number = ReadNumber();
    cout << "My Round Result : " << MyCeil(Number) << endl;
    cout << "C++ Round Result : " << ceil(Number) << endl;

    return 0;
}
