#include <iostream>
using namespace std;



// Home Work

int main()
{
	float Grade[3];
	cout << "Please Enter Grade1? " << endl;
	cin >> Grade[0];
	cout << "Please Enter Grade2? " << endl;
	cin >> Grade[1];
	cout << "Please Enter Grade3? " << endl;
	cin >> Grade[2];
	cout << "\n*********************************\n";
	float Avg = (Grade[0] + Grade[1] + Grade[2]) / 3;
	cout << "The Overage Of Grades Is " << Avg<< endl;

	return 0;
}

