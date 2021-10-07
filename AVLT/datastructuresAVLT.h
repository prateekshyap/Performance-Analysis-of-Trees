class AVLTStack
{
private:
	int size; //size of the stack

public:
	AVLTStackNode * top; //top pointer of stack
	AVLTStack()
	{
		top = nullptr; //initialize to null
		size = 0; //initialize to 0
	}
	void push(AVLTNode *); //function to push
	AVLTNode * pop(); //function to pop
	bool isEmpty(); //function to check if the stack is empty
	int getSize(); //function to get the size of the stack
	AVLTNode * viewTop(); //function to get the top
};

class AVLTree
{
public:
	AVLTNode * root; //root pointer
	AVLTree()
	{
		root = new AVLTNode(-1);
		//root->left = new AVLTNode(0);
	}
	AVLTree(const AVLTree &avlt) //copy constructor
	{
		if (avlt.root->right == nullptr) //store null if root is null
			root->right = nullptr;
		unordered_map<AVLTNode *, AVLTNode *> treeNodeMap; //create a hashmap to map the nodes of two trees
		root->right = copyNodes(avlt.root->right,treeNodeMap); //call the copy nodes function
	}
	void insert(int); //insert
	void deleteK(int); //delete
	bool search(int); //search
	void print(const char *); //print tree
	void evaluatePerformance();

private:
	bool isLeaf(AVLTNode *); //function to check whether a node is leaf or not
	AVLTNode * searchNode(int); //search a node
	AVLTNode * deleteNodeWithNullChildren(AVLTNode *, AVLTNode *); //function to delete leaf node or nodes with single child
	AVLTNode * getParent(AVLTNode *); //function to find the parent of a given node
	AVLTNode * leftMost(AVLTNode *); //function to find the leftmost or the smallest node
	AVLTNode * rightMost(AVLTNode *); //function to find the rightmost or the largest node
	AVLTNode * rotateLL(AVLTNode *, AVLTNode *, int, int); //function for LL rotation
	AVLTNode * rotateRR(AVLTNode *, AVLTNode *, int, int); //function for RR rotation
	AVLTNode * rotateLR(AVLTNode *, AVLTNode *, int, int); //function for LR rotation
	AVLTNode * rotateRL(AVLTNode *, AVLTNode *, int, int); //function for RL rotation
	void transplant(AVLTNode *, AVLTNode *, AVLTNode *); //function to attach a subtree to main tree
	AVLTNode * copyNodes(AVLTNode *, unordered_map<AVLTNode *, AVLTNode *> &); //function called by the copy constructor
	void deleteNodes(AVLTNode *);
	int getTotalDepth(AVLTNode *); //find the total depth of the tree
};

class AVLTQueue
{
private:
	int size; //size of the queue

public:
	AVLTQueueNode * front, * rear; //front and rear pointer
	AVLTQueue()
	{
		front = rear = nullptr; //initialize both the pointers to null
		size = 0; //initialize size to 0
	}
	void enqueue(AVLTNode *); //function to enqueue
	AVLTNode * dequeue(); //function to dequeue
	bool isEmpty(); //function to check if the queue is empty
	int getSize(); //function to get the size of the queue
};