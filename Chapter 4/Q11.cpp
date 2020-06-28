#include "std_lib_facilities.h"

int main()
{
	constexpr int Max = 100;

	vector<int> primes = { 2 };
	bool isPrime = true;

	for (int i = 3; i < Max; i++)
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


	for (int prime : primes)
	{
		cout << prime << '\n';
	}


	return 0;
}