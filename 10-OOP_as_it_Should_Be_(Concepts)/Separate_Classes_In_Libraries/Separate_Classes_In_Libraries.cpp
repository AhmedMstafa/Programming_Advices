#include <iostream>
#include "clsDeveloper.h"
using namespace std;


int main()
{
    clsDeveloper Developer1(10, "Ahemd", "Moatafa", "A@a", "010005050", "Developer Title", "xceed", 1000, "C++");
    Developer1.Print();

    Developer1.SendSMS("Hi Developer :-)");

    return 0;
}