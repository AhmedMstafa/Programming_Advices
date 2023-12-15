
#include <iostream>
#include <string>

using namespace std;

/*
void ReadArrayData(int Arr1[100], int &Length)
{
	cout << "How Many Number do you want to enter ? 1 to 100" << endl;
	cin >> Length;
	for (int i = 0; i <= Length - 1; i++) {
		cout << "Please Enter Number " << i + 1 << endl;
		cin >> Arr1[i];
	}
	
}
void PrintArrayData(int Arr1[100], int Length) {
	cout << "**************************\n";
	for (int i = 0; i <= Length - 1; i++) {
		cout << "Number [" << i + 1 << "] : " << Arr1[i] << endl;
	}
	cout << "**************************\n";
}
int CalcultateArraySum(int Arr1[100], int Length)
{
	int sum = 0;
	for (int i = 0; i <= Length - 1; i++) {
		sum += Arr1[i];
	}
	return sum;
}
float CalculateArrayAverage(int Arr1[100], int Length) {

	return (float)CalcultateArraySum(Arr1, Length) / Length;
}
*/
	/*
int main()
{
	int Arr1[100], Length = 0;
	ReadArrayData(Arr1, Length);
	PrintArrayData(Arr1, Length);
	cout << "Sum Numbers is :" << CalcultateArraySum(Arr1, Length) << endl;
	cout << "Average Numbers is : " << CalculateArrayAverage(Arr1, Length) << endl;

}
	*/

////////////////// Home Work

struct strInfo {
    string Name, City, Country;
    int Age, MonthlySalary, YearlySalary;
    char Gender;
    bool Marride;
};

void ReadInfo(strInfo& Person)
{

   
    cout << "Enter Yoru Name? \n";
    cin.ignore(1, '\n');
    getline(cin, Person.Name);
    cout << "Enter Your Age? \n";
    cin >> Person.Age;
    cout << "Enter Your City? \n";
    cin >> Person.City;
    cout << "Enter Your Country? \n";
    cin >> Person.Country;
    cout << "Enter Your Monthly Salary? \n";
    cin >> Person.MonthlySalary;
    cout << "Enter Your Yearly Salary? \n";
    cin >> Person.YearlySalary;
    cout << "Enter Your Gender? \n";
    cin >> Person.Gender;
    cout << "Are You Marred? \n";
    cin >> Person.Marride;
}

void PrintInfo(strInfo Person)
{
    cout << "\n************************\n";
    cout << "Name: " << Person.Name << endl;
    cout << "Age: " << Person.Age << endl;
    cout << "City: " << Person.City << endl;
    cout << "Country: " << Person.Country << endl;
    cout << "Monthly Salary: " << Person.MonthlySalary << endl;
    cout << "Yearly Salary: " << Person.YearlySalary << endl;
    cout << "Gender: " << Person.Gender << endl;
    cout << "Marred: " << Person.Marride;
    cout << "\n************************\n";
}

void ReadPersonsInfo(strInfo Persons[100],int Length) {

    for (int i = 0;i <= Length; i++) {
        cout << "Person [" << i + 1 << "]" << endl;
        ReadInfo(Persons[i]);
    }
}

void PrindPersonsInfo(strInfo Persons[100], int Length) {
    for (int i = 0; i <= Length ;i++) {
        PrintInfo(Persons[i]);
    }
}

int main()
{
    strInfo Persons[100];
    int Length = 0;
    cout << "Enter How Many Person you are added ? ";
    cin >> Length;
    ReadPersonsInfo(Persons, Length);
    PrindPersonsInfo(Persons, Length);


    return 0;
}


