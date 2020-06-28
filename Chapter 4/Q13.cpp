#include "std_lib_facilities.h"

int main()
{
	constexpr int Max = 100;

	// Create a vector of 100 bool values, all of which are initially true.
	vector<bool> primes(Max+1, true);

	for (int p = 2; p * p <= Max; p++)
	{
		if (primes.at(p) == true)
		{
			for (int i = p * p; i <= Max; i += p)
			{
				primes.at(i) = false;
			}
		}
	}

	cout << "Prime Numbers: ";

	for (int i = 0; i < Max; i++)
	{
		if (primes.at(i))
		{
			cout << i << "\n";
		}
	}

	return 0;

}