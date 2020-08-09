#include "std_lib_facilities.h"

vector<int> ProcessString(const vector<string>& inputStrings)
{
	vector<int> stringLengths;
	for (string s : inputStrings)
	{
		stringLengths.push_back(s.length());
	}
	return stringLengths;
}

string FindShortestString(const vector<string>& inputStrings)
{
	int sLength{ INT32_MAX };
	string shortestString;

	for (string s : inputStrings)
	{
		if (s.length() < sLength)
		{
			shortestString = s;
			sLength = s.length();
		}
	}

	return shortestString;
}

string FindLongestString(const vector<string>& inputStrings)
{
	int sLength{ 0 };
	string longestString;

	for (string s : inputStrings)
	{
		if (s.length() > sLength)
		{
			longestString = s;
			sLength = s.length();
		}
	}

	return longestString;
}

string FindFirstLexicalString(const vector<string>& inputStrings)
{
	string first = inputStrings[0];
	for (string s : inputStrings)
	{
		if (s < first)
		{
			first = s;
		}
	}

	return first;
}
string FindLastLexicalString(const vector<string>& inputStrings)
{
	string last = inputStrings[0];
	for (string s : inputStrings)
	{
		if (s > last)
		{
			last = s;
		}
	}
	
	return last;
}

int main()
{
	vector<string> sequence = { "Hello", "Earthlings", "I", "Am", "Zack" };
	vector<int> lengths = ProcessString(sequence);

	for (int i = 0; i < sequence.size(); i++)
	{
		cout << sequence[i] << ": " << lengths[i] << '\n';
	}

	cout << "Shortest String: " << FindShortestString(sequence) << '\n';
	cout << "Longest String: " << FindLongestString(sequence) << '\n';
	cout << "First String: " << FindFirstLexicalString(sequence) << '\n';
	cout << "Last String: " << FindLastLexicalString(sequence) << '\n';

	return 0;
}

// This straightforward functionality is best split into multiple functions that all use a const-reference. This way,
// the functions require minimal copying but also still maintain a very elegant separation of functionality and each
// function is limited in scope to providing a single return value.
