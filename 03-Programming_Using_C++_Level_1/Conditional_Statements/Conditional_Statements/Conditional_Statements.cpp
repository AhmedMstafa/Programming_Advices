
#include <iostream>
using namespace std;


// Home Work

struct Driver {
    int Age;
    bool HasDriverLicense;
};

int main()
{
    /*
    Driver Person;
    cout << "Enter Your Age" << endl;
    cin >> Person.Age;
    cout << "Are You Have Driver License? " << endl;
    cin >> Person.HasDriverLicense;
    if (Person.Age >= 21 && Person.HasDriverLicense) {
        cout << "Hired.";
    }
    else {
        cout << "Rejected.";
    }
    */

    /*
    int Mark;
    cout << "Enter The Mark: ";
    cin >> Mark;
    if (Mark >= 50) {
        cout << "PASS" << endl;
    }
    else {
        cout << "Fail" << endl;
    };
    */

    /*
    int Mark1, Mark2, Mark3, AVG;
    cout << "Enter Mark 1: " << endl;
    cin >> Mark1;
    cout << "Enter Mark 2: " << endl;
    cin >> Mark2;
    cout << "Enter Mark 3: " << endl;
    cin >> Mark3;
    AVG = (Mark1 + Mark2 + Mark3) / 3;
    if (AVG >= 50) {
        cout << "PASS" << endl;
    }
    else {
        cout << "Fail" << endl;
    }
    */

    /*
    int Age;
    cout << "Enter Age: ";
    cin >> Age;
    bool Result = (Age >= 18 && Age <= 45);
    if (Result) {
        cout << "Valid Age \n";
    }
    else {
        cout << "Invalid Age \n";
    }
    */

    /*
    */
    int PIN, UserBalance = 7500;
    cout << "Enter Your Password: ";
    cin >> PIN;
    if (PIN == 1234) {
        cout <<  "Your Balance is: " << UserBalance << endl;
    }
    else {
        cout << "Wrong PIN \n";
        main();
    }

    return 0;
}  

