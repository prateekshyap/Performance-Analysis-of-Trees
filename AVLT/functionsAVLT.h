/*avltFileCount stores a number so that multiple files could be created easily
avltFileType stores a number to indicate the type of file to be generated based on OS type*/
int avltFileCount = -1, avltFileType = -1;
string avltColor = "black"; //stores the avltColor names
AVLTStack avltStack; //used for deletion
int insertKeyComparisons = 0, deleteKeyComparisons = 0; //total key comparisons
int insertRotateCount = 0, deleteRotateCount = 0; //total number of rotations
int tempCount = 0, maxHeight = -1;
long nodeCount = 0, totalHeight = 0, totalDepth = 0;



/**************************************************************************************************************
 * Utility Functions
 * ***********************************************************************************************************/

void generatePNGInAVLT(int os)
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
 * Functions for AVLTStack
 * ***********************************************************************************************************/

void AVLTStack :: push(AVLTNode * node)
{
	AVLTStackNode * newNode = new AVLTStackNode(node); //create a new node
	if (top == nullptr) //if top is null, make it point to the new node
		top = newNode;
	else //otherwise store the new node before top and move top
	{
		newNode->next = top;
		top = newNode;
	}
	++size; //increase avltStack size
}

AVLTNode * AVLTStack :: pop()
{
	AVLTNode * returnNode = top->avltNode; //hold the node to return
	if (top->next == nullptr) //if this is the last node, reset the avltStack
	{
		delete(top);
		top = nullptr;
		size = 0;
	}
	else //otherwise move top and reduce size
	{
		AVLTStackNode * temp = top;
		top = top->next;
		delete(temp);
		--size;
	}
	return returnNode;
}

bool AVLTStack :: isEmpty() //check for emptiness
{
	return size == 0 ? true : false;
}

int AVLTStack :: getSize() //return the size
{
	return size;
}

AVLTNode * AVLTStack :: viewTop()
{
	return top->avltNode;
}



/**************************************************************************************************************
 * Functions for AVLTQueue
 * ***********************************************************************************************************/

