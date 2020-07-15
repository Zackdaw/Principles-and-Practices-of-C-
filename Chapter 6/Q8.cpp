#include "std_lib_facilities.h"

vector<char> GenerateAnswer(int quantity)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> randomnum(97, 122);

	vector<char> sequence;

	for (int i = 0; i < quantity; i++)
	{
		sequence.push_back(static_cast<char>(randomnum(gen)));
	}

	return sequence;
}

vector<char> GetPlayerAnswer()
{
	vector<char> playerAnswer;

	cout << "Please enter four letters:\n";

	while (playerAnswer.size() < 4)
	{
		char buffer;
		cin >> buffer;
		if (!cin || buffer < 'a' || buffer > 'z')
		{
			cout << "Please letters between 'a' and 'z'";
		}
		else
		{
			playerAnswer.push_back(buffer);
		}
	}

	return playerAnswer;
}

int main()
{
	vector<char> answer = GenerateAnswer(4);

	for (char x : answer)
	{
		cout << x << ' ';
	}
	cout << '\n';

	vector<char> playerAnswer;
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