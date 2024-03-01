#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

string ToUpper(string S1) {
	for (short i = 0; i < S1.length(); i++) 
		S1[i] = toupper(S1[i]);
	return S1;
}


string CustomReplace(string S1,short From,short To, string sReplace) {
	return S1.substr(0, From) + sReplace + S1.substr((From + To), (S1.length() - From - To));
}

string ReplaceWordInString(string S1, string sOriginal, string sReplace,bool isMach = true) {
	
	short pos = isMach ? S1.find(sOriginal) : ToUpper(S1).find(ToUpper(sOriginal));
	
	while (pos != string::npos) {
		S1 = CustomReplace(S1, pos, sOriginal.length(), sReplace);
		pos = isMach ? S1.find(sOriginal) : ToUpper(S1).find(ToUpper(sOriginal));
	}
	return S1;
}
*/


string AllToLower(string S1) {
	for (short i = 0; i < S1.length(); i++) {
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

vector<string> SplitString(string S1, string Delim) {
	vector<string> vString;
	short pos = 0;
	string sWord = "";
	while ((pos = S1.find(Delim)) != string::npos) {
		sWord = S1.substr(0, pos);
		if (sWord != "")
			vString.push_back(sWord);

		S1.erase(0, (pos + Delim.length()));
	}
	if (S1 != "")
		vString.push_back(S1);

	return vString;
}

string JoinString(vector<string>& vString, string Delim) {
	string S1 = "";
	for (string& sWord : vString) {
		if (sWord != " ")
			S1 += sWord + Delim;
	}

	return S1.substr(0, (S1.length() - Delim.length()));
}

string ReplaceStringUsingSplit(string S1, string StringToReplace, string sRepalceTo, bool Match = true) {
	vector<string> vString = SplitString(S1, " ");

	for (string& sWord : vString) {
		if (Match) {
			if (sWord == StringToReplace)
				sWord = sRepalceTo;
		}
		else {
			if (AllToLower(sWord) == AllToLower(StringToReplace))
				sWord = sRepalceTo;
		}
	}

	return JoinString(vString, " ");
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country\n";
	cout << S1 << endl;
	cout << "\nRepace with match case:\n";
	cout << ReplaceStringUsingSplit(S1, "jordan", "USA",true) << endl;
	cout << "\nRepace with dont match cae:\n";
	cout << ReplaceStringUsingSplit(S1, "jordan", "USA", false);
}