void AVLTQueue :: enqueue(AVLTNode * node)
{
	AVLTQueueNode * newNode = new AVLTQueueNode(node); //create a new node
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

AVLTNode * AVLTQueue :: dequeue()
{
	AVLTNode * returnNode = front->avltNode; //hold the node to return
	if (front == rear) //if this is the last node, reset the queue
	{
		delete(front);
		front = rear = nullptr;
		size = 0;
	}
	else //otherwise move front and reduce the size
	{
		AVLTQueueNode * temp = front;
		front = front->next;
		delete(temp);
		--size;
	}
	return returnNode;
}

bool AVLTQueue :: isEmpty() //check for emptiness
{
	return size == 0 ? true : false;
}

int AVLTQueue :: getSize() //return the size
{
	return size;
}



/**************************************************************************************************************
 * Functions for AVL Tree
 * ***********************************************************************************************************/

void AVLTree :: insert(int x)
{
	AVLTNode * tree = root; //tree stores the reference to the node under which rotation will happen
	/*start stores the balance point
	temp moves from root to leaf for inserting end node
	end points to the new node which is being inserted
	rotate points to the node where first potential rotation happens
	for single rotation, that is the first rotation itself
	for double rotation, the first rotation happens at rotate*/
	AVLTNode * start = nullptr, * temp = nullptr, * end = nullptr, * rotate = nullptr;
	int newBF = -2; //it stores the new balance factor

	if (root->right == nullptr) //if this is the first node being inserted, insert and return
	{
		root->right = new AVLTNode(x);
		return;
	}

	++insertKeyComparisons;
	if (root->right->data == x) //if the value is already present in root, throw exception
		throw "Duplicate Value Exception";

	/*Search for the location of the new node to be inserted*/
	start = root->right; //start from the root node of the tree
	temp = start;
	while (true) //run an infinite loop
	{
		if (x == temp->data) //if the value already exists, throw an exception
			throw "Duplicate Value Exception";
		end = x < temp->data ? temp->left : temp->right; //move end point appropriately
		++insertKeyComparisons;
		if (end == nullptr) //if end becomes null
		{
			if (x < temp->data) //if x is less than temp
			{
				temp->left = new AVLTNode(x); //add x to left of temp
				end = temp->left; //point end to the newly added node
			}
			else //if x is greater than temp
			{
				temp->right = new AVLTNode(x); //add x to right of temp
				end = temp->right; //point end to the newly added node
			}
			break;
		}
		else //if end is not null
		{
			if (end->bF != 0) //if balance factor is non zero
			{
				start = end; //make it a balance point
				tree = temp; //store its parent in tree
			}
			temp = end; //move temp
		}
	}

	newBF = x < start->data ? 1 : -1; //find out the new balance factor
	rotate = newBF == 1 ? start->left : start->right; //point rotate to the left or right of start according to where insertion happened
	temp = newBF == 1 ? start->left : start->right; //point temp to the left or right of start according to where insertion happened
	
	while (temp != end) //till temp is not equal to end
	{
		if (x < temp->data) //if x is less than temp
		{
			temp->bF = 1; //set its balance factor to 1
			temp = temp->left; //move left
		}
		else if (x > temp->data) //if x is greater than temp
		{
			temp->bF = -1; //set its balance factor to -1
			temp = temp->right; //move right
		}
	}

	if (start->bF == 0) //if balance factor of start is 0
	{
		start->bF = newBF; //store the new balance factor in it
		return; //return
	}
	else if (start->bF == -1*newBF) //if balance factor of start is opposite to the new balance factor that means the tree has become more balanced
	{
		start->bF = 0; //set the balance factor to 0
		return; //return
	}
	else //if (start->bF == newBF) //if balance factor of start is equal to the new balance factor
	{
		if (rotate->bF == newBF) //if balance factor of rotate is also same as balance factor of start
		{
			temp = newBF == 1 ? rotateLL(start,rotate,0,0) : rotateRR(start,rotate,0,0); //single rotations will happen
			++insertRotateCount;
		}
		else if (rotate->bF == -1*newBF) //if balance factor of rotate is different from balance factor of start
		{
			temp = newBF == 1 ? rotateLR(start,rotate,newBF,1) : rotateRL(start,rotate,newBF,1); //double rotations will happen
			insertRotateCount += 2;
		}
		transplant(tree, start, temp); //reattach the rotated subtree
	}
}

bool AVLTree :: search(int x)
{
	AVLTNode * returnNode = root->right; //point to root
	while (returnNode != nullptr && returnNode->data != x) //till the pointer is not null and its data is not equal to x
	{
		++tempCount;
		if (x < returnNode->data) //if x is smaller
			returnNode = returnNode->left != nullptr ? returnNode->left : nullptr; //if pointer points to leaf, make it null, otherwise, move left
		else //if x is greater
			returnNode = returnNode->right != nullptr ? returnNode->right : nullptr; //if pointer points to leaf, make it null, otherwise, move right
	}
	return (returnNode == nullptr ? false : true); //return a boolean value
}

void AVLTree :: print(const char * fileName)
{
	string nodeStructure = ""; //stores the node structure
	string linkStructure = ""; //stores the pointer structure
	ofstream graphViz; //.gv file in output mode
	ofstream commands; //commands file in output mode

	string treeFileName = "";
	treeFileName.append(fileName);
	treeFileName.append(to_string(avltFileCount)); //along with a number that is file count
	treeFileName.append(".gv"); //adding extension name
	graphViz.open(treeFileName); //opening the file

	if (avltFileType == 0) //if os is windows
	{
		avltFileCount == 0 ? commands.open("commands.bat") : commands.open("commands.bat",std::ios_base::app); //open a batch file, first time in write mode and then in append mode
		commands << "dot -Tpng " << treeFileName << " -o "<< fileName << to_string(avltFileCount++) << ".png" << endl; //add the .gv to .png conversion command to batch file
	}
	else if (avltFileType == 1) //if os is linux
	{
		avltFileCount == 0 ? commands.open("commands.sh") : commands.open("commands.sh",std::ios_base::app); //open a shell script, first time in write mode and then in append mode
		commands << "dot -Tpng " << treeFileName << " -o "<< fileName << to_string(avltFileCount++) << ".png" << endl; //add the .gv to .png conversion command to shell script
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
	AVLTQueue queue;
	queue.enqueue(root);
	while (queue.isEmpty() == false) //till queue has more nodes
	{
		AVLTNode * currNode = queue.dequeue(); //dequeue from the queue
		if (currNode->left != nullptr) //if left child is not null
			queue.enqueue(currNode->left); //add left child to queue
		if (currNode->right != nullptr) //if right child is not null
			queue.enqueue(currNode->right); //add right child to queue

		/*appending the node structure to nodeStructure*/
		nodeStructure.append(to_string(currNode->data));
		nodeStructure.append("[label = \"<L> |<D> ");
		nodeStructure.append(to_string(currNode->data));
		nodeStructure.append("(");
		nodeStructure.append(to_string(currNode->bF));
		nodeStructure.append(")");
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
			linkStructure.append(";\n");
		}

		if (currNode->right != nullptr)
		{
			linkStructure.append("\"");
			linkStructure.append(to_string(currNode->data));
			linkStructure.append("\":R -> \"");
			linkStructure.append(to_string(currNode->right->data));
			linkStructure.append("\":D");
			linkStructure.append(";\n");
		}
	}
	//delete &queue;

	/*writing to .gv file and closing it*/
	graphViz << "digraph G {" << endl;
	graphViz << "node [shape = record, height = .1, color = \""<< avltColor <<"\"];" << endl;

	graphViz << nodeStructure;
	graphViz << linkStructure;

	graphViz << "}" << endl;
	
	graphViz.close();
}

void AVLTree :: deleteK(int x)
{
	AVLTNode * tree = root; //tree stores the reference to the node under which rotation will happen
	AVLTNode * start = root->right; //start from root of tree
	AVLTNode * node = nullptr, * parent = nullptr; //node and parent will point to the node to be deleted and its parent respectively

	tempCount = 0;
	node = searchNode(x); //search for x using the private searchNode function
	deleteKeyComparisons += tempCount;
	if (node == nullptr) //if node not found
		throw "Missing Node Exception"; //throw and exception
	parent = getParent(node); //get the parent of node
	if (node->left == nullptr || node->right == nullptr) //if any of the child of node is null
		deleteNodeWithNullChildren(node,parent); //call the delete function which deletes such nodes
	else //if node has two children
	{
		tempCount = 0;
		AVLTNode * succ = leftMost(node->right); //find the successor of node
		deleteKeyComparisons += tempCount;
		searchNode(succ->data); //call searchNode function for successor
		AVLTNode * parentSucc = getParent(succ); //find the parent of the successor node
		AVLTNode * newCurrNode = deleteNodeWithNullChildren(succ,parentSucc); //delete successor using the delete function and catch the deleted node
		newCurrNode->bF = node->bF; //store the balance factor
		newCurrNode->left = node->left; //store the left link
		newCurrNode->right = node->right; //store the right link
		parent = getParent(node); //get the new parent of node
		transplant(parent, node, newCurrNode); //replace node with newCurrNode
	}
	delete(node); //free node
}

void AVLTree :: evaluatePerformance()
{
	ofstream evaluation;
	evaluation.open("../evaluation.txt",std::ios_base::app);
	evaluation << "AVL Tree performance:" << endl;

	//height from root
	AVLTQueue queue;
	queue.enqueue(root->right);
	while (queue.isEmpty() == false) //till queue has more nodes
	{
		int currQueueSize = queue.getSize();
		int currLevelNodeCount = 0;
		++maxHeight;
		for (int i = 0; i < currQueueSize; ++i)
		{
			AVLTNode * currNode = queue.dequeue(); //dequeue from the queue
			++currLevelNodeCount;
			++nodeCount;
			if (currNode->left != nullptr) //if left child is not null
				queue.enqueue(currNode->left); //add left child to queue
			if (currNode->right != nullptr) //if right child is not null
				queue.enqueue(currNode->right); //add right child to queue
		}
		totalHeight += (maxHeight*currLevelNodeCount);
	}

	//height from the reverse direction
	getTotalDepth(root->right);

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

bool AVLTree :: isLeaf(AVLTNode * node)
{
	if (node->left == nullptr && node->right == nullptr) //if both the children are null
		return true; //return true
	return false; //return false
}

AVLTNode * AVLTree :: searchNode(int x)
{
	while (!avltStack.isEmpty()) //till avltStack is not empty
		avltStack.pop(); //pop everything
	avltStack.push(root); //push root
	AVLTNode * returnNode = root->right; //point to root of tree
	while (returnNode != nullptr && returnNode->data != x) //till the pointer is not null and its data is not equal to x
	{
		if (returnNode != nullptr) //if returnNode is not null
			avltStack.push(returnNode); //push it to avltStack
		if (x < returnNode->data) //if x is smaller
			returnNode = returnNode->left != nullptr ? returnNode->left : nullptr; //if pointer points to leaf, make it null, otherwise, move left
		else //if x is greater
			returnNode = returnNode->right != nullptr ? returnNode->right : nullptr; //if pointer points to leaf, make it null, otherwise, move right
	}
	return returnNode; //return the node
}

AVLTNode * AVLTree :: deleteNodeWithNullChildren(AVLTNode * node, AVLTNode * parent)
{
	/*rotate will point to the node where first potential rotation will happen
	ancestor will point to the ancestors of node
	tree will point to the parent of ancestor*/
	AVLTNode * rotate = nullptr, * ancestor = nullptr, * tree = nullptr;
	AVLTNode * temp = node->left == nullptr ? node->right : node->left; //point temp to the left or right of node which is non-null
	int newBF = -2; //stores the new balance factor
	int ancestorBF = -2;
	if (parent == root) //if parent is root
		root->right = isLeaf(node) ? nullptr : temp; //if node is leaf make tree null, otherwise make it point to temp
	else if (parent->left == node) //if node is left child
		parent->left = isLeaf(node) ? nullptr : temp; //if node is leaf store null, otherwise store temp in parent's left pointer
	else //if node is right child
		parent->right = isLeaf(node) ? nullptr : temp; //if node is leaf store null, otherwise store temp in parent's right pointer
	while (avltStack.viewTop() != root) //till avltStack top is not equal to root
	{
		ancestor = avltStack.pop(); //pop the avltStack and store in ancestor
		ancestorBF = ancestor->bF; //store the current balance factor of the ancestor
		tree = avltStack.viewTop(); //store current top in tree
		newBF = node->data < ancestor->data ? 1 : -1; //update the new balance factor
		if (ancestor->bF == newBF) //if ancestor's balance factor is same as new balance factor
		{
			ancestor->bF = 0; //make it 0
			continue; //continue
		}
		else if (ancestor->bF == 0) //if ancestor's balance factor was 0
		{
			ancestor->bF = -1*newBF; //store the opposite of new balance factor in it
			/*reset the node and return*/
			node->left = node->right = nullptr;
			return node;
		}
		else //if (ancestor->bF == -1*newBF) //if ancestor's balance factor is opposite to new balance factor
		{
			rotate = ancestor->bF == 1 ? ancestor->left : ancestor->right; //point rotate to left or right of ancestor
			if (rotate->bF == -1*newBF) //if rotate's balance factor is same as ancestor's balance factor
			{
				temp = newBF == 1 ? rotateRR(ancestor,rotate,0,0) : rotateLL(ancestor,rotate,0,0); //single rotations will happen
				++deleteRotateCount;
			}
			else if (rotate->bF == 0) //if rotate's balance factor is 0
			{
				temp = newBF == 1 ? rotateRR(ancestor,rotate,-2,newBF) : rotateLL(ancestor,rotate,-2,newBF); //single rotations will happen
				++deleteRotateCount;
			}
			else if (rotate->bF == newBF) //if rotate's balance factor is opposite to ancestor's balance factor
			{
				temp = newBF == 1 ? rotateRL(ancestor,rotate,newBF,0) : rotateLR(ancestor,rotate,newBF,0); //double rotations will happen
				deleteRotateCount += 2;
			}
			transplant(tree, ancestor, temp); //reattach the rotated subtree
			if (temp->bF == ancestorBF || temp->bF == -1*ancestorBF) //if the balance factor has not changed for the subtree, we need not do further rotations
			{
				node->left = node->right = nullptr;
				return node;
			}
		}
	}
	/*reset the node and return*/
	node->left = node->right = nullptr;
	return node;
}

AVLTNode * AVLTree :: leftMost(AVLTNode * node)
{
	if (node == nullptr) //if node is null return null
		return nullptr;
	AVLTNode * temp = node; //start from node
	while (temp->left != nullptr) //move left till there is no more left child
	{
		++tempCount;
		temp = temp->left;
	}
	++tempCount;
	return temp;
}

AVLTNode * AVLTree :: rightMost(AVLTNode * node)
{
	if (node == nullptr) //if node is null return null
		return nullptr;
	AVLTNode * temp = node; //start from node
	while (temp->right != nullptr) //move right till there is no more right child
		temp = temp->right;
	return temp;
}

AVLTNode * AVLTree :: getParent(AVLTNode * node)
{
	/*start from root*/
	AVLTNode * temp = root->right;
	AVLTNode * parent = root;
	while (temp != node) //till temp not equals to node
	{
		parent = temp; //move parent to temp
		if (node->data < temp->data) //if node is less than temp
			temp = temp->left; //move left
		else //otherwise
			temp = temp->right; //move right
	}
	return parent; //return parent otherwise
}

AVLTNode * AVLTree :: rotateRR(AVLTNode * oldRoot, AVLTNode * rotate, int oldRootBF, int rotateBF)
{
	AVLTNode * newRoot = rotate; //point the new root of rotated subtree to rotate
	oldRoot->right = rotate->left; //attach rotate's left subtree to old root's right subtree
	rotate->left = oldRoot; //attach old root as the left child of rotate i.e. the new root
	if (oldRootBF >= -1 && oldRootBF <= 1) oldRoot->bF = oldRootBF; //update balance factor
	if (rotateBF >= -1 && rotateBF <= 1) rotate->bF = rotateBF; //update balance factor
	return newRoot; //return new root
}

AVLTNode * AVLTree :: rotateLL(AVLTNode * oldRoot, AVLTNode * rotate, int oldRootBF, int rotateBF)
{
	AVLTNode * newRoot = rotate; //point the new root of rotated subtree to rotate
	oldRoot->left = rotate->right; //attach rotate's right subtree to old root's left subtree
	rotate->right = oldRoot; //attach old root as the right child of rotate i.e. the new root
	if (oldRootBF >= -1 && oldRootBF <= 1) oldRoot->bF = oldRootBF; //update balance factor
	if (rotateBF >= -1 && rotateBF <= 1) rotate->bF = rotateBF; //update balance factor
	return newRoot; //return new root
}

AVLTNode * AVLTree :: rotateLR(AVLTNode * oldRoot, AVLTNode * rotate, int newBF, int operation)
{
	AVLTNode * newRoot = rotate->right; //point new root to the right child of rotate, since that is going to be the actual rotation point after first rotation
	rotate->right = newRoot->left; //attach new root's left subtree to rotate's right subtree
	newRoot->left = rotate; //attach rotate as the left child of new root
	oldRoot->left = newRoot->right; //attach new root's right subtree to old root's left subtree
	newRoot->right = oldRoot; //attach old root as the right child of new root
	if (operation == 1) //if insertion is happening, update the balance factors as follows
	{
		oldRoot->bF = newRoot->bF == 0 ? 0 : newRoot->bF == newBF ? -1*newBF : 0;
		rotate->bF = newRoot->bF == 0 ? 0 : newRoot->bF == newBF ? 0 : newBF;
	}
	else if (operation == 0) //if deletion is happening, update the balance factor sexactly opposite to the insertion operation's updation 
	{
		oldRoot->bF = newRoot->bF == 0 ? 0 : newRoot->bF == newBF ? 0 : newBF;
		rotate->bF = newRoot->bF == 0 ? 0 : newRoot->bF == newBF ? -1*newBF : 0;
	}
	newRoot->bF = 0; //set new root's balance factor to 0
	return newRoot; //return new root
}

AVLTNode * AVLTree :: rotateRL(AVLTNode * oldRoot, AVLTNode * rotate, int newBF, int operation)
{
	AVLTNode * newRoot = rotate->left; //point new root to the left child of rotate, since that is going to be the actual rotation point after first rotation
	rotate->left = newRoot->right; //attach new root's right subtree to rotate's left subtree
	newRoot->right = rotate; //attach rotate as the right child of new root
	oldRoot->right = newRoot->left; //attach new root's left subtree to old root's right subtree
	newRoot->left = oldRoot; //attach old root as the left child of new root
	if (operation == 1) //if insertion is happening, update the balance factors as follows
	{
		oldRoot->bF = newRoot->bF == 0 ? 0 : newRoot->bF == newBF ? -1*newBF : 0;
		rotate->bF = newRoot->bF == 0 ? 0 : newRoot->bF == newBF ? 0 : newBF;
	}
	else if (operation == 0) //if deletion is happening, update the balance factor sexactly opposite to the insertion operation's updation
	{
		oldRoot->bF = newRoot->bF == 0 ? 0 : newRoot->bF == newBF ? 0 : newBF;
		rotate->bF = newRoot->bF == 0 ? 0 : newRoot->bF == newBF ? -1*newBF : 0;
	}
	newRoot->bF = 0; //set new root's balance factor to 0
	return newRoot; //return new root
}

void AVLTree :: transplant(AVLTNode * mainTree, AVLTNode * replace, AVLTNode * subTree)
{
	if (replace == mainTree->right) //if the node to be replaced is the right child of the main tree
		mainTree->right = subTree; //attach the new subtree to the right of main tree
	else //if the node to be replaced is the left child of the main tree
		mainTree->left = subTree; //attach the new subtree to the left of main tree
}

AVLTNode * AVLTree :: copyNodes(AVLTNode * root, unordered_map<AVLTNode *, AVLTNode *> &map)
{
	AVLTNode * newNode = new AVLTNode(root->data); //create a new node having same data as root
	map[root] = newNode; //store it in map
	if (root->left != nullptr) //if root has a left child
		newNode->left = copyNodes(root->left,map); //recur on left child
	if (root->right != nullptr) //if root has a right child
		newNode->right = copyNodes(root->right,map); //recur on right child
	return newNode;
}

void AVLTree :: deleteNodes(AVLTNode * root)
{
	if (root != nullptr)
	{
		deleteNodes(root->left);
		deleteNodes(root->right);
		delete root;
	}
}

int AVLTree :: getTotalDepth(AVLTNode * root)
{
	if (root == nullptr) return 0;
	int leftDepth = getTotalDepth(root->left);
	int rightDepth = getTotalDepth(root->right);
	int currentDepth = max(leftDepth,rightDepth)+1;
	totalDepth += currentDepth;
	return currentDepth;
}