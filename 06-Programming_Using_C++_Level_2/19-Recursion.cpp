#include <iostream>
using namespace std;

/*
Stak overflow
*/

void PrintNumbers(int N, int M) {
    if (N < M) {
        PrintNumbers(N + 1, M);
        cout << N << endl;
    }
}

int PrintPower(int N, int P) {
    if(P == 0) {
        return 1;
    }
    else {
        return (N * PrintPower(N, P - 1));
    }
}


int main()
{
    PrintNumbers(1, 4);
   cout << PrintPower(4, 2) << endl;
}
