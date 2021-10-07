===============================================
	Instructions to execute the code
===============================================

1. If you're using Dev C++, Follow the steps to support $unordered\_map$. Go to tools--
compiler option--general tab--tick mark option (add the following commands when calling
compiler)--add -std=c++11 there. Then build and execute the project.

2. In linux or GNU windows compiler, open the terminal or command prompt and type
"g++ TreapImpl.cpp" and hit enter.

3. Then for linux type "./a.out". For windows type "a.exe" or "TreapImpl.exe"
(One of them should work). Hit enter.

4. You can also write "./TreapImpl" and hit enter to execute the makefile which is
provided.

5. Now the prompt will be displayed. Enter 0 or 1 for windows or linux respectively.

6. Give a name for all the files which are going to be generated during execution.

7. Write a .txt file according to the given format and enter the file name there. If
you give wrong sequence, it can destroy the execution. Alternatively you can choose
random file generation.

8. You can write "quit" or "view" instead of file name to exit from the program or to
generate the images till now respectively. However, adding a quit command at the end
of the input file is suggested.

9. The entire execution process can be visualized in $<user\_given\_name>Output.txt$.

10. The performance comparison of the current execution can be visualized in
$evaluation.txt$.

11. After printing a tree, you can view the images in the same directory. The
respective file names are written in the output file.

12. You can give multiple .txt files one after another. For example- in the first run,
you can insert a few nodes and delete one of them to check how the tree rotates, and
after seeing the result you can write another .txt file to delete the root node.

13. You can run the batch file or shell script to manually generate the images.

14. A separate batch file or shell script is being generated for performance comparison
and the entire process is automated. You need not perform it manually.

15. Avoid printing images for larger input files (if you choose to print, around $10\%$
of the total operations will be print commands in case of random input files. That means
if the number of operations is 100, you can observe 107-110 operations in the input file
out of which 7-10 are print commands at various places). One print command is always
being added at the end to observe the final tree.

16. Sometimes the process pauses if you click somewhere in the console. Try pressing
some key from the keyboard to continue.

17. Keep the width of the console window large enough to view a proper progress bar.

18. If you're using test files having different conventions and you're unable to quit
the execution, simply enter $1$ to enter a manual input file and then type "quit" in
place of file name.

19. For executing bst.cpp or avlt.cpp separately (after executing treap at least once),
you need 3 command line arguments. First one is the type of OS (0 for Windows and 1 for
Linux), second one is the user given file name and third one is the output file name.
A sample command for windows can be - a.exe 0 demo demoOutput.txt.