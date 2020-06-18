#include "std_lib_facilities.h"

int main()
{
	cout << "Hello User\n";
	string previous = "";
	string current;
	while (cin >> current)
	{
		if (previous == current)
		{
			cout << "Repeated Word: " << current << '\n';
		}
		previous = current;
	}

	keep_window_open();
	return 0;
}

// In this program, the definition of word is a set of chars separated by a whitespace. The chars
// must be identical including the usage of capitalization due to the string comparison ultimately
// being an integer comparison.