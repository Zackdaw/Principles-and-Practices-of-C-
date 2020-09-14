#pragma once
#include "std_lib_facilities.h"

static const unsigned long long SecondsPerDay = 86400;
static const unsigned long long DaysPerWeek = 7;
static const unsigned long long DaysPerYear = 365;
static const unsigned long long DaysPerLeapYear = 366;

class LongDate
{
public:
	LongDate();
	LongDate(unsigned short year, unsigned short month, unsigned short day);
	long GetDay();

	bool IsLeapYear(int year);
	void AddDays(unsigned int days);
	void AddSeconds(unsigned long long seconds);

	void GetReadableDate()
	{
		int year = 1970;
		int daysPassed = epoch_time / SecondsPerDay;


	}

#pragma region Operator Overloads
	friend ostream& operator<<(ostream& o, LongDate& d);
	friend bool operator<(LongDate& a, LongDate& b);
	friend bool operator>(LongDate& a, LongDate& b);
	friend bool operator==(LongDate& a, LongDate& b);
	friend bool operator!=(LongDate& a, LongDate& b);
	friend bool operator<=(LongDate& a, LongDate& b);
	friend bool operator>=(LongDate& a, LongDate& b);
	friend LongDate operator+(LongDate& a, LongDate& b);
	friend LongDate operator-(LongDate& a, LongDate& b);

#pragma endregion

private:
	const int DaysInAMonth[2][12]
	{ 
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
	};
	unsigned long long epoch_time;
};