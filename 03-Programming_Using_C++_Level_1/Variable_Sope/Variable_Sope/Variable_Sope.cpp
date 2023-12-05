
#include <iostream>
using namespace std;

// Varible => name/value/address

int x = 300; // Global Varible 


void MyFunction()
{
    int x = 5;
    cout << "The Value of x inside function is: " << x << endl;
}

int main()
{
    int x = 20;
    cout << "The local value of x inside main is : " << x << endl;
    MyFunction();
    ::x = 7000; // global
    cout << "the gloabal value of x is: " << ::x << endl;

    return 0;
}
