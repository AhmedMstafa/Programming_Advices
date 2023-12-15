
#include <iostream>
using namespace std;

int main()
{
    // Home Work 

    cout << "12 >= 12 = " << (12 >= 12) << endl;
    cout << "12 > 7 = " << (12 > 7) << endl;
    cout << "8 <  6 = " << (8 < 6) << endl;
    cout << "8 == 8 = " << (8 == 8) << endl;
    cout << "12 <= 12 = " << (12 <= 12) << endl;
    cout << "7 > 5 = " << (7 > 5) << endl;
    cout << "12 > 7 = " << (12 > 7) << endl << endl;
    
    cout << "Not(12 >=12) = " << !(12 >= 12) << endl;
    cout << "Not(12 > 7) = " << !(12 < 7) << endl;
    cout << "Not(8 < 6) = " << !(8 < 6) << endl;
    cout << "Not(8 = 8) = " << !(8 == 8) << endl;
    cout << "Not(12 <= 12) = " << !(12 <= 12) << endl;
    cout << "Not(7 = 5) = " << !(7 == 5) << endl << endl;

    cout << "1 AND 1 = " << (1 && 1) << endl;
    cout << "True AND 0 = " << (true && 0) << endl;
    cout << "0 OR 1 = " << (0 || 1) << endl;
    cout << "0 OR 0 = " << (0 || 0) << endl;
    cout << "Not 0 = " << !0 << endl;
    cout << "Not(1 OR 0) = " << !(1 || 0) << endl << endl;

    cout << "(7 = 7) and (7 > 5) = " << (7 == 7 && 7 > 5) << endl;
    cout << "(7 = 7) and (7 < 5) = " << (7 == 7 && 7 < 5) << endl;
    cout << "(7 = 7) OR (7 < 5) = " << (7 == 7 || 7 < 5) << endl;
    cout << "(7 < 7) OR (7 > 5) = " << (7 < 7 || 7 > 5) << endl;
    cout << "NOT(7 = 7) and (7 > 5) = " << !(7 == 7 && 7 > 5) << endl;
    cout << "(7 = 7) and NOT(7 < 5) = " << (7 == 7 && !(7 < 5))<< endl << endl;

    // Home Wrok 2

    cout << "(5 > 6 and 7 = 7) OR (1 Or 0) = " << (5 > 6 && 7 == 7) << endl;
    cout << "NOT(5 > 6 and 7 = 7) OR (1 Or 0) = " << !((5 < 6 || 7 == 7) || (1 || 0)) << endl;
    cout << "NOT(5 > 6 and 7 = 7) OR NOT (1 Or 0) = " << !((5 > 6 && 7 == 7) || !(1 || 0)) << endl;
    cout << "NOT(5 < 6 OR 7 = 7) AND NOT (1 Or 0) = " << !((5 < 6 || 7 == 7) && !(1 || 0)) << endl;
    cout << "((5>6 && 7<=8) OR (8>1 and 4<=3)) AND True = " << (((5 > 6 && 7 <= 8) || (8 > 1 && 4 <= 3)) && true) << endl;
    cout << "((5>6 AND NOT(7<=8) AND (8>1 OR 4<=3) OR True) = " << ((5 > 6 && !(7 <= 8) && (8 > 1 || 4 <= 3)) || true) << endl << endl;


















    return 0;
}
