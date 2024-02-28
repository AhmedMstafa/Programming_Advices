#include <iostream>
#include <string>
#include <vector>
using namespace std;




/*
string Join(vector<string>& V, string Separetor) {
	string sWord = "";
	for (string& vWord : V) {
		sWord += vWord;
		if(vWord != V.back())
			sWord += Separetor;
	}

	return sWord;
}
*/

string JoinString(vector<string> vString, string Delim) {
	string S1 = "";

	for (string& S : vString) {
		S1 = S1 + S + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	vector<string> vString = { "Ahmed" , "Mostafa", "Mansour" };
	cout << "The Stirng After Jouin\n" << JoinString(vString, "#");
}
