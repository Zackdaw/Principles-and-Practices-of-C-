#include "std_lib_facilities.h"

struct BelowAbsZeroException : public std::exception
{
	const char* what() const throw ()
	{
		return "Below Absolute Zero Exception!";
	}
};

double CtoF(double c)
{
	constexpr double AbsoluteZeroC = -273.15;
	if (c < AbsoluteZeroC)
	{
		throw BelowAbsZeroException();
	}

	double f = (c * 1.8) + 32;
	return f;
}

double FtoC(double f)
{
	constexpr double AbsoluteZeroF = -459.67;
	if (f < AbsoluteZeroF)
	{
		throw BelowAbsZeroException();
	}

	double c = (f - 32) * (0.5555555);
	return c;
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
			cout << t << " Fahrenheit\n";
		}
		else if (unit == 'f')
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