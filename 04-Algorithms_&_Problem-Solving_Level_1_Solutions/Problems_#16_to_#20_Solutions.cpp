
#include <iostream>
using namespace std;

// #16

/*
void ReadNumbers(float& A, float& D) {
	cout << "Enter A: \n";
	cin >> A;
	cout << "Enter D: \n";
	cin >> D;
}

float RectangleAreaBySideAndDiagonal(float A, float D)
{
	float Area = A * sqrt(pow(D, 2) - pow(A, 2));
	return Area;
}

void PrintResult(float Area) {
	cout << "Reactangel Area = " << Area << endl;
}
*/


// 17

/*

void ReadNumbers(float &A,float &H)
{
	cout << "Enter A : \n";
	cin >> A;
	cout << "Enter H : \n";
	cin >> H;
}

float TriangleArea(float A, float H)
{
	return (A / 2) * H;
}

void PrintResult(float Area)
{
	cout << "Triangle Area = " << Area << endl;
}

*/

// #18

/*
float ReadRadious() {
	float R;
	cout << "Please enter radious : \n";
	cin >> R;
	return R;
}

float CircleArea(float R)
{
	const float PI = 3.141592653589793238462643383279502884197;
	float Area = PI * pow(R, 2);
	return Area;
}

void PrintResult(float Area) {
	cout << "Circle Area = " << Area << endl;
}
*/

// #19

/*

float ReadDiameter()
{	
	float D;
	cout << "Enter Diameter: \n";
	cin >> D;
	return D;
}

float DiameterArea(float D)
{
	const float PI = 3.141592653589793238462643383279502884197;
	float Area = (PI * pow(D, 2)) / 4;
	return Area;
}

void PrintResult(float Area)
{
	cout << "Circle Area = " << Area << endl;
}

*/

// #20

float ReadSquareSide()
{
	float A;
	cout << "Enter Square Side: \n";
	cin >> A;
	return A;
}

float CircleAreaInscribedInSquare(float A)
{
	const float PI = 3.141592653589793238462643383279502884197;
	float Area = (PI * pow(A, 2)) / 4;
	return Area;
}

void PrintResult(float Area) {
	cout << "Circle Area is = " << Area << endl;
}

int main()
{
//	float A, D;
//	ReadNumbers(A, D);
//	PrintResult(RectangleAreaBySideAndDiagonal(A, D));

//	float A, H;
//	ReadNumbers(A, H);
//	PrintResult(TriangleArea(A, H));


//	PrintResult(CircleArea(ReadRadious()));


//	PrintResult(DiameterArea(ReadDiameter()));

	PrintResult(CircleAreaInscribedInSquare(ReadSquareSide()));

}

