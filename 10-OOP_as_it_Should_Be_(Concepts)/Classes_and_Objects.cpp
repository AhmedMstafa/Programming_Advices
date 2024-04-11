#include <iostream>
using namespace std;

class clsPerson
{
private:
    int x;

public:
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }
};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Ahmed";
    Person1.LastName = "Mostafa";

    cout << Person1.FullName() << endl;
}