#include "std_lib_facilities.h"

void print_until_s(const vector<string>& v, string quit)
{
	for (string s : v)
	{
		if (s == quit) 
		{
			char c;
			cout << "\nPlease enter y if you wish to Quit or N to continue.\n>";
			cin >> c;
			if (c == 'y')
			{
				return;
			}
			else
			{
				cout << '\n';
				continue;
			}
		}
		else
		{
			cout << s << '\n';
		}
	}
}

int main()
{
	string quit = "quit";
	vector<string> sequence = { "Hello", "quit", "World", "!" };

	print_until_s(sequence, quit);

	if (quit == )

	return 0;
}

