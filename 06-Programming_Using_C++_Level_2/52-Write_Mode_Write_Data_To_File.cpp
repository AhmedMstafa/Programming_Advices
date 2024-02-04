#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream MyFile;

	MyFile.open("MyFile.txt", ios::out); //Write Mode

	if (MyFile.is_open()) {
		MyFile << "This is my First File! \n";
		MyFile << "The Second Line\n";
		MyFile << "The Third Line" << endl;
		MyFile.close();
	}
	return 0;
}
