#include "std_lib_facilities.h"

const string fileName{ "E14.txt" };

int main()
{
	ifstream ifs{ fileName };

	char buffer{ };

	int alphaCount{ 0 }, numCount{ 0 }, punctCount{ 0 }, wsCount{ 0 };

	while (ifs >> noskipws >> buffer)
	{
		if (isalpha(buffer)) alphaCount++;
		else if (isdigit(buffer)) numCount++;
		else if (ispunct(buffer)) punctCount++;
		else if (isspace(buffer)) wsCount++;
	}

	ifs.close();

	cout << "Character Counts:\n";
	cout << "Alphabetic Characters:" << "\t" << alphaCount << '\n';
	cout << "Numeric Characters:" << "\t" << numCount << '\n';
	cout << "Punctuation Characters:" << "\t" << punctCount << '\n';
	cout << "Whitespace Characters:" << "\t" << wsCount << '\n';


	return 0;
}