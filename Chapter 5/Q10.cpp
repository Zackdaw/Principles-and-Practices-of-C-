#include "std_lib_facilities.h"

void ClearBuffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{

	vector<double> nums;
	vector<double> numsMinusOne;

	double input;
	int toBeSummed, sum = 0;

	cout << "Please enter the amount of numbers to be summed: ";


	while (1)
	{
		cin >> toBeSummed;
		ClearBuffer();
		if (cin)
		{
			break;
		}
	}

	cout << "Please enter a sequence of numbers. (Terminate with |): \n";
	while (1)
	{
		cin >> input;
		if (!cin)
		{
			if (nums.size() < toBeSummed)
			{
				cout << "Insufficient numbers to calculate the desired sum. Please enter more numbers.\n";
				ClearBuffer();
			}
			else
			{
				break;
			}
		}
		else
		{
			nums.push_back(input);
		}
	}

	for (int i = 0; i < toBeSummed; i++)
	{
			sum += nums[i];
			if (i > 0)
			{
				numsMinusOne.push_back(nums[i] - nums[i - 1]);
			}
	}
	
	cout << "Calcuated Sum: " << sum << "\n";
	cout << "Other Figures: \n";
	for (double n : numsMinusOne)
	{
		cout << n << '\n';
	}

	return 0;
}