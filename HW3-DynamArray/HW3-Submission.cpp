/*
	 Author: Matthew Lepis
	 Date: 10/2/2021
	 Description: CPE593A, HW3c, Capacity Based Growing Array; HW3 Main function cpp
*/

#include <iostream>
#include <string>
#include <chrono>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class DynamArray
{
private:
	int * data;
	int length;
	int capacity;

public:
	DynamArray()
	{
		data = 0;
		length = 0;
		capacity = 0;
	}
	DynamArray(const DynamArray& src)
	{
		data = new int[length];
		for(int i = 0; i < length; i++)
			data[i] = src.data[i];
		
		length = src.length;
		capacity = src.capacity;
	}
	DynamArray& operator = (const DynamArray& src)
	{
		data = new int[length];
		for(int i = 0; i < length; i++)
			data[i] = src.data[i];
		
		length = src.length;
		capacity = src.capacity;

		return *this;
	}
	~DynamArray()
	{
		delete [] data;
		data = 0;
	}

	int getData(int pos)
	{
		if (length == 0)
			std::cout << "The list is empty, no data to aquire.\n";

		else if(pos >= length || pos < 0)
			std::cout << "Requested position is out of bounds for the list.\n";

		else
			return data[pos];
	}
	void setData(int pos, int val)
	{
		if (length == 0)
			std::cout << "The list is empty, no data to aquire.\n";

		else if(pos >= length || pos < 0)
			std::cout << "Requested position is out of bounds for the list.\n";

		else
			data[pos] = val;		
	}

	int getLength()
	{
		return length;
	}

	void printList()
	{
		for(int i = 0; i < length; i++)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	}

	void capacityManager()
	{
		if(length == 0 && capacity == 0)
		{
			data = new int[length];
			capacity++;
		}
		else if(length == capacity)
		{
			capacity *= 2;
			const int* temp = data; 			// Creating temporary pointer to hold memory address for copying the old data from.
			data = new int[capacity];			// Creating new array of size + 1 to the old array at a new memory location. MEMORY ALLOCATION!

			for (int i = 0; i < length; i++)	// Looping through the array to copy data from the old (temp) array to the new (data) array.
				data[i] = temp[i];
			delete [] temp;						// Deleting the temp array		
		}
	}

	void addEnd(int val)
	{
		capacityManager();
		data[length] = val;					// Adding the new element to the array
		length++;
	}
	void addStart(int val)
	{
		// Array Size Management & Copying
		capacityManager();
		int temp;
		for (int i = length-1; i >= 0; i--)	// Looping through the array to copy data from the old (temp) array to the new (data) array.
			data[i+1] = data[i];

		// Adding in new value to the start of the array
		data[0] = val;		

		// Incrementing length
		length++;
	}
	void insert(int pos, int val)
	{
		if(pos > length || pos < 0)
			std::cout << "Provided position is out of bounds. Aborting Current Operation.\n";

		else if (length == 0)
		{
			capacityManager();

			std::cout << "List was empty, starting list with this value.\n";
			data[0] = val;
			length++;
		}
		else
		{
			capacityManager();

			int i = length-1;			
			while(i > pos-1)
			{
				data[i+1] = data[i];
				i--;
			}
			data[pos] = val;
			length++;
		}		
	}

	void removeEnd()
	{
		if (length == 0)
			std::cout << "List is already empty.\n";
		else
			length--;	
	}
	void removeStart()
	{
		if (length == 0)
			std::cout << "List is already empty.\n";
		else
		{
			for(int i = 0; i < length-1; i++)
				data[i] = data[i+1];

			length--;
		}	
	}	
	void remove(int pos)
	{
		if(pos >= length || pos < 0)
			std::cout << "Provided position is out of bounds.\n";

		else if (length == 0)
			std::cout << "List is already empty.\n";

		else
		{
			for(int i = pos; i < length; i++)
				data[i] = data[i+1];

			length--;
		}			
	}

	void HW3compaction(int multipleOf)
	{
		int j = 0;
		for (int i = 0; i < length; i++)
		{
			if (data[i] % multipleOf != 0)
			{
				data[j] = data[i];
				j++;
			}
		}
		int toRemove = length - j;
		while (toRemove > 0)
		{
			removeEnd();
			toRemove--;
		}
	}
	void HW3arrayInitializer(int start, int end)
	{
		if (start >= end)
			std::cout << "Invalid parameters, starting value must be smaller than ending value.\n";
		else
		{
			for (int i = start; i <= end; i++)
				addEnd(i);
		}
	}
};


DynamArray HW3inputParse2nd(string in, int inCount)
{
	DynamArray out;
	string temp = in;

	while(temp.find(" ") != -1)
	{
		out.addEnd(stoi(temp.substr(0, temp.find(" "))));
		temp = temp.substr(temp.find(" ")+1);
	}
	out.addEnd(stoi(temp.substr(0, temp.find(" "))));
	return out;
}

int main()
{
	int temp[3];
	uint64_t sum = 0;
	string secondInput;

	cout << "CPE 593A - Applied Data Structures\n\tHW3c - Growing Array\n\n";
	cout << "Please provide your first input string: ";
	cin >> temp[0] >> temp[1] >> temp[2];
	cin.ignore();
	cout << "\n";


	cout << "Please provide your second input string: ";
	getline(cin, secondInput);
	cout << "\n";

	DynamArray multiples = HW3inputParse2nd(secondInput, temp[2]);

	DynamArray list;
	list.HW3arrayInitializer(temp[0], temp[1]);


	auto start = std::chrono::steady_clock::now();

	for(int i = 0; i < multiples.getLength(); i++)
		list.HW3compaction(multiples.getData(i));

	auto end = std::chrono::steady_clock::now();

	for (int i = 0; i < list.getLength(); i++)
		sum += list.getData(i);

	cout << "Length of Array: " << list.getLength() << endl;
	cout << "Sum of array elements: " << sum << endl;
	cout << "Execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;

	return 1;
}