/**
 * @file SortingAlgorithms.cpp
 * @author Matthew Lepis
 * @brief A collection of sorting algorithms
 * @version 0.1
 * @date 2021-09-14
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
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
 * @brief Bubble sort implementation
 * 
 * @param arr ; input array of type uint64_t
 * @param n ; number of elements in arr
 * @param accending ; boolean for denoting the order of sort, true = accending order, false = descending order
 */
void bubbleSort(uint64_t arr[], uint64_t n, bool accending)
{
	// Bubble sort is: counter < n-1

	if (accending) // choosing direction of sort
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

/**
 * @brief Selection sort implementation
 * 
 * @param arr ; input array of type uint64_t
 * @param n ; number of elements in arr
 * @param accending ; boolean for denoting the order of sort, true = accending order, false = descending order
 */
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

/**
 * @brief Insertion sort implementation
 * 
 * @param arr ; input array of type uint64_t
 * @param n ; number of elements in arr
 * @param accending ; boolean for denoting the order of sort, true = accending order, false = descending order
 */
void insertionSort(uint64_t arr[], uint64_t n, bool accending)
{
	uint64_t key;
	int64_t j;

	if (accending)
	{
		for (uint64_t i = 1; i < n; i++)
		{
			key = arr[i];
			j = i - 1;
			while (j >= 0 && arr[j] > key)
			{
				arr[j+1] = arr[j];
				arr[j] = key;
				j -= 1;
			}
		}
	}
	else
	{
		for (uint64_t i = 1; i < n; i++)
		{
			key = arr[i];
			j = i - 1;
			while (j >= 0 && arr[j] < key)
			{
				arr[j+1] = arr[j];
				arr[j] = key;
				j -= 1;
			}
		}		
	}
}


void quickSort(uint64_t arr[], uint64_t low, uint64_t high)
{
	if ((high - low) < 2)
		return;
	uint64_t pivotIndex = (high+low)/2, l = low, h = high;

	while (l < h && arr[l] != arr[h])
	{
		while (arr[l] < arr[pivotIndex] && l != h)
			l++;
		while (arr[h] > arr[pivotIndex] && h != l)//---------
			h--;
		if (l < h && arr[l] != arr[h] && l != h)
		{
 			swap(arr[l], arr[h]);
			if (l == pivotIndex)
				pivotIndex = h;
			if (h == pivotIndex)
				pivotIndex = l;
		}
	}
	quickSort(arr, low, pivotIndex);
	quickSort(arr, pivotIndex+1, high);
	
}

int main()
{
	uint64_t 	arr1[] = {1, 2, 3, 4, 5},
				arr2[] = {5, 4, 3, 2, 1},
				arr3[] = {3, 5, 1, 4, 2},
				arr4[] = {3, 2, 4, 5, 1},
				arr5[] = {2, 8, 5, 3, 9, 4},
				arr6[] = {10, 6, 5, 3, 5};

	uint64_t 	size = *(&arr1 + 1) - arr1;
	bool		accending = false;

	printArray(arr1, size);
	quickSort(arr1, 0, size-1);
	printArray(arr1, size);
	cout << endl;

	printArray(arr2, size);
	quickSort(arr2, 0, size-1);
	printArray(arr2, size);
	cout << endl;

	printArray(arr3, size);
	quickSort(arr3, 0, size-1);
	printArray(arr3, size);	
	cout << endl;

	printArray(arr4, size);
	quickSort(arr4, 0, size-1);
	printArray(arr4, size);
	cout << endl;

	printArray(arr5, size+1);
	quickSort(arr5, 0, size);
	printArray(arr5, size+1);
	cout << endl;

	printArray(arr6, size+1);
	quickSort(arr6, 0, size-1);
	printArray(arr6, size+1);
	cout << endl;

	return 1;
}