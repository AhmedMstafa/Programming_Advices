#include <iostream>
using namespace std;

int sumToNumbers(int, int);

int AvgNumbers(int num1, int num2) {
    return sumToNumbers(num1, num2) / 2;
}

int sumToNumbers(int num1, int num2) {
    return num1 + num2;
}


void add(int, int);



int main()
{
    add(10, 20);
    cout << AvgNumbers(10, 2) << endl;
    return 0;
}


void add(int a, int b) {
    cout << a + b << endl;
}