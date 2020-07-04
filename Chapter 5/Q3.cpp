#include "std_lib_facilities.h"

//Custom Error

struct BelowAbsZeroException : public std::exception
{
	const char* what() const throw ()
	{
		return "Below Zero Exception!";
	}
};

double CtoF(double c)
{
	double k = c + 273.15;

	if (k < 0)
	{
		throw BelowAbsZeroException();
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

	try
	{
		k = CtoF(c);
	}
	catch (BelowAbsZeroException& e)
	{
		cerr << "Exception: " << e.what() << '\n';
		cerr << "Output Default of 0\n";
		k = 0;
	}

	cout << k << " Kelvin \n";
}