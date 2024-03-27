#pragma warning(disable: 4996)
#include <iostream>
#include <ctime>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

short ReadYear() {
    short Year;
    cout << "Please Enter a Year? ";
    cin >> Year;
    return Year;
}


short ReadMonth() {
    short Month;
    cout << "Please Enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadDay() {
    short Day;
    cout << "Please Enter a Day? ";
    cin >> Day;
    return Day;
}

stDate ReadDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsLeapYear(short Year) {
    return !(Year % 400) || ((Year % 100) && !(Year % 4));
}

short NumberOfDaysInMonth(short Year, short Month) {
    if (Month < 1 || Month > 12)
        return 0;

    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];

}


bool IsLastDayInMonth(short Year, short Month, short Day) {
    return (Day == NumberOfDaysInMonth(Year, Month));
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date) {

    if (IsLastDayInMonth(Date.Year, Date.Month, Date.Day)) {

        if (IsLastMonthInYear(Date.Month)) {
            Date.Year++;
            Date.Month = 1;
            Date.Day = 1;
        }
        else {
            Date.Month++;
            Date.Day = 1;
        }

    }
    else {
        Date.Day++;
    }

    return Date;
}

stDate IncreaseDateByXDays(stDate Date, int NumberOfDays) {
    for (int i = 1; i <= NumberOfDays; i++) {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date ) {
    for (int i = 1; i <= 7; i++) {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, short NumberOfWeeks) {
    for (short i = 1; i <= NumberOfWeeks; i++) {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 12) {
        Date.Month = 1;
        Date.Year++;
    }
    else {
        Date.Month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate IncreaseDateByXMonths(stDate Date, short NumberOfMonths) {
    for (short i = 1; i <= NumberOfMonths; i++) {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate IncreaseDateByOneYear(stDate Date) {
    Date.Year++;
    return Date;
}

stDate IncreaseDateByXYears(stDate Date, short NumberOfYears) {
    for (short i = 1;i <= NumberOfYears; i++) {
        Date = IncreaseDateByOneYear(Date);
   }
    return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short NumberOfYears) {
    Date.Year += NumberOfYears;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {
    Date.Year += 10;
    return Date;
}

stDate IncreaseDateByXDecades(stDate Date, short NumberOfDecades) {
    for (short i = 1; i <= NumberOfDecades * 10; i++) {
     Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades) {
    Date.Year += NumberOfDecades * 10;
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date) {
    Date.Year += 100;
    return Date;
}

stDate IncreaseDateByOneMillennium(stDate& Date) {
    Date.Year += 1000;
    return Date;
}


int main() {

    stDate Date = ReadDate();

    cout << "\nDate After: \n" << endl;

    Date = IncreaseDateByOneDay(Date);
    cout << "01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDays(Date,10);
    cout << "02-Adding 10 day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneWeek(Date);
    cout << "03-Adding One Week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXWeeks(Date,10);
    cout << "04-Adding 10 Weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMonth(Date);
    cout << "05-Adding One Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXMonths(Date,5);
    cout << "06-Adding 5 Months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneYear(Date);
    cout << "07-Adding One Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYears(Date,10);
    cout << "08-Adding 10 Years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYearsFaster(Date, 10);
    cout << "09-Adding 10 Years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneDecade(Date);
    cout << "10-Adding One Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecades(Date, 10);
    cout << "11-Adding 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecadesFaster(Date, 10);
    cout << "12-Adding 10 Decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneCentury(Date);
    cout << "13-Adding One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMillennium(Date);
    cout << "14-Adding One Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    return 0;
}