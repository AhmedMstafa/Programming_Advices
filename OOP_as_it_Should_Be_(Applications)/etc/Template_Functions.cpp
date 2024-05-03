#include <iostream>
using namespace std;

template <typename T>  T Max(T Num1, T Num2)
{
    return (Num1 > Num2) ? Num1 : Num2;

}

int main()
{
    cout << Max<int>(2, 4) << endl;
    cout << Max <double> (2.5, 4.5) << endl;
    cout << Max<char>('e', 'a') << endl;


}
