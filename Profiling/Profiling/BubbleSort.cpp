#include <vector>

void bubbleSort(std::vector<int> & t_v)
{
	int temp;
	int size = t_v.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (t_v.at(j) > t_v.at(j+1))
			{
				temp = t_v.at(j);
				t_v.at(j) = t_v.at(j + 1);
				t_v.at(j+1) = temp;
			}
		}
		// Largest number 'bubbles' to position (size-i-1) at end of each pass
		// std::cout << size-i-1 << " " << t_v.at(size-i-1) << std::endl;
		
	}
}
