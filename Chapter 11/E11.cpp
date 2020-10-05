#include "std_lib_facilities.h"

vector<string> Split_String(const string& s, const string& w)
{
	char charBuffer{};
	string wordBuffer{};

	vector<string> strings{ };

	for (char c : s)
	{
		if (isspace(c) || (ispunct(c) && c != '\''))
		{
			strings.push_back(wordBuffer);
			wordBuffer = "";
		}
		else 
		{
			wordBuffer += c;
			for (char x : w)
			{
				if (c == x)
				{
					strings.push_back(wordBuffer);
					wordBuffer = "";
				}
			}
		}
	}

	return strings;
}

int main()
{
	string testString{ "The quick brown fox jumped over the fence." };
	vector<string> splitStrings{};

	splitStrings = Split_String(testString, "o");

	for (auto x : splitStrings)
	{
		cout << x << '\n';
	}

	return 0;
}