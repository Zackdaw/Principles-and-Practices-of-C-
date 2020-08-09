#include "Q1_Header.h"

Token TokenStream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	inStream >> ch;
	switch (ch)
	{
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '^':
	case '=':
	{
		return Token(ch);
	}
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		inStream.unget();
		double val;
		inStream >> val;
		return Token(number, val);
	}
	case let:
		return Token(let);
	default:
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (inStream.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			inStream.unget();
			cout << s;
			if (s == "sqrt") return Token(squareRoot);
			if (s == "k") return Token(number, 1000);
			if (s == "exit" || s == "quit") return Token(quit);
			return Token(name, s);
		}
		error("Bad token");
		return Token(0, 0);
	}
}

void TokenStream::putback(Token t) 
{ 
	buffer = t; 
	full = true; 
}

void TokenStream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (inStream >> ch)
		if (ch == c) return;
}