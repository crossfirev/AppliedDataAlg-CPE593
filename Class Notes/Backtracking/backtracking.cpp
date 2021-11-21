[/**
 * @file backtracking.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

class BackTracking
{
private:
	int* p;

public:

	BackTracking(int n)
	{
		p = new int[n];
		for (int i = 0; i < n; i++)
			p[i] = i+1;
		generate(n-1);
	}

	void generate(int n)
	{
		if (n == 0)
		{
			doit();
			return;
		}

		for(int c = 0; c <= n; c++)
		{
			generate(n-1);
			swap(n % 2 != 0 ? 0  : c, n);
		}

	} 


	void doit()
	{
		for (int i = 0; i < sizeof(p)/sizeof(p[0]); i++)
		{
			cout << p[i] << " " << endl;
		}
	}
};

int main()
{

	return 0;
}
