/*bstFileCount stores a number so that multiple files could be created easily*/
int bstFileCount = -1, bstFileType = -1;
string bstColor = "black"; //stores the bstColor names
int insertKeyComparisons = 0, deleteKeyComparisons = 0; //total key comparisons
int insertRotateCount = 0, deleteRotateCount = 0; //total number of rotations
int tempCount = 0, maxHeight = -1;
long nodeCount = 0, totalHeight = 0, totalDepth = 0;

/**************************************************************************************************************
 * Utility functions
 * ***********************************************************************************************************/
/*void printMessage()
{
	/*The initial message printed just after starting the execution
	cout << "1- Insert x" << endl;
	cout << "2- Search x" << endl;
	cout << "3- Delete x" << endl;
	cout << "4- Reverse Inorder Traversal" << endl;
	cout << "5- Successor of x" << endl;
	cout << "6- Split the tree around k" << endl;
	cout << "7- Elements between k1 and k2" << endl;
	cout << "8- kth largest element" << endl;
	cout << "9- Print tree" << endl;
	cout << "10- Quit" << endl;
	cout << "Input Format-\n9\nmeans print the tree\n1\n5\n9\nmeans insert 5 into tree and then print tree\n7\n9\n14\nmeans find elements between 9 to 14" << endl;
	cout << "Write a .txt file in mentioned format and give the file name-" << endl;
	cout << "You can check execution details in output.txt" << endl;
}*/

void printLinkedList(BSTList list, ofstream &file)
{
	BSTListNode * temp = list.head; //make temp to point head
	while (temp != nullptr) //till temp is not null
	{
		cout << temp->data << "->"; //print the value to console
		file << temp->data << "->"; //print the value to file
		temp = temp->next; //move temp to next node
	}
	cout << "X" << endl; //print end of list to console
	file << "X" << endl; //print end of list to file
}

void generatePNGInBST(int os)
{
	/*if os is windows run the batch file*/
	if (os == 0)
		std :: system("commands.bat");
	/*if os is linux change the permission and run the shell script*/
	else if (os == 1)
	{
		std :: system("chmod +x commands.sh");
		std :: system("./commands.sh");
	}
}


/**************************************************************************************************************
 * Functions for BSTList
 * ***********************************************************************************************************/
void BSTList :: addNode(BSTNode * bstNode)
{
	tail->next = new BSTListNode(bstNode->data); //add a node to the next of tail
	tail = tail->next; //move tail
}

void BSTList :: trim()
{
	head = head->next; //move head
}


/**************************************************************************************************************
 * Functions for BSTQueue
 * ***********************************************************************************************************/
void BSTQueue :: enqueue(BSTNode * node)
{
	BSTQueueNode * newNode = new BSTQueueNode(node); //create a new node
	if (front == nullptr && rear == nullptr) //if front and rear are null, make both point to the new node
	{
		front = newNode;
		rear = newNode;
	}
	else //otherwise store the new node in the next of rear and move rear
	{
		rear->next = newNode;
		rear = rear->next;
	}
	++size; //increase queue size
}

BSTNode * BSTQueue :: dequeue()
{
	BSTNode * returnNode = front->bstNode; //hold the node to return
	if (front == rear) //if this is the last node, reset the queue
	{
		delete(front);
		front = rear = nullptr;
		size = 0;
	}
	else //otherwise move front and reduce the size
	{
		BSTQueueNode * temp = front;
		front = front->next;
		delete(temp);
		--size;
	}
	return returnNode;
}

bool BSTQueue :: isEmpty() //check for emptiness
{
	return size == 0 ? true : false;
}

int BSTQueue :: getSize() //return the size
{
	return size;
}


/**************************************************************************************************************
 * Functions for BST
 * ***********************************************************************************************************/
void BinarySearchTree :: insert(int x)
{
	++insertKeyComparisons;
	if (root == nullptr) //if root is null then create root
		root = new BSTNode(x);
	else if (root->data == x) //if x is equal to root, throw exception
		throw "Duplicate Value Exception";
	else //otherwise call recursive insertion
		insertIntoTree(root,x);
}

BSTNode * BinarySearchTree :: search(int x)
{
	BSTNode * returnNode = root; //point to root
	while (returnNode != nullptr && returnNode->data != x) //till the pointer is not null and its data is not equal to x
	{
		++tempCount;
		if (x < returnNode->data) //if x is smaller
			returnNode = returnNode->leftThread == true ? nullptr : returnNode->left; //if pointer points to leaf, make it null, otherwise, move left
		else //otherwise
			returnNode = returnNode->rightThread == true ? nullptr : returnNode->right; //if pointer points to leaf, make it null, otherwise, move right
	}
	return returnNode; //return the node
}

