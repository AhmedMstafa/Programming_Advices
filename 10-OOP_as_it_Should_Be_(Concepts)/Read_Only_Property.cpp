#include <iostream>
using namespace std;

class clsPerson
{

	int _ID = 123456;
	string _FirstName;

public:
	const int Id = 123;

	void SetFirstName(string Name)
	{
		_FirstName = Name;
	}
	string FirstName()
	{
		return _FirstName;
	}

	int ID() {
		return _ID;
	}


};

int main()
{
	clsPerson Person1;
	
	Person1.SetFirstName("Ahmed");
	cout << Person1.FirstName() << endl;

	cout << Person1.ID() << endl;
}
