#include "std_lib_facilities.h"

int main()
{
	bool calculate = true;
	vector<int> sequence = { 0, 1 };

	for (int i = 1; i < sequence.size(); i++)
	{
		int value = sequence[i] + sequence[i - 1];
		if (INT32_MAX - sequence[i] > value)
		{
			cout << "Most recent value: " << value << '\n';
			sequence.push_back(value);
		}
		else
		{
			cout << "At integer maximum. Total number of numbers stored: " << sequence.size() << '\n';
			cout << "Highest number: " << sequence.back();
		}
	}
}