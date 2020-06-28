#include "std_lib_facilities.h"

int main() 
{
	vector<string> plays = { "paper", "rock", "scissors" };
	bool winner = false;
	int player1, player2;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum(0, 2);


	while (winner == false)
	{
		player1 = randomnum(gen);
		player2 = randomnum(gen);

		cout << "Player 1 played " << plays[player1] << " and player 2 played " << plays[player2] << "!\n";

		switch (player1)
		{
		case 0:
			if (player2 == 0)
			{
				cout << "Push!\n";
				break;
			}
			else if (player2 == 1)
			{
				cout << "Player 1 Wins!\n";
				winner = true;
				break;
			}			
			else if (player2 == 2)
			{
				cout << "Player 2 Wins!\n";
				winner = true;
				break;
			}
			else
			{
				cout << "ERROR: Case 1 Else reached.";
				break;
			}		
		case 1:
			if (player2 == 1)
			{
				cout << "Push!\n";
				break;
			}
			else if (player2 == 2)
			{
				cout << "Player 1 Wins!\n";
				winner = true;
				break;
			}			
			else if (player2 == 0)
			{
				cout << "Player 2 Wins!\n";
				winner = true;
				break;
			}
			else
			{
				cout << "ERROR: Case 1 Else reached.";
				break;
			}
		case 2:
			if (player2 == 2)
			{
				cout << "Push!\n";
				break;
			}
			else if (player2 == 0)
			{
				cout << "Player 1 Wins!\n";
				winner = true;
				break;
			}			
			else if (player2 == 1)
			{
				cout << "Player 2 Wins!\n";
				winner = true;
				break;
			}
			else
			{
				cout << "ERROR: Case 1 Else reached.";
				break;
			}

		default:
			break;
		}
	}

}