#include <iostream>
using namespace std;

class clsA
{

private:

    int _Var1;
    void Fun1()
    {
        cout << "Function 1";
    }

protected:

    int _Var2;
    void Fun2()
    {
        cout << "Function 2";
    }

public:

    int _Var3;
    void Fun3()
    {
        cout << "Function 3";
    }

};

class clsB : public clsA
{
public: 

    void Func1()
    {
        clsA::Fun2();
    }

};

int main()
{
    clsA A;
    A.Fun3();

    clsB B;
    B.Func1();
    
}
