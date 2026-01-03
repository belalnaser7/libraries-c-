#pragma once
#include<string>
#include<iostream>
#include "ClsDate.h"
#include "Utility.h"
using namespace std;
class clsInputValidate {
public:
  // static bool IsNumberBetween(int Number, int From, int To) {
  //   if (Number >= From && Number <= To)
  //     return true;
  //   else
  //     return false;
  // }

  // static bool IsNumberBetween(double Number, double From, double To) {
  //   if (Number >= From && Number <= To)
  //     return true;
  //   else
  //     return false;
  // }
  // عندي مشكله هنا الاسترينج مش بيتفق مع ال template
  static bool IsNumberBetween(string Number, string From, string To) {
    if (stoi(Number) >= stoi(From) && stoi(Number) <= stoi(To))
      return true;
    else
      return false;
  }
  template<typename T> // Template allows writing generic code that works with different data types
  static bool IsNumberBetween(T Number, T From, T To) {
    if (Number >= From && Number <= To)
      return true;
    else
      return false;
  }

 static int readnumber(string text) // دالة آمنة لقراءة العدد
{
    int number;
    cout << text;
    cin >> number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter an integer: ";
        cin >> number;
    }
    return number;
}
// static double readnumber(string text) // دالة آمنة لقراءة العدد
// {
//     double number;
//     cout << text;
//     cin >> number;
//     while (cin.fail())
//     {
//         cin.clear();
//         cin.ignore(1000, '\n');
//         cout << "Invalid input. Please enter an integer: ";
//         cin >> number;
//     }
//     return number;
// }

static int ReadIntNumberBetween(string text, int From, int To) // دالة آمنة لقراءة العدد
{
    int number;
    cout << text;
    cin >> number;
    while (cin.fail() || number < From || number > To)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter an integer between " << From << " and " << To << ": ";
        cin >> number;
    }
    return number;
}

static double ReadDoubleNumberBetween(string text, int From, int To) // دالة آمنة لقراءة العدد
{
    double number;
    cout << text;
    cin >> number;
    while (cin.fail() || number < From || number > To)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter an integer between " << From << " and " << To << ": ";
        cin >> number;
    }
    return number;
}
static bool IsDateBetweenDates(ClsDate date, ClsDate date1, ClsDate date2)
{
   return ClsDate::IsDateBetweenDates(date, date1, date2);
}


static int ReantNumber(string ErrorMessage="Invalid Number, Enter again\n")
	{
		int Number;
        cin>>Number;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << ErrorMessage ;
		}
		return Number;
	}
};