#include <iostream>
using namespace std;

class clsPerson
{

public:

  virtual void Print()
    {
        cout  << "Hi, i'm a Person\n";
    }

};

class clsEmployee : public clsPerson
{

public:

    void Print()
    {
        cout << "Hi, i'm an Employee\n";
    }

};

class clsStudent : public clsEmployee
{

public:

    void Print()
    {
        cout << "Hi, i'm a student\n";
    }

};

int main()
{
    clsEmployee Employee1;
    clsStudent Student1;

    clsPerson* Person1 = &Employee1;
    clsPerson* Person2 = &Student1;

    Person1->Print();
    Person2->Print();

    return 0;
}
