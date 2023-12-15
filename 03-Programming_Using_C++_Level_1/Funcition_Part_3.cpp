

#include <iostream>
using namespace std;

// Home Work 

void MyName() {
	cout << "\n#1\n";
	cout << "Ahmed \n";
}

void EnterYourName() {
	cout << "\n#2\n";
	string name;
	cout << "What is your Name? ";
	cin >> name;
	cout << "Your Name is : " << name << endl;
}

int OddEven(int num) {
	int odd;
	odd =  num % 2 == 0;
	return odd;
}

void Swap() {
	int num1, num2;
	cout << "Enter First Number: ";
	cin >> num1;
	cout << "Enter Second Number: ";
	cin >> num2;
	int temp = num1;
	num1 = num2;
	num2 = temp;
	cout << num1 << endl <<  num2 << endl;
}

int RectangleArea()
{
	int a, b, Area;
	cout << "Enter A ";
	cin >> a;
	cout << "Enter B ";
	cin >> b;
	Area = a * b;
	return Area;
}

float RectangelAreaDiagonal()
{
	float a, d, Area;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter d: ";
	cin >> d;
	Area = a * sqrt(pow(d, 2) - pow(a, 2));
	return Area;
};

float CircleArea()
{
	const float pt = 3.14;
	float r, Area ;
	cout << "Enter r: ";
	cin >> r;
	Area = pt * pow(r, 2);
	return Area;
}

float CircleDiameter()
{
	const float pt = 3.14;
	float D, Area;
	cout << "Enter D: ";
	cin >> D;
	Area = (pt * pow(D, 2)) / 4;
	return Area;
}

float CircleAreaInSquare()
{
	const float pt = 3.14;
	float A, Area;
	cout << "Enter A: ";
	cin >> A;
	Area = pt * pow((A / 2), 2);
	return Area;
}

float CircleAreaAlong()
{
	const float pi = 3.14;
	float l, Area;
	cout << "Enter l: ";
	cin >> l;
	Area = pow(l, 2) / (4 * pi);
	return Area;
}

float CircleAreaTriangel()
{
	const float pi = 3.14;
	float a, b, Area;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	Area = pi * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
	return Area;
};

float CircleAreaArbitrary()
{
	const float pi = 3.14;
	float a, b, c, p, Area;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;
	p = (a + b + c) / 2;
	Area = pi * pow(((a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2);
	return Area;
};

void PowerOf()
{
	int num, num1, num2, num3;
	cout << "Enter Number1: ";
	cin >> num;
	num1 = num * num, num2 = num * num * num , num3 = num * num * num * num;
	cout << num1 << endl << num2 << endl << num3;
};

int PowerOfM()
{
	int num, m, result;
	cout << "Enter Number: ";
	cin >> num;
	cout << "Enter Power Of Number: ";
	cin >> m;
	result = pow(num, m);
	return result;
};

int DurationInSeconds()
{
	int days, hours, minutes, seconds, TotalSeconds;
	cout << "Enter Days: ";
	cin >> days;
	cout << "Enter Hours: ";
	cin >> hours;
	cout << "Enter Minutes: ";
	cin >> minutes;
	cout << "Enter Seconds: ";
	cin >> seconds;
	 TotalSeconds = days * 24 * pow(60, 2) + hours * pow(60, 2) + minutes * 60 + seconds;
	return TotalSeconds;
}

void SecondsTo()
{
	int days = 24 * pow(60, 2), hours = pow(60, 2), minutes = 60, seconds, totalseconds, remainder;
	int numberofdays, numberofhours, numberofminutes;
	cout << "Enter Number Of Seconds: ";
	cin >> totalseconds;
	numberofdays = floor(totalseconds / days);
	remainder = totalseconds % days;
	numberofhours = floor(remainder / hours);
	remainder = remainder % hours;
	numberofminutes = floor(remainder / minutes);
	remainder = floor(remainder % minutes);
	seconds = remainder;
	cout << numberofdays << ":" << numberofhours << ":" << numberofminutes << ":" << seconds;

};

int main()
{
//	MyName();
//  EnterYourName();
//  cout << OddEven(10);
//	Swap();
//	cout << "Reactangle Area is: " << RectangleArea() << endl;
//	cout << "Rectangel Area Is: " << RectangelAreaDiagonal();
//	cout << "Circle Area is : " << CircleArea();
//	cout << "Circle Area Throgh Diameter is: " << CircleDiameter();
//	cout << "Cirle Area Inscribed in a Suare is: " << CircleAreaInSquare();
//	cout << "circle Area Along the Circumference is: " << CircleAreaAlong();
//	cout << "Circle Area Inscribed in an Isosceles Triangel is: " << CircleAreaTriangel() << endl;
//	cout << "Circle Area Circle Descibed Around an Arbitrary Triangle is:" << CircleAreaArbitrary() << endl;
//	PowerOf();
//	cout << PowerOfM();
//  cout << DurationInSeconds(); 
	SecondsTo();

	return 0;
}

