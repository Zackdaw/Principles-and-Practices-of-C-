#include "std_lib_facilities.h"

int main()
{
	int Max = 100;
	int Min = 0;

	int answer = Min - 1, guess = randint(Min, Max);

	int guesses = 0;

	cout << "Please enter a number between " << Min << " and " << Max << ", the computer will then guess it: ";

	cin >> answer;

	while (answer < Min || answer > Max)
	{
		cout << "Error: Please enter a valid number between " << Min << " and " << Max << ".\n";
		cin >> answer;
	}


	while (guess != answer)
	{
		cout << "The computer guesses: " << guess << " and is incorrect. Min: " << Min << ", Max: " << Max << '\n';

		if (guess < answer)
		{
			Min = guess + 1;
		}
		else if (guess > answer)
		{
			Max = guess - 1;
		}
		guess = (Min + Max) / 2;
		guesses++;
	}

	cout << "The computer guessed the number " << guess << " and was correct.\n";
	cout << "The computer guessed the number in " << guesses << " guesses.\n";

	return 0;

}