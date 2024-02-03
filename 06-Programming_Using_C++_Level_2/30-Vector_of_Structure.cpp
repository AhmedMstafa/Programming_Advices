#include <iostream>
#include <vector>
using namespace std;

struct stEmployee {
	string FristName;
	string LastName;
	int Salary = 0;
};

void ReadEmployee(vector <stEmployee>&  vEmployees) {
	stEmployee TempEmployee;
	char ReadMore = 'Y';
	while (ReadMore == 'Y' || ReadMore == 'y') {
		cout << "Enter First Name: ";
		cin >> TempEmployee.FristName;
		cout << "Enter Last Name: ";
		cin >> TempEmployee.LastName;
		cout << "Enter Salary: ";
		cin >> TempEmployee.Salary;
		vEmployees.push_back(TempEmployee);
		cout << endl <<"Do you want to add more Employee? Y/N ";
		cin >> ReadMore;
		cout << endl;
	}
}

void PrintEmployees(vector <stEmployee>& vEmployees) {
	for (stEmployee& Employee : vEmployees) {
		cout << "\nFirst Name: " << Employee.FristName << "\n";
		cout << "Last Name: " << Employee.LastName << "\n";
		cout << "Salary: " << Employee.Salary << "\n";
		cout << "_________________" << endl;
	}
}

int main()
{
	vector <stEmployee> vEmployees;

	ReadEmployee(vEmployees);
	PrintEmployees(vEmployees);

	/*

	stEmployee TempEmployee;
	TempEmployee.FristName = "Ahmed";
	TempEmployee.LastName = "Mostafa";
	TempEmployee.Salary = 5000;
	vEmployees.push_back(TempEmployee);

	TempEmployee.FristName = "Ali";
	TempEmployee.LastName = "Gamal";
	TempEmployee.Salary = 500;
	vEmployees.push_back(TempEmployee);

	TempEmployee.FristName = "Farah";
	TempEmployee.LastName = "Abdollah";
	TempEmployee.Salary = 3000;
	vEmployees.push_back(TempEmployee);

	for (stEmployee& Employee : vEmployees) {
		cout << "\nFirst Name: " << Employee.FristName << "\n";
		cout <<"Last Name: "<< Employee.LastName << "\n";
		cout <<"Salary: "<< Employee.Salary << "\n";
		cout << "_________________" << endl;
	}
	*/

	return 0;
}
