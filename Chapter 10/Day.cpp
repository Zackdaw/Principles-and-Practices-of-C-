#include "E5_Header.h"

istream& operator >> (istream& i, Day& d) 
{
	char ch;
	if (i >> ch && ch == '<')
	{
		string tag;
		i >> tag;
		if (tag == "Day=")
		{
			i >> d.number;
		}
	}
	if (i >> ch && ch != '>')
	{
		throw exception("Invalid closure.");
	}

	return i;

}

ostream& operator << (ostream& o, Day& d)
{
	return o << "< Day= " << d.number << " >";
}