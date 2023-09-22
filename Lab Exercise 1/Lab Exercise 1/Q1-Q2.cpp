#include <iostream>

int main()
{
	//Q1
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *ptrArray = array;

	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		std::cout << *ptrArray + i << "\n";
	}

	std::cout << "sizeof(array) " << sizeof(array) << "\n";
	std::cout << "sizeof(array) " << sizeof(ptrArray) << "\n";

	//Q2
	for (int& ref : array)
	{
		//ref++;
		std::cout << ref << "\n";
	}

	return 1;
}