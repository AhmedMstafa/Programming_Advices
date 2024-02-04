#include <iostream>
using namespace std;
int main()
{
	// declare an int pointer
	int* ptrX;

	// declare a float pointer
	float* ptrY;

	// dynamically allocate memory
	ptrX = new int;
	ptrY = new float;

	// assinging value to the memory
	*ptrX = 45;
	*ptrY = 85.35f;

	cout << *ptrX << endl;
	cout << *ptrY << endl;

	// deallocate the memory
	delete ptrX;
	delete ptrY;

}
