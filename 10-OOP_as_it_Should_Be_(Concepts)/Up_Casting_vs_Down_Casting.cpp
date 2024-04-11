#include <iostream>
using namespace std;

class clsPerson
{

public:
    string FullName = "Ahmed Mostafa";

};

class clsEmployee : public clsPerson
{

public:
    string Title = "CEO";

};

int main()
{
    clsEmployee Employee1;
    cout << Employee1.FullName << endl;

    clsPerson* Person1 = &Employee1;
    cout << Person1->FullName << endl;
}
