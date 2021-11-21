/*
Binary Tree
Ordered Binary Tree
Balanced Trees
	RB-Tree
	AVL Trees (not covered)
	Fibonacci tree (not covered)
	BTree
Tries
*/

// Binary Tree
//  Root - Node, start of the tree
//      Every node has AT MOST 2 children
//      Nodes with no children are LEAF NODES
//      Branches cannot rejoin

class BinaryTree
{
private:
	class Node {
  public:
	int val;
	Node* parent;
	Node* left;                // int* a,b; a is pointer to int, b is just int
	Node* right;
	Node(int v, Node* L, Node* r) : val(v), left(L), right(R) {}
  };
	Node* root;
public:
	BinaryTree() : root(nullptr) {}
	
	void add(int v)
	{
		if (root == nullptr)
		{
			root = new Node(v, nullptr, nullptr);
			return;
		}
	}
};

// Printing orders
/*
INORDER

		inorder(node n)
			if n == null
				return
			inorder(n.left)
			print (val)
			inorder(n.right)
		end

		-OR-

		inorder(node n)
			if n.left != null
				inorder(n.left)
			print (val)
			if n.right != null
				inorder(n.right)
		end

PREORDER

		preorder(node n)
			if n == null
				return
			print (val)
			preorder(n.left)
			preorder(n.right)
		end

POSTORDER

		postorder(node n)
			if n == null
				return
			postorder(n.left)
			postorder(n.right)
			print (val)
		end
*/	
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;


int main() {
  map<string, double> obt;
  obt["IBM"] = 123.45; // O(log(n))

// THIS IS DIFFERENT FROM MAP IN SOMEWAY. IDK.
  unordered_map<string, double> hm;
  hm["IBM"] = 123.45; // O( 1  )
  hm["AAPL"] = 151.45;
  hm["T"] = 29.0;

  unordered_map<string,double>::iterator i = hm.find("x");
  if (i != hm.end()) {
    double price = i->second;
  }
  for (pair<string, double> element : hm)
  {
    cout << element.first << " :: " << element.second << endl;
  }
  for (auto e : hm) {
    cout << e.first << " :: " << e.second << endl;
  }
}

// SOMETHING SOMETHING BLACK RED TREE AND SORTED TREES


// TRIES
