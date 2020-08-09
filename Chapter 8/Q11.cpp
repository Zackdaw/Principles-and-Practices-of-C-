#include "std_lib_facilities.h"

struct DataStruct
{
	double min;
	double max;
	double mean;
	double median;

	DataStruct(double min, double max, double mean, double median) : min(min), max(max), mean(mean), median(median) {}
};

double FindMedian(const vector<double>& sequence)
{
	double median;

	if (sequence.size() % 2 == 0)
	{
		median = ((sequence[sequence.size() / 2] + sequence[(sequence.size() / 2) - 1]) / 2);
	}
	else
	{
		median = sequence[(sequence.size() / 2)];
	}

	return median;
}

double FindMean(const vector<double>& sequence)
{
	double total{ 0 };

	for (double d : sequence)
	{
		total += d;
	}

	double mean =  total / sequence.size();

	return mean;
}

DataStruct Calculate( vector<double>& sequence)
{
	double min{ INT32_MAX };
	double max{ INT32_MIN };

	sort(sequence);

	for (double d : sequence)
	{ 
		if (d < min)
		{
			min = d;
		}
		if (d > max)
		{
			max = d;
		}
	}

	double median = FindMedian(sequence);
	double mean = FindMean(sequence);

	return DataStruct(min, max, mean, median);
}


int main()
{
	vector<double> sequence{7.0, 2.0, 3.0, 4.0, 5.0};

	DataStruct data = Calculate(sequence);

	cout << data.min << " | " << data.max << " | " << data.mean << " | " << data.median << '\n';

	return 0;

}