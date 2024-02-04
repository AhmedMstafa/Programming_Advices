#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S1 = "My Name is Ahmed , I Love Programing. ";

	//Prints the length of the string
	cout << S1.length() << endl;

	//Returns the letter at position 3
	cout << S1.at(3) << endl;

	//Adds #ProgrammingAdvices to the end of string
	S1.append("#ProgrammingAdvices");
	cout << S1 << endl;

	//insers All at postion 7
	S1.insert(7, "Ali");
	cout << S1 << endl;

	//Prints all teh next 8 letters from postion 16.
	cout << S1.substr(16, 8);
	cout << S1 << endl;

	//Adds one charecter to the end of the string
	S1.push_back('x');
	cout << S1 << endl;

	//Remove one character form the end of the string
	S1.pop_back();
	cout << S1 << endl;

	//Find Ali in the string 
	cout << S1.find("Ali") << endl;

	//Find ali in the String
	cout << S1.find("ali") << endl;

	if (S1.find("ali") == S1.npos) {
		cout << "ali is not found";
	}

	//clears all  string letters.
	S1.clear();
	cout << S1 << endl;
}
