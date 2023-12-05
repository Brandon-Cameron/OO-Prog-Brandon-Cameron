#include <iostream>
#include <vector>

// Three sorting algorithms
void quickSort(std::vector<int> & t_v);
void insertionSort(std::vector<int> & t_v);
void bubbleSort(std::vector<int> & t_v);

void orderHighToLow(std::vector<int>& t_v)
{
	for (int x = 0; x < t_v.size(); x++)
	{
		t_v.at(x) = t_v.size() - x;
	}
}

int main1()
{
	std::vector<int> v;

	int const SIZE = 200000;
	v.resize(SIZE);
	
	orderHighToLow(v);
	bubbleSort(v);
	orderHighToLow(v);
	insertionSort(v);
	orderHighToLow(v);
	quickSort(v);

}