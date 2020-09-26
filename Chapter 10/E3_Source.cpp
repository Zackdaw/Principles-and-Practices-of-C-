#include "E3_Header.h"

const string fileName{ "E3_original_readings.txt" };

void Create_Original_Readings(int quantity)
{
	ofstream file{ fileName };
	for (int i{ 0 }; i < quantity; i++)
	{
		Reading reading{ (i % 24), narrow_cast<double>(randint(0, 2000)) };
		file << reading << '\n';
	}

	file.close();
}

int main()
{
	vector<Reading> temps;
	int hour;
	double currentTemp{ 0 }, medianTemp{ 0 }, meanTemp{ 0 };
	char unit;

	fstream file{ fileName, std::fstream::in };
	if (!file)
	{
		cout << "Template file not found. Please wait while a template of readings is created.\n";
		Create_Original_Readings(5);
		//Reload with template file.
		fstream file{ fileName, std::fstream::in };
		Reading r{ 0,0 };
		while (file >> r)
		{
			temps.push_back(r);
		}
		file.close();
	}
	else
	{
		Reading r{ 0,0 };
		while (file >> r)
		{
			temps.push_back(r);
		}
		file.close();
	}

	cout << "Please enter any new entries in a (H, T, U) format. Type E to continue.\n>";

	while (true)
	{
		char ch;
		cin >> ch;

		if (ch == 'E')
			break;
		if (ch == '(')
		{
			cin >> hour;
			cin.get();
			cin >> currentTemp;
			cin.get();
			cin >> unit;
			cin.get();
			temps.push_back(Reading{ hour, currentTemp, unit });
		}
	}

	std::sort(temps.begin(), temps.end());

	medianTemp = temps[temps.size() / 2].temperature;
	for (auto t : temps)
	{
		cout << t << '\n';
		meanTemp += t.temperature;
	}
	meanTemp /= temps.size();

	cout << "Median: " << medianTemp << ", Mean Temp: " << meanTemp << '\n';

	return 0;
}