/* Homework 
	Implement Linked List variant "DoubleLinkedList2"
		addEnd()
		addStart()
		removeEnd()
		use cout w/ '<<' operator or printList() if you're lazy
		size()
		
*/
#include <iostream>
using std::cout;
using std::endl;

class Node
{
public:
	Node* prev;
	Node* next;
	int val;
	
	// Constructors.
	Node() : next(nullptr), val(0) {};								// ctor: Default
	Node(int v, Node *p, Node *n) : val(v), prev(p), next(n) {};	// ctor: Accepting a value, the next node and the last node.
};

class DoubleLinkedList2
{
private:
	Node* head;
	Node* tail;
	int length;

public:
	// Constructors.
	DoubleLinkedList2()
	{
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	// For Printing out the linked list.
	friend std::ostream& operator <<(std::ostream& out, const DoubleLinkedList2& list)
	{
		if(list.head != nullptr)
			for(Node* temp = list.head; temp != nullptr; temp = temp->next)
				cout << temp->val << " ";

		return out;
	}

	void printList(int direction)
	{
		if (direction == 1)
		{
			for(Node* temp = head; temp != nullptr; temp = temp->next)
				cout << temp->val << " ";
		}
	}

	void addEnd(int v)
	{
		if(length == 0)
		{
			head = new Node(v, nullptr, nullptr);
			tail = head;
		}
		else 
		{
			tail->next = new Node(v, tail, nullptr);
			tail = tail->next;
		}
		length++;
	}
 	void addStart(int v)
	{
		if(length == 0)
		{
			head = new Node(v, nullptr, nullptr);
			tail = head;
		}
		else
			head = new Node(v, nullptr, head);
		length++;
	}
	void removeEnd()
	{
		if(length != 0)
		{
			Node* temp = tail;
			tail = tail->prev;
			delete temp;
		}
		cout << size << endl;
	}
	int size()
	{
		return length;
	}

};

int main()
{
	DoubleLinkedList2 list;
	
	for (int i = 1; i <= 10; i++)
		list.addStart(i);
	for (int i = 1; i <= 10; i++)
		list.addEnd(i);
	for (int i = 1; i <= 10; i++)
		list.removeEnd();	
	cout << list.size() << endl;
	//list.printList();
	cout << 1 << endl;
}
/*

		DoubleLinkedList2 mylist;

	for (int i = 0; i < 10; i++)
	  mylist.addEnd(i);
	for (int i = 0; i < 10; i++)
	  mylist.addStart(i);
	for (int i = 0; i < 5; i++)
	  mylist.removeEnd();
	cout << mylist << '\n'; // print the list!
	cout << mylist.size(); 
}
*/
// HOMEWORK MAIN FUNCTION!
        
