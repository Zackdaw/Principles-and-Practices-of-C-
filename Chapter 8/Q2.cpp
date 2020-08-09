#include "Q2H.h"
#include <iostream>

using namespace std;

void print(string& label, const vector<int>& nums)
{
	cout << label << ": " ;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i];
		if (i < nums.size() - 1)
		{
			cout << ", ";
		}
		else
		{
			cout << "\n";
		}
	}
}

/*
int main()
{
	string label{ "Number Sequence" };
	vector<int> sequence{ 3, 5, 9 };

	print(label, sequence);

	return 0;
}
*/