# Expression-Tree
Binary Expression Tree Project:

Input a mathematical expression, and using a binary expression tree, the program will calculate the final value of the expression and display the tree.

The program starts with a string. In this example, I used a premade string for convinence, but one could easily add user input to solve any simple mathematical expession.
In the main function, the string is converted into a stack of characters.
The buildTree function then turns those characters into a tree implementing the treeNode class.
The printTree function prints the tree horizontally.
Finally, the calculateSum function traverses the tree and returns the sum of the tree to the main.

The OUTPUT file shows an example of compiling the code.