void BinarySearchTree :: deleteX(int x)
{
	tempCount = 0;
	BSTNode * curr = search(x); //search x
	deleteKeyComparisons += tempCount;
	BSTNode * parent = nullptr; //parent pointer
	if (curr == nullptr) //if x is not found throw exception
		throw "Missing Node Exception";
	else //otherwise find the parent
		parent = getParent(curr);
	if (isLeaf(curr) == true) //for leaf node
	{
		reduceSubtreeCount(curr); //reduce the subtree count till current node
		deleteLeafNode(curr,parent); //delete the leaf node
	}
	else if ((curr->left == nullptr || curr->leftThread == true) || (curr->right == nullptr || curr->rightThread == true)) //for single child
	{
		reduceSubtreeCount(curr); //reduce the subtree count till current node
		deleteNodeWithSingleChild(curr,parent); //delete the current node
	}
	//for double children, replacing with successor strategy
	else
	{
		tempCount = 0;
		BSTNode * succ = leftMost(curr->right); //find the successor of current node
		deleteKeyComparisons += tempCount;
		BSTNode * parentSucc = getParent(succ); //find the parent of the successor node
		BSTNode * newCurrNode = nullptr; //create another pointer
		if (isLeaf(succ) == true) //if successor is a leaf
		{
			reduceSubtreeCount(succ); //reduce the subtree count till successor
			newCurrNode = deleteLeafNode(succ,parentSucc); //detach the successor by calling leaf deletion function and store in the pointer
		}
		else //otherwise
		{
			reduceSubtreeCount(succ); //reduce the subtree count till successor
			newCurrNode = deleteNodeWithSingleChild(succ,parentSucc); //detach the successor by calling single child deletion function and store in the pointer
		}
		if (curr == root) //if current node is root
			root = newCurrNode; //point root to the new node
		else //otherwise attach the new node to the parent of current node
		{
			if (parent->left == curr)
				parent->left = newCurrNode;
			else
				parent->right = newCurrNode;
		}
		/*update the children of the new node*/
		newCurrNode->left = curr->left;
		newCurrNode->right = curr->right;
		newCurrNode->leftThread = curr->leftThread;
		newCurrNode->rightThread = curr->rightThread;
		/*update the subtree count of the new node*/
		/*newCurrNode->leftSubtreeCount = curr->leftSubtreeCount;
		newCurrNode->rightSubtreeCount = curr->rightSubtreeCount;
		*//*update the threads if any, for safety*/
		if (!newCurrNode->leftThread)
		{
			BSTNode * predec = rightMost(newCurrNode->left);
			if (predec != nullptr && predec->rightThread == true)
			{
				predec->rightThread = true;
				predec->right = newCurrNode;
			}
		}
		if (!newCurrNode->rightThread)
		{
			succ = leftMost(newCurrNode->right);
			if (succ != nullptr && succ->leftThread == true)
			{
				succ->leftThread = true;
				succ->left = newCurrNode;
			}
		}
	}
	delete(curr);
}

