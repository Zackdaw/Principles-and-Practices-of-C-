#include "std_lib_facilities.h"

const string fileName{ "E16.txt" };

int main()
{
	ifstream ifs{ fileName };

	int buffer{};

	vector<int> nums{};

	while (ifs >> buffer)
	{
		nums.push_back(buffer);
	}

	ifs.close();

	sort(nums);

	for (int i = 0; i < nums.size();)
	{
		int countInts = count(nums.begin(), nums.end(), nums[i]);
		if (countInts > 1)
		{
			cout << nums[i] << '\t' << countInts << '\n';
		}
		else
		{
			cout << nums[i] << '\n';
		}
		i += countInts;
	}

	return 0;
}