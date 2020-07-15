#include "std_lib_facilities.h"
#include <math.h>

vector<int>UserInput;
int finalInt = 0;

int main()
{
	char buffer;
	while (1)
	{
		cin >> buffer;
		if (buffer == 'q')
		{
			break;
		}
		if (buffer < '0' || buffer > '9')
		{
			cerr << "Please enter digits only.";
		}
		else
		{
			UserInput.push_back(static_cast<int>(buffer) - static_cast<int>('0'));
			if (UserInput.size() >= 4)
			{
				break;
			}
		}
	}

	for (int i = 0; i < UserInput.size(); i++)
	{
		finalInt += (UserInput[i] * pow(10, (UserInput.size() - 1) - i));
	}

	cout << "The number " << finalInt << " is " 
		<< (finalInt / 1000) % 10 << " thousands, "
		<< (finalInt / 100) % 10 << " hundreds, "
		<< (finalInt / 10) % 10 << " tens, and "
		<< finalInt % 10 << " ones";

}