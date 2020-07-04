#include "std_lib_facilities.h"

void ClearBuffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
	vector<string> day;
	vector<string> acceptableDaysLong = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
	vector<string> acceptableDaysShort = { "mon", "tue", "wed", "thur", "fri", "sat", "sun" };
	vector<int> dayNum;
	string sInput;
	int iInput;
	int rejectedInputs = 0;

	while (sInput != "q")
	{
		cout << "Please enter a day of the week and a number: ";

		cin >> sInput >> iInput;

		transform(sInput.begin(), sInput.end(), sInput.begin(), tolower);

		bool accepted = false;

		if (sInput == "q" && iInput == 0)
		{
			break;
		}

		for (int i = 0; i < acceptableDaysLong.size(); i++)
		{
			if (sInput == acceptableDaysLong[i] || sInput == acceptableDaysShort[i])
			{
				day.push_back(sInput);
				dayNum.push_back(iInput);
				accepted = true;
			}
		}
		if (!accepted)
		{
			rejectedInputs++;
			ClearBuffer();
		}
	}

	int sum = 0;

	for (int i = 0; i < day.size(); i++)
	{
		cout << day[i] << " " << dayNum[i] << '\n';
		sum += dayNum[i];
	}

	cout << "Total of DayNum Vector: " << sum << '\n';
	cout << "Rejected Inputs: " << rejectedInputs << '\n';

	return 0;
}