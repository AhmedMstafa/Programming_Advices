#include <iostream>
using namespace std;

class clsPerson
{

    string _FirstName;

public:
    void SetFirstName(string Name)
    {
        _FirstName = Name;
    }

    string FirstName()
    {
        return _FirstName;
    }

};


int main()
{
    clsPerson Person1;

    Person1.SetFirstName("Ahmed");

    cout << Person1.FirstName();
}
