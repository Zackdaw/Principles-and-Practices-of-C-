#pragma once

#include "std_lib_facilities.h"

class NamePair
{
public:
	NamePair();

	void AddEntry(string name, int age);
	void DeleteEntry(string name);
	void DeleteEntry(int index);
	void EditAge(string name, int age);

	void SortPairs();
	void const ReadPairs();
	bool const FindPair(string name, int age);

	bool operator==(NamePair& n);
	bool operator!=(NamePair& n);

	friend ostream& operator<<(ostream& os, NamePair& n);

private:
	vector<pair<string, int>> pairs;
};
