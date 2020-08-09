#include "Q1_Header.h"

VariableTable::VariableTable()
{
	names = { Variable("pi", 3.14, true) };
}

void VariableTable::addVariable(Variable addition)
{
	names.push_back(addition);
}

void VariableTable::setValue(string name, double value)
{
	for (int i = 0; i < names.size(); i++)
	{
		if (names[i].name == name)
		{
			names[i].value = value;
			return;
		}
	}
	error("Undefined Name: ", name);
}

double VariableTable::getValue(string name)
{
	for (int i = 0; i < names.size(); i++)
	{
		if (names[i].name == name)
		{
			return names[i].value;
		}
	}
	error("Undefined Name: ", name);
	return 0;
}

bool VariableTable::isDeclared(string name)
{
	for (int i = 0; i < names.size(); i++)
	{
		if (names[i].name == name)
		{
			return true;
		}
	}
	return false;
}