#include "std_lib_facilities.h"
#include <stack>

const string fileName{ "E12Test.txt" };

string ReverseLine(string& originalLine)
{
	string modifiedLine{};
	modifiedLine.reserve(originalLine.size());
	for (int i{ (int)originalLine.size() - 1 }; i >= 0; i--)
	{
		modifiedLine.push_back(originalLine[i]);
	}

	return modifiedLine;
}

int main()
{
	string buffer{};
	vector<string> forwardLines, backwardLines;

	std::stack<string> readLines{};

	ifstream ifs{ fileName };

	while (getline(ifs, buffer))
	{
		readLines.push(buffer);
		forwardLines.push_back(buffer);
	}

	while (!readLines.empty())
	{
		backwardLines.push_back(ReverseLine(readLines.top()));
		readLines.pop();
	}

	for (int i = 0; i < forwardLines.size(); i++)
	{
		cout << forwardLines[i] << '\n';
	}

	cout << "\n\n";

	for (int i = 0; i < backwardLines.size(); i++)
	{
		cout << backwardLines[i] << '\n';
	}

	return 0;
}