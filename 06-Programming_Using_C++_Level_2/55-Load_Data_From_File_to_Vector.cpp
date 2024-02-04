#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



void FillFileContent(string FileName, vector<string>& vFilecontent) {

	fstream MyFile;

	MyFile.open(FileName, ios::in); //Read Mode

	if (MyFile.is_open()) {
		string Line;

		while (getline(MyFile, Line)) {
			vFilecontent.push_back(Line);
		}

		MyFile.close();
	}
}

void EditFileContent(string FileName, vector<string>& vFileContenet) {
	for (string& Line : vFileContenet) {
		Line.append(" *Edited");
		cout << Line << endl;
	}
	fstream MyFile;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {
		for (string& Line : vFileContenet) {
			MyFile << Line << endl;
		}

		MyFile.close();
	}
}

int main()
{
	vector <string> vFileContent;
	FillFileContent("MyFile.txt",vFileContent);

	EditFileContent("MyFile.txt", vFileContent);

	return 0;
}