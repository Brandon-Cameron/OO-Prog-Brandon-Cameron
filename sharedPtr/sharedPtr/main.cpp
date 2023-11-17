#include <iostream>

class Enemy
{
public:
	Enemy(int t_health) : m_health(t_health){}
	~Enemy()
	{
		std::cout << "~Enemy() called" << "\n";
	}
	int m_health;
};

std::shared_ptr<Enemy> createEnemy()
{
	std::shared_ptr<Enemy> sptr = std::make_shared<Enemy>(10);
	return sptr;
}

int main()
{
	auto sp = createEnemy();
	// Increase the reference count by 1
	std::shared_ptr<Enemy> sp2 = sp;
	// Next two lines drop the refernec count back to 0
	sp2 = nullptr;
	sp = nullptr;
	// Allocate an interger on the heap
	// Use shared_ptr to manage that int
	std::shared_ptr<int> sptr = std::make_shared<int>(100);
	std::cout << *sptr << "\n";
	// Print the reference count for the heap resourse
	std::cout << sptr.use_count() << "\n";
}