
#include <iostream>
#include <string>
using namespace std;

// #1
/*
void PrintName(string Name)
{
	cout << "\n Your Name is : " << Name  << endl;

}
*/

// #2

/*
string ReadName() {
	string Name;
	cout << "Enter Your Name: ";
	getline(cin, Name);
	return Name;
}

void PrintName(string Name)
{
	cout << "\nYour Name is: " << Name << endl;
}

*/

//#2

/*
int ReadNumber()
{
	int Num;
	cout << "Enter a Number : \n";
	cin >> Num;
	return Num;
}

enum enNumberType {Odd = 1, Even = 2 };

enNumberType CheckNumberType(int Num)
{
	int Result = Num % 2;
	if (Result == 0)
		return enNumberType::Even;
	else
		return enNumberType::Odd;
}

void PrintNumberType(enNumberType NumberType)
{
	if (NumberType == enNumberType::Even)
		cout << "\n Number is Even. \n";

	else
		cout << "\n Number is odd \n";

}
*/


//4

/*

struct strInfo {
	int Age;
	bool HasDrivingLicense;
};

strInfo ReadInfo()
{
	strInfo Info;
	cout << "Please Enter Your Age?" << endl;
	cin >> Info.Age;
	cout << "Do you have driver License?" << endl;
	cin >> Info.HasDrivingLicense;

	return Info;
}

bool IsAccepted(strInfo info)
{
	if (info.Age > 21 && info.HasDrivingLicense)
		return true;
	else
		return false;
}


void PrintResult(bool IsAccepted) {
	if (IsAccepted)
		cout << "\n Hired" << endl;
	else
		cout << "\n Rejected" << endl;
}
*/


// #5

struct strInfo {
	int Age;
	bool HasDrivingLicense;
	bool HasRecommendation;
};

strInfo ReadInfo()
{
	strInfo Info;
	cout << "Please Enter Your Age?" << endl;
	cin >> Info.Age;
	cout << "Do you have driver License?" << endl;
	cin >> Info.HasDrivingLicense;
	cout << "Do you habe Recommendation?" << endl;
	cin >> Info.HasRecommendation;

	return Info;
}

bool IsAccepted(strInfo Info)
{
	if (Info.HasRecommendation)
		return true;
	else 
		(Info.Age > 21 && Info.HasDrivingLicense);
}


void PrintResult(bool IsAccepted) {
	if (IsAccepted)
		cout << "\n Hired" << endl;
	else
		cout << "\n Rejected" << endl;
}


int main()
{
	//PrintName("Mohamed");

	//PrintName(ReadName());

	//PrintNumberType(CheckNumberType(ReadNumber()));

	//PrintResult(IsAccepted(ReadInfo()));

PrintResult(IsAccepted(ReadInfo()));


	return 0;
}