#include <iostream>

// CLass EnemyBot
class EnemyBot
{
public:
	EnemyBot(std::string t_name) : m_name(t_name)
	{}

	~EnemyBot()
	{
		std::cout << "Deleting : " << m_name << "\n";
	}

	void setPartner(std::shared_ptr<EnemyBot> t_partner)
	{
		m_partner = t_partner;
	}

	std::string getName() const
	{
		return m_name;
	}
	
	std::weak_ptr<EnemyBot> getPartner()
	{
		return m_partner;
	}

private:
	std::weak_ptr<EnemyBot> m_partner;
	std::string m_name;
};

void spawnBots()
{
	std::shared_ptr<EnemyBot> bigBot =
		std::make_shared<EnemyBot>("Bigbot");
	
	std::shared_ptr<EnemyBot> smallBot =
		std::make_shared<EnemyBot>("Smallbot");
	// set a reference from bigbot to smallbot
	bigBot->setPartner(smallBot);
	// set a reference from smallbot to bigbot
	smallBot->setPartner(bigBot);
	// Get a shared_ptr from the weak_ptr reference
	std::shared_ptr<EnemyBot> temp = smallBot->getPartner().lock();

	int bigStrongRefCount = bigBot.use_count();
	int bigWeakRefCount = smallBot->getPartner().use_count();


	// Print the name of bigBot from the smallBot object
	std::cout << temp->getName() << "\n";
}

int main()
{
	spawnBots();
}