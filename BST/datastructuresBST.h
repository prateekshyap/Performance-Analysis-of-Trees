class BSTList
{
public:
	BSTListNode * head, * tail; //head and tail pointers
	BSTList()
	{
		/*create a dummy node and point both head and tail to it*/
		head = new BSTListNode(0);
		tail = head;
	}
	void addNode(BSTNode *); //function to add a new node at the end of the list
	void trim(); //function to delete the dummy node
};

class BinarySearchTree
{
public:
	BSTNode * root; //root pointer
	BinarySearchTree()
	{
		root = nullptr;
	}
	BinarySearchTree(const BinarySearchTree &bst) //copy constructor
	{
		if (bst.root == nullptr) //store null if root is null
			root = nullptr;
		unordered_map<BSTNode *, BSTNode *> BSTNodeMap; //create a hashmap to map the nodes of two trees
		root = copyNodes(bst.root,BSTNodeMap); //call the copy nodes function
	}
	void insert(int); //insert
	BSTNode * search(int); //search
	void deleteX(int); //delete
	BSTList reverseInOrder(); //reverse inorder
	int successor(BSTNode *); //successor
	BSTNode * split(int); //split
	BSTList inOrder(); //inorder
	BSTList allElementsBetween(int, int); //all elements between k1 and k2
	int kthElement(int); //kth largest element
	void printTree(const char *); //print tree
	void printInOrder(BSTNode *);
	void evaluatePerformance();
	
private:
	void insertIntoTree(BSTNode *,int); //recursive insertion function
	void reduceSubtreeCount(BSTNode *); //function to reduce the subtree count during deletion
	bool isLeaf(BSTNode *); //function to check whether a node is leaf or not
	BSTNode * deleteLeafNode(BSTNode *,BSTNode *); //function to delete the leaf node
	BSTNode * deleteNodeWithSingleChild(BSTNode *,BSTNode *); //function to delete a node with single child
	BSTNode * leftMost(BSTNode *); //function to find the leftmost or the smallest node
	BSTNode * rightMost(BSTNode *); //function to find the rightmost or the largest node
	BSTNode * getParent(BSTNode *); //function to find the parent of a given node
	BSTNode * copyNodes(BSTNode *, unordered_map<BSTNode *, BSTNode *> &); //function called by the copy constructor
	int getTotalDepth(BSTNode *); //find the total depth of the tree
};

class BSTQueue
{
private:
	int size; //size of the queue

public:
	BSTQueueNode * front, * rear; //front and rear pointer
	BSTQueue()
	{
		front = rear = nullptr; //initialize both the pointers to null
		size = 0; //initialize size to 0
	}
	void enqueue(BSTNode *); //function to enqueue
	BSTNode * dequeue(); //function to dequeue
	bool isEmpty(); //function to check if the queue is empty
	int getSize(); //function to get the size of the queue
};