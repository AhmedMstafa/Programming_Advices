#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string S;
	cout << "Plaese Enter Your String?\n";
	getline(cin, S);
	return S;
}


int CountEachWordInString(string S) {
	string dilam = " ";
	string sWord;
	short Count = 0;
	short pos = 0;

	while ((pos = S.find(dilam)) != std::string::npos) {
		sWord = S.substr(0, pos);
		if (sWord != "")
			Count++;

		S.erase(0, pos + dilam.length());
	}
	if (S.length() && S != " ")
		Count++;

	return Count;
}

int main()
{
	string S = ReadString();
	cout << "\nThe number of words in your string is: \n";
	cout << CountEachWordInString(S) << endl;
}

