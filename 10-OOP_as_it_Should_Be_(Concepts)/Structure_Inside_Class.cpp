#include <iostream>
using namespace std;

class clsPerson
{
    struct stAddress
    {
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };

public:
    string FullName;
    stAddress Address;

    clsPerson()
    {
        FullName = "Ahmed Mostafa";
        Address.AddressLine1 = "Buildeing 10";
        Address.AddressLine2 = "Cairo - Giza";
        Address.City = "Buildeing 10";
        Address.Country = "Cairo - Giza";
    }

    void PrintAddress()
    {
        cout << "\nAddress:\n";
        cout << Address.AddressLine1 << endl;
        cout << Address.AddressLine2 << endl;
        cout << Address.City << endl;
        cout << Address.Country << endl;
    }
        
};

int main()
{
    clsPerson Person1;

    Person1.PrintAddress();

    return 0;
}
