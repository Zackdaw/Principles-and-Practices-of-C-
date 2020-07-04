#include "std_lib_facilities.h"

vector<int> GenerateAnswer(int quantity)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum(0, 9);

	vector<int> sequence;

	for (int i = 0; i < quantity; i++)
	{
		sequence.push_back(randomnum(gen));
	}

	return sequence;
}

vector<int> GetPlayerAnswer()
{
	vector<int> dividedAnswer;
	int playerAnswer;

	cout << "Please enter a four digit number: ";

	while (1)
	{
		cin >> playerAnswer;
		if (!cin || playerAnswer < 1000 || playerAnswer > 9999)
		{
			cout << "Please enter a number between 1000 and 9999";
		}
		else
		{
			break;
		}
	}

	dividedAnswer.push_back(playerAnswer / 1000 % 10);
	dividedAnswer.push_back(playerAnswer / 100 % 10);
	dividedAnswer.push_back(playerAnswer / 10 % 10);
	dividedAnswer.push_back(playerAnswer % 10);

	return dividedAnswer;
}

int main()
{
	vector<int> answer = GenerateAnswer(4);

	for (int x : answer)
	{
		cout << x << ' ';
	}
	cout << '\n';
	
	vector<int> playerAnswer;
	int bulls = 0, cows;

	while (bulls != 4)
	{
		playerAnswer = GetPlayerAnswer();
		bulls = 0;
		cows = 0;

		for (int i = 0; i < playerAnswer.size(); i++)
		{
			for (int j = 0; j < answer.size(); j++)
			{
				if (playerAnswer[i] == answer[j])
				{
					if (i == j)
					{
						bulls++;
					}
					else
					{
						cows++;
					}
				}
			}
		}
		cout << '\n' << "Cows: " << cows << "| Bulls: " << bulls << '\n';
	}

	cout << "\n YOU WIN!\n";


}