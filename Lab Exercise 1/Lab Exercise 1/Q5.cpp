#include <iostream>
#include <time.h>

int main()
{
	srand(time(NULL));

	enum class InventoryItem{ NONE, HEALTH_PACK, POWER_UP, SILVER_COIN, GOLD_COIN };

	InventoryItem array[5];

	for (int i = 0; i < sizeof(array) / sizeof(InventoryItem); i++)
	{
		array[i] = InventoryItem(rand() % 5);
		//std::cout << array[i] << "\n";
	}

	return 1;
}