#include <iostream>
using namespace std;

template <class T>
class clsCalculator {
private:
    T _Num1, _Num2;

public:
    clsCalculator(T Num1, T Num2) {
        _Num1 = Num1;
        _Num2 = Num2;
    }

    T Add() {
        return _Num1 + _Num2;
    }

    T Subtract() {
        return _Num1 - _Num2;
    }

    T Divide() {
        return _Num1 / _Num2;
    }

    T Multiply() {
        return _Num1 * _Num2;
    }

    void PrintResults() {
        cout << "Numbers: " << _Num1 << " And " << _Num2 << "." << endl;
        cout << _Num1 << " + " << _Num2 << " = " << Add() << endl;
        cout << _Num1 << " - " << _Num2 << " = " << Subtract() << endl;
        cout << _Num1 << " / " << _Num2 << " = " << Divide() << endl;
        cout << _Num1 << " * " << _Num2 << " = " << Multiply() << endl;
    }
};

int main() {
    clsCalculator<int> IntCalc(5, 5);
    clsCalculator<float> FloatCalc(5.1, 5.5);

    cout << "Int results:" << endl;
    IntCalc.PrintResults();

    cout << endl << "Float results:" << endl;
    FloatCalc.PrintResults();

    return 0;
}
