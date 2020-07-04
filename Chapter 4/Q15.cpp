#include "std_lib_facilities.h"

int main()
{
	int max = 100;

	vector<int> primes = { 0, 1, 2 };
	bool isPrime = true;

	cout << "Please enter how many primes you wish to find: ";
	cin >> max;
	cout << "--------RESULTS--------\n";

	if (max > primes.size())
	{
		for (int i = primes.size(); primes.size() != (max); i++)
		{
			isPrime = true;
			for (int p = 2; p < primes.size(); p++)
			{
				if (i % primes[p] == 0)
				{
					isPrime = false;
				}
			}
			if (isPrime)
			{
				primes.push_back(i);
			}
		}
	}

	for (int i = 0; i != max; i++)
	{
		cout << primes[i] << '\n';
	}

	return 0;
}