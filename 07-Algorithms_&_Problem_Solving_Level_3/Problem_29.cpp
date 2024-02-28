#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string S;
	cout << "Please Enter Your String?\n";
	getline(cin, S);
	return S;
}

short CountCapitalLetter(string S) {
	short Count = 0;
	for (short i = 0; i< S.length(); i++) {
		if (isupper(S[i]))
			Count++;
	}
	return Count;
}

short CountSmallLetter(string S) {
	short Count = 0;
	for (short i = 0; i < S.length(); i++) {
		if (islower(S[i]))
			Count++;
	}
	return Count;
}


int main()
{
	string S = ReadString();
	cout << endl;
	cout << "String Length = " << S.length() << endl;
	cout << "Caplital Letters Count= " << CountCapitalLetter(S) << endl;
	cout << "Small Letters Count= " << CountSmallLetter(S) << endl;
}
