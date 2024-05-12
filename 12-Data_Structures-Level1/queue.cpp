#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> MyQueue;

    MyQueue.push(1);
    MyQueue.push(2);
    MyQueue.push(3);
    MyQueue.push(4);
    MyQueue.push(5);
    MyQueue.push(6);

    cout << "\nCount: " << MyQueue.size() << endl;
    cout << "\nFront: " << MyQueue.front() << endl;
    cout << "\nBack: " << MyQueue.back() << endl;

    cout << "\nMyQueue: " ;


    while (!MyQueue.empty())
    {
        cout << MyQueue.front() << " ";

        MyQueue.pop();

    }

    cout << new int*  << endl;

    system("pause");
    return 0;
}
