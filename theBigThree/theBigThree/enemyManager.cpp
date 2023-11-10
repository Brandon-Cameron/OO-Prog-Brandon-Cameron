#include <iostream>

enum class EnemyType
{
	BOSS,
	GUARDIAN,
	MINION
};

class Enemy
{
	friend class EnemyManager;
public:
	Enemy(EnemyType t_type = EnemyType::BOSS) : m_type(t_type)
	{
	}
private:
	EnemyType m_type;
};

class EnemyManager
{
public:
	EnemyManager(int t_enemies) :
		m_length(t_enemies),
		m_enemy(new Enemy[t_enemies])
	{
		for (int i = 0; i < t_enemies; i++)
		{
			int nextType = (static_cast<int>(m_enemy[i].m_type) + i) % 3;
			m_enemy[i].m_type = static_cast<EnemyType>(nextType);
		}
	}

	EnemyManager(EnemyManager const& t_copy)
	{
		m_enemy = new Enemy[t_copy.m_length];

		memcpy(m_enemy, t_copy.m_enemy, sizeof(Enemy) * t_copy.m_length);
	}

	~EnemyManager()
	{
		delete[] m_enemy;
	}

	void operator=(EnemyManager const& t_rhs)
	{
		if (this != &t_rhs)
		{
			if (m_length != t_rhs.m_length)
			{
				delete[] m_enemy;

				m_enemy = new Enemy[t_rhs.m_length];
			}
			memcpy(m_enemy, t_rhs.m_enemy, sizeof(Enemy) * t_rhs.m_length);

			m_length = t_rhs.m_length;
		}
	}

private:
	Enemy* m_enemy;
	int m_length;
};

EnemyManager create()
{
	EnemyManager manager(10);
	return manager;
}

int main()
{
	EnemyManager enemyManager1(10);
	EnemyManager enemyManager2 = enemyManager1;

	return 1;
}