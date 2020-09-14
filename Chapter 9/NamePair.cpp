#include "Q2,3H.h";

NamePair::NamePair()
{
}

void NamePair::AddEntry(string name, int age)
{
	pairs.push_back(make_pair(name, age));
}

void NamePair::DeleteEntry(string name)
{
	for (int i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == name)
		{
			pairs.erase(pairs.begin() + i);
			return;
		}
	}
}

void NamePair::DeleteEntry(int index)
{
	pairs.erase(pairs.begin() + index);
}

void NamePair::EditAge(string name, int age)
{
	for (int i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == name)
		{
			pairs[i].second = age;
			return;
		}
	}
}

void NamePair::SortPairs()
{
	sort(pairs.begin(), pairs.end());
}

void const NamePair::ReadPairs()
{
	cout << "Current Name Pairs:\n";
	for (int i = 0; i < pairs.size(); i++)
	{
		cout << i << ": Name: " << pairs[i].first << ", Age: " << pairs[i].second << "\n";
	}
}

bool const NamePair::FindPair(string name, int age)
{
	for (pair<string, int> p : pairs)
	{
		if (p.first == name && p.second == age)
		{
			return true;
		}
	}
	return false;
}

bool NamePair::operator==(NamePair& n)
{
	for (auto p : pairs)
	{
		if (!n.FindPair(p.first, p.second))
		{
			return false;
		}
	}
	return true;
}

bool NamePair::operator!=(NamePair& n)
{
	for (auto p : pairs)
	{
		if (!n.FindPair(p.first, p.second))
		{
			return true;
		}
	}
	return false;
}


ostream& operator<<(ostream& os, NamePair& n)
{
	string rstring = "";
	for (auto p : n.pairs)
	{
		string newString = "Name: " + p.first + ", Age:" + to_string(p.second) + "\n";
		rstring += newString;
	}
	os << rstring;
	return os;
}
