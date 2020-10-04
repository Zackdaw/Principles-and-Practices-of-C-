#include "std_lib_facilities.h"
#include "E7.h"

const vector<std::pair<std::string, std::string>> Definitions
{ 
	pair{"cant", "cannot"}, {"can't", "cannot"}, 
	pair{"dont", "do not"}, {"don't", "do not"} 
};

string sampleLine{ "Hello, this is a sample text. It is the best! I don't care what anybody says, you can't make a better program." };

void Check_Word(string& word)
{
	for (pair<string, string> forbiddenWord : Definitions)
	{
		if (word == forbiddenWord.first)
		{
			word = forbiddenWord.second;
		}
	}
}

string Replace_Words(string line)
{
	char punct{};
	string word{ "" }, modifiedLine{ "" };
	for (auto c : line)
	{

		if (isspace(c) || (ispunct(c) && c != '\''))
		{
			Check_Word(word);
			modifiedLine += word + c;
			word = "";
		}
		else
		{
			word += isupper(c) ? tolower(c) : c;
		}
	}

	return modifiedLine;
}

int main()
{
	cout << sampleLine << '\n';
	string modifiedSampleLine{ "" };
	modifiedSampleLine = Replace_Words(sampleLine);
	cout << modifiedSampleLine;
}