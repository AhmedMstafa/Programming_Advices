#include <iostream>
using namespace std;

// #31

/*


int ReadNumber()
{
    int N; 
    cout << "Please Enter a Number: \n";
    cin >> N;
    return N;
}


void PowerOf2_3_4(int Number)
{
    int a, b, c;
    a = Number * Number;
    b = Number * Number * Number;
    c = Number * Number * Number;

    cout << a << " " << b << " " << c << endl;
}

*/



// #32

/*

int ReadNumber() {
    int Number;
    cout << "Enter a Number: \n";
    cin >> Number;
    return Number;
}


int ReadPower() {
    int Pow;
    cout << "Enter a Power: \n";
    cin >> Pow;
    return Pow;
}

int PowerOfM(int Number, int M) {
    if (M == 0) {
        return 1;
    }

    int P = 1;
    for (int i = 1; i <= M; i++) {
        P *= Number;
    }

    return P;
}

*/

// #33


/*
int ReadNumberInRange(int From, int To)
{
    int Number;
    do
    {
        cout << "Enter Number From " << From << " To " << To << endl;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
}

char GetGradeLetter(int Grade)
{
    if (Grade >= 90)
        return 'A';
    else if (Grade >= 80)
        return 'B';
    else if (Grade >= 70)
        return 'C';
    else if (Grade >= 60)
        return 'D';
    else if (Grade >= 50)
        return 'E';
    else
        return 'F';
}
*/

//#34

/*
int ReadTotalSales()
{
    int TotalSales;
    cout << "Please Enter a Total Sales ? " << endl;
    cin >> TotalSales;

    return TotalSales;
}

float GetComissionPercentage(float TotalSales)
{
    if (TotalSales >= 1000000)
        return 0.01;
    else if (TotalSales >= 500000)
        return 0.02;
    else if (TotalSales >= 100000)
        return 0.03;
    else if (TotalSales >= 50000)
        return 0.05;
    else
        return 0.00;

}



float CalculateCommission(float TotalSales)
{
    return GetComissionPercentage(TotalSales) * TotalSales;
}

*/

//#35

struct stPiggyBankContent
{
    int Pennies, Nickels, Dimes, Quarters, Dollars;
};

stPiggyBankContent ReadPiggyBankContetnet()
{
    stPiggyBankContent PiggyBankcontent;

    cout << "Please enter a Total Pinnnes? " << endl;
    cin >> PiggyBankcontent.Pennies;
    cout << "Please enter a Total Nickels? " << endl;
    cin >> PiggyBankcontent.Nickels;
    cout << "Please enter a Total Dimes? " << endl;
    cin >> PiggyBankcontent.Dimes;
    cout << "Please enter a Total Quarters? " << endl;
    cin >> PiggyBankcontent.Quarters;
    cout << "Please enter a Total Dollars? " << endl;
    cin >> PiggyBankcontent.Dollars;

    return PiggyBankcontent;
}

int CalculateTotalPennies(stPiggyBankContent PiggyBankContenet) {
    int TotalPennies = 0;

    TotalPennies = PiggyBankContenet.Pennies + PiggyBankContenet.Nickels * 5 + PiggyBankContenet.Dimes * 10 + PiggyBankContenet.Quarters * 25 + PiggyBankContenet.Dollars * 100;
    return TotalPennies;
}


int main()
{
// PowerOf2_3_4(ReadNumber());

//  cout << PowerOfM(ReadPower(), ReadNumber()) << endl;

//  cout << GetGradeLetter(ReadNumberInRange(10,100));

//    float TotalSales = ReadTotalSales();
//    cout <<  "Comission Percentage = " << GetComissionPercentage(TotalSales) << endl;
//    cout << "Total Comission = " << CalculateCommission(TotalSales); 


    int TotalPennies = CalculateTotalPennies(ReadPiggyBankContetnet());
    cout << endl << "Total Pennies = " << TotalPennies << endl;
    cout << endl << "Dotal Dollars = " << (float)TotalPennies / 100 << endl;
 
    return 0;


}

