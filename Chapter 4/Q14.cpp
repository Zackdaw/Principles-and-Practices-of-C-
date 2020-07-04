#include "std_lib_facilities.h"

int main()
{
	int max = 100;

	cout << "Please enter a value to find all the prime numbers between it and 1: ";
	cin >> max;

	// Create a vector of 100 bool values, all of which are initially true.
	vector<bool> primes(max, true);

	for (int p = 2; p * p < max; p++)
	{
		if (primes.at(p) == true)
		{
			for (int i = p * p; i < max; i += p)
			{
				primes.at(i) = false;
			}
		}
	}

	cout << "Prime Numbers: ";

	for (int i = 0; i < max; i++)
	{
		if (primes.at(i))
		{
			cout << i << "\n";
		}
	}

	return 0;

}