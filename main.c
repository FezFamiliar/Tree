#include <stdio.h>
#include <stdlib.h>

struct Node{

	int data;
	struct Node* left;
	struct Node* right;

};


struct Node* CreateNode(int value){

	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = value;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;

}

struct Node* Insert(struct Node* root,int value){

	if(root == NULL) root = CreateNode(value);
	else if(value < root->data) root->left = Insert(root->left,value);
	else root->right = Insert(root->right,value);

	return root;
}


void Preorder(struct Node* start){

	if(start == NULL) return;
	printf("%d ",start->data);
	Preorder(start->left);
	Preorder(start->right);

}
int main(){

	struct Node* root = NULL;
	root = Insert(root,5);
	root = Insert(root,10);
	root = Insert(root,2);
	root = Insert(root,7);
	Preorder(root);
	return 0;
}
