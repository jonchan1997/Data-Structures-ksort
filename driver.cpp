
#include<iostream>

using namespace std;

//creating a node to be used in BST

struct Node

{

int data;

struct Node *left, *right;

};

// This function designs a BST Node.

Node *newNode(int item)

{

Node *tmp = new Node;

tmp->data = item;

tmp->left = NULL;

tmp->right = NULL;

return tmp;

}

//Insert data into BST to create a new BSt

Node* insert( Node* Node, int data)

{

if (Node == NULL) return newNode(data); //if tree is empty, newNode is returned

if (data < Node->data) //find the appropiate place of data in the BST.

Node->left = insert(Node->left, data);

else if (data > Node->data)

Node->right = insert(Node->right, data);

return Node;

}

// Function prints the inorder traversal of a BST.

void inorder( Node *root)

{

if (root != NULL)

{

inorder(root->left);

cout<<root->data<<endl;

inorder(root->right);

}

}

//Find kth smallest value in the BST.

int kthSmallestElement(Node *root, int k)

{

Node *current = root;// starts iterating from the root

int count = 0;

int kthSmall = -5000000; // taking the arbitrary large negative value which will be replaced by kth smallest value in BST.

  

while (current != NULL) //starting iterating from root

{

if (current->left == NULL) // if the root has no left child

{

count++;

  

if (count==k) //if the value of count is k we have found the kth smallest element in bst

kthSmall = current->data;

current = current->right;

}

else

{ // Iterating through the BST and incrementing the value of k until we find the kth smallest value.

Node *previous = current->left;

while (previous->right != NULL && previous->right != current)

previous = previous->right;

  

if (previous->right==NULL)

{

previous->right = current;

current = current->left;

}

else

{

previous->right = NULL;

count++;

if (count==k) //if the value of count is k we have found the kth smallest element in bst

kthSmall = current->data;

current = current->right;

}

}

}

return kthSmall;

}

// Main function

int main()

{

int a[]={6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};

Node *root = NULL;

root = insert(root, 6);//Assuming first element of array as the root

int n= sizeof(a)/sizeof(a[0]);

for(int i=1;i<n;i++)// inserting all element of the array in bst

insert(root, a[i]);

  

cout<<"Printing inorder traversal of the binary search tree created"<<endl;

inorder(root);

  

cout<<endl;

cout<<"Enter the value of k, k determines the kth smallest element in the bst";
cout<<endl;

int k;

cin>>k;

  

cout<<kthSmallestElement(root,k);

return 0;

}