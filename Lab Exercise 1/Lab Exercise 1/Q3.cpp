#include <iostream>

int sumSquares(int *t_ptr, int t_elements)
{
	int sum = 0;
	
	for (int i = 0; i < t_elements; i++)
	{
		sum += *t_ptr * *t_ptr;
		*t_ptr++;
	}

	return sum;
}

int main2()
{
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
	int* ptrArray = array;
	int sum = 0;

	sum = sumSquares(array, sizeof(array) / sizeof(int));

	std::cout << sum << "\n";

	return 1;
}