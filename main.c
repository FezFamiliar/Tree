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

struct Node* Search(struct Node* root,int value){

	if(root->data == value) return root;
	else if(value < root->data && root->left != NULL) root->left = Search(root->left,value);
	else if(value > root->data && root->right != NULL) root->right = Search(root->right,value);
	else{

	printf("The value %d you are looking for is not present in the tree!",value);
	exit(1);
	}

}


struct Node* MinNode(struct Node* root){

	while(root->left != NULL)  root = root->left;

	return root;

}

struct Node* MaxNode(struct Node* root){

	while(root->right != NULL) root = root->right;

	return root;
}

struct Node* RemoveNode(struct Node* root, int value) {

	if (root == NULL) {

		printf("The tree is empty!");
		return root;
	}
	else if (value < root->data) root->left = RemoveNode(root->left,value);
	else if (value > root->data) root->right = RemoveNode(root->right, value);
	else { // i have found the desired element

		// Leaf node
		if (root->left == NULL && root->right == NULL) {

			free(root);
			root = NULL;

		}
		// Has One Child
		else if (root->left == NULL) {

			struct Node* aux = root;
			root = root->right;
			free(aux);

		}
		else if (root->right == NULL) {

			struct Node* aux = root;
			root = root->left;
			free(aux);

		}
		// 2 children
		else {

			struct Node* aux = MinNode(root->right);
			root->data = aux->data;
			root->right = RemoveNode(root->right,aux->data);
		}
	}

	return root;

}



void Preorder(struct Node* start){

	if(start == NULL) return;
	printf("%d ",start->data);
	Preorder(start->left);
	Preorder(start->right);

}

int Height(struct Node* root){


	if(root == NULL) return 0;
	else{

	int lh = Height(root->left);
	int rh = Height(root->right);

	if(lh > rh) return(lh + 1);
	else return(rh + 1);

	}
}


int main(){

	struct Node* root = NULL;
	root = Insert(root,5);
	root = Insert(root,10);
	root = Insert(root,15);
	root = Insert(root,13);
	printf("left subtree height: %d\n",Height(root->left));
	printf("Right subtree height: %d",Height(root->right));
	return 0;
}
