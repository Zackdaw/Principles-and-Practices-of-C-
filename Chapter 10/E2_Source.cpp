#include "E2_Header.h"

const string fileName{ "E2_original_readings.txt" };

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
	double currentTemp;

	fstream file{ fileName, std::fstream::in};
	
	if (!file)
	{
		cout << "Template file not found. Please wait while a template of readings is created.\n";
		Create_Original_Readings(50);
	}

	Reading r{ 0,0 };
	while (file >> r)
	{
		temps.push_back(r);
	}
	file.close();

	for (Reading r : temps)
	{
		cout << r << '\n';
	}

	return 0;
}