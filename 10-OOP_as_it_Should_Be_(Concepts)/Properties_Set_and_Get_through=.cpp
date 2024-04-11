#include <iostream>
using namespace std;

class clsPerson
{
    string _FristName;

public:

    void SetFristName(string Name)
    {
        _FristName = Name;
    }

    string GetFirstName() {
        return _FristName;
    }

    __declspec(property(get = GetFirstName, put = SetFristName)) string FirstName;

};


int main()
{
    clsPerson Person1;

    Person1.FirstName = "Ahmed";
    cout << Person1.FirstName;
}
