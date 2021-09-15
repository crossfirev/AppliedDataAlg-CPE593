/**
 * @file SortingAlgorithms.cpp
 * @author Matthew Lepis
 * @brief A collection of sorting algorithms
 * @version 0.1
 * @date 2021-09-14
 */
#include <iostream>
using namespace std;

/**
 * @brief uint64_t swapper; takes two uint64_t Pass-By-References (i and j) and swaps their values.
 * 
 * @param i
 * @param j 
 */
void swap(uint64_t &i, uint64_t &j)
{
	i = i + j;
	j = i - j;
	i = i - j;
}

/**
 * @brief Prints out the given array of type uint64_t
 * 
 * @param arr ; array to be printed
 * @param n ; size of arr
 */
void printArray(uint64_t arr[], uint64_t n)
{
	for(uint64_t i = 0; i < n; i++)
	{
		if (i != n-1)
			std::cout << arr[i] << ", ";
		else
			std::cout << arr[i] << endl;
	}
}

/**
 * @brief bubbleSort Implementation
 * 
 * @param arr ; input array of type uint64_t
 * @param n ; number of elements in arr
 */
void bubbleSort(uint64_t arr[], uint64_t n, bool accending)
{
	// Bubble sort is: counter < n-1

	if (accending)
	{
		for (uint64_t i = 0; i < n-1; i++)
			for (uint64_t j = 0; j < n-1-i; j++)
				if (arr[j] > arr[j+1])
					swap(arr[j], arr[j+1]);
	}
	else
	{
		for (uint64_t i = 0; i < n-1; i++)
			for (uint64_t j = 0; j < n-1-i; j++)
				if (arr[j] < arr[j+1])
					swap(arr[j], arr[j+1]);
	}
}

void selectionSort(uint64_t arr[], uint64_t n, bool accending)
{
	uint64_t minIndex = 0;
	bool swapBool = false;

	if (accending)
	{
		for (uint64_t i = 0; i < n; i++)
		{
			for (uint64_t j = i; j < n; j++)
			{
				if (arr[minIndex] > arr[j])
				{
					minIndex = j;
					swapBool = true;
				}
			}
			if(swapBool)
				swap(arr[i], arr[minIndex]);
			minIndex = i+1;
			swapBool = false;
		}
	}
	else
		for (uint64_t i = 0; i < n; i++)
		{
			for (uint64_t j = i; j < n; j++)
			{
				if (arr[minIndex] < arr[j])
				{
					minIndex = j;
					swapBool = true;
				}
			}
			if(swapBool)
				swap(arr[i], arr[minIndex]);
			minIndex = i+1;
			swapBool = false;
		}		
}

int main()
{
	uint64_t 	arr1[] = {1, 2, 3, 4, 5}, 
				arr2[] = {5, 4, 3, 2, 1},
				arr3[] = {3, 5, 1, 4, 2},
				arr4[] = {3, 2, 4, 5, 1};

	uint64_t 	size = *(&arr1 + 1) - arr1,
				accending = true;

	
	printArray(arr1, size);
	selectionSort(arr1, size, accending);
	printArray(arr1, size);
	cout << endl;

	printArray(arr2, size);
	selectionSort(arr2, size, accending);
	printArray(arr2, size);
	cout << endl;

	printArray(arr3, size);
	selectionSort(arr3, size, accending);
	printArray(arr3, size);	
	cout << endl;

	printArray(arr4, size);
	selectionSort(arr4, size, accending);
	printArray(arr4, size);
	cout << endl;

	return 1;
}