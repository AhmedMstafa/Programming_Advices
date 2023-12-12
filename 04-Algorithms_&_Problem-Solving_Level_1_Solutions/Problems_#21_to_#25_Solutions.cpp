#include <iostream>
using namespace std;

// #21

/*


float ReadCircumferenc()
{
	float L;
	cout << "Enter Circumference : \n";
	cin >> L;
	return L;
}

float CircleAreaByCircumference(float L)
{
	const float PI = 3.141592653589793238462643383279502884197;
	float Area = pow(L, 2) / (4 * PI);
	return Area;
}

void PrintResult(float Area)
{
	cout << "Circle Area By Circumference = " << Area << endl;
}
*/

// #22

/*

void ReadTriangleData(float& A, float& B)
{
	cout << "Enetr A: \n";
	cin >> A;
	cout << "Enter B: \n";
	cin >> B;
}


float CircleAreaByITriange(float A, float B)
{
	const float PI = 3.141592653589793238462643383279502884197;
	float Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));
	return Area;
}

void PrintResult(float Area) {
	cout << "Circle Area Inscribed in an isosceles Triangel = " << Area << endl;
}
*/


//#23

/*

void ReadTriangleData(float& A, float& B, float& C)
{
	cout << "Enter A: \n";
	cin >> A;
	cout << "Enter B: \n";
	cin >> B;
	cout << "Entr C: \n";
	cin >> C;
}

float CircleAreaByITringle(float A, float B, float C)
{
	const float PI = 3.141592653589793238462643383279502884197;
	float P = (A + B + C) / 2;
	float T =  (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
	float Area = PI * pow(T, 2);
	return Area;
}

void PrintResult(float Area)
{
	cout << "Circle Area  = " << Area << endl;
}
*/

//#24

/*
*/

int ReadAge() {
	int Age;
	cout << "Enter Your Age between 18 and 45 ? \n";
	cin >> Age;
	return Age;
}


bool ValidUntilAgeBetween(int Number,int From, int To)
{
	return  (Number >= From && Number <= To);
}


int ReadUntilAgeBetween(int From, int To)
{
	int Age = 0;
	do
	{
	Age = ReadAge();

	} while (!ValidUntilAgeBetween(Age, From, To));

	return Age;
}


void PrintResult(int Age)
{
	cout << "Your Age is: " << Age << endl;
}


int main()
{

// PrintResult(CircleAreaByCircumference(ReadCircumferenc()));

//	float A, B;
//	ReadTriangleData(A,B);
//	PrintResult(CircleAreaByITriange(A,B));

//	float A, B, C;
//	ReadTriangleData(A, B, C);
//	PrintResult(CircleAreaByITringle(A, B, C));

   PrintResult(ReadUntilAgeBetween(18, 45));
	return 0;
}
