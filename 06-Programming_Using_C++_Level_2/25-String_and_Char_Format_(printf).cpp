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
	char Name[] = "Ahmed Mostafa";
	char SchoolName[] = "Programming Advics";

	// PRINT STRING AND STRING 
	printf("Dear %s , How are You ? \n\n", Name);
	printf("Welcome to %s School! \n\n", SchoolName);

	char c = 'S';

	printf("Setting the width of c :%*c \n", 1, c);
	printf("Setting the width of c :%*c \n", 2, c);
	printf("Setting the width of c :%*c \n", 3, c);
	printf("Setting the width of c :%*c \n", 4, c);
	printf("Setting the width of c :%*c \n", 5, c);


	return 0;

}
