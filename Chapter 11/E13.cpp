#include "std_lib_facilities.h"

string Reverse_Words(const string& line)
{
	istringstream iss{ line };
	string buffer;
	string reversedLine{""};

	while (iss >> buffer)
	{
		if (reversedLine != "")
		{
			reversedLine.insert(0, buffer + ' ');
		}
		else
		{
			reversedLine.insert(0, buffer);
		}
	}

	return reversedLine;
}

int main()
{
	string testString{ "blue Norwegian Parrot" };

	string reversedLine{ Reverse_Words(testString) };

	cout << testString << '\n' << reversedLine << '\n';

	return 0;
}