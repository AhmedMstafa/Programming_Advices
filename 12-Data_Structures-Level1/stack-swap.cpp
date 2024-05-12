#include <iostream>
#include <stack>
using namespace std;


int main()
{
	stack<int> MyStack1;
	stack<int> MyStack2;

	MyStack1.push(10);
	MyStack1.push(11);
	MyStack1.push(12);
	MyStack1.push(13);
	MyStack1.push(14);

	MyStack2.push(15);
	MyStack2.push(16);
	MyStack2.push(17);
	MyStack2.push(18);
	MyStack2.push(19);

	MyStack1.swap(MyStack2);

	cout << "MySatck1 = ";
	while (!MyStack1.empty())
	{
		cout << MyStack1.top() << " ";
		MyStack1.pop();
	}

	// 

	cout << endl << "MySatck2 = ";
	while (!MyStack2.empty())
	{
		cout << MyStack2.top() << " ";
		MyStack2.pop();
	}

	system("pause>0");
	return 0;
}