#include "std_lib_facilities.h"

int main()
{
	int total = 1, steps = 1;
	double longTotal = 1;
	unsigned long long int vlongTotal = 1;

	for (; steps <= 64; steps++)
	{
		cout << "Step: " << steps << '\n';
		cout << "Int: " << total << '\n';
		cout << "Long: " << longTotal << '\n';
		cout << "Long Long: " << vlongTotal << '\n';
		total *= 2;
		longTotal *= 2;
		vlongTotal *= 2;

	}

	return 0;
}