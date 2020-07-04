#include "std_lib_facilities.h"

int main()
{
	vector<string> sequence = { "Kit", "Kitten", "Gigantic", "Rupee","Rupee", "Thief" };
	
	sort(sequence);
	
	string shortest = "";
	string longest = "";

	string current = "";
	string mode = "";
	int count = 0;
	int max = 0;

	for (string entry : sequence)
	{
		if (entry != current)
		{
			current = entry;
			count = 0;
		}
		if (entry.length() > longest.length())
		{
			longest = entry;
		}
		if (entry.length() < shortest.length() || shortest.length() == 0)
		{
			shortest = entry;
		}
		if (++count > max)
		{
			max = count;
			mode = entry;
		}
	}

	cout << "Results:\n"
		<< "Mode: " << mode << '\n'
		<< "Min: " << shortest << '\n'
		<< "Max: " << longest << '\n';

	return 0;
}