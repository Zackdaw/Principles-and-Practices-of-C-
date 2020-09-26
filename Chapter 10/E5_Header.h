#pragma once
#include "std_lib_facilities.h";

struct Day
{
	int number;

	friend istream& operator >> (istream& o, Day& d);
	friend ostream& operator << (ostream& o, Day& d);

};

class Month
{
public:
	string name;
	int length;
	vector<Day> days;

	Month(string name, int length);
	Month();

	friend istream& operator >> (istream& o, Month& d);
	friend ostream& operator << (ostream& o, Month& d);

private:

};

struct Year
{
	int date;
	vector<Month> months;
};