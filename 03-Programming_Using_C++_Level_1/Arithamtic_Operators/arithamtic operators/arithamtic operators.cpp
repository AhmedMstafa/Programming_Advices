
#include <iostream>
using namespace std; 

int main()
{
	/*
	int A = 10, B = 20;
	cout << "A + B = " << A + B << endl;
	cout << "A - B = " << A - B << endl;
	cout << "A / B = " << A / B << endl;
	cout << "A * B = " << A * B << endl;
	cout << "A % B = " << A % B << endl;

	// Home Work //
	int FirstNumber, SecondNumber;
	cout << "Enter The First Number : ";
	cin >> FirstNumber;
	cout << "Enter The First Number : ";
	cin >> SecondNumber;
	cout << FirstNumber << " + " << SecondNumber << " = " << FirstNumber + SecondNumber << endl;
	cout << FirstNumber << " - " << SecondNumber << " = " << FirstNumber - SecondNumber << endl;
	cout << FirstNumber << " / " << SecondNumber << " = " << FirstNumber / SecondNumber << endl;
	cout << FirstNumber << " * " << SecondNumber << " = " << FirstNumber * SecondNumber << endl;
	cout << FirstNumber << " % " << SecondNumber << " = " << FirstNumber % SecondNumber << endl;

	// Home Work #7 Half Number//
	float Number;
	cout << "Enter a number :";
	cin >> Number;
	float HalfNumber = Number / 2;
	cout << "Halef of the Number " << Number << " is " << HalfNumber << endl;

	// Home Work #9 Sum of 3 numbers//
	short num1, num2, num3, result;
	cout << "Enter First Number : ";
	cin >> num1;
	cout << "Enter Second Number : ";
	cin >> num2;
	cout << "Enter Third Number : ";
	cin >> num3;
	result = num1 + num2 + num3;
	cout << "The Result is : " << result << endl;
	// Home Work #10 Average of 3 Marks//
	short Mark1, Mark2, Mark3, Average;
	cout << "Enter First Mark : ";
	cin >> Mark1;
	cout << "Enter Second Mark : ";
	cin >> Mark2;
	cout << "Enter Therd Mark : ";
	cin >> Mark3;
	Average = (Mark1 + Mark2 + Mark3) / 3;
	cout << "The Average is : " << Average << endl;
	// Home Work #14 Swap Numbers//
	short Number1, Number2, temp;
	cout << "Enter First Number: ";
	cin >> Number1;
	cout << "Enter Second Number: ";
	cin >> Number2;
	cout << Number1 << "\n" << Number2 << endl;
	cout << "Swap <()> \n";
	temp = Number1;
	Number1 = Number2;
	Number2 = temp;
	cout << Number1 << "\n" << Number2 << endl;

	// Home Work #15 Rectangle Area//
	short a, b, Area;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	Area = a * b;
	cout << Area << endl;

	// Home Work #17 Traingle Area//

	short a, h;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter h: ";
	cin >> h;
	float Area = a / 2 * h;
	cout << "Traingle Area is: " << Area;

	// Home Work #19 Circle Area Through Diameter//
	const float p = 3.14;
	float  d , Area;
	cout << "Enter Diameter of the Circle: ";
	cin >> d;
	Area = (p * d * d) / 4;
	cout << "Circle Area is: " << Area << endl;


	// Home Work #20 Circle Area Inscribed in a Square//
	const float p = 3.14;
	float a, Area;
	cout << "Enter a in Square :";
	cin >> a;
	Area = (p * a * a) / 4;
	cout << "Circle Area is: " << Area << endl;


	// Home Work #21 Circle Area Along the Circumferece//
	const float p = 3.13;
	float l, Area;
	cout << "Enter the long of circle: ";
	cin >> l;
	Area = (l * l) / (4 * p);
	cout << "Circle Area is: "<< Area << endl;
	

	// Home Work #22 Circle Area Along the Circumferece//
	const float p = 3.14;
	float a, b;
	cout << "Enter a: ";
	cin >> a; 
	cout << "Enter b: ";
	cin >> b;
	double Area = (p * b * b / 4) * ((2 * a - b) / (2 * a + b));
	cout << "Circle Area is: " << Area << endl;


	// Home Work #31 Power of 2,3,4//
	short num, a, b ,c;
	cout << "Enter Number: ";
	cin >> num;
	a = num * num;
	b = num * num * num;
	c = num * num * num;
	cout << a << "\n" << b << "\n" << c << "\n";

	
	// Home Work #35 Piggy Bank Calculator//
	short Pinny, Nickel, Dime, Quarter, Dollar;
	cout << "Pinnys: ";
	cin >> Pinny;
	cout << "Nickels: ";
	cin >> Nickel;
	cout << "Dimes: ";
	cin >> Dime;
	cout << "Quarters: ";
	cin >> Quarter;
	cout << "Dollars: ";
	cin >> Dollar;
	float TotalPinnys = Pinny + (Nickel * 5) + (Dime * 10) + (Quarter * 25) + (Dollar * 100);
	float TotalDolars = TotalPinnys / 100;
	cout << "TotalDollaras = " << TotalDolars << endl;
	cout << "TotalPinnys = " << TotalPinnys;


	// Home Work #39 Pay Remainder//
	short TotalBill, CashPaid , Remainder;
	cout << "Enter TotalBill: ";
	cin >> TotalBill;
	cout << "Enter CashPaid: ";
	cin >> CashPaid;
	Remainder = CashPaid - TotalBill;
	cout << "Remaind: " << Remainder << endl;
	

	// Home Work #40 Servie Fee and Sales Tax//
	
	float BillValue, TotalBill;
	cout << "Enter The BillValue: ";
	cin >> BillValue;
	TotalBill = BillValue * 1.16 * 1.10;
	cout << "Total Bill: " << TotalBill << endl;

	// Home Work #42 Task Duration in Seconds//
	short days, hours, minutes, seconds;
	cout << "Enter Days: ";
	cin >> days;
	cout << "Enter Hours: ";
	cin >> hours;
	cout << "Enter Minutes: ";
	cin >> minutes;
	cout << "Enter Seconds: ";
	cin >> seconds;
	float duration = days * 24 * 60 * 60 + hours * 60 * 60  + minutes * 60  + seconds ;
	cout << "Duration is: " << duration << endl;
	

	// Home Work #43 Seconds To Days Hours Minutes Seconds//

	int days = 24 * 60 * 60, hours = 60 * 60, minutes = 60, seconds;
	cout << "Enter The Seconds: ";
	cin >> seconds;
	short NumberOfDays, NumberOfHourss, NumberOfMinutes, NumberOfSeconds, Remainder;
	NumberOfDays = floor(seconds / days);
	Remainder = seconds % days;
	NumberOfHourss = floor(Remainder / hours);
	Remainder = Remainder % hours;
	NumberOfMinutes = floor(Remainder / minutes);
	Remainder = Remainder % minutes;
	NumberOfSeconds = Remainder;
	cout << NumberOfDays << ":" << NumberOfHourss << ":" << NumberOfMinutes << ":" << Remainder << endl;

	// Home Work #47 Loan Instalment Months//

	short LoonAmount,MonthlyInstalment, MonthlyPayment;
	cout << "Enter Loon Amount: ";
	cin >> LoonAmount;
	cout << "Monthly instalment: ";
	cin >> MonthlyInstalment;
	MonthlyPayment  = LoonAmount / MonthlyInstalment;
	cout << MonthlyPayment << "Months"<< endl;
	// Home Work #48 Monthly Loan Installment//
short LoonAmount, MonthlyPyament, Monthlyinstalment;
cout << "Enter Loon Amount: ";
cin >> LoonAmount;
cout << "Enter Months: ";
cin >> MonthlyPyament;
Monthlyinstalment = LoonAmount / MonthlyPyament;
cout << "You Have To Pay: " << Monthlyinstalment << " Dollar Every Month" << endl;
	

	*/

	return 0;
	}