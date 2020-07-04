#include "std_lib_facilities.h"

int main()
{
	int max = 100;

	vector<int> primes = { 2 };
	bool isPrime = true;

	cout << "Please enter a max number for the prime calculation: ";
	cin >> max;

	for (int i = 3; i < max; i++)
	{
		isPrime = true;
		for (int prime : primes)
		{
			if (i % prime == 0)
			{
				isPrime = false;
			}
		}
		if (isPrime)
		{
			primes.push_back(i);
		}
	}

	primes.insert(primes.begin(), 1);
	primes.insert(primes.begin(), 0);

	for (int prime : primes)
	{
		cout << prime << '\n';
	}

	return 0;
}