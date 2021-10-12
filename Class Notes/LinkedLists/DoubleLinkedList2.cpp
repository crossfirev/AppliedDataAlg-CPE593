/* Homework 
	Implement Linked List variant "DoubleLinkedList2"
		addEnd()
		addStart()
		removeEnd()
		use cout w/ '<<' operator or printList() if you're lazy
		size()
		
*/
#include <ostream>;

class DoubleLinkedList2
{
private:

	class Node
	{
	private:
		Node* next;
		Node* prev;
		int val;
	public:
		// Constructors.
		Node() : next(nullptr), val(0) {};								// ctor: Default
		Node(int v, Node n, Node p) : val(v), next(&n), prev(&p) {};	// ctor: Accepting a value, the next node and the last node.
	};
	Node* head;
	Node* tail;
	int size;
public:
	// Constructors.
	DoubleLinkedList2(int v)
	{
		head = new Node();
		tail =

	};
	DoubleLinkedList2()
	{

	};


	// For Printing out the linked list.
	friend std::ostream& operator <<(std::ostream& out, const DoubleLinkedList2& list)
   {

   }

	void addEnd()
	{

	}
	void addStart()
	{

	}
	void removeEnd()
	{

	}
	int size()
	{

	}

};










int main() {
	DoubleLinkedList2 mylist;

	for (int i = 0; i < 10; i++)
	  mylist.addEnd(i); // 0 1 2 3 4 5 6 7 8 9
	for (int i = 0; i < 10; i++)
	  mylist.addStart(i); 9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
	for (int i = 0; i < 5; i++)
	  mylist.removeEnd();  // this is the one that needs DoubleLinkedList!
	cout << mylist << '\n'; // print the list!
	cout << mylist.size();         
}