#include <iostream>
#include <string>
using namespace std;


int main()
{
	/*
	int Num1;
	double Num2 = 18.99;
//	Num1 = Num2;
//	Num1 = (int)Num2;
	Num1 = int(Num2);
	cout << Num1;
	string str = "123.456";
	int num_int = stoi(str);
	float num_float = stof(str);
	double num_double = stod(str);

	cout << "num_int = " << num_int << endl;
	cout << "num_float = " << num_float << endl;
	cout << "num_float = " << num_double << endl;

	int Num1 = 123;
	double Num2 = 18.99;
	string st1, st2;
	st1 = to_string(Num1);
	st2 = to_string(Num2);
	 
	cout << st1 << endl;
	cout << st2 << endl;
	*/

	// Home Work //

	// convert string st1 = "43.22" to double, float, and int.
	string st1 = "43.22";
	
	double st2;
	float st3;
	int st4;

	st2 = stod(st1);
	st3 = stof(st1);
	st4 = stoi(st1);

	cout << "string to double  " << st1 << endl;
	cout << "string to flota  " << st2 << endl;
	cout << "string to int  " << st3 << endl;

	// convert integer N1 = 20 to string;
	int N1 = 20;
	string N1_toString;
	N1_toString = to_string(N1);

	cout << "N1 To String " << N1_toString << endl;

	// convert double N2 = 33.5 to string.
	double N2 = 33.5;
	string N2_toString;
	N2_toString = to_string(N2);

	cout << "N2 To String " << N2_toString << endl;

	// Convert float N3 = 55.23 to string, and integer
	float N3 = 55.23;
	string N3_toString;
	N3_toString = to_string(N3);
	int N3_toInteger_Explicit, N3_toInteger_implicit, N3_toInteger_type_c;
	N3_toInteger_implicit = N3;
	N3_toInteger_type_c = (int)N3;
	N3_toInteger_Explicit = int(N3);

	cout << "N3 To String " << N3_toString << endl;
	cout << "N3 To Int implicit " << N3_toInteger_implicit << endl;
	cout << "N3 To Int Type C " << N3_toInteger_type_c << endl;
	cout << "N3 To Int Explicit " << N3_toInteger_Explicit << endl;


	return 0;



}

