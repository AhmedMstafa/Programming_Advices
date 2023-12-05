
#include <iostream>
using namespace std;

void ReadGreades(float x[3])
{
    cout << "Please Enter Garade1? \n";
    cin >> x[0];
    cout << "Please Enter Garade2? \n";
    cin >> x[1];
    cout << "Please Enter Garade3? \n";
    cin >> x[2];
    cout << "**************************\n";
};

float AvgGreads(float x[3])
{
    float Avg = (x[0] + x[1] + x[2]) / 3;
    return Avg;
}

int main()
{
    float x[3];
    ReadGreades(x);
    cout << "The average of grades is " << AvgGreads(x);
    return 0;

}
