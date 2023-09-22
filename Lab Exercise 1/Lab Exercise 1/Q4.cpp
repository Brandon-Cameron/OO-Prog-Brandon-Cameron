#include <iostream>

int main()
{
	enum Enemy{ ZOMBIE, BOSS, ARCHER };

	enum Player{ ARCHER, MEDIC, MAGE };

	// The program fails to compile because legacy enums don't have
	// their own scope, therfore when the enum player attempts to
	// have the value ARCHER the program says its has already been
	// declared

	return 1;
}