void BinarySearchTree :: printTree(const char * fileName)
{
	string nodeStructure = ""; //stores the node structure
	string linkStructure = ""; //stores the pointer structure
	ofstream graphViz; //.gv file in output mode
	ofstream commands; //commands file in output mode

	string treeFileName = ""; //giving a distinguishable file name
	treeFileName.append(fileName);
	treeFileName.append(to_string(bstFileCount)); //along with a number that is file count
	treeFileName.append(".gv"); //adding extension name
	graphViz.open(treeFileName); //opening the file

	if (bstFileType == 0) //if os is windows
	{
		bstFileCount == 0 ? commands.open("commands.bat") : commands.open("commands.bat",std::ios_base::app); //open a batch file, first time in write mode and then in append mode
		commands << "dot -Tpng " << treeFileName << " -o " << fileName << to_string(bstFileCount++) << ".png" << endl; //add the .gv to .png conversion command to batch file
	}
	else if (bstFileType == 1) //if os is linux
	{
		bstFileCount == 0 ? commands.open("commands.sh") : commands.open("commands.sh",std::ios_base::app); //open a shell script, first time in write mode and then in append mode
		commands << "dot -Tpng " << treeFileName << " -o " << fileName << to_string(bstFileCount++) << ".png" << endl; //add the .gv to .png conversion command to shell script
	}

	commands.close(); //close the commands file

	if (root == nullptr) //if root is null
	{
		/*write a blank tree template and return*/
		graphViz << "digraph G {" << endl;
		graphViz << "node [shape = record, height = .1];" << endl;
		graphViz << "}" << endl;
		graphViz.close();
		return;
	}

	/*adding the root node to queue*/
	BSTQueue queue;
	queue.enqueue(root);
	while (queue.isEmpty() == false) //till queue has more nodes
	{
		BSTNode * currNode = queue.dequeue(); //dequeue from the queue
		if (currNode->left != nullptr && currNode->leftThread == false) //if left thread is false
			queue.enqueue(currNode->left); //add left child to queue
		if (currNode->right != nullptr && currNode->rightThread == false) //if right thread is false
			queue.enqueue(currNode->right); //add right child to queue

		/*appending the node structure to nodeStructure*/
		nodeStructure.append(to_string(currNode->data));
		nodeStructure.append("[label = \"<L> |<D> ");
		nodeStructure.append(to_string(currNode->data));
		nodeStructure.append("|<R> \"");
		if (isLeaf(currNode))
			nodeStructure.append(",fontcolor=\"red\"");
		nodeStructure.append("];\n");

		/*appending pointer structure to linkStructure*/
		if (currNode->left != nullptr)
		{
			linkStructure.append("\"");
			linkStructure.append(to_string(currNode->data));
			linkStructure.append("\":L -> \"");
			linkStructure.append(to_string(currNode->left->data));
			linkStructure.append("\":D");
			if (currNode->leftThread == true)
				linkStructure.append("[style=dashed]");
			linkStructure.append(";\n");
		}

		if (currNode->right != nullptr)
		{
			linkStructure.append("\"");
			linkStructure.append(to_string(currNode->data));
			linkStructure.append("\":R -> \"");
			linkStructure.append(to_string(currNode->right->data));
			linkStructure.append("\":D");
			if (currNode->rightThread == true)
				linkStructure.append("[style=dashed]");
			linkStructure.append(";\n");
		}
	}
	//delete &queue;
	
	/*writing to .gv file and closing it*/
	graphViz << "digraph G {" << endl;
	graphViz << "node [shape = record, height = .1, color = \""<< bstColor <<"\"];" << endl;

	graphViz << nodeStructure;
	graphViz << linkStructure;

	graphViz << "}" << endl;
	
	graphViz.close();					
}

void BinarySearchTree :: evaluatePerformance()
{
	ofstream evaluation;
	evaluation.open("../evaluation.txt",std::ios_base::app);
	evaluation << "Binary Search Tree performance:" << endl;

	//height from root
	BSTQueue queue;
	queue.enqueue(root);
	while (queue.isEmpty() == false) //till queue has more nodes
	{
		int currQueueSize = queue.getSize();
		int currLevelNodeCount = 0;
		++maxHeight;
		for (int i = 0; i < currQueueSize; ++i)
		{
			BSTNode * currNode = queue.dequeue(); //dequeue from the queue
			++currLevelNodeCount;
			++nodeCount;
			if (currNode->left != nullptr && currNode->leftThread == false) //if left child is not null
				queue.enqueue(currNode->left); //add left child to queue
			if (currNode->right != nullptr && currNode->rightThread == false) //if right child is not null
				queue.enqueue(currNode->right); //add right child to queue
		}
		totalHeight += (maxHeight*currLevelNodeCount);
	}

	//height from the reverse direction
	getTotalDepth(root);

	double avgHeight = double(totalHeight)/double(nodeCount);
	double avgDepth = double(totalDepth)/double(nodeCount);

	cout << endl << "Total Key Comparisons: " << (insertKeyComparisons+deleteKeyComparisons) << endl;
	cout << "Total Rotations: " << (insertRotateCount+deleteRotateCount) << endl;
	cout << "Height of Tree: " << maxHeight << endl;
	cout << "Average height of nodes (from root to node): " << avgHeight << endl;
	cout << "Average height of nodes (from bottom): " << avgDepth << endl;
	cout << "Total number of Nodes: " << nodeCount << endl;
	evaluation << "Total Key Comparisons: " << (insertKeyComparisons+deleteKeyComparisons) << endl;
	evaluation << "Total Rotations: " << (insertRotateCount+deleteRotateCount) << endl;
	evaluation << "Height of Tree: " << maxHeight << endl;
	evaluation << "Average height of nodes (from root to node): " << avgHeight << endl;
	evaluation << "Average height of nodes (from bottom): " << avgDepth << endl;
	evaluation << "Total number of Nodes: " << nodeCount << endl << endl;
	evaluation.close();
}

