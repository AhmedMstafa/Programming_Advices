#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


void SaveVectorToFile(string FileName, vector <string> vFileContent) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {
		for (string& Line : vFileContent) {
			if (Line != "") {
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}

int main()
{
	vector <string> vFileContent{"Ahmed","Mohamed", "Mostafa", "Ali", "Maha"};
	

	SaveVectorToFile("MyFile.txt", vFileContent);


}
