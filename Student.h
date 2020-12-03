// Brayan Villatoro : Assignment #5 : Student.h File 
#include <iostream>
using namespace std;

class Student // Student BTS Main.cpp
{  
struct node 
{
	string Name;  // Requirement #1
	char   Grade; // Requirement #1 
	node*  left;  // BST Left  :: Min Values 'likely' 
	node*  right; // BST Right :: Greater values 'likely'
};

node* root; // Height ZERO 
node* makeEmpty(node* t) // Height ZERO (Root)
{
if(t == NULL) // Zero  
return NULL; // If no Value the BST tree is non-exist 
{
	makeEmpty( t -> left);  // Clear left 
	makeEmpty( t -> right); // Clear right 
	delete t; // Node removed 
}
return NULL; // Nothing is returned == 0
}

node* insert(string a,char b, node* t) // New data inserted 
{
if(t == NULL) // Zero
{
	t = new node;  // BST node 
	t -> Name = a; // a: Name 
	t -> Grade= b; // b: Grade 
	t -> left = t -> right = NULL; // 2 identical node values renders Zero 
  
}
else 
{
	int x = a.compare(t -> Name); // Comparing name logic stored in x 
	if (x < 0) 
	t -> left  = insert(a,b, t -> left); // Left search (Name,Grade,Node) :: inserting node until not possible 
else
	t -> right = insert(a,b, t -> right); // Otherwise right search 
}
return t; // Returns node value from org node
}

int find(node *root, string d) // Starting node   
{
	int depth = 0; // Default Node = Root 
	node *temp = new node;
	temp = root;
// Figure 6.9 Textbook Page 221  
while(temp != NULL) // While Root has a value  
{
	depth++; // Increase height every new node loop while new insert 
	if(d.compare(temp -> Name) == 0) 
{
	cout << "\n\tItem found at depth: " << depth << "\n\n" ; // Location of node in tree height 0 = root, 1 = node location 
return 1; 
}
else if(d.compare(temp -> Name) < 0) // otherwise node non-existant also handle non-name values to not crash 
	temp = temp->left;
else temp = temp->right;
}
return 0; 
}

node* findMin(node* t) // Smallest values at the top of BST : Returning smallest from root node 
{
	if(t == NULL) // Non value 
	return NULL; // Nothing returned 
else if(t -> left == NULL) 
	return t;
else
	return findMin(t -> left); // Whatever smallest value in left side is 
}
  
node* remove(string d, node* t) // Removing student name from BST tree
{ 
	node* temp;
	if(t == NULL)
	return NULL;

else if (d.compare(t -> Name) < 0 ) // Left side BST search
	t -> left = remove(d, t -> left); // If found APPOVED removal 

else if(d.compare(t -> Name) > 0) // Right side BST search
	t -> right = remove(d, t -> right); // If found APPOVED removal  

else if(t -> left && t -> right) 
{
	temp = findMin(t -> right); // findmine Line 70: looking for smallest node in right side 
	t -> Name = temp -> Name; 
	t -> right = remove(t -> Name, t -> right); // Pushing right search 
}

else
{
	temp = t;
	if(t -> left == NULL) // If left contains no record of value 
	t = t -> right; // Right will contain it 
else if(t -> right == NULL) // otherwise start right search 
	t = t -> left; // left will contain it 
delete temp; // if none, node removed 
}
return t; 
}

int update(node *root, string d,char g) // Grade update : New Grade 
{ 
int depth = 0; // Start 
node *temp = new node;
temp = root;
while(root != NULL) // While a value is exist at root 
{
depth++; // Node level increases as new node data enters tree 
if(d.compare(root -> Name) == 0) // If entered name match is found update BST  
{ 
	root -> Grade = g;
	cout<< "\n\t0%...50%...Done!\n" << "\n\t--------------------\n"; // Possible progress bar feature Version 4 
return 1;
}
else if(d.compare(root -> Name) < 0)
	root = root -> left;
else root = root -> right;
}
return 0;
}

void inorder(node* t) // Displaying BST inorder 
{ 
	if(t == NULL)
	return;
	inorder(t -> left);
  
	cout << "\t" << t -> Name << "\t" << t -> Grade << endl; // Display #4 grade output 
	inorder(t -> right);
}

public:
Student() // Student 'Nodes'
{
	root = NULL; // Level Zero 
}

~Student() 
{
	root = makeEmpty(root); 
}

void insert(string a,char b) // Insert values into tree 
{ 
  
root = insert(a,b,root); // Name, Grade, Level 
}

int find(string x) // Searching for name in tree 
{ 
	return find(root , x);
}

void remove(string x) // Removing name from tree 
{ 
	root = remove(x, root);
}

void update(string StudentName ,char c) // Updating stored Grade in tree 
{ 
	update(root,StudentName ,c);
}

void display() // Displaying all tree node values  
{
	inorder(root); 
	cout << endl;
}
};
