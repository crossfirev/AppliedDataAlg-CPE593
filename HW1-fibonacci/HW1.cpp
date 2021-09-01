/*
     Author: Matthew Lepis
	 Date: 8/31/202
	 Description: CPE593A, HW1, fibonacci recursion
*/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int fiboIterative(int n) // Iteratively finds the requested fibonacci number
{
	// Order // 1, 2, 3, 4, 5, 6,  7,  8,  9, ...
	// Fibon // 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
	// Vars1 // a, b, c,  ,  ,  ,   ,   ,   , ...
	// Vars2 //  , a, b, c,  ,  ,   ,   ,   , ...
	
	int a = 1, b = 1, c;
	
	if(n == 1 || n == 2)
		return 1;
	else
	{
		for(int i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

int fiboRecursive(int n) // Recursively find the requested fibonacci number
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fiboRecursive(n-1) + fiboRecursive(n-2);
}

int fiboRecursiveDynamic(int n) // Recursively find the requested fibonacci number, utilizing dynamic programming...Memorization
{
	static int memory[200] = {1, 1};
	
	if (memory[n-1] != 0)
		return memory[n-1];
	else
		if(memory[n-2] == 0)
			memory[n-2] = fiboRecursiveDynamic(n-2);
		if(memory[n-3] == 0)
			memory[n-3] = fiboRecursiveDynamic(n-3);
		memory[n-1] = memory[n-2] + memory[n-3];
		return fiboRecursive(n-1) + fiboRecursive(n-2);
}

int main()
{	
	int n;
	cout << "Enter wanted fibonacci number: ";
	cin >> n;
	
	cout << "Iterative Approach Answer: " << fiboIterative(n) << endl;
	cout << "Recursive Approach Answer: " << fiboRecursive(n) << endl;
	cout << "Dynamic Recursive Approach Answer: " << fiboRecursiveDynamic(n) << endl;
	return 0;
}