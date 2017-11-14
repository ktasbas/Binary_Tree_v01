//M. Kaan Tasbas
//12 November 2017
//COP3530 Data Structure and Algorithm Analysis
//Dr. Feng-Hao Liu
//Homework 4


#include<iostream>

using namespace std;


class TNode
{
public:
	int val;
	TNode() {}
	TNode(int v) { val = v; }
	TNode * left;
	TNode * right;
	TNode * parent;
};



class BTree
{
public:

	//constructors and destructor
	BTree();
	BTree(TNode *r);// initialize BTree with the root r. r is the only node.
	BTree(const BTree & t); // copy constructor
	BTree(const int *p, const int n);// similar to the copy constructor, but your input is of the array form.
									 // input is given an array that denotes a tree that uses  up to n slots. The size of the tree is not given directly as input.
									 // the array is pointed by p and has size n, where p[0] is used to store the empty symbol.
									 //the function converts the array representation into a linked-list representation, i.e. BTree



	~BTree();

	int size;
	TNode *root;

	TNode * convertpos(int position);// find the pointer where the position points to

	void add2left(TNode *newnode, TNode *p);
	void add2right(TNode *newnode, TNode *p);

	void add2left(TNode *newnode, int position);
	void add2right(TNode *newnode, int position);


	void add2left(BTree *newsubtree, int position);
	void add2right(BTree *newsubtree, int position);


	void removeleaf(int position);
	void removeleaf(TNode *p);

	void swapnodes(TNode *n1, TNode *n2);//swap-the-values is fine

	int * Toarray(int &n);// convert the BT into the array form. Determine what n should be, and new an array of size n+1, and store the empty symbol at array[0]. Convert the BT into the array form and  retrun the array pointer. The size of the array will be given to the variable n.

	void print_pre_order();// print the node as you traverse according to the order.
	void print_in_order();
	void print_post_order();
	bool isValidBST(); // return whether this BT is a valid BST
};

bool isValidBT(const int *p, const int n);


bool isValidBT(const int *p, const int n) //p points to array, n is number of slot used in array
{
	//need to calculate size of array based on slots used
	//max n layers -> max size = 2^n - 1
	//int size = (1 << n) - 1;
	/* technically size of array not given, only number of slots used so must determine max 
	/  possible size array to fit given number of slots used but this will likely cause
	/  access violation exceptions that cannot be caught real time... don't implement */

	//check for parents
	for (int i = n-1; i > 1; i--) //n-1 because last element = size-1 //lower limit 1 because top root has no parent
	{
		if (p[i/2] != p[0]) {
			//each node has a parent
		}
		else
		{
			//node has no parent
			return false;
		}
	}
	
	//check for max 2 children
	//Can't check using simple implementation, unnecessary for now
}


int main()
{
	int arr[10] = { -1, 1, 2, 3, 4, -1, -1, -1, -1, -1 };
	cout << isValidBT(arr, 10);


	return 0;
}