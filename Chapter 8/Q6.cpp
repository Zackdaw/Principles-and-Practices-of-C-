#include "Q2H.h"
#include "std_lib_facilities.h"

vector<string> ReverseExternal(vector<string> inSequence)
{
	vector<string> reversedSequence;

	for (int i = inSequence.size() - 1; i >= 0; i--)
	{
		reversedSequence.push_back(inSequence[i]);
	}

	return reversedSequence;
}

void InPlaceReverse(vector<string>& sequence)
{
	for (int i = 0; i < sequence.size() / 2; i++)
	{
		std::swap(sequence[i], sequence[(sequence.size() - 1) - i]);
	}
}

void Print(vector<string>& target)
{
	for (auto var : target)
	{
		cout << var << ", "; 
	}
	cout << '\n';
}

int main()
{
	string forward = "Forward Order";
	string reverse = "Reverse Order";
	string inPlace = "In-Place Reorder";

	vector<string> sequence = { "One", "Two", "Three", "Four", "Five" };
	vector<string> reverseSequence = ReverseExternal(sequence);

	Print(sequence);
	Print(reverseSequence);
	InPlaceReverse(sequence);
	Print(sequence);

	return 0;
}