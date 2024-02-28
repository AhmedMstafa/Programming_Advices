#include <iostream>
#include <string>
#include <vector>
using namespace std;

// OverLoading


string JoinString(vector<string> vString, string Delim) {
	string S1 = "";

	for (string& S : vString) {
		S1 = S1 + S + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string arr[3], short Length,string Delim) {
	string aString = "";
	for (short i = 0; i < Length; i++) {
		aString += arr[i] + Delim;
	}
	return aString.substr(0, aString.length() - Delim.length());
}

int main()
{
	vector<string> vString = { "Ahmed" , "Mostafa", "Mansour" };
	cout << "The Vector After Jouin\n" << JoinString(vString, "#");
	cout << '\n'<< endl;
	string Array[3] = { "Ahmed" , "Mostafa", "Mansour" };
	short Length = 3;
	cout << "The Array After Jouin\n" << JoinString(Array, 3,"#");


}
