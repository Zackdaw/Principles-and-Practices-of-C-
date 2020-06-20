#include "std_lib_facilities.h"

int main()
{
	int square(int);
	int x;

	cin >> x;

	cout << square(x);

	keep_window_open();
	return 0;
}

int square(int x)
{
	int y = 0;
	for (int i = 0; i < x; i++)
	{
		y += x;
	}
	return y;
}
