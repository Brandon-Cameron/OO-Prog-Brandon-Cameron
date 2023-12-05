#include <iostream>
#include <vector>
#include <ctime>

class Player 
{
public:
	Player(int t_id) : m_id(t_id), m_skill(rand() % 10) {}

	Player(Player const & t_player)
	{
		//std::cout << "Copied Player with id: " << t_player.m_id << "\n";
	}

	int skill() const
	{
		return m_skill;
	}

private:
	int m_id;
	int m_skill;
};

// t)playerList is now a reference argument (not copied)
unsigned long averageSkill(std::vector<Player> & t_playerList) 
{
	unsigned long averageSkill = 0;
	// Player variable p is a reference (Player not copied)
	for (Player & p : t_playerList)
	{
		averageSkill += p.skill();
	}
	return averageSkill / t_playerList.size();
}

int main() 
{
	srand(time(0));
	std::vector<Player> playerList;

	for (unsigned int i = 0; i < 50000000; i++)
	{
		if (playerList.size() - playerList.capacity() == 0)
		{
			//std::cout << "Vector resizing, copying " << playerList.size() << " elements to new location\n";
		}
		// This means create the Player in the vector directly
		// It does not get copied in
		playerList.emplace_back(i);
		//playerList.push_back(Player(i));
	}

	//std::cout << averageSkill(playerList);
}
