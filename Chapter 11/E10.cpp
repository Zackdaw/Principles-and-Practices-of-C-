#include "std_lib_facilities.h"

vector<string> Split_String(const string& s)
{
	istringstream iss;
	iss.str(s);
	string buffer{ "" };

	vector<string> strings{ };

	while (iss >> buffer)
	{
		strings.push_back(buffer);
	}

	return strings;
}

int main()
{
	string testString{ "The quick brown fox jumped over the fence." };
	vector<string> splitStrings{};

	splitStrings = Split_String(testString);

	for (auto x : splitStrings)
	{
		cout << x << '\n';
	}

	return 0;
}