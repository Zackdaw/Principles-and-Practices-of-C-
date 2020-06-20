#include "std_lib_facilities.h"

int main()
{
	int i = int('a');
	while (i <= int('z'))
	{
		cout << char(i) << '\t' << i << '\n';
		i++;
	}

	keep_window_open();
	return 0;
}