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



stDate DecreaseDateByOneDay(stDate Date) {

    if (Date.Day == 1) {
        if (Date.Month == 1) {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
        }
    }
    else {
        Date.Day--;
    }

    return Date;
}

stDate DecreaseDateByXDays(stDate Date, int Days) {
    for (int i = 1; i <= Days; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date) {
    return DecreaseDateByXDays(Date, 7);
}

stDate DecreaseDateByXWeeks(stDate Date, short Weeks) {
    for (short i = 1; i <= Weeks; i++) {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 1) {
        Date.Month = 12;
        Date.Year--;
    }
    else {
        Date.Month--;
    }

    short NumberOfDays = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberOfDays) {
        Date.Day = NumberOfDays;
    }

    return Date;

}

stDate DecreaseDateByXMonths(stDate Date, short Months) {
    for (short i = 1; i <= Months; i++) {
        Date = DecreaseDateByOneMonth(Date);
   }
   return Date;
}

stDate DecreaseDateByOneYear(stDate Date) {
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears(stDate Date, short Years) {
    for (short i = 1; i <= Years; i++) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date ,short Years) {
    Date.Year -= Years;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date) {
    Date.Year -= 10;
    return Date;
}

stDate DecreaseDateByXDecades(stDate Date, short Decateds) {
    for (short i = 1; i <= Decateds * 10; i++) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date ,short Decades) {
    Date.Year -= 10 * Decades;
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date) {
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date) {
    Date.Year -= 1000;
    return Date;
}


int main() {

    stDate Date = ReadDate();


    Date = DecreaseDateByOneDay(Date);
    cout << "01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDays(Date, 10);
    cout << "02-Adding 10 day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneWeek(Date);
    cout << "03-Adding One Week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXWeeks(Date, 10);
    cout << "04-Adding 10 Weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMonth(Date);
    cout << "05-Adding One Month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXMonths(Date, 5);
    cout << "06-Adding 5 Months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneYear(Date);
    cout << "07-Adding One Year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYears(Date, 10);
    cout << "08-Adding 10 Years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "09-Adding 10 Years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneDecade(Date);
    cout << "10-Adding One Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "11-Adding 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "12-Adding 10 Decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneCentury(Date);
    cout << "13-Adding One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMillennium(Date);
    cout << "14-Adding One Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

}