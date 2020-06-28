#include "std_lib_facilities.h"

int main()
{
	double AverageVector(vector<double> sequence);

	vector<double> distances;
	double totalDistance = 0, averageDistance = 0, smallestDistance = 0, largestDistance = 0;

	for (double length; cin >> length;)
	{
		distances.push_back(length);
		totalDistance += length;
	}
	sort(distances);

	averageDistance = AverageVector(distances);

	smallestDistance = distances.front();
	largestDistance = distances.back();

	cout << "A total of " << distances.size() << " distances were entered. The trip has a total sum distance of "
	 	 << totalDistance << " miles will be travelled, with the average distance between two points being "
		 << averageDistance << " and the shortest distance being " << smallestDistance
		 << ", while the longest distance is " << largestDistance << ".\n";
	
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