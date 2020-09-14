#include "LongDate.h"

LongDate::LongDate() : epoch_time{ 0 }{}

LongDate::LongDate(unsigned short year, unsigned short month, unsigned short day) : epoch_time{ 0 }
{

	if (year < 1970) throw exception("Invalid Date");

	for (int i = 1970; i < year; i++)
	{
		epoch_time += IsLeapYear(i) ? DaysPerLeapYear * SecondsPerDay : DaysPerYear * SecondsPerDay;
	}

	for (int i = 0; i < month - 2; i++)
	{
		int calendar = IsLeapYear(year);
		epoch_time += DaysInAMonth[calendar][month] * SecondsPerDay;
	}
	epoch_time += day * SecondsPerDay;
}

void LongDate::AddDays(unsigned int days)
{
	epoch_time += days * SecondsPerDay;
}

void LongDate::AddSeconds(unsigned long long seconds)
{
	epoch_time += seconds;
}

long LongDate::GetDay()
{
	return epoch_time / SecondsPerDay;
}

bool LongDate::IsLeapYear(int year)
{
	return (!(year % 4 && (year % 100 || !year % 400)));
}

ostream& operator<<(ostream& o, LongDate& d)
{
	return o << d.epoch_time;
}

bool operator<(LongDate& a, LongDate& b)
{
	return a.epoch_time < b.epoch_time;
}

bool operator>(LongDate& a, LongDate& b)
{
	return a.epoch_time > b.epoch_time;
}

bool operator==(LongDate& a, LongDate& b)
{
	return a.epoch_time == b.epoch_time;
}

bool operator!=(LongDate& a, LongDate& b)
{
	return a.epoch_time != b.epoch_time;
}

bool operator<=(LongDate& a, LongDate& b)
{
	return a.epoch_time <= b.epoch_time;
}

bool operator>=(LongDate& a, LongDate& b)
{
	return a.epoch_time >= b.epoch_time;
}

LongDate operator+(LongDate& a, LongDate& b)
{
	LongDate date{};
	date.epoch_time = a.epoch_time + b.epoch_time;
	return date;
}

LongDate operator-(LongDate& a, LongDate& b)
{
	LongDate date{};
	date.epoch_time = a.epoch_time - b.epoch_time;
	if (date.epoch_time < 0)
	{
		date.epoch_time = 0;
	}
	return date;
}
