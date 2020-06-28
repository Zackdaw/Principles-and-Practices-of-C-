#include "std_lib_facilities.h"

int main()
{
	vector<string> numbers = { "zero", "one", "two", "three", "four", "five","six", "seven", "eight", "nine" };

	string input = "";

	while (cin >> input)
	{
		transform(input.begin(), input.end(), input.begin(), tolower);

		if (input == "q")
		{
			break;
		}

		for (int i = 0; i < numbers.size(); i++)
		{
			if (input == numbers[i] || (static_cast<int>(input[0]) - 48) == i)
			{
				cout << numbers[i] << " == " << i << '\n';
				break;
			}
		}
	}


	return 0;
}
