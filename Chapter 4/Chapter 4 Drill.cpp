#include "std_lib_facilities.h"

int main()
{
	//All Units are reduced to CM by this program.

	double buffer;
	string unit;
	double smallest = DBL_MAX, largest = DBL_MIN, sum = 0.0;
	vector<double> values;
	
	int count = 0;

	bool UnitIsValid(string unit);
	double ConvertUnit(double buffer, string unit);

	cout << "Please enter a single number followed by its unit. Terminate input with '|'.\n";
	while (cin >> buffer >> unit)
	{
		if (unit == " ")
		{
			cin >> unit;
		}

		transform(unit.begin(), unit.end(), unit.begin(), tolower);

		if (UnitIsValid(unit))
		{
			buffer = ConvertUnit(buffer, unit);
			values.push_back(buffer);
			sum += buffer;
			count++;

			if (smallest == DBL_MAX && largest == DBL_MIN)
			{
				smallest = buffer;
				largest = buffer;
			}
			else if (buffer < smallest)
			{
				smallest = buffer;
			}
			else if (buffer > largest)
			{
				largest = buffer;
			}

			cout << "The smallest distance so far is: " << smallest << " meters" << '\n';
			cout << "The largest distance so far is: " << largest << " meters" << '\n';
		}
		else
		{
			cout << "Invalid unit, please try again.\n";
		}
	}
	
	sort(values);

	cout << "\nYou entered " << count << " values with a total distance of "
		<< sum << " meters.\n\n";

	cout << "The following values were entered:\n";

	for (double x : values)
	{
		cout << x << '\n';
	}

	return 0;
}


double ConvertUnit(double buffer, string unit)
{
	constexpr double FeetToInches = 12;
	constexpr double InchesToMeters = 0.0254;
	constexpr double CMToMeters = 0.01;

	if (unit == "ft")
	{
		return buffer * FeetToInches * InchesToMeters;
	}
	else if (unit == "in")
	{
		return buffer * InchesToMeters;
	}
	else if (unit == "cm")
	{
		return buffer * CMToMeters;
	}
	else
	{
		return buffer;
	}

}

bool UnitIsValid(string unit)
{
	if (unit == "cm")
	{
		return true;
	}	
	else if (unit == "ft")
	{
		return true;
	}
	else if (unit == "in")
	{
		return true;
	}
	else if (unit == "m")
	{
		return true;
	}
	else
	{
		return false;
	}
}