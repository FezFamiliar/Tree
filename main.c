#include <stdio.h>
#include <stdlib.h>

struct Node{

	int data;
	struct Node* left;
	struct Node* right;

};

int CheckBalance(struct Node* root);
struct Node* LeftRotate(struct Node* root);
struct Node* RightRotate(struct Node* root);
struct Node* LeftRight(struct Node* root);
struct Node* RightLeft(struct Node* root);

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
	else if(value > root->data)root->right = Insert(root->right,value);
	else {
	printf("Duplicate values are not allowed!");
	exit(1);
	}

	if(CheckBalance(root) > 1 && value < root->left->data)
        	 return RightRotate(root);
	if(CheckBalance(root) < -1 && value > root->right->data)
	       	return LeftRotate(root);
	if(CheckBalance(root) > 1 && value > root->left->data)
		return LeftRight(root);
	if(CheckBalance(root) < -1 && value < root->right->data)
		return RightLeft(root);

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

struct Node* LeftRotate(struct Node* root){

	struct Node* aux = root->right;
	root->right = aux->left;
	aux->left = root;
	return aux;


}

struct Node* RightRotate(struct Node* root){

	struct Node* aux = root->left;
	root->left = aux->right;
	aux->right = root;
	return aux;

}

struct Node* LeftRight(struct Node* root){

	root->left = LeftRotate(root->left);
	return RightRotate(root);

}
struct Node* RightLeft(struct Node* root){

	root->right = RightRotate(root->right);
	return LeftRotate(root);
}
int abs(int a){

	return	a < 0 ? -a : a;
}
int CheckBalance(struct Node* root){

	int _leftH = Height(root->left);
	int _rightH = Height(root->right);

	return (_leftH - _rightH);
}



int main(){

	struct Node* root = NULL;
	 root = Insert(root, 10);  
    	root = Insert(root, 20);  
    	root = Insert(root, 30);  
    	root = Insert(root, 40);  
    	root =Insert(root, 50);  
    	root = Insert(root, 25); 
	root = Insert(root,50); 
	Preorder(root);
	return 0;

}
