#include "C10_Drill_Header.h"

int main()
{
	vector<Point> original_points{};
	vector<Point> loaded_points{};

	cout << "Please enter seven points.\n>";
	while (original_points.size() != 7)
	{
		Point p{Point()};
		cin >> p;
		original_points.push_back(p);
		cout << ">";
	}

	string oname{ "C12_Drill_Save.txt" };
	fstream file{ oname, std::fstream::out | std::fstream::trunc };

	for (auto p : original_points)
	{
		file << p;
	}

	file.close();

	fstream file2{ oname, std::fstream::in };

	for (Point p; file2 >> p;)
	{
		loaded_points.push_back(p);
	}

	file2.close();

	cout << "Printing Comparison:\n";
	for (auto p : original_points)
	{
		cout << p;
	}

	cout << '\n';

	for (auto p : loaded_points)
	{
		cout << p;
	}

	return 0;
}