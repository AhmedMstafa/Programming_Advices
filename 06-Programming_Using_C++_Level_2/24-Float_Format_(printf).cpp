#include <iostream>
#include <stdio.h>
using namespace std;

/*
%d = Digital or int
%c = char
%s = string
%f = float
*/




int main()
{
	float PI = 3.14159265;

	//Precision specification
	printf("Precision Specification of %.*f\n", 1, PI);
	printf("Precision Specification of %.*f\n", 2, PI);
	printf("Precision Specification of %.*f\n", 3, PI);
	printf("Precision Specification of %.*f\n", 4, PI);

	float x = 7.0, y = 9.0;
	printf("\nThe float division is : %.3f / %.3f = %.3f \n\n", x, y, x / y);

	double d = 12.45;
	printf("The double vlaue is : %.3f \n", d);
	printf("The double vlaue is : %.4f \n", d);
	return 0;
}
