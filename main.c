
#include "tree.h"



int main(){

	struct Node* root = NULL;
	root = Insert(root, 10);
    	root = Insert(root, 20);
    	root = Insert(root, 30);
    	root = Insert(root, 40);
    	root = Insert(root, 50);
    	root = Insert(root, 25);
	root = Insert(root,25);
	Preorder(root);
	return 0;

}
