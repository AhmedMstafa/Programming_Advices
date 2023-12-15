#include <iostream>
using namespace std;

//#46

/*
void PrintLettersAtoZ()
{
	for (int i = 65; i <= 90; i++) {
		cout << char(i) << endl;
	}
}
*/

//#47

float ReadPosiviveNumber(string Message)
{
	float Number;

	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

/*
float TotalMonths(float LoanAmount, float MonthlyInstallment)
{
	return LoanAmount / MonthlyInstallment;
}
*/

//#48
/*
float MonthlyInstallment(float LoanAmount, float HowManyMonths)
{
	return LoanAmount / HowManyMonths;
}
*/

//#49
/*
string ReadPinCode()
{
	string PIN;
	cout << "Please Enter PIN Code ?";
	cin >> PIN;
	return PIN;
}

bool Login()
{


	string PinCode;
	do
	{
		PinCode = ReadPinCode();
		if (PinCode == "1234")
		{
			return 1;
		}
		else {
			
			system("color 4F");
			cout << "\nWrong PIN\n";
		}
	} while (PinCode != "1234");
}
*/

//#50

string ReadPinCode()
{
	string PIN;
	cout << "Please Enter PIN Code ?";
	cin >> PIN;
	return PIN;
}

bool Login()
{
	int counter = 3;

	string PinCode;
	do
	{
		counter--;
		PinCode = ReadPinCode();
		if (PinCode == "1234")
		{
			return 1;
		}
		else {
			system("color 4F");
			cout << "\nWrong PIN, you have \'" << counter << "\' more try! \n";
		}
	} while (PinCode != "1234" && counter >= 1);
	return 0;
}


int main()
{
//	PrintLettersAtoZ();


//	float LoanAmount = ReadPosiviveNumber("Please Enter Loan Amount? ");
//	float MonthlyInstallment = ReadPosiviveNumber("Please Enter Monthly Installment? ");
//	cout << "\nToatal Months to pay = " << TotalMonths(LoanAmount, MonthlyInstallment) << endl;

//	float LoanAmout = ReadPosiviveNumber("Please Enter Loan Amount? ");
//	float HowManyMonths = ReadPosiviveNumber("How Many Months? ");
//	cout << "\nMonthly installment = " << MonthlyInstallment(LoanAmout, HowManyMonths);


/*
	if (Login()) {
		system("color 2F");
		cout << "\nYour Account Balance is " << 7500 << '\n';
	}
*/

if (Login()) {
	system("color 2F");
	cout << "\nYour Account Balance is " << 7500 << '\n';
}
else {
	cout << "\nYour card blocked call the bank for help. \n";
}

	return 0;

}
