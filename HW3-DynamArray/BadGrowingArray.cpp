/*
	 Author: Matthew Lepis
	 Date: 10/2/2021
	 Description: CPE593A, HW3c, Bad Growing Array


	 NOT TO BE USED! THIS IS BAD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	 /\     /\     /\     /\     /\     /\     /\     /\     /\     /\     /\     
	Use DynamArray.h instead!
	/\     /\     /\     /\     
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
using namespace std;

class BadGrowArray
{
private:
	int * data;
	int length;

public:
	BadGrowArray()
	{
		data = NULL;
		length = 0;
	}
	BadGrowArray(const BadGrowArray& src)
	{
		data = new int[length];
    	for(int i = 0; i < length; i++)
        	data[i] = src.data[i];
		
		length = src.length;
	}
	BadGrowArray& operator = (const BadGrowArray& src)
	{
		data = new int[length];
    	for(int i = 0; i < length; i++)
        	data[i] = src.data[i];
		
		length = src.length;

		return *this;
	}
	~BadGrowArray()
	{
		delete [] data;
		data = NULL;
	}

	int getData(int pos)
	{
		if (length == 0)
			cout << "The list is empty, no data to aquire.\n";

		else if(pos >= length || pos < 0)
			cout << "Requested position is out of bounds for the list.\n";

		else
			return data[pos];
	}
	void setData(int pos, int val)
	{
		if (length == 0)
			cout << "The list is empty, no data to aquire.\n";

		else if(pos >= length || pos < 0)
			cout << "Requested position is out of bounds for the list.\n";

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
			cout << data[i] << " ";
	}

	void addEnd(int val)
	{
		if (length == 0)
		{
			data = new int [length];
			data[length] = val;
		}
		else
		{
			const int* temp = data; 			// Creating temporary pointer to hold memory address for copying the old data from.
			data = new int[length + 1];			// Creating new array of size + 1 to the old array at a new memory location. MEMORY ALLOCATION!

			for (int i = 0; i < length; i++)	// Looping through the array to copy data from the old (temp) array to the new (data) array.
				data[i] = temp[i];
			delete [] temp;						// Deleting the temp array

			data[length] = val;					// Adding the new element to the array
		}
		length++;
	}
	void addStart(int val)
	{
		if (length == 0)
		{
			data = new int [length];
			data[length] = val;
		}
		else
		{
			const int* temp = data; 			// Creating temporary pointer to hold memory address for copying the old data from.
			data = new int[length + 1];			// Creating new array of size + 1 to the old array at a new memory location. MEMORY ALLOCATION!

			for (int i = 0; i < length; i++)	// Looping through the array to copy data from the old (temp) array to the new (data) array.
				data[i+1] = temp[i];
			delete [] temp;						// Deleting the temp array

			data[0] = val;		
		}
		length++;
	}
	void insert(int pos, int val)
	{
		if(pos > length || pos < 0)
			cout << "Provided position is out of bounds.\n";

		else if (length == 0)
		{
			cout << "List was empty, starting list with this value.\n";
			data = new int [length];
			data[length] = val;
			length++;
		}
		else
		{
			const int* temp = data; 			// Creating temporary pointer to hold memory address for copying the old data from.
			data = new int[length + 1];			// Creating new array of size + 1 to the old array at a new memory location. MEMORY ALLOCATION!

			for (int i = 0; i <= length; i++)	// Looping through the array to copy data from the old (temp) array to the new (data) array.
			{
				if(i < pos)
					data[i] = temp[i];
				else if (i > pos)
					data[i] = temp[i-1];
				else
					data[i] = val;
			}
			delete [] temp;						// Deleting the temp array	
			length++;
		}		
	}

	void removeEnd()
	{
		if (length == 0)
			cout << "List is already empty.\n";
		else
		{
			const int* temp = data; 			// Creating temporary pointer to hold memory address for copying the old data from.
			data = new int[length];				// Creating new array of size + 1 to the old array at a new memory location. MEMORY ALLOCATION!

			for (int i = 0; i < length-1; i++)	// Looping through the array to copy data from the old (temp) array to the new (data) array.
				data[i] = temp[i];
			delete [] temp;						// Deleting the temp array
			length--;	
		}		
	}
	void removeStart()
	{
		if (length == 0)
			cout << "List is already empty.\n";
		else
		{
			const int* temp = data; 			// Creating temporary pointer to hold memory address for copying the old data from.
			data = new int[length];				// Creating new array of size + 1 to the old array at a new memory location. MEMORY ALLOCATION!

			for (int i = 1; i < length; i++)	// Looping through the array to copy data from the old (temp) array to the new (data) array.
				data[i-1] = temp[i];
			delete [] temp;						// Deleting the temp array	
			length--;
		}	
	}	
	void remove(int pos)
	{
		if(pos >= length || pos < 0)
			cout << "Provided position is out of bounds.\n";

		else if (length == 0)
			cout << "List is already empty.\n";

		else
		{
			const int* temp = data; 			// Creating temporary pointer to hold memory address for copying the old data from.
			data = new int[length];				// Creating new array of size + 1 to the old array at a new memory location. MEMORY ALLOCATION!

			for (int i = 0; i < length; i++)	// Looping through the array to copy data from the old (temp) array to the new (data) array.
			{
				if(i < pos)
					data[i] = temp[i];
				else if (i > pos)
					data[i] = temp[i+1];
			}
			length--;
		}			
	}
};

int main()
{
	BadGrowArray list, list2;

	list.addEnd(2);
	list.addEnd(3);
	list.insert(2, 6);
	list.addStart(4);

	list.printList();
	return 1;
}
