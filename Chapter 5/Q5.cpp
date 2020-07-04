#include "std_lib_facilities.h"

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

double FtoC(double k)
{
	if (k < 0)
	{
		throw BelowAbsZeroException();
	}
	return k - 273.15;
}

int main()
{
	double t;
	char unit;
	cin >> t >> unit;
	while (!cin)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> t >> unit;
	}

	try
	{
		if (unit == 'c')
		{
			t = CtoF(t);
			cout << t << " Kelvin\n";
		}
		else if (unit == 'k')
		{
			t = FtoC(t);
			cout << t << " Celcius\n";
		}
	}
	catch (BelowAbsZeroException& e)
	{
		cerr << "Exception: " << e.what() << '\n';
		cerr << "Output Default of 0\n";
		t = 0;
	}
}