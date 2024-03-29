#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string S;
	cout << "Please Enter Your Stirng?\n";
	getline(cin, S);
	return S;
}

string TrimLeft(string S) {
	/*
	for (short i = 0; i < S.length(); i++) {
		if (S[0] == ' ')
			S.erase(0, 1 );
		else
			break;
	}
	return S;
	*/
	for (short i = 0; i < S.length(); i++) {
		if (S[i] != ' ') {
		return	S.substr(i, (S.length() - i));
		}
	}
	return "";
}


string TrimRight(string S) {
	/*
	for (short i = 0; i < S.length(); i++) {
		if (S[S.length() - 1] == ' ')
			S.erase((S.length()   -1), (S.length()));
		else
			break;
	}
	return S;
	*/
	for (short i = S.length() - 1; i >= 0; i--) {
		if (S[i] != ' ')
			return	S.substr(0,i + 1);
	}
	return "";
}

string Trim(string S) {
	return TrimLeft(TrimRight(S));
}

int main()
{
	string S = ReadString();
	cout << "\nTrim Left =|" << TrimLeft(S) << "|" << endl;
	cout << "\nTrim Right = " << TrimRight(S) << "|" << endl;
	cout << "\nTrim  =|" << Trim(S) << "|" << endl;

}