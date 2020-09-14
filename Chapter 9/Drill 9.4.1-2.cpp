#include "std_lib_facilities.h"

struct LongDate
{
	int y;
	int m;
	int d;
};

LongDate Create_Day(int y, int m, int d)
{
	LongDate day{ 1, 1, 1 };
	if (y < 0)
	{
		error("Year out of range\n");
	}
	else
	{
		day.y = y;
	}
	if (m < 1 || m > 12)
	{
		error("Month out of range\n");
	}
	else
	{
		day.m = m;
	}	
	if (d < 1 || d > 31)
	{
		error("Day out of range\n");
	}
	else
	{
		day.d = d;
	}

	return day;
}

void Add_Day(LongDate& currentDate)
{
	currentDate.d++;
	if (currentDate.d > 31)
	{
		currentDate.d = 1;
		if (currentDate.m == 12)
		{
			currentDate.m = 1;
			currentDate.y++;
		}
		else
		{
			currentDate.m++;
		}
	}
}

int main()
{
	try 
	{
		LongDate today = Create_Day(2005, 14, 31);
		cout << "Day: " << today.d << "\nMonth: " << today.m << "\nYear: " << today.y;
		cout << "\n";
		Add_Day(today);
		cout << "Day: " << today.d << "\nMonth: " << today.m << "\nYear: " << today.y;
	}
	catch (const exception& e)
	{
		cout << e.what();
	}

	return 0;
}