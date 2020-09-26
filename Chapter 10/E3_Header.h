#pragma once
#include "std_lib_facilities.h"

struct Reading
{
	int hour;
	double temperature;

	Reading(int hour, double temperature);
	Reading(int hour, double temperature, char unit);

	friend istream& operator >> (istream& i, Reading& r);
	friend ostream& operator << (ostream& o, Reading r);

	inline bool operator < (const Reading& r);
	inline bool operator > (const Reading& r);
};

Reading::Reading(int hour, double temperature) : hour{ hour }, temperature{ temperature }{};

Reading::Reading(int hour, double temperature, char unit) : hour {hour}, temperature{0}
{
	switch (unit)
	{
	case 'K': case 'k':
		this->temperature = temperature;
		break;
	case 'C': case 'c':
		this->temperature = temperature + 273.15;
		break;
	case 'F' : case 'f':
		this->temperature = (temperature + 459.67) * (0.55555555556);
		break;
	default:
		cout << "Invalid Unit. Resetting to 0";
		break;
	}

	if (this->temperature < 0)
	{
		cout << "\nWARNING: Invalid temperature entered. Defaulting to 0.\n";
		this->temperature = 0;
	}
}

istream& operator >> (istream& i, Reading& r)
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

inline bool Reading::operator<(const Reading& r)
{
	return temperature < r.temperature;
}
inline bool Reading::operator>(const Reading& r)
{
	return temperature > r.temperature;
}