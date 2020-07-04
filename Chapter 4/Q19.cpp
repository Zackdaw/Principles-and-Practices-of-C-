// NOTE: Technically this is the answer to 19, 20, and 21.

#include "std_lib_facilities.h"

int main()
{
	vector<string> names;
	vector<int> scores;

	string name;
	int score;

	cout << "Please enter a name and age: \n";
	while (cin >> name >> score)
	{
		bool unique = true;
		if (name == "NoName" && score == 0)
		{
			break;
		}
		for (string n : names)
		{
			if (n == name)
			{
				unique = false;
				break;
			}
		}
		if (unique)
		{
			names.push_back(name);
			scores.push_back(score);
		}
	}

	cout << "Please enter a name to request it's records, or input an S followed by number to search by score: \n";

	while (cin >> name)
	{
		if (name == "Q")
		{
			break;
		}
		if (name == "S")
		{
			int searchScore;
			bool found = false;
			cin >> searchScore;
			for (int i = 0; i < scores.size(); i++)
			{
				if (searchScore == scores[i])
				{
					found = true;
					cout << names[i] << " : " << scores[i] << '\n';
				}
			}
			if (!found)
			{
				cout << "Score not found";
			}
			continue;
		}

		bool found = false;
		for (int i = 0; i < names.size(); i++)
		{
			if (name == names[i])
			{
				cout << names[i] << " : " << scores[i] << '\n';
				found = true;
			}
		}

		if (!found)
		{
			cout << "Name or Score not found.\n";
		}
	}

	return 0;
}