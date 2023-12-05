
#include <iostream>
using namespace std;

// Home Work

void MySumProcedural() 
{
	int num1;
	int num2;
	cout << "lease Enter Number1? \n";
	cin >> num2;
	cout << "Please Enter Number2? \n";
	cin >> num1; 
	int result = num1 + num2;
	cout << "\n***********************\n";
	cout << result << endl;
};

int MySumFunction() {
	int num1;
	int num2;
	cout << "lease Enter Number1? \n";
	cin >> num2;
	cout << "Please Enter Number2? \n";
	cin >> num1;
	int result = num1 + num2;
	cout << "\n***********************\n";
	return result;
};

int main()
{
	MySumProcedural();

	cout << MySumFunction() ;
	
}

