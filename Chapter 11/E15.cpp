#include "std_lib_facilities.h"

const string fileName{ "E14.txt" };

int main()
{
	ifstream ifs{ fileName };

	char buffer{ };

	float alphaCount{ 0 }, numCount{ 0 }, punctCount{ 0 }, wsCount{ 0 };

	while (ifs >> noskipws >> buffer)
	{
		if (isalpha(buffer)) alphaCount++;
		else if (isdigit(buffer)) numCount++;
		else if (ispunct(buffer)) punctCount++;
		else if (isspace(buffer)) wsCount++;
	}

	ifs.close();

	cout << "Character Counts:\n";
	cout << "Alphabetic Characters:" << "\t" << scientific << setprecision(8) << setw(20) << alphaCount << '\n';
	cout << "Numeric Characters:" << "\t" << scientific << setprecision(8) << setw(20) << numCount << '\n';
	cout << "Punctuation Characters:" << "\t" << scientific << setprecision(8) << setw(20) << punctCount << '\n';
	cout << "Whitespace Characters:" << "\t" << scientific << setprecision(8) << setw(20) << wsCount << '\n';


	return 0;
}