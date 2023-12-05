#include <iostream>
using namespace std;


// Home Work

int swap(int &num1, int &num2) {
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    return 0;
}

int main()
{
    int num1 = 20, num2 = 30;
    cout << num1 << endl << num2 << endl;
    swap(num1, num2);
    cout << num1 << endl << num2 << endl;

}
