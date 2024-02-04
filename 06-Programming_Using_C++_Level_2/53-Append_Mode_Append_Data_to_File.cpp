#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream MyFile;

	MyFile.open("MyFile.txt", ios::out | ios::app); //append Mode

	if (MyFile.is_open()) {
		MyFile << "This is a new Line\n";
		MyFile << "This is another Line" << endl;
		MyFile.close();
	}
	return 0;
}
