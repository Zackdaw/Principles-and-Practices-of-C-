#pragma once
#include "std_lib_facilities.h"

class Point
{
public:
	Point(int x, int y);
	Point();

	friend ostream& operator<<(ostream& o, Point& p);
	friend istream& operator>>(istream& o, Point& p);

private:
	int x;
	int y;
};

ostream& operator<<(ostream& o, Point& p)
{
	return o <<'(' << p.x << "," << p.y << ')';
}

istream& operator>>(istream& is, Point& p)
{
	char ch;
	is >> ch;
	if (ch != '(')
	{
		is.unget();
		is.clear(ios::failbit);
		return is;
	}
	else
	{
		int x;
		is >> x;

		is >> ch;
		if (ch != ',')
		{
			is.unget();
			is.clear(ios::failbit);
			return is;
		}
		is >> ch;
		if (ch != ' ')
		{
			is.unget();
		}

		int y;
		is >> y;

		is >> ch;
		if (ch != ')')
		{
			is.unget();
			is.clear(ios::failbit);
			return is;
		}

		p.x = x;
		p.y = y;

		return is;
	}
}


Point::Point(int x, int y) : x{ x }, y{ y }
{}

Point::Point() : x{ 0 }, y{ 0 }
{}