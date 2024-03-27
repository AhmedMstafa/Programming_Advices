#include <iostream>
using namespace std;

enum enCompareDates { Before = -1, Equal = 0, After = 1 };

struct stDate {
    short Year;
    short Month;
    short Day;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
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

stPeriod ReadPeriod() {
    stPeriod Period;
    cout << "\nEnter Start Date:\n\n";
    Period.StartDate = ReadDate();
    cout << "\nEnter End Date:\n\n";
    Period.EndDate = ReadDate();
    return Period;
}

short ReadVacationDays() {
    short VacationDay = 0;
    cout << "Please Enter Vacation Day? ";
    cin >> VacationDay;
    return VacationDay;
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


bool IsDateOneBeforeDateTwo(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : 0) : 0);
}

bool IsDateOneEqualDateTwo(stDate Date1, stDate Date2) {
    return (Date1.Day == Date2.Day) ? ((Date1.Month == Date2.Month) ? Date1.Year == Date2.Year : 0) : 0;
}

bool IsDateOneAfterDateTwo(stDate Date1, stDate Date2) {
    return (!IsDateOneBeforeDateTwo(Date1, Date2)) && (!IsDateOneEqualDateTwo(Date1, Date2));
}

short CompareDates(stDate Date1, stDate Date2) {

    if (IsDateOneBeforeDateTwo(Date1, Date2))
        return enCompareDates::Before;

    if (IsDateOneEqualDateTwo(Date1, Date2))
        return enCompareDates::Equal;

    return enCompareDates::After;
}


bool IsDateInPeriod(stDate Date, stPeriod Period1) {

    return !(
        CompareDates(Date, Period1.StartDate) == enCompareDates::Before
        ||
        CompareDates(Date, Period1.EndDate) == enCompareDates::After
        );

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

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {
    if (
        CompareDates(Period2.EndDate, Period1.StartDate) == enCompareDates::Before
        ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enCompareDates::After
        )
        return false;
    else
        return true;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDate = false) {
    short Day = 0;

    while (IsDateOneBeforeDateTwo(Date1, Date2))
    {
        Date1 = IncreaseDateByOneDay(Date1);
        Day++;
    }
    return (IncludeEndDate) ? ++Day : Day;
}

int CalculatePeriodLength(stPeriod Period, bool IncludeEndDate = false) {
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}

int CountOverlapDays(stPeriod Period1, stPeriod Period2) {

    int Period1Length = CalculatePeriodLength(Period1, true);
    int Period2Length = CalculatePeriodLength(Period2, true);
    int OverlapDays = 0;

    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    if (Period1Length < Period2Length) {

    while (IsDateOneBeforeDateTwo(Period1.StartDate, Period1.EndDate)) {

        if (IsDateInPeriod(Period1.StartDate, Period2))
            OverlapDays++;

        Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
    }

    }
    else {

        while (IsDateOneBeforeDateTwo(Period2.StartDate, Period2.EndDate)) {

            if (IsDateInPeriod(Period2.StartDate, Period1))
                OverlapDays++;

            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }

    }

    return OverlapDays;
}

int main() {
    cout << "Enter Period 1:";
    stPeriod Period1 = ReadPeriod();
    
    cout << "\nEnter Period 2:";
    stPeriod Period2 = ReadPeriod();

    cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2) << endl;

    return 0;
}