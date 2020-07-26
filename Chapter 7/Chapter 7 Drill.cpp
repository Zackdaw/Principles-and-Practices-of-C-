/*
	Drill Instructions for Portability

	01. Starting from the file below, get the calculator to compile. // Done
	02. Go through the entire program and add appropriate comments. // Done
	03. As you commented, fix any errors that you found. // Done
	04. Prepare a set of inputs and use them to test the calculator. Is your list
		pretty complete? What should you look for? Include negative values, 0, very small,
		very large, and absurd inputs. // Done
	05. Fix any bugs uncovered by testing. // Done
	06. Add a predefined name k meaning 1000. // Done
	07. Give the user a usable square root function.
	08. Catch attempts to take the square root of a negative numer and print an appropriate
		error message.// Done
	09. Allow the user to use the ^ operator to conduct exponential operations.// Done
	10. Change the delcaration keyword from let to #. // Complete;
	11. Change the quit keyword from quit to exit. // Complete;
*/
#include "C7_Header.h"

void cleanTokens();

double getSquareRoot(double d)
{
	if (d < 0)
	{
		error("Square Roots of negative numbers are undefined.");
		return 0;
	}
	else
	{
		return sqrt(d);
	}
}

TokenStream ts;
VariableTable vt;
double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
		//For parenthesis in particular, reloop to expression if an opening parenthesis is detected. Then return the total of that subloop upon detecting a closing parenthesis.
	case '(':
	{	
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '-':
		return -primary();
	case squareRoot:
		return getSquareRoot(primary());
	case number:
		return t.value;
	case name:
	{
		return vt.getValue(t.name);
	}
	default:
		error("primary expected");
		cleanTokens();
	}
}

double secondary()
{
	double left = primary();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '^':
			left = pow(left, primary());
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double term()
{
	double left = secondary();
	while (true) 
	{
		Token t = ts.get();
		switch (t.kind) 
		{
		case '*':
			left *= secondary();
			break;
		case '/':
			{	
				double d = secondary();
				if (d == 0) error("divide by zero");
				left /= d;
				break;
			}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') 
	{
		error("name expected in declaration");
	}
	string name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=')
	{
		error("= missing in declaration of ", name);
	}

	double d = expression();

	if (vt.isDeclared(name))
	{
		vt.setValue(name, d);
	}
	else
	{
		vt.addVariable(Variable(name, d));
	}
	return d;
}

double statement()
{
	//Get the token from the stream. This would be the token put back into the stream by the Calculate() function for the first call.
	Token t = ts.get();
	switch (t.kind) {
		//If the token is a Let, return the declaration function's results.
	case let:
		return declaration();
		//Otherwise, put the token back into the stream and return the results of the expression() function.
	default:
		ts.putback(t);
		return expression();
	}
}

void cleanTokens()
{
	ts.ignore(print);
}

void calculate()
{
	while (true) try {
		//Display the prompt.
		cout << prompt;
		// Get the latest token.
		Token t = ts.get();
		// If the token is a print token, get the next token.
		while (t.kind == print) t = ts.get();
		// If the token is a quit token, quit.
		if (t.kind == quit) return;
		// Put the token back into the stream.
		ts.putback(t);
		//Print the result constant char, run the statement() function, then insert the end line character and flushes the buffer using endl.
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		cleanTokens();
	}
}

//Main in this context simply to execute the calculate function and catch any exceptions that come up from it.
int main()
{
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}