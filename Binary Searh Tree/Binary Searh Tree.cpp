#include <iostream>
#include <string>

using namespace std;

// BinarySearchTree_0190
//Minimal commit 15

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//Constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = nullptr; // Initializing Root to null
	}

	void insert(string element) //Insert a node in the binary search tree
	{
		Node* newNode = new Node(element, nullptr, nullptr); // allocate memory for the new node
		newNode->info = element; //Assignn value to the data field of the new node
		newNode->leftchild = nullptr; // Make the left child of the new node point to NULL
		newNode->rightchild = nullptr; //Make the right child of the new node point to NULL

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode); // Locate the node which will be the parent of the node to be insert

		if (parent == nullptr) //if the parent is Null (Tree is empty)
		{
			ROOT = newNode; // Mark the new node as ROOT
			return; //Exit
		}
		if (element < parent->info) // if the value in the dta field of the new node is less than that of the
		{
			parent->leftchild = newNode; // Make the left child of the parent poiint to the new node
		}
		else if (element > parent->info) //if th value in the data field of the new node is greater than that
		{
			parent->rightchild = newNode; // Make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode)
	{
		//this function searches the currentNode of the specified Node as well as the curent Node of itss parent
		currentNode = ROOT;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}
	void inorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}