#include "Q2H.h"
#include "std_lib_facilities.h"

vector<int> ReverseExternal(vector<int> inSequence)
{
	vector<int> reversedSequence;

	for (int i = inSequence.size() - 1; i >= 0; i--)
	{
		reversedSequence.push_back(inSequence[i]);
	}

	return reversedSequence;
}

void InPlaceReverse(vector<int>& sequence)
{
	for (int i = 0; i < sequence.size() / 2; i++)
	{
		std::swap(sequence[i], sequence[(sequence.size() - 1) - i]);
	}
}

int main()
{
	string forward = "Forward Order";
	string reverse = "Reverse Order";
	string inPlace = "In-Place Reorder";

	vector<int> sequence = { 1, 2, 3, 4, 5 };
	vector<int> reverseSequence = ReverseExternal(sequence);

	print(forward, sequence);
	print(reverse, reverseSequence);

	InPlaceReverse(sequence);
	print(inPlace, sequence);

	return 0;
}