#include <iostream>

using namespace std;

int RandomeNumber(int From, int To) {
    int random = rand() % (To - From + 1) + From;
    return random;
}






int main()


{
    srand((unsigned)time(NULL));

    cout << RandomeNumber(20, 50) << endl;
    cout << RandomeNumber(20, 50) << endl;
    cout << RandomeNumber(20, 50) << endl;

}
