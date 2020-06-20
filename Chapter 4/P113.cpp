#include "std_lib_facilities.h"

int main()
{

	for (int i = int('A'); i <= int('Z'); i++)
	{
		cout << char(i) << '\t' << i << '\n';
	}
	cout << '\n';
	for (int i = int('a'); i <= int('z'); i++)
	{
		cout << char(i) << '\t' << i << '\n';
	}

	keep_window_open();
	return 0;
}