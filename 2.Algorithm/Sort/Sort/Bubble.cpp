#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& arr)
{
	int num = arr.size();

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void PrintArray(std::vector<int>& arr)
{
	for (int num : arr)
	{
		std::cout << num << ' ';
	}
}

int main()
{
	std::vector<int> arr = { 5, 3, 8, 4, 23, 3, 9, 10, 11, 28, 30 };
	std::cout << "Unsorted array: ";
	PrintArray(arr);

	BubbleSort(arr);

	std::cout << "\nSorted array: ";
	PrintArray(arr);
	return 0;
}