#include <iostream>
using namespace std;

class clsCalculator
{
    float _Result = 0;
    float _LastNumber = 0;
    float _PreviousResult = 0;
    string _LastOperation = "Clear";

    bool _IsZero(float Number)
    {
        return (Number == 0);
    }

public :

    void Add(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += Number;
    }

    void Suptract(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Supstracting";
        _Result -= Number;
    }

    void Divide(float Number)
    {
        if (_IsZero(Number))
            Number = 1;

        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Dividing";
        _Result /= Number;
    }

    void Multiply(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Multipling";
        _Result *= Number;
    }

    void Clear()
    {
        _PreviousResult = _Result;
        _LastNumber = 0;
        _Result = 0;
        _LastOperation = "Clear";
    }

    void PrintResult()
    {
        cout << "Result After " << _LastOperation << " " << _LastNumber
            << " is: " << _Result << endl;
    }

    void CancelLastOperation()
    {
        _Result = _PreviousResult;
        _LastNumber = 0;
        _LastOperation = "Cancelling Last Operation";
        }
};

int main()
{
    clsCalculator Calculator1;

    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(100);
    Calculator1.PrintResult();

    Calculator1.Suptract(20);
    Calculator1.PrintResult();

    Calculator1.Divide(0);
    Calculator1.PrintResult();

    Calculator1.Divide(2);
    Calculator1.PrintResult();

    Calculator1.Multiply(3);
    Calculator1.PrintResult();
    
    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();

    return 0;
}
