#include <iostream>
#include <queue>
using namespace std;


int main()
{
	queue<int> MyQueue1;
	queue<int> MyQueue2;

	MyQueue1.push(1);
	MyQueue1.push(2);
	MyQueue1.push(3);
	MyQueue1.push(4);

	MyQueue2.push(5);
	MyQueue2.push(6);
	MyQueue2.push(7);
	MyQueue2.push(8);

	MyQueue1.swap(MyQueue2);

	cout << "\nMyQueue1 : ";
	while (!MyQueue1.empty())
	{
		cout << MyQueue1.front() << " ";
		MyQueue1.pop();
	}

	cout << endl << "\nMyQueue2 : ";
	while (!MyQueue2.empty())
	{
		cout << MyQueue2.front() << " ";
		MyQueue2.pop();
	}

	system("pause>0");
	return 0;
}