void BinarySearchTree :: insertIntoTree(BSTNode * root, int x)
{
	++insertKeyComparisons;
	if (x < root->data) //if x is less than root
	{
		if (root->left == nullptr || root->leftThread == true) //if left is null or left thread is present
		{
			BSTNode * newNode = new BSTNode(x); //create a new node

			newNode->rightThread = true; //mark its right thread to be true
			newNode->right = root; //point the right thread to root

			if (root->leftThread == true) //if root has a left thread
			{
				newNode->left = root->left; //update the left child of new node
				root->left = newNode; //store new node in root's left
				root->leftThread = false; //mark root's left thread false
				if (newNode->left != nullptr) newNode->leftThread = true; //if new node's left is not null, mark thread true
			}
			else //otherwise
				root->left = newNode; //store new node in root's left
			//++root->leftSubtreeCount; //increase the left subtree count
		}
		else if (root->left->data == x) //if x is already present in left
			throw "Duplicate Value Exception"; //throw exception
		else //otherwise
		{
			insertIntoTree(root->left, x); //recur
			//++root->leftSubtreeCount; //increase the left subtree count
		}
	}
	if (x > root->data) //if x is greater than root
	{
		if (root->right == nullptr || root->rightThread) //if right is null or right thread is present
		{
			BSTNode * newNode = new BSTNode(x); //create a new node

			newNode->leftThread = true; //mark its left thread to be true
			newNode->left = root; //point the left thread to root

			if (root->rightThread == true) //if root has a right thread
			{
				newNode->right = root->right; //update the right child of new node
				root->right = newNode; //store new node in root's right
				root->rightThread = false; //mark root's right thread false
				if (newNode->right != nullptr) newNode->rightThread = true; //if new node's right is not null, mark thread true
			}
			else //otherwise
				root->right = newNode; //store new node in root's right
			//++root->rightSubtreeCount; //increase the right subtree count
		}
		else if (root->right->data == x) //if x is already present in right
			throw "Duplicate Value Exception"; //throw exception
		else //otherwise
		{
			insertIntoTree(root->right, x); //recur
			//++root->rightSubtreeCount; //increase the right subtree count
		}
	}
}

void BinarySearchTree :: reduceSubtreeCount(BSTNode * node)
{
	BSTNode * temp = root; //start from root
	while (temp != node) //till temp is not equal to node
	{
		if (node->data < temp->data) //if node is less than temp
		{
			//--temp->leftSubtreeCount; //reduce left subtree count
			temp = temp->left; //move left
		}
		else //otherwise
		{
			//--temp->rightSubtreeCount; //reduce right subtree count
			temp = temp->right; //move right
		}
	}
}

bool BinarySearchTree :: isLeaf(BSTNode * node)
{
	if ((node->left == nullptr || node->leftThread == true) && (node->right == nullptr || node->rightThread == true))
		return true;
	return false;
}

BSTNode * BinarySearchTree :: deleteLeafNode(BSTNode * node, BSTNode * parent)
{
	if (parent == nullptr) //if parent is null store null in root
		root = nullptr; //store null in root
	else if (parent->left == node) //if node is left child
	{
		parent->left = node->left; //store node's left in parent's left
		if (parent->left != nullptr) //update thread
			parent->leftThread = true;
	}
	else //if node is right child
	{
		parent->right = node->right; //store node's right in parent's right
		if (parent->right != nullptr) //update thread
			parent->rightThread = true;
	}
	/*reset the node and return*/
	node->left = node->right = nullptr;
	node->leftThread = node->rightThread = false;
	return node;
}

