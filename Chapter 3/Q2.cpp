#include "std_lib_facilities.h"

int main()
{
	const double converstionFactor = 1.609;
	double miles = -1;
	cout << "Welcome to the unit converter. Please enter the number of miles to convert to kilometers: ";
	while (cin >> miles)
	{
		cout << miles << " miles = " << miles * converstionFactor << " kilometers\n";
	}

	keep_window_open();
	return 0;
}