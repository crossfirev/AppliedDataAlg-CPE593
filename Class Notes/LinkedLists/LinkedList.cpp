#include <iostream>


class LinkedList
{
private:
	class Node // LinkedList::Node
	{
		int val;
		Node* next; 
		Node() : val(0), next(nullptr) {}
		Node(int v, Node* n) : val(v), next(n) {};
	};
	Node* head;
	int size;
public:
	LinkedList(){
		head = nullptr;
		size = 0;
	}

	friend ostream& operator <<(ostream& s, const DoubleLinkedList2& list)
	{
		
	}
	void addFirst(int val){
		/*Node temp = new Node();
		temp.val = val;
		temp.next = head;
		head = temp;*/

		head = new Node(val, head);  // Same process as the above comment, but uses specialized constructor.
		size++;
	}
	void addEnd(int val)
	{
		Node* p;
		if (head != nullptr)
			for(p = head; p->next != nullptr; p = p->next)
				p->head = new Node(val, nullptr);
		else
			head = new Node(val, nullptr);
		size++;
	}

	int getSize() const {
		/*
	  int count = 0;
	  for (Node* p = head; p != nullptr; p = p->next)
		count++;
	  return count;
	  */
	 return size;
		
	}
};

int main() {
	LinkedList a;
	a.addFirst(5);
	a.addEnd(9);

	int n = 1000;
	for (int i = 0; i < n; i++)
		a.addStart(i);
	for (int i = 0; i < n; i++)
		a.addEnd(i);
	
}