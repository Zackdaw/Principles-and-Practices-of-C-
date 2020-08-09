#include "std_lib_facilities.h"

double productCost(const vector<pair<double, double>>& productTable)
{
	double total = 0;

	for (pair<double, double> entry : productTable)
	{
		if (entry.first == 0 || entry.second == 0)
		{
			error("Error: Entry is 0 or incomplete.");
		}
		total += entry.first * entry.second;
	}

	return total;
}

int main()
{
	vector<pair<double, double>> products{ {1, 5,}, {3, 5}, {5, 5} };

	cout << productCost(products);

	return 0;
}