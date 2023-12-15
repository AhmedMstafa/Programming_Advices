#include <iostream>
#include <string>
using namespace std;


//#41

float ReadPositiveNumber(string Message)
{
	float Number;
	do {
	cout << Message << endl;
	cin >> Number;
	} while (Number <= 0);
	return Number;
}

/*
float HoursToDays(float NumbersOfHours)
{
	return (float)NumbersOfHours / 24;
}

float HoursToWeeks(float NumberOfHours)
{
	return (float)NumberOfHours / 24 / 7;
}

float DaysToWeeks(float NumberOfDays)
{
	return (float)NumberOfDays / 7 ;
}
*/

//#42

struct stTaskDuration {
	int Seconds, Minuts, Hours, Days;
};

/*
stTaskDuration ReadTaskDuration()
{
	stTaskDuration TaskDuration;
	TaskDuration.Seconds = ReadPositiveNumber("Enter Number Of Seconds: ");
	TaskDuration.Minuts = ReadPositiveNumber("Enter Number Of Minuts: ");
	TaskDuration.Hours = ReadPositiveNumber("Enter Number Of Hours: ") ;
	TaskDuration.Days = ReadPositiveNumber("Enter Number Of Days: ") ;
	return TaskDuration;

}

int TaskDurationInSeconds(stTaskDuration TaskDuration)
{
	int DurationInSeconds = 0;
	DurationInSeconds = TaskDuration.Days * 24 * 60 * 60;
	DurationInSeconds += TaskDuration.Hours * 60 * 60;
	DurationInSeconds += TaskDuration.Minuts * 60;
	DurationInSeconds += TaskDuration.Seconds;
	return DurationInSeconds;
}
*/

// #43
/*
stTaskDuration SeconsToTaskDuration(int TotalSeconds)
{
	stTaskDuration TaskDurtation;
	int const Days = 24 * 60 * 60;
	int const Hours = 60 * 60;
	int const Minuts = 60;
	
	int Remainder = 0;
	TaskDurtation.Days = floor(TotalSeconds / Days);
	Remainder = TotalSeconds % Days;
	TaskDurtation.Hours = floor(Remainder / Hours);
	Remainder = Remainder % Hours;
	TaskDurtation.Minuts = floor(Remainder / Minuts);
	Remainder = Remainder % Minuts;
	TaskDurtation.Seconds = Remainder;

	return TaskDurtation;
}

void PrintTaskDurationDetails(stTaskDuration TaskDuration)
{
	cout << endl << TaskDuration.Days << ":" << TaskDuration.Hours << ":" << TaskDuration.Minuts << ":" << TaskDuration.Seconds << endl;
}
*/

//#44


// enum enDayOfWeek  { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };

int ReadNumberInRange(int From, int To, string Message)
{
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number < From || Number > To);
	return Number;
}

/*

enDayOfWeek ReadDayOfWeek() {
	return (enDayOfWeek)ReadNumberInRange(1, 7, "Please Enter Day From 1 To 7");
}

string GetDayOfWeek(enDayOfWeek Day)
{
	switch (Day)
	{

		case enDayOfWeek::Sunday:
			return"Sunday";
		case enDayOfWeek::Monday:
			return "Monday";
		case enDayOfWeek::Tuesday:
			return "Tuesday";
		case enDayOfWeek::Wednesday:
			return "Wednesday";
		case enDayOfWeek::Thursday:
			return "Thursday";
			return  "Friday";
		case enDayOfWeek::Saturday:
			return  "Saturday";
	}
}
*/

enum enMonthOfYear {
	January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7,
	August = 8, September = 9, October = 10, November = 11, December = 12
};


enMonthOfYear ReadMonthOfYear()
{
	return (enMonthOfYear)ReadNumberInRange(1, 12, "Please Enter Number Of Month From 1 To 12");
}

string GetMonthOfYear(enMonthOfYear Month)
{
	switch (Month) {
	case enMonthOfYear::January:
		return "January";
	case enMonthOfYear::February:
		return "February";
	case enMonthOfYear::March:
		return "March";
	case enMonthOfYear::April:
		return "April";
	case enMonthOfYear::May:
		return "May";
	case enMonthOfYear::June:
		return "June";
	case enMonthOfYear::July:
		return "July";
	case enMonthOfYear::August:
		return "August";
	case enMonthOfYear::September:
		return "September";
	case enMonthOfYear::October:
		return "October";
	case enMonthOfYear::November:
		return "November";
	case enMonthOfYear::December:
		return "December";
	}
}



int main()
{
//	float NumberOfHours = ReadPositiveNumber("Please Enter Number Of Hours ?");
//	float NumberOfDays = HoursToDays(NumberOfHours);
//	float NumberOfWeeks = DaysToWeeks(NumberOfDays);
//	cout << endl;
//	cout << "Total Hours = " << NumberOfHours << endl;
//	cout << "Total Days = " << NumberOfDays << endl;
//	cout << "Total Weeks = " << HoursToWeeks(NumberOfHours) << endl;

	
//	cout << "Task Duration in Seconds: " << TaskDurationInSeconds(ReadTaskDuration()) << endl;

//	int TotalSeconds = ReadPositiveNumber("Please Enter Number Of Seconds :");
//	PrintTaskDurationDetails(SeconsToTaskDuration(TotalSeconds));

//	cout << "is " << GetDayOfWeek(ReadDayOfWeek()) << endl;


	cout << "is " << GetMonthOfYear(ReadMonthOfYear()) << endl;


	return 0;
}
