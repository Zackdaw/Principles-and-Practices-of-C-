#include "std_lib_facilities.h"

int maxv(vector<int>& sequence)
{
	int max = INT32_MIN;
	for (int i : sequence)
	{
		if (i > max)
		{
			max = i;
		}
	}

	return max;
}

int main()
{
	vector<int> sequence = { -5, 5, 10, 23 };

	cout << maxv(sequence);

	return 0;
}