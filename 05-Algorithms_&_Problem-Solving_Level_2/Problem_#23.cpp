#include <iostream>
#include <cstdlib>
using namespace std;

int Random(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int Array[100], int& Length)
{
	cout << "Enter Number of Elements: ";
	cin >> Length;
		for(int i = 0; i < Length;i++) {
		Array[i] = Random(1, 100);
	}
}

void PrintArray(int Array[100], int Length)
{
	for (int i = 0; i < Length; i++) {
		cout << Array[i] << " ";
	}
	cout << "\n";
}





int main()
{
	srand((unsigned)time(NULL));

	int Array[100], Length;
	FillArrayWithRandomNumbers(Array, Length);
	cout << "\nArray Elements : ";
	PrintArray(Array, Length);

}
