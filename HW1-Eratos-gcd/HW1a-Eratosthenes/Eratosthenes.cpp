/*
     Author: Matthew Lepis
	 Date: 9/28/2021
	 Description: CPE593A, HW1, Eratosthenes Sieve
	 Citation: Dov Kruger, 2021F Number Theoretic Algorithms, CPE 593

*/

#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

uint32_t eratosthenes(uint64_t n)
{
	uint32_t count = 0;
	bool *isPrime = new bool[n+1];

	for (uint64_t i = 2; i <= n; i++)
		isPrime[i] = true;

	for (uint64_t i = 2; i <= sqrt(n); i++)
		if (isPrime[i])
		{
			count++;
			for (uint64_t j = 2*i; j <= n; j += i)
				if(isPrime[j] == true)
					isPrime[j] = false;
		}

	for (uint64_t i = sqrt(n)+1; i <= n; i++)
	{
		if (isPrime[i])
			count++;
	}
	delete [] isPrime;
	return count;
}

int main()
{
	uint64_t n;

	cout << "Eratosthenes Sieve\nUp to and including? ";
	cin >> n;

	auto start = std::chrono::steady_clock::now();
	cout << "\t# of Primes: " << eratosthenes(n) << endl;
	auto end = std::chrono::steady_clock::now();

	std::cout << "Execution Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

	return 0;
}