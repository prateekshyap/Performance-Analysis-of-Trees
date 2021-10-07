using namespace std;

//inbuilt header files
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<exception>
#include<unordered_map>
#include<ctime>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//header files created for various tasks
#include"nodesAVLT.h" // contains all the node structures
#include"datastructuresAVLT.h" //contains all the data structures
#include"functionsAVLT.h" //contains functions

extern int avltFileCount, avltFileType; //external variables

int main(int argc, char ** argv)
{
	/*choice stores the choice of operation by the user
	x stores the data given by user*/
	int choice = 0, x = 0, count = 0, percentageBreak = 0, nop = 0, i = 0;
	AVLTree tree; //tree contains the main tree
	bool isXPresent = false; //stores whether a searched value is present or not
	/*inputFileName stores the input file name
	outputFileName stores the output file name
	printFileName takes the file name from user
	timestamp stores the current timestamp in string format*/
	string inputFileName = "../", fileSequence = "../fileSequence.txt", timestamp = "", inputString = "", tempString= "";
	time_t now; //stores the current time
	ifstream inputFile, sequence; //input file stream
	ofstream outputFile; //output file stream
	avltFileCount = 0;
	string printFileName = "", outputFileName = "";

	avltFileType = atoi(argv[1]);
	printFileName = argv[2];
	outputFileName = argv[3];

	if (avltFileType == 0)
	{
		//remove all existing graphviz and image files
		std :: system("del *.gv");
		std :: system("del *.png");
	}
	else if (avltFileType == 1)
	{
		//remove all existing graphviz and image files
		std :: system("rm *.gv");
		std :: system("rm *.png");
	}

	sequence.open(fileSequence);
	outputFile.open(outputFileName);
	while (sequence >> tempString)
	{
		//cout << inputFileName << endl;
		inputFileName.append(tempString);
		inputFile.open(inputFileName);
		inputFileName = "../";

		sequence >> nop;
		percentageBreak = nop/100;

		//store timestamp in output file
		now = time(0);
		timestamp = ctime(&now);
		outputFile << "Execution started at: " << timestamp << endl;
		
		cout << endl << endl << "Executing" << endl;
		count = 0;

		while (inputFile >> inputString)
		{
			//cout << "Command: " << inputString << endl;
			outputFile << endl << inputString << endl;
			if (percentageBreak >= 10)
			{
				++count;
				if (count%percentageBreak == 0)
				{
					cout << "\r";
					i = 0;
					cout << "[";
					for (i = percentageBreak; i <= count; i += percentageBreak)
						cout << "|";
					for (; i <= nop; i += percentageBreak)
						cout << " ";
					cout << "]" << (count/percentageBreak);
				}
			}

			if (inputString.compare("insert") == 0)
			{
				inputFile >> inputString;
				x = stoi(inputString);
				outputFile << x << endl << "Inserting " << x << endl << endl; //write operation details to output file
				try {
				tree.insert(x); //call insert function
				}catch(char const * message) //catch the thrown exception and print into both console and output file
				{
					//cout << message << endl;
					outputFile << message << endl << endl;
				}
			}
			else if (inputString.compare("delete") == 0)
			{
				inputFile >> inputString;
				x = stoi(inputString);
				outputFile << x << endl << "Deleting " << x << endl << endl; //write operation details to output file
				try{
				tree.deleteK(x); //call delete function
				}catch(const char * message) //catch the thrown exception and print into both console and output file
				{
					//cout << message << endl;
					outputFile << message << endl << endl;
				}
			}
			else if (inputString.compare("search") == 0)
			{
				inputFile >> inputString;
				x = stoi(inputString);
				outputFile << x << endl << "Searching " << x << endl; //write operation details to output file
				isXPresent = tree.search(x); //call search function
				if (!isXPresent) //if result is false print the same to both console and output file
				{
					cout << x << " is not present" << endl;
					outputFile << x << " is not present" << endl << endl;
				}
				else //otherwise also print to both console and output file
				{
					cout << x << " is present" << endl;
					outputFile << x << " is present" << endl << endl;
				}
			}
			else if (inputString.compare("print") == 0 || inputString.compare("view") == 0|| inputString.compare("view") == 0|| inputString.compare("run") == 0|| inputString.compare("visualize") == 0|| inputString.compare("picture") == 0)
			{
				outputFile << "Printing treap with file name- " << printFileName << avltFileCount << ".png" << endl;
				outputFile << "Graphviz file can be found with file name- " << printFileName << avltFileCount << ".gv" << endl << endl;
				tree.print(printFileName.c_str()); //call print tree function
			}
			else if (inputString.compare("quit") == 0 || inputString.compare("exit") == 0 || inputString.compare("stop") == 0 || inputString.compare("return") == 0)
			{
				//cout << "Quit" << endl; //print to console
				outputFile << endl << "Quit" << endl << endl; //print to output file
				/*//store timestamp in output file*/
				now = time(0);
				timestamp = ctime(&now);
				outputFile << "Execution ended at: " << timestamp << endl;
				tree.evaluatePerformance();
				cout << endl << "Want to generate images? (Y/N)" << endl;
				cin >> inputString;
				if (inputString.compare("Y") == 0 || inputString.compare("y") == 0)
					generatePNGInAVLT(avltFileType); //generate images
				return 0;
			}
			else
			{
				cout << "Invalid Input! Please try again!" << endl;
				outputFile << "Invalid Input! Please try again!" << endl;
			}
		}

		/*//store timestamp in output file*/
		now = time(0);
		timestamp = ctime(&now);
		outputFile << "Execution ended at: " << timestamp << endl << endl << endl << endl ;
		inputFile.close(); //close input file
	}
	/*//store timestamp in output file*/
	now = time(0);
	timestamp = ctime(&now);
	outputFile << "Execution ended at: " << timestamp << endl;
	tree.evaluatePerformance();
	cout << endl << "Want to generate images? (Y/N)" << endl;
	cin >> inputString;
	if (inputString.compare("Y") == 0 || inputString.compare("y") == 0)
		generatePNGInAVLT(avltFileType); //generate images

	sequence.close();
	outputFile.close();
	//delete &tree;
	return 0;
}