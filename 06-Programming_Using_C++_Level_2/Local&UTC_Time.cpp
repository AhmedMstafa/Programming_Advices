#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	time_t t =  time(0);  // Get Time Now

	char* dt = ctime(&t);  // Convert In String Form
	cout << "Local date and time is : " << dt << "\n";

	tm* gmtm = gmtime(&t); // Converting Now To tm Struct For UTC date/time
	dt = asctime(gmtm);
	cout << "UTC date and time is: " << dt;
	
}
