#include "std_lib_facilities.h"

int main()
{
	double AverageVector(vector<double> sequence);

	vector<double>temps;
	double average = 0;

	for (double temp; cin >> temp;)
	{
		temps.push_back(temp);
	}

	//Average Temperature
	average = AverageVector(temps);
	cout << "Average Temperature: " << average << '\n';

	//Median Temperature
	sort(temps);
	if (temps.size() % 2 == 0)
	{
		double medianLower = temps[temps.size()/2 - 1];
		double medianHigher = temps[temps.size()/2];
		cout << "No exact median. Median would lie between: " << medianLower << " and " << medianHigher <<'\n';              
	}
	// If odd, return the middle value.
	else
	{
		cout << "Exact Median is: " << temps[temps.size() / 2] << '\n';
	}

	keep_window_open();
	return 0;
}

double AverageVector(vector<double> sequence)
{
	double sum = 0;

	for (double x : sequence)
	{
		sum += x;
	}
	return sum / sequence.size();
}