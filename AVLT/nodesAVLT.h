/*
* Node for AVL Tree
* Contains integer data, two self references, balance factor
*/
class AVLTNode
{
private:
	AVLTNode * left;
	int data;
	int bF;
	AVLTNode * right;

public:
	AVLTNode(int x)
	{
		data = x;
		bF = 0;
		left = right = nullptr;
	}
	
	friend class AVLTree;
};

/*
* Node for Queue
* Contains a reference to AVLTNode, a self reference
*/
class AVLTQueueNode
{
private:
	AVLTNode * avltNode;
	AVLTQueueNode * next;

public:
	AVLTQueueNode(AVLTNode * node)
	{
		avltNode = node;
		next = nullptr;
	}

	friend class AVLTQueue;
};

/*
* Node for Stack
* Contains a reference to AVLTNode, a self reference
*/
class AVLTStackNode
{
private:
	AVLTNode * avltNode;
	AVLTStackNode * next;

public:
	AVLTStackNode(AVLTNode * node)
	{
		avltNode = node;
		next = nullptr;
	}

	friend class AVLTStack;
};