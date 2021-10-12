/**
 * @file DoubleLinkedList2.cpp
 * @author Matthew Lepis (mlepis@stevens.edu / lepismatthew@gmail.com)
 * @brief Linked List implementation which employs a previous pointer for backwards navigation. For CPE 593, Applied Algorithms and Data Structures.
 * @version 0.1
 * @date 2021-10-12
 */

/* Homework 
	Implement Linked List variant "DoubleLinkedList2"
		addEnd()
		addStart()
		removeEnd()
		use cout w/ '<<' operator or printList() if you're lazy
		size()	
*/
#include <ostream>
#include <iostream>
using std::cout;
using std::endl;

/**
 * @brief Node - a class that acts as a 'node' of the linked list. Nodes are linked together using the "Node" pointers via DoubleLinkedeList2.
 */
class Node
{
public:
	Node *prev;
	Node *next;
	int value;

	Node()
	{
		prev = nullptr;
		next = nullptr;
		value = 0;
	}
	Node(int v)
	{
		prev = nullptr;
		next = nullptr;
		value = v;
	}
};

/**
 * @brief Two-way navigable data structure. 
 */
class DoubleLinkedList2
{
private:
	unsigned int len;
public:
	Node* head;
	Node* tail;

	/**
	 * @brief Construct a new Double Linked List 2 object
	 */
	DoubleLinkedList2()
	{
		head = nullptr;
    	tail = nullptr;
    	len = 0;
	}

	/**
	 * @brief Construct a new Double Linked List 2 object : convert int array to DoubleLinkedList2
	 * 
	 * @param list 
	 * @param listLength 
	 */
	DoubleLinkedList2(int list[], int listLength)
	{
		DoubleLinkedList2();
		for(int i = 0; i < listLength; i++)
			addEnd(list[i]);
	}

	/**
	 * @brief Print via with cout <<
	 * 
	 * @param out 
	 * @param list 
	 * @return std::ostream& 
	 */
	friend std::ostream& operator <<(std::ostream& out, const DoubleLinkedList2& list)
	{
		if(list.head != nullptr)
			for(Node *temp = list.head; temp != nullptr; temp = temp->next)
				cout << temp->value << " ";
		return out;
	}

	/**
	 * @brief Prints the list forward or backwards
	 * 
	 * @param direction : True for forward, False for backwards
	 */
	void printList(bool direction)
	{
		if(head != nullptr)
		{
			if (direction) 	// Forward
				for(Node *temp = head; temp != nullptr; temp = temp->next)
					cout << temp->value << " ";
			else			// Backwards
				for(Node *temp = tail; temp != nullptr; temp = temp->prev)
					cout << temp->value << " ";	
		}
	}
	/**
	 * @brief returns size of list
	 * 
	 * @return int : size of list
	 */
	int size()
	{
		return len;
	}
	/**
	 * @brief Adds to the beginning of the list.
	 * 
	 * @param val : the value to be added to the front of the list
	 */
	void addStart(int val)
	{
		if(len == 0)
			head = tail = new Node(val);
		else
		{
			head->prev = new Node(val);
			head->prev->next = head;
			head = head->prev;
		}
		len++;
	}
	/**
	 * @brief Adds to the end of the list.
	 * 
	 * @param val : the value to be added to the front of the list
	 */
	void addEnd(int val)
	{
		if(len == 0)
			head = tail = new Node(val);
		else
		{
			tail->next = new Node(val);
			tail->next->prev = tail;
			tail = tail->next;
		}
		len++;	
	}
	/**
	 * @brief Removes the last value from the list.
	 * 
	 */
	void removeEnd()
	{
		if(len != 0)
		{
			tail = tail->prev;
			Node *temp = tail->next;
			tail->next = nullptr;
			delete temp;
			len--;
		}
	}
};

int main()
{
    DoubleLinkedList2 mylist;

    for (int i = 0; i < 10; i++)
      mylist.addEnd(i); // 0 1 2 3 4 5 6 7 8 9
    for (int i = 0; i < 10; i++)
      mylist.addStart(i); // 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
    for (int i = 0; i < 5; i++)
      mylist.removeEnd();  // this is the one that needs DoubleLinkedList!
    cout << mylist << '\n'; // print the list!
    cout << mylist.size();  
	return 0;
}