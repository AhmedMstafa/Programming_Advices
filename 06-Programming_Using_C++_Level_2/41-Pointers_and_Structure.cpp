#include <iostream>
using namespace std;

struct stEmplyee {
	string Name;
	float Salary;
};

int main()
{
	stEmplyee Employee1, * ptr;

	Employee1.Name = "Ahmed Mostafa";
	Employee1.Salary = 5000;

	cout << Employee1.Name << endl;
	cout << Employee1.Salary << endl;

	ptr = &Employee1;

	cout << "\nUsing Pointers:\n";
	cout << ptr->Name << endl;
	cout << ptr->Salary << endl;

	return 0;
}
