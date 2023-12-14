#include <iostream>
#include <string>
using namespace std;

//#36


// enum enOperationType {Add = '+' , Sup = '-', Div = '/' , Mul = '*' };

float ReadNumber(string Message)
{
	float Number;
	cout << Message ;
	cin >> Number;
	return Number;
}

/*

enOperationType ReadOpType()
{
	char OT = '+';
	cout << "Enter Opertation Type ( + , - , * , / ) \n";
	cin >> OT;

	return (enOperationType)OT;
}


float Calculate(float Number1, float Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
		case enOperationType::Sup:
			return Number1 - Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	case enOperationType::Mul:
		return Number1 * Number2;
	default:
		return Number1 + Number2;
	}
}

*/

// #37

/*
float SumNumber()
{
	int Number = 0, Sum = 0, Counter = 1;
	do
	{
	Number = ReadNumber("Please Enter Number " + to_string(Counter) + " : ");
	if (Number == -99) {
		break;
	}
	Sum += Number;
	Counter++;
	} while (Number != -99);

	return Sum;
}
*/

// #38

//enum enPrimNumPrime {Prime = 1 , NotPrime = 2};

float ReadPosistiveNumber(string Message)
{
	float Number;
	do {
	cout << Message << endl;
	cin >> Number;

	} while (Number <= 0);
	return Number;
}

/*

enPrimNumPrime CheckPrime(int Number)
{
	int M = round(Number / 2);
		for (int i = 2; i <= M; i++) {
			if (i % 2 == 0)
				return enPrimNumPrime::NotPrime;
			else
				return enPrimNumPrime::Prime;
	}
}

void PrintNumberType(int Number) {


	switch(CheckPrime(Number))
	{
		case enPrimNumPrime::Prime:
		    cout << "Number is Prime \n";
			break;
		case enPrimNumPrime::NotPrime:
			cout << "Number is Not Prime \n";
			break;
	}
}

*/

//#39

/*
float CalculateRemainder(float ToatalBill, float TotalCashPaid)
{
	return ToatalBill - TotalCashPaid;
}
*/


//#40

float TotaBillAfterServiceAndTax(float TotalBill)
{
	return (TotalBill * 1.1) * 1.16;
}

int main()
{
//	float Number1 = ReadNumber("Enter First Number: \n");
//	float Number2 = ReadNumber("Enter Second Number: \n");
//	enOperationType Optype = ReadOpType();
//	cout << endl << "Result = " << Calculate(Number1, Number2, Optype) << endl;

//	cout << endl << "Result = " << SumNumber() << endl;

// PrintNumberType(ReadPosistiveNumber("Enter a Positive Number : "));

//	float TotalBill = ReadPosistiveNumber("Please Enter Total Bill?");
// 	float TotalCashPaid = ReadPosistiveNumber("Please Enter Total Cach Paid?");
//  cout << endl;
//  cout << "Total Bill = " << TotalBill << endl;
//  cout << "Total Cash Paid = " << TotalCashPaid << endl;
//  cout << "****************************\n";
//  cout << "Remaider = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;

	float TotalBill = ReadPosistiveNumber("Please Enter Total Bill ?");
	cout << endl;
	cout << "Total Bill = " << TotalBill << endl;
	cout << "Total Bill After Service Fee and Sales Tax = " << TotaBillAfterServiceAndTax(TotalBill) << endl;


	return 0;
}
