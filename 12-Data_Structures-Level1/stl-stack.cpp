#include <iostream>
#include <stack>
using namespace std;


int main()
{
	stack<int> stkNumbers;

	stkNumbers.push(10);
	stkNumbers.push(11);
	stkNumbers.push(12);
	stkNumbers.push(13);
	stkNumbers.push(14);


	cout << "count = " << stkNumbers.size() << endl;

	cout << "Numbers are: \n";

	while (!stkNumbers.empty())
	{
		cout << stkNumbers.top() << "\n";

		stkNumbers.pop();
	}


	system("pause>0");
	return 0;
}