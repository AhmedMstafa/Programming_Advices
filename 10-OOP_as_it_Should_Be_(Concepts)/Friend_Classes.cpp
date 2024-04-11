#include <iostream>
using namespace std;

class clsA
{
    int _Var1;

public:
    int Var2;

    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
    }

    friend class clsB; 
};

class clsB
{
public:
    void display(clsA A1)
    {
        cout << "\nThe Varible Var1 in Class A is: " << A1._Var1;
        cout << "\nThe Varible Var2 in Class A is: " << A1.Var2;
    }
};

int main()
{
    clsA A1;
    clsB B1;

    B1.display(A1);

    return 0;
}
