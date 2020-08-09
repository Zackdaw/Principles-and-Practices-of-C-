#include "std_lib_facilities.h"

int main()
{
	vector<pair<string, int>> people;

	string name;
	int age;

	cout << "Please enter a name followed by an age: \n";
	while (true)
	{
		cout << "Name(Type 'exit' to quit) > ";
		cin >> name;
		if (name == "exit" || name == "Exit")
		{
			break;
		}
		cout << "Age > ";
		cin >> age;

		pair<string, int> newRecord = make_pair(name, age);
		people.push_back(newRecord);
	}

	sort(people.begin(), people.end());

	for (pair<string, int> record : people)
	{
		cout << record.first << ", " << record.second << '\n';
	}

	return 0;
}