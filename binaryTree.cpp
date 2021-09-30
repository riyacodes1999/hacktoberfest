#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
     node*left;
     node*right;
    node(int val){
        data =val;
        left=NULL;
        right=NULL;
    }
};

void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root= new node(1);
    root->left=new node(2);
    root->right= new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

    return 0;
}
/*
#include<iostream>   
using namespace std; 
 // A structure representing a node of a tree. struct node { 
	int data; 
	node *left; 
	node *right; };  
 // A function creating new node of the tree and assigning the data. node* CreateNode(int data) { 
	node *newnode = new node; 
	newnode->data = data; 	
newnode->left = NULL; 	
newnode->right = NULL;   	
return newnode; }  
 // A function creating binary search tree. node* InsertIntoTree(node* root, int data) { 
	// Create node using data from argument list. 	node *temp = CreateNode(data);
 	node *t = new node; 
	t = root;   	
// If root is null, assign it to the node created. 
	if(root == NULL) 	
	root = temp; 	else	 	{ 		
// Find the position for the new node to be inserted. 	
	while(t != NULL) 		{ 			if(t->data < data ) 			{ 			
	if(t->right == NULL) 		
		{ 					// If current node is NULL then insert the node. 			
		t->right = temp; 					break; 				} 				// Shift pointer to the left. 				t = t->right; 			}   			else if(t->data > data) 			{ 				if(t->left == NULL) 				{ 					// If current node is NULL then insert the node. 					t->left = temp; 					break; 				} 				// Shift pointer to the left.	 				t = t->left; 			} 		} 	} 	return root; }   // A function to search item in a BST. void Search(node *root, int data) { 	int depth = 0; 	node *temp = new node; 	temp = root; 	// Run the loop untill temp points to a NULL pointer. 	while(temp != NULL) 	{ 		depth++; 		if(temp->data == data) 		{ 			cout<<"\nData found at depth: "<<depth; 			return; 		} 		// Shift pointer to left child. 		else if(temp->data > data) 			temp = temp->left; 		// Shift pointer to right child. 		else 			temp = temp->right; 	}   	cout<<"\n Data not found"; 	return; }     int main() { 	char ch; 	int n, i, a[20]={89, 53, 95, 1, 9, 67, 72, 66, 75, 77, 18, 24, 35, 90, 38, 41, 49, 81, 27, 97}; 	node *root = new node; 	root = NULL;   	// Construct the BST. 	for(i = 0; i < 20; i++) 		root = InsertIntoTree(root, a[i]);   	up: 	cout<<"\nEnter the Element to be searched: "; 	cin>>n;   	Search(root, n);   	// Ask user to enter choice for further searching. 	cout<<"\n\n\tDo you want to search more...enter choice(y/n)?"; 	cin>>ch; 	if(ch == 'y' || ch == 'Y') 	goto up;   	return 0; }
*/
