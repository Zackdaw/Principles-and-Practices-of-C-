#include "std_lib_facilities.h"
#include <math.h>
#include <errno.h>
#include <cmath>

struct RootFailure : public std::exception
{
	const char* what() const throw()
	{
		return "Negative Square Root detected. Quadratic Failure imminent.";
	}
};

double SquareRoot(double x)
{
	if (x < 0)
	{
		throw RootFailure();
	}

	return sqrt(x);
}


vector<double> SolveQuadraticEquation(double a, double b, double c)
{
	vector<double> answers(2);
	double root = 0;
	
	try 
	{
		 root = SquareRoot((b * b) - (4 * a * c));
		 answers[0] = (-b + root) / (2 * a);
		 answers[1] = (-b - root) / (2 * a);
	}
	catch (const RootFailure& e)
	{
		cout << e.what() << '\n';
		answers[0] = 1;
		answers[1] = 1;
	}

	return answers;
}


int main()
{
	vector<double> answers(2);
	double a = 5;
	double b = 1;
	double c = 1;

	answers = SolveQuadraticEquation(a, b, c);

	cout << "A = " << a << ", "; 
	cout << "B = " << b << ", ";
	cout << "C = " << c << ", ";

	cout << "Answers: (" << answers[0] << ", " << answers[1] << ")";

	keep_window_open();
}
