/* Honor Pledge:
*
* I pledge that I have neither given nor 
* received any help on this assignment.
*
* Youngjon
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
//creating a node to be used in BST

struct Node{

	int data;

	struct Node *left, *right;

};

// This function designs a BST Node.

Node *newNode(int item){

	Node *tmp = new Node;

	tmp->data = item;

	tmp->left = NULL;

	tmp->right = NULL;

	return tmp;

}

//Insert data into BST to create a new BSt

Node* insert( Node* Node, int data){
	if (Node == NULL){ 
		return newNode(data);
	}

	if (data < Node->data){ 
		Node->left = insert(Node->left, data);
	}else if (data > Node->data){
		Node->right = insert(Node->right, data);
	}
	return Node;

}

// Function prints the inorder traversal of a BST.

void inorder( Node *root){
	if (root != NULL){
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}

}

//Find kth smallest value in the BST.
//Tried to split into a new library but that became very complicated so I put it back.

int FindkSmallElement(Node *root, int k)

{

Node *current = root;

int count = 0;

int kSmall = -5000000; 

  

while (current != NULL) 

{

if (current->left == NULL) 

{

count++;

  

if (count==k) 

kSmall = current->data;

current = current->right;

}

else

{ 

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

if (count==k) 

kSmall = current->data;

current = current->right;

}

}

}

return kSmall;

}

int main(){
	//checks outer loop
	int outerL = 1;
	// response
	int response = 0;
	//maximum options
	Libray[26][27];
	
	while(outerL == 1){
		
		cout << endl;
		cout << "1. Load Data (From File)" << endl;
		cout << "2. Exit Program" << endl;
		cout << "Please enter your selection:" << endl;
		cout << endl;
		// user input
		cin >> response;
		cout << endl;
		if( response == 1){
			// loads txt file
			int len = 0;
			string line;
			stringstream ss;
			int num[100];
			ifstream inputText ("data.txt");
			if (inputText.is_open()){
				// reads in each number to integer
				while( getline(inputText, line, ',')){
					ss << line;
					ss >> num[len];
					ss.str("");
					ss.str( std::string() );
					ss.clear();
					len++;
				}
				inputText.close();
			}
			//saving text
			}
			//outputting
			// check inner loop
			int innerL = 1;
			response = 0;
			while (innerL == 1){
				cout << endl;
				cout << "1.  Hash" << endl;
				cout << "2. Exit Program" << endl;
				cout << "Please enter your selection:" << endl;
				cout << endl;
				//user input
				cin >> response;
				cout << endl;
				if( response == 1){
					
					cout<<endl;
					cout<<"Enter the value of k when k determines the kth smallest element in the BST:"<<endl;
					int k;
					cin>>k;
					cout<<endl;
					cout<<"Your "<<k<<"th smallest element in the BST is ";
					cout<<FindkSmallElement(root,k)<<"."<<endl;
					innerL = 0;
					response = 0;
					
				} else if( response == 2){
					//exit program
					innerL = 0;
					outerL = 0;
					break;
			
				} else {
					response = 0;
					continue;
				}
			}
			
		
		} else if( response == 2){
			//exit program
			outerL = 0;
			break;
		} else {
			response = 0;
			continue;
		}
	}
	
	return 0;
}

