/*
* Node for Linked List
* Contains integer and a self reference
*/
class BSTListNode
{
public:
	int data;
	BSTListNode * next;
	BSTListNode(int x)
	{
		data = x;
		next = nullptr;
	}
};

/*
Node for Binary Search Tree
Contains integer data, subtree counts, two self references, two boolean threads
*/
class BSTNode
{
public:
	BSTNode * left;
	bool leftThread;
	int data;
	bool rightThread;
	BSTNode * right;
	BSTNode(int x)
	{
		data = x;
		leftThread = rightThread = false;
		left = right = nullptr;
	}
};

/*
Node for Queue
Contains a reference to BSTNode, a self reference
*/
class BSTQueueNode
{
public:
	BSTNode * bstNode;
	BSTQueueNode * next;
	BSTQueueNode(BSTNode * node)
	{
		bstNode = node;
		next = nullptr;
	}
};