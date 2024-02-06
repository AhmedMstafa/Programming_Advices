#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


void SaveVectorToFile(string FileName, vector <string> vFileContent) {
	fstream MyFile;
	MyFile.open(FileName, ios::out); // Wrigth Mode

	if (MyFile.is_open()) {
		for (string& Line : vFileContent) {
			if (Line != "") {
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}

void LoadDatatFromFileToVector(string FileName, vector<string>& vFileContent) {
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string Line;
		while (getline(MyFile, Line)) {
			vFileContent.push_back(Line);
		}
		MyFile.close();
	}
}

void PrintFileContent(string FileName) {
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		string Line;
		while (getline(MyFile, Line)) {
			cout << Line << endl;
		}
		MyFile.close();
	}
}

void UpdateRecordFromFileVector(string FileName,string Record, string UpdateTo) {
	vector <string> vFileContent;
	LoadDatatFromFileToVector(FileName, vFileContent);
	for (string& Line : vFileContent) {
		if (Line == Record)
			Line = UpdateTo;
	}

	SaveVectorToFile(FileName, vFileContent);
}

int main()
{
	cout << "File Content Before Delete.\n";
	PrintFileContent("MyFile.txt");
	UpdateRecordFromFileVector("MyFile.txt", "Ali", "Ahmed");

	cout << "\nFile Content After Delete.\n";
	PrintFileContent("MyFile.txt");

}