BSTNode * BinarySearchTree :: deleteNodeWithSingleChild(BSTNode * node, BSTNode * parent)
{
	if (node->left == nullptr || node->leftThread == true) //if right child is present
	{
		if (parent == nullptr) //if parent is null
		{
			BSTNode * succ = leftMost(node->right); //find the successor of node
			if (succ->leftThread == true) //if its left thread is present, delete it
			{
				succ->leftThread = false;
				succ->left = nullptr;
			}
			root = root->right; //move root
		}
		else if (parent->right == node) //if node is right child
		{
			parent->right = node->right; //store node's right in parent's right
			BSTNode * succ = leftMost(parent->right); //find the successor of node
			if (succ->leftThread == true) succ->left = parent; //if its left thread is present then point it to parent
		}
		else //if node is left child
		{
			parent->left = node->right; //store node's right in parent's left
			BSTNode * succ = leftMost(parent->left); //find the successor of node
			succ->left = node->left; //store node's left in successor's left
			succ->leftThread = node->leftThread; //store node's left thread in successor's left thread
		}			
	}
	else if (node->right == nullptr || node->rightThread == true) //if left child is present
	{
		if (parent == nullptr) //if parent is null
		{
			BSTNode * predec = rightMost(node->left); //find the successor of node
			if (predec->rightThread == true) //if its right thread is present, delete it
			{
				predec->rightThread = false;
				predec->right = nullptr;
			}
			root = root->left; //move root
		}
		else if (parent->left == node) //if node is left child
		{
			parent->left = node->left; //store node's left in parent's left
			BSTNode * predec = rightMost(parent->left); //find the predecessor of node
			if (predec->rightThread == true) predec->right = parent; //if its right thread is present then point it to parent
		}
		else //if node is right child
		{
			parent->right = node->left; //store node's left in parent's right
			BSTNode * predec = rightMost(parent->right); //find the predecessor of node
			predec->right = node->right; //store node's right in successor's right
			predec->rightThread = node->rightThread; //store node's right thread in successor's right thread
		}
	}
	/*reset the node and return*/
	node->left = node->right = nullptr;
	node->leftThread = node->rightThread = false;
	return node;
}

BSTNode * BinarySearchTree :: leftMost(BSTNode * node)
{
	if (node == nullptr) //if node is null return null
		return nullptr;
	BSTNode * temp = node; //start from node
	while (temp->left != nullptr && temp->leftThread == false) //move left till there is no more left child
	{
		++tempCount;
		temp = temp->left;
	}
	++tempCount;
	return temp;
}

BSTNode * BinarySearchTree :: rightMost(BSTNode * node)
{
	if (node == nullptr) //if node is null return null
		return nullptr;
	BSTNode * temp = node; //start from node
	while (temp->right != nullptr && temp->rightThread == false) //move right till there is no more right child
		temp = temp->right;
	return temp;
}

BSTNode * BinarySearchTree :: getParent(BSTNode * node)
{
	/*start from root*/
	BSTNode * temp = root;
	BSTNode * parent = root;
	while (temp != node) //till temp not equals to node
	{
		parent = temp; //move parent to temp
		if (node->data < temp->data) //if node is less than temp
			temp = temp->left; //move left
		else //otherwise
			temp = temp->right; //move right
	}
	if (temp == parent) //if temp and parent are still equal
		return nullptr; //return null
	return parent; //return parent otherwise
}

BSTNode * BinarySearchTree :: copyNodes(BSTNode * root, unordered_map<BSTNode *, BSTNode *> &map)
{
	BSTNode * newNode = new BSTNode(root->data); //create a new node having same data as root
	/*copy the subtree counts*/
	/*newNode->leftSubtreeCount = root->leftSubtreeCount;
	newNode->rightSubtreeCount = root->rightSubtreeCount;*/
	map[root] = newNode; //store it in map
	/*copy thread details*/
	if (root->leftThread == true)
	{
		newNode->left = map[root->left];
		newNode->leftThread = true;
	}
	if (root->rightThread == true)
	{
		newNode->right = map[root->right];
		newNode->rightThread = true;
	}
	if (root->left != nullptr && root->leftThread == false) //if root has a left child
		newNode->left = copyNodes(root->left,map); //recur on left child
	if (root->right != nullptr && root->rightThread == false) //if root has a right child
		newNode->right = copyNodes(root->right,map); //recur on right child
	return newNode;
}

int BinarySearchTree :: getTotalDepth(BSTNode * root)
{
	if (root == nullptr) return 0;
	int leftDepth = 0, rightDepth = 0;
	if (!root->leftThread) leftDepth = getTotalDepth(root->left);
	if (!root->rightThread) rightDepth = getTotalDepth(root->right);
	int currentDepth = max(leftDepth,rightDepth)+1;
	totalDepth += currentDepth;
	return currentDepth;
}