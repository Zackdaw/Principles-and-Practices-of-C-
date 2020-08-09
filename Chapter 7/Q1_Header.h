#pragma once
#include "std_lib_facilities.h"

constexpr char let = '#';
constexpr char quit = 'Q';
constexpr char print = ';';
constexpr char number = '8';
constexpr char name = 'a';
constexpr char squareRoot = 'I';

const string prompt = "> ";
const string result = "= ";


class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch);
	Token(char ch, double val);
	Token(char ch, string n);
};

class TokenStream 
{
	istream& inStream;
	bool full;
	Token buffer;
public:
	TokenStream(istream& inputStream) :inStream(inputStream), full(0), buffer(0) { }

	Token get();
	void putback(Token t);

	void ignore(char);
};

struct Variable
{
	string name;
	double value;
	bool constant;
	Variable(string n, double v);
	Variable(string n, double v, bool c);
};

class VariableTable
{
private:
	vector<Variable> names;
public:
	VariableTable();

	void addVariable(Variable addition);
	bool isDeclared(string name);

	double getValue(string name);
	void setValue(string name, double value);
};