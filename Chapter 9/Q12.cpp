#include "LongDate.h"

int main()
{
	vector<LongDate> dates
	{
		LongDate{ 1970, 1, 15 },
		LongDate{ 1970, 2, 13 },
		LongDate{ 1971, 1, 15 },
		LongDate{ 1975, 1, 15 },
		LongDate{ 1978, 1, 15 },
	};

	for (auto d : dates)
	{
		cout << d << '\n';
	}

}