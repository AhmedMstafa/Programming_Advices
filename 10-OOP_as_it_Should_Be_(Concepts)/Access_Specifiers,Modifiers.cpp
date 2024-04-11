#include <iostream>
using namespace std;

class clsPerson
{
private:

	int Variabl1 = 5;

	int Function()
	{
		return 40;
	}

protected:

	int Variabl2 = 100;
	int Function2()
	{
		return 50;
	}

public:

	string FirstName;
	string LastName;

	string FullName() {
		return FirstName + " " + LastName;
	}

	int Variable3 = Variabl1 + Variabl2;

	float Function3()
	{
		return Variabl1 * Variabl2;
	}
};

int main()
{


	clsPerson Person1;

	Person1.FirstName = "Ahmed";
	Person1.LastName = "Mostafa";

	cout << "Person1: " << Person1.FullName() << endl;
	cout << Person1.Function3();


}
