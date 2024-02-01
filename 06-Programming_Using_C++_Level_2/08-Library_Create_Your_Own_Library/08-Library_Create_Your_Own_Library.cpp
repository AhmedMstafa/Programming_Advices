#include <iostream>
#include "MyLib.h"
#include "NumLib.h"
using namespace std;
using namespace MyLib;
int main()
{
    std::cout << "Hello World!\n";
    print("Hello World!");
    cout << Sum2Numbers(1, 3) << endl;
    Nums::PrintNumbers(1345);
    Nums::PrintRevesedNumbers(1234);
    cout << Nums::Avg2Numbers(10, 20) << endl;
    cout << Nums::PowerOf(4, 2) << endl;
}
