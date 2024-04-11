#include <iostream>
#include "clsString.h"
using namespace std;

int main()
{
	clsString String1;
	String1.Value = "    Ahmed Mostafa Mansour    ";
	cout << String1.Trim();
	cout << String1.Trim();


	return 0;
}