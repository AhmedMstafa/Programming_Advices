
#include <iostream>
using namespace std;

// Home Work

struct Person
{
	string FirstName, LastName;
	int Age, Phone;
};

void ReadInfo(Person &info)
{
	cout << "Enter Your First Name? ";
	cin >> info.FirstName;
	cout << "Enter Your Last Name? ";
	cin >> info.LastName;
	cout << "Enter Your Age? ";
	cin >> info.Age;
	cout << "Enter Your Phone Number? ";
	cin >> info.Phone;
}

void PrintInfo(Person PersonArray)
{
	cout << "\n****************************\n";
	cout << "First Name: " << PersonArray.FirstName << endl;
	cout << "Last Name: " << PersonArray.LastName << endl;
	cout << "Age : " << PersonArray.Age << endl;
	cout << "Phone: " << PersonArray.Phone ;
	cout << "\n****************************\n";
}


void ReadPeasonsInfo(Person PersonArray[2]) {
	ReadInfo(PersonArray[0]);
	ReadInfo(PersonArray[1]);
};
void PrintPersonsInfo(Person PersonArray[2])

{
	PrintInfo(PersonArray[0]);
	PrintInfo(PersonArray[1]);
}

int main()
{
	Person PersonArray[2];
	ReadPeasonsInfo(PersonArray);
	PrintPersonsInfo(PersonArray);

	return 0; 
}

