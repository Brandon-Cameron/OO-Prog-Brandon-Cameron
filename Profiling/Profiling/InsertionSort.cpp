#include <vector>
#include <algorithm>

void quickSort(std::vector<int> & t_v)
{
	std::sort(t_v.begin(), t_v.end());
}

void insertionSort(std::vector<int> & t_v)
{
	int j, temp;
	int size = t_v.size();
	for (int i = 0; i < size; i++)
	{
		j = i;

		while (j > 0 && t_v.at(j) < t_v.at(j-1))
		{
			temp = t_v.at(j);
			t_v.at(j) = t_v.at(j-1);
			t_v.at(j-1) = temp;
			j--;
		}
	}
}