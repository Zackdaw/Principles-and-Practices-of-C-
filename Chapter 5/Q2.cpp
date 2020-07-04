#include "std_lib_facilities.h"

double CtoF(double c)
{
	double k = c + 273.15;
	if (k < 0)
	{
		return 0;
	}
	return k;
}

int main()
{
	double c, k;
	cin >> c;
	while (!cin)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> c;
	}

	k = CtoF(c);
	cout << k << " Kelvin \n";

}