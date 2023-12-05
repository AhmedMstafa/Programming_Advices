

#include <iostream>
using namespace std;

enum Gender {Male = 0, Female = 1 };
enum FvColor{Red, Green , Blue, Yellow};
enum MaritalStatus {Single = 0, Married = 1};
int main()
{
    Gender MyGender;
    MyGender = Gender::Male;
    FvColor MyFvColor;
    MyFvColor = FvColor::Blue;
    MaritalStatus MyMaritalStatus;
    MyMaritalStatus = MaritalStatus::Single;
    cout << "*********************/n";
    cout << "Name Ahmed Mostafa Mansour" << endl;
    cout << "Age: 25 Years" << endl;
    cout << "Country: Egypt" << endl;
    cout << "City: Assiut" << endl;
    cout << "Monthly Salary: 3000" << endl;
    cout << "Yearly Salary: 12000" << endl;
    cout << "Gender: " << MyGender << endl;
    cout << "Marrid: " << MyMaritalStatus << endl;
    cout << "My Favorite Color: " << MyFvColor << endl;
    cout << "*********************/n";

    return 0;

}

