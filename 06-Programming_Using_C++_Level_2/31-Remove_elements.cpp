#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(40);

	cout << "vector size=" << vNumbers.size() << endl;

	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();

	cout << "vector size=" << vNumbers.size() << endl;

	if (!vNumbers.empty())
		vNumbers.pop_back();

	cout << "vector size=" << vNumbers.size() << endl;

	return 0;
}

