#include <iostream>
using namespace std;
void FibonacciUsingRecursion(int Number, int Pev1,int Pev2) {
	int FebNumber = 0;
	if (Number > 0) {
		FebNumber = Pev1 + Pev2;
		Pev2 = Pev1;
		Pev1 = FebNumber;
		cout << FebNumber << "  ";
	  FibonacciUsingRecursion(Number-1,Pev1,Pev2);
	}

}


int main()
{
	FibonacciUsingRecursion( 10,1,0);
}
