#include "std_lib_facilities.h"

class Player 
{
public:
	string name;
	int score;
	Player(string name)
		:name(name), score(0) {};
	Player(string name, int score)
		:name(name), score(score) {};
};

int main()
{
	vector<Player> players;

	string name;
	int score;

	cout << "Please enter a name and score: \n";
	while (cin >> name >> score)
	{
		bool unique = true;
		if (name == "NoName" && score == 0)
		{
			break;
		}
		for (Player n : players)
		{
			if (n.name == name)
			{
				unique = false;
				break;
			}
		}
		if (unique)
		{
			players.push_back(Player(name, score));
		}
	}

	cout << "Please enter a name to request it's records, or input an S followed by number to search by score: \n";

	while (cin >> name)
	{
		if (name == "Q")
		{
			break;
		}
		if (name == "S")
		{
			int searchScore;
			bool found = false;
			cin >> searchScore;
			for (int i = 0; i < players.size(); i++)
			{
				if (searchScore == players[i].score)
				{
					found = true;
					cout << players[i].name << " : " << players[i].score << '\n';
				}
			}
			if (!found)
			{
				cout << "Score not found";
			}
			continue;
		}

		bool found = false;
		for (int i = 0; i < players.size(); i++)
		{
			if (name == players[i].name)
			{
				cout << players[i].name << " : " << players[i].score << '\n';
				found = true;
			}
		}

		if (!found)
		{
			cout << "Name or Score not found.\n";
		}
	}

	return 0;
}