#include "std_lib_facilities.h"

void Classify_Character(char& ch)
{
	if (isgraph(ch))
	{
		if (isalpha(ch))
		{
			cout << ch << "\tType: Alphabetic character\n";
			return;
		}
		else if (isdigit(ch))
		{
			cout << ch << "\tType: Numeric character\n";
			return;
		}
		else if (ispunct(ch))
		{
			cout << ch << "\tType: Punctuation character\n";
			return;
		}
	}
	else
	{
		cout << ch << '\n';
	}
}

int main()
{

	const string line{ "1: Hello World!" };

	for (char ch : line)
	{
		Classify_Character(ch);
	}

	cout << '\n';

	return 0;
}