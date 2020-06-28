#include "std_lib_facilities.h"

int main()
{
	int total = 1, steps = 1;

	for (; total < 1000; steps++)
	{
		cout << "Amount of Rice: " << total << " gained in " << steps << " steps.\n";
		total *= 2;
	}

	cout << "MILESTONE: Over 1000 grains of rice accomplished at step: " << steps << '\n';
	cout << "Total Amount of Rice at this Point: " << total << '\n';

	for (; total < 1000000; steps++)
	{
		cout << "Amount of Rice: " << total << " gained in " << steps << " steps.\n";
		total *= 2;
	}

	cout << "MILESTONE: Over 1000000 grains of rice accomplished at step: " << steps << '\n';
	cout << "Total Amount of Rice at this Point: " << total << '\n';

	for (; total < 1000000000; steps++)
	{
		cout << "Amount of Rice: " << total << " gained in " << steps << " steps.\n";
		total *= 2;
	}

	cout << "MILESTONE: Over 10000000000 grains of rice accomplished at step: " << steps << '\n';
	cout << "Total Amount of Rice at this Point: " << total << '\n';

	return 0;
}