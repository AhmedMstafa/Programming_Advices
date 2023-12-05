
#include <iostream>
#include <string>
using namespace std;

// Home Work
// Home Work

enum Operation {Add=1,Subtact=2, Multiply=3, Division=4 };
enum Days {Sunday=1,Monday=2,Tuseday=3,Wednesday=4,Thursday=5,Friday=6,Saturday=7};
enum Months { NotSet = 0, January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12 };

int main()
{
	/*
	int Number1, Number2, Result ,OperationType;
	cout << "Enter First Number: \n";
	cin >> Number1;
	cout << "Enter Second Number: \n";
	cin >> Number2;
	cout << "Enter Operation Type: \n";
	cout << "(1) Add\n";
	cout << "(2) Subtract\n";
	cout << "(3) Multiply\n";
	cout << "(4) Division\n";
	cin >> OperationType;
	int Op = (Operation)OperationType;

	switch (Op)
	{
	case Operation::Add:
		Result = Number1 + Number2;
		cout << Result << endl;
		break;
	case Operation::Subtact:
		Result = Number1 - Number2;
		cout << Result << endl;
		break;
	case Operation::Multiply:
		Result = Number1 * Number2;
		cout << Result << endl;
		break;
	case Operation::Division:
		Result = Number1 / Number2;
		cout << Result << endl;
		break;
	default: 
		cout << "Wrong Operator!";
	}
	*/

	/*
	int Day;
	cout << "Enter Number The Day: \n";
	cout << "(1) Print Sunday \n";
	cout << "(2) Print Monday \n";
	cout << "(3) Print Tuseday \n";
	cout << "(4) Print Wednesday \n";
	cout << "(5) Print Thursday \n";
	cout << "(6) Print Friday \n";
	cout << "(7) Print Saturday \n";

	cin >> Day;

	switch (Day)
	{
	case Days::Sunday:
		cout << "Its Sunday";
		break;
	case Days::Monday:
		cout << "Its Monday \n";
		break;
	case Days::Tuseday:
		cout << "Its Tuseday \n";
		break;
	case Days::Wednesday:
		cout << "Its Wednesday \n";
		break;
	case Days::Thursday:
		cout << "Its Thursday \n";
		break;
	case Days::Friday:
		cout << "Its Friday \n";
		break;
	case Days::Saturday:
		cout << "Its Saturday \n";
		break;
	default:
		cout << "Wrong Day! \n";
	}
	*/

	int Month;
	cout << "Enter Number Of Month: ";
	cin >> Month;
	Month = (Months)Month;
	
	switch (Month)
	{
	case Months::January:
		cout << "January\n";
		break;
	case Months::February:
		cout << "February\n";
		break;
	case Months::March:
		cout << "March\n";
		break;
	case Months::April:
		cout << "April\n";
		break;
	case Months::May:
		cout << "May\n";
		break;
	case Months::June:
		cout << "June\n";
		break;
	case Months::July:
		cout << "July\n";
		break;
	case Months::August:
		cout << "August\n";
		break;
	case Months::September:
		cout << "September\n";
		break;
	case Months::October:
		cout << "October\n";
		break;
	case Months::November:
		cout << "November\n";
		break;
	case Months::December:
		cout << "December\n";
		break;
	default: 
		cout << "Wrong Month! \n" ;
		main();
	}

	return 0;



	
		
}

