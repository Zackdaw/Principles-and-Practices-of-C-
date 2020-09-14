#include "Q5-9.h"

Date::Date() : year{ 0 }, month{ 0 }, day{ 0 }, leap{ false }
{
}

Date::Date(short y, short m, short d) : year{ y }, month{ m }, day{ d }, leap{ false }
{
	Determine_Leap_Year();
	Validate_Date();
}

void Date::Determine_Leap_Year()
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0 && year % 400 != 0)
		{
			leap = false;
		}
		else
		{
			leap = true;
			cout << to_string(year) + " is a Leap Year!\n";
		}
	}
}

void Date::Validate_Date()
{
	if (month > 12 || month < 1)
	{
		throw exception("Invalid Month");
	}

	if (day < 0)
	{
		throw exception("Invalid Day");
	}

	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		if (day > 31)
		{
			throw exception("Invalid day for: " + month);
			break;
		}
	}
	case 4: case 6: case 9: case 11 :
	{
		if (day > 30)
		{
			throw exception("Invalid day for: " + month);
			break;
		}
	}
	case 2:
	{
		if ((leap && day > 29) || (!leap && day >28))
		{
			throw exception("Invalid day for: " + month);
		}
	}

	}
}


void Date::AddDays(int days)
{
	day += days;

	bool running = true;

	while (running)
	{
		switch (month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10:
		{

			if (day > 31)
			{
				month++;
				day -= 31;
				continue;
			}
			else
			{
				running = false;
				break;
			}
		}
		case 4: case 6: case 9: case 11:
		{
			if (day > 30)
			{
				month++;
				day -= 30;
				continue;
			}
			else
			{
				running = false;
				break;
			}
		}
		case 2:
		{
			if (leap && day > 29)
			{
				month++;
				day -= 29;
				continue;
			}
			else if (!leap && day > 28)
			{
				month++;
				day -= 28;
				continue;
			}
			else
			{
				running = false;
				break;
			}
		}
		case 12:
		{
			if (day > 31)
			{
				year++;
				month = 1;
				day -= 31;
				Determine_Leap_Year();
				continue;
			}
			else
			{
				running = false;
				break;
			}
		}
		}
	}
}


ostream& operator<<(ostream& o, Date date)
{
	string outString = to_string(date.year) + '-' + to_string(date.month) + '-' + to_string(date.day);

	return o << outString;
}

Date operator+(Date a, int b) 
{
	Date c = a;
	c.AddDays(b);
	return c;
}

bool operator<(Date a, Date b)
{
	if (a.year < b.year)
	{
		return true;
	}
	else if (a.year == b.year)
	{
		if (a.month < b.month)
		{
			return true;
		}
		else if (a.month == b.month && a.day < b.day)
		{
			return true;
		}
	}
	return false;
}

bool operator>(Date a, Date b)
{
	if (a.year > b.year)
	{
		return true;
	}
	else if (a.year == b.year)
	{
		if (a.month > b.month)
		{
			return true;
		}
		else if (a.month == b.month && a.day > b.day)
		{
			return true;
		}
	}
	return false;
}

bool operator==(Date a, Date b)
{
	return (a.year == b.year && a.month == b.month && a.day == b.day);
}

bool operator!=(Date a, Date b)
{
	return (a.year != b.year && a.month != b.month && a.day != b.day);
}
