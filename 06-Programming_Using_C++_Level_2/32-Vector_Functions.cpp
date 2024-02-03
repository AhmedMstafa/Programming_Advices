#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <int> vNumbers;
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);
	vNumbers.push_back(10);


	cout << "First Element: " << vNumbers.front() << endl;
	cout << "Last Element: " << vNumbers.back() << endl;

	//returns the number of elements present in the vecotr
	cout << "Size: " << vNumbers.size() << endl;

	//check the overall size of a vector
	cout << "Capacity: " << vNumbers.capacity() << endl;

	//returns 1 (true) if the vector is empty 
	cout << "Empty: " << vNumbers.empty() << endl;

	vNumbers.clear();
}
