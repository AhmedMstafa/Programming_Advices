#include <iostream>
using namespace std;
/*

Ctrl + M + 0 = Open All Functions
Ctrl + M + p = Open All Functions
Go To Defination F12
Go To Declaretion Ctrl + F12
Peek Alt + F12
Find All Refrances
Rename Ctrl + R ,Ctrl + R 
*/

void Functuon4() {
    cout << "Hi I'm Fuction 4 " << endl;
}


void Functuon3() {
    Functuon4();
}


void Functuon2() {
    Functuon3();
}


void Functuon1() {
    Functuon2();
}

int main()
{
    Functuon1();

    return 0;
}
