
#include <iostream>
using namespace std;

struct address
{
    short PhoneNumber;
    string Streat;
};

struct Customer
{
    string name,city, country;
    short age, MonthlySalary;
    int YearlySalary;
    char gender;
    bool married;
    address info;
};


int main()
{
    Customer Customer1;
    cout << "Enter Name : ";
    cin >> Customer1.name ;
    cout << "Enter Age : " ;
    cin >> Customer1.age ;
    cout << "Enter City : " ;
    cin >> Customer1.city ;
    cout << "Enter Country : " ;
    cin >> Customer1.country ;
    cout << "Enter  Monthly Salary : " ;
    cin >> Customer1.MonthlySalary ;
    cout << "Enter Yearly Salary : " ;
    cin >> Customer1.YearlySalary ;
    cout << "Enter Gender : " ;
    cin >> Customer1.gender ;
    cout << "Enter Mared : ";
    cin >> Customer1.married;
    cout << "Enter Phone Number : ";
    cin >> Customer1.info.PhoneNumber;
    cout << "Enter Streat : ";
    cin >> Customer1.info.Streat ;
    cout << endl;


    cout << "*****************************\n";
    cout << "Name: " <<  Customer1.name << endl;
    cout << "Age: " << Customer1.age << endl;
    cout << "City: " << Customer1.city << endl;
    cout << "Country " << Customer1.country << endl;
    cout << "Monthly Salary: " << Customer1.MonthlySalary << endl;
    cout << "Yearly Salary: " << Customer1.YearlySalary << endl;
    cout << "Gender: " << Customer1.gender << endl;
    cout << "Married: " << Customer1.married << endl;
    cout << "Phone Number: " << Customer1.info.PhoneNumber << endl;
    cout << "Steat: " << Customer1.info.Streat << endl;
    cout << "" << "*****************************\n";

}
