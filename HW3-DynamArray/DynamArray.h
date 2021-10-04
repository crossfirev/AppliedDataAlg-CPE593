/*
	 Author: Matthew Lepis
	 Date: 10/2/2021
	 Description: CPE593A, HW3c, Capacity Based Growing Array; DynamArray Header.
*/

/* Notes:
addEnd(value)       : Adds a value to the end of the list
addStart(value)     : Adds a value to the start of the list
insert(pos, value)  : Adds a value to the given position

removeEnd()         : Removes a value from the end of the list
removeStart()       : Removes a value from the start of the list
remove(pos)         : Removes a value from the given position

get(pos)            : Retrieves the value from the given position
set(pos, value)     : Sets the value at a given position

size()              : Retrieves the size of the list (# of elements)
*/
#include <iostream>

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
