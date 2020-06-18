#include "std_lib_facilities.h";

int main()
{
	double i1, i2;
	double larger;
	double smaller;
	cout << "Please enter two numbers: ";
	cin >> i1 >> i2;

	if (i1 >= i2)
	{
		larger = i1;
		smaller = i2;
	}
	else
	{
		larger = i2;
		smaller = i1;
	}

	cout << "Value 1: " << i1 << '\n'
		<< "Value 2: " << i2 << '\n'
		<< "Largest Number: " << larger << '\n'
		<< "Smaller Number: " << smaller << '\n'
		<< "Sum: " << larger + smaller << '\n'
		<< "Difference: " << larger - smaller << '\n'
		<< "Product: " << larger * smaller << '\n'
		<< "Ratio(Smaller:Larger): " << (smaller / larger) << ":1" << '\n';

	keep_window_open();
	return 0;
}
