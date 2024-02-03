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
	int Page = 1, TotalPages = 10;
	// print string and int variable
	printf("The Page Number  = %d \n", Page);
	printf("You are in Page %d of %d \n", Page, TotalPages);

	//Width specification
	printf("The page number = %0*d \n",2, Page);
	printf("The page number = %0*d \n",3, Page);
	printf("The page number = %0*d \n",4, Page);
	printf("The page number = %0*d \n",5, Page);


	int Number1 = 20, Number2 = 30;

	printf("The Result of %d + %d = %d \n", Number1, Number2);
	return 0;
}
