#include "std_lib_facilities.h"

const vector<std::pair<std::string, std::string>> Definitions
{
	pair{"dungaree", "heavy coarse durable twilled cotton, usually coloured."},
	pair{"wuffler", "agricultural machine for turning and fluffing bales of hay."}
};

void Check_Word(string& word)
{
	for (pair<string, string> definition : Definitions)
	{
		if (word == definition.first)
		{
			cout << "\nWord found: " << word << '\n';
			cout << definition.second <<'\n';
			return;
		}
	}
	cout <<'\n' << word << " is not found.\n";
}

string Replace_Words(string line)
{
	char punct{};
	string word{ "" }, modifiedLine{ "" };
	for (auto c : line)
	{

		if (isspace(c) || (ispunct(c) && c != '\''))
		{
			continue;
		}
		else
		{
			word += isupper(c) ? tolower(c) : c;
		}
	}

	Check_Word(word);

	return modifiedLine;
}

int main()
{
	string searchTerm{ "" };

	cout << "Please enter a word to look up:\n>";

	while (true)
	{
		cin >> searchTerm;
		if (searchTerm == "0")
		{
			break;
		}
		else
		{
			Replace_Words(searchTerm);
		}
		cout << "Please enter another term:\n>";
	}
}