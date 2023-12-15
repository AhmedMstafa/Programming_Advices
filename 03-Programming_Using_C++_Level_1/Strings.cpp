#include <iostream>
#include <string>
using namespace std;

int main()
{
	/*
	string MyString = "ABCDAFGHIJKLMNOPQRSTUVWXYZ";
	cout << "The lenght of the MyString is: " << MyString.length() << endl;

	cout << MyString[2] << endl; 

	string s1 = "10", s2 = "20";

	string s3 = s1 + s2;
	cout << s3 << endl;

	int Sum = stoi(s1) + stoi(s2);

	cout << Sum << endl;
	
	// Full Name

	string FullName;
	// cin >> FullName;
	getline(cin, FullName);
	cout << FullName << endl;
	*/

	// Home Work
	string s1, s2, s3;
	cout << "Please Enter String1? ";
	getline(cin, s1);
	cout << "Please Enter String2? ";
	cin >> s2;
	cout << "Please Enter String3? \n";
	cin >> s3 ;
	cout << "********************************** \n";
	cout << "The Lenth of String1 is 20 \n";
	cout << "Charter at 0, 2, 4, 7 are : " << s1[0] << " " << s1[2] << " " << s1[4] << " " << s1[7] << endl;
	cout << "Conctenating String2 and String3 = " << s2 + s3 << endl;
	int result = stoi(s2) * stoi(s3);
	cout << s2 << "*" << s3 << " = " << result << endl;

	return 0;
	
}
