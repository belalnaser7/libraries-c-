#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include "ClsString.h"
#include "Utility.h"
using namespace std;

class ClsDate
{
private:
    int day;
    int month;
    int year;

public:
    ClsDate()
    {
        time_t t = time(0); // get time now
        tm *now = localtime(&t);
        day = now->tm_mday;
        month = now->tm_mon + 1;
        year = now->tm_year + 1900;
    };
    ClsDate(string Date)
    {
        // the function of ClsString::printEachWordInNewLine() returns a vector of strings
        day = stoi(ClsString::printEachWordInNewLine(Date, "/")[0]);
        month = stoi(ClsString::printEachWordInNewLine(Date, "/")[1]);
        year = stoi(ClsString::printEachWordInNewLine(Date, "/")[2]);
    };
    ClsDate(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    };
    void setDay(int day)
    {
        this->day = day;
    };
    void setMonth(int month)
    {
        this->month = month;
    };
    void setYear(int year)
    {
        this->year = year;
    };
    int getDay()
    {
        return day;
    };
    int getMonth()
    {
        return month;
    };
    int getYear()
    {
        return year;
    };
    void printDate()
    {
        cout << day << "/" << month << "/" << year << endl;
        // is leap year
        if (LeapYear())
        {
            cout << "This year is leap year" << endl;
        }
        else
        {
            cout << "This year is not leap year" << endl;
        }
    };

    static int daysinmonth(int month, int year)
    {
        if (month == 2)
        {
            if (LeapYear(year))
                return 29;
            else
                return 28;
        }
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            return 31;
        else
            return 30;
    }
    int daysinmonth()
    {
        return daysinmonth(this->month, this->year);
    }

    static bool LeapYear(int year)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            return true;
        else
            return false;
    }

    bool LeapYear()
    {
        return LeapYear(this->year);
    }

    static int NumberOfDaysFromBeginingOfYear(ClsDate date)
    {
        int days = 0;

        for (size_t i = 1; i < date.month; i++)
        {
            days += daysinmonth(i, date.year);
        }
        return (days + date.day);
    }
    int NumberOfDaysFromBeginingOfYear()
    {
        return NumberOfDaysFromBeginingOfYear(*this);
    }

    static ClsDate GetDateAfterDays(ClsDate date, int NumberOfDays)
    {

        while (NumberOfDays > 0)
        {
            int daysInCurrentMonth = daysinmonth(date.month, date.year);

            if (date.day + NumberOfDays <= daysInCurrentMonth)
            {
                date.day += NumberOfDays;
                NumberOfDays = 0;
            }
            else
            {
                NumberOfDays -= (daysInCurrentMonth - date.day + 1);
                date.day = 1;
                date.month++;

                if (date.month > 12)
                {
                    date.month = 1;
                    date.year++;
                }
            }
        }
        return date;
    }

    ClsDate GetDateAfterDays(int NumberOfDays)
    {
        return GetDateAfterDays(*this, NumberOfDays);
    }

    static bool Isdate1Afterdate2(ClsDate date1, ClsDate date2)
    {
        if (date1.year > date2.year)
            return true;
        else if (date1.year == date2.year && date1.month > date2.month)
            return true;
        else if (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day)
            return true;
        else
            return false;
    }
    static bool Isdate1Beforedate2(ClsDate date2, ClsDate date1)
    {
        return !Isdate1Afterdate2(date1, date2);
    }
    static bool Isdate1Equaldate2(ClsDate date1, ClsDate date2)
    {
        return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
    }
    static bool IsDateBetweenDates(ClsDate date, ClsDate date1, ClsDate date2)
    {
       
        return (Isdate1Afterdate2(date, date1) && Isdate1Beforedate2(date2, date));
    }
};