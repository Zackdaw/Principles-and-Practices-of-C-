#include "std_lib_facilities.h"

void ClearBuffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{

	vector<int> nums;

	int input;
	int toBeSummed, sum = 0;

	cout << "Please enter the amount of numbers to be summed: ";


	while (1)
	{
		cin >> toBeSummed;
		if (!cin)
		{
			ClearBuffer();
		}
		else
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
		if (INT32_MAX - sum > nums[i])
		{
			cerr << "\nERROR: Integer Overflow. These numbers cannot be added.\n";
			break;
		}
		else 
		{
			sum += nums[i];
		}
		if (i == toBeSummed - 1)
		{
			cout << "Calcuated Sum: " << sum;
		}
	}

}