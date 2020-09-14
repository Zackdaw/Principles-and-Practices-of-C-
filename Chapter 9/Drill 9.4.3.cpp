#include "std_lib_facilities.h"

class LongDate
{
	int y, m, d;
public:
	LongDate(int y, int m, int d);
	void add_day(int n);
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
};

LongDate::LongDate(int y, int m, int d) : y(y), m(m), d(d) 
{
	if (y < 0 || m > 12 || d > 31)
	{
		error("Date is out of range.");
	}
}

void LongDate::add_day(int n)
{
	d++;
	if (d > 31)
	{
		d = 1;
		if (m == 12)
		{
			m = 1;
			y++;
		}
		else
		{
			m++;
		}
	}
}

int main()
{
	try
	{
		LongDate today(2005, 12, 31);
		cout << "Day: " << today.day() << "\nMonth: " << today.month() << "\nYear: " << today.year();
		cout << "\n";
		today.add_day(1);
		cout << "Day: " << today.day() << "\nMonth: " << today.month() << "\nYear: " << today.year();
	}
	catch (const exception& e)
	{
		cout << e.what();
	}

	return 0;
}