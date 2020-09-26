#include "E5_Header.h"

Month::Month() : name{ "" }, length{ 0 }, days{}{};

Month::Month(string name, int length) : name{ name }, length{ length }
{
	for (int i = 1; i <= length; i++)
	{
		days.push_back(Day{ i });
	}
}

istream& operator >> (istream& i, Month& m)
{
	char ch;
	if (i >> ch && ch == '<')
	{
		string tag;
		i >> tag;
		if (tag == "Month=")
		{
			i >> m.name;
		}

		i >> tag;
		if (tag == "Length=")
		{
			i >> m.length;
		}
	}
	if (i >> ch && ch != '>')
	{
		throw exception("Invalid closure.");
	}

	for (int j = 0; j < m.length; j++)
	{
		Day d;
		i >> d;
		m.days.push_back(d);
	}

	return i;
};

ostream& operator << (ostream& o, Month& m)
{
	o << "<Month= " << m.name << " Length= " << m.length << " >\n";
	for (Day d : m.days)
	{
		o << d <<'\n';
	}

	return o;
}