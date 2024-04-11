#include <iostream>
using namespace std;

class clsPerson
{
public:
	string FullName;

	clsPerson() 
	{
		FullName = "Ahmed Mosfafa";
		cout << "\nHi, I'm Constructor";
	}

	~clsPerson()
	{
		cout << "\nHi, I'm Destructor";
	}

};

void Fun1()
{
	clsPerson Person1;
}

void Fun2()
{
	clsPerson* Person2 = new clsPerson;
	delete Person2;
}

int main()
{
	Fun1();

	Fun2();

	system("pause>0");
	return 0;
}

