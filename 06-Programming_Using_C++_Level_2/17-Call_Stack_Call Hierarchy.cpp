#include <iostream>
using namespace std;


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
