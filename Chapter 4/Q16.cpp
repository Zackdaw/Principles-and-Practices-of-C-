#include "std_lib_facilities.h"

int main()
{
	vector<int> sequence = { 1, 2, 3, 3, 4, 5, 5, 5, 6, 3, 3 };
	int current = 0;
	int count = 0;
	int max = 0;
	int mode = 0;

	sort(sequence);

	for (int num : sequence)
	{
		if (num != current)
		{
			current = num;
			count = 0;
		}
		if (++count > max)
		{
			max = count;
			mode = num;
		}
	}

	cout << "Mode: " << mode << "\nCount: " << max << '\n';

}