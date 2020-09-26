#pragma once
#include "std_lib_facilities.h"

struct Reading
{
	int hour;
	double temperature;

	friend istream& operator>>(istream& i, Reading& r);
	friend ostream& operator<<(ostream& o, Reading r);
};

istream& operator>>(istream& i, Reading& r)
{
	char ch;

	i >> ch;
	if (ch != '(')
	{
		i.unget();
		i.clear(ios::failbit);
		return i;
	}
	else
	{
		i >> r.hour;
	}	
	
	i >> ch;
	if (ch != ',')
	{
		i.unget();
		i.clear(ios::failbit);
		return i;
	}
	else
	{
		i >> r.temperature;
	}

	i >> ch;
	if (ch != ')')
	{
		i.unget();
		i.clear(ios::failbit);
		return i;
	}
	return i;
}

ostream& operator<<(ostream& o, Reading r)
{
	return o << "(" << r.hour << "," << r.temperature << ')';
}
