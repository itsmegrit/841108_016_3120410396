#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->right = NULL;
	new_node->left = NULL;
	return new_node;
}

// thêm một node
Node* insert(Node* root, int data) {
	// If tree is empty
	if (root == NULL) {
		return createNode(data);
	}
	// else tree is not empty
	if (root->data > data) {
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}
	return root;
}

// in BST
void printLNR(Node *root) {
	if (root == NULL) return;
	printLNR(root->left);           //Left
	printf("%d ", root->data);  //Node
	printLNR(root->right);          //Right
}

void printRNL(Node *root) {
	if (root == NULL) return;
	printRNL(root->right);           //Right
	printf("%d ", root->data);  //Node
	printRNL(root->left);          //Left
}

void printNLR(Node *root) {
	if (root == NULL) return;
	printf("%d ", root->data);  //Node
	printNLR(root->left);           //Left
	printNLR(root->right);          //Right
}

void printNRL(Node *root) {
	if (root == NULL) return;
	printf("%d ", root->data);  //Node
	printNRL(root->right);          //Right
	printNRL(root->left);           //Left
}

// tìm kiếm
Node* searchNode(Node* root, int key) {
	// If tree is empty
	if (root == NULL) {
		return root;
	}

	if (root->data == key) {
		return root;
	}

	Node* result = searchNode(root->left, key);
	if (result != NULL) {
		return result;
	}

	result = searchNode(root->right, key);
	if (result != NULL) {
		return result;
	}

	return NULL;
}

// xoá BST
void removeTrees(Node* &root) {
	if (root == NULL) {
		return;
	}
	removeTrees(root->right);
	removeTrees(root->left);
	delete(root);
	root = NULL;
}

Node* minNode(Node* node) {
	Node* current = node;
	while (current -> left != NULL) {
		current = current -> left;
	}
	return current;
}

Node* maxNode(Node* node) {
	Node* current = node;
	while (current -> right != NULL) {
		current = current -> right;
	}
	return current;
}


Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	else if (data < root -> data) {
		root -> left = deleteNode(root -> left, data);
	}
	else if (data > root -> data) {
		root -> right = deleteNode(root -> right, data);
	}
	else {
		// case 1: Node khong co node con
		// case 2: Node khong co Node->left thi Node = Node->right
		// case 3: Node khong co Node->right thi Node = Node->left
		// case 4: Node co ca Node->left va Node->right thi lay min cua rightSubTree (cay con ben phai) thay the cho Node can xoa
		if (root->left == NULL && root->right == NULL) {
			return NULL;
		} else if (root -> left == NULL) {
			Node* temp = root -> right;
			delete root; // xoa Node hien tai (giai phong bo nho)
			return temp; // Node hien tai (Node duoc truyen vao trong ham) bang Node->right
		} else if (root -> right == NULL) {
			Node* temp = root -> left;
			delete root;
			return temp;
		} else {
			Node * temp = minNode(root -> right); // tim Node nho nhat cua rightSubTree
			root -> data = temp -> data;
			root -> right = deleteNode(root -> right, temp -> data); // xoa Node nho nhat
		}
	}
	return root;
}

// kiểm tra cây có phải là BST hay không
bool validBST(Node* root) {
	if (root == NULL) {
		return true;
	}
	// cây con bên trái không rỗng thì tìm giá trị lớn nhất của cây con đó và so sánh với root
	// cây con bên phải cũng tương tự
	if (root->left != NULL) {
		if (maxNode(root->left)->data > root->data) {
			return false;
		}
	}
	if (root->right != NULL) {
		if (minNode(root->right)->data < root->data) {
			return false;
		}
	}
	if (!validBST(root->right) || !validBST(root->left) ) {
		return false;
	}
	return true;
}

// rút gọn
bool validBST1(Node* root) {
	if (root == NULL) {
		return true;
	}
	// cây con bên trái không rỗng thì tìm node có node->data lớn nhất của cây con đó và so sánh với root->data
	// cây con bên phải cũng tương tự
	if ((root->left != NULL && maxNode(root->left)->data > root->data) || (root->right != NULL && minNode(root->right)->data < root->data)) {
		return false;
	}
	if (!validBST(root->right) || !validBST(root->left) ) {
		return false;
	}
	return true;
}

void printValidBST(Node* tree) {
	cout << "\nvalid BST: " ;
	if (validBST(tree)) {
		cout << "BST\n";
	} else {
		cout << "not BST\n";
	}
}

int main(int argc, char const * argv[]) {
	Node* tree = NULL;
	tree = insert(tree, 15);
	tree = insert(tree, 6);
	tree = insert(tree, 7);
	tree = insert(tree, 4);
	tree = insert(tree, 5);
	tree = insert(tree, 23);
	tree = insert(tree, 71);
	tree = insert(tree, 50);

	removeTrees(tree);

	tree = deleteNode(tree, 4);

	// Node *p = searchNode(tree, 6);
	// cout << "p: " << p << "; p->data: " << p->data ;
	// Node* p = searchNode(tree, 999);
	// cout << "\np: " << p << "; p->data: " << p->data ;

	// tree->left->right->data = -99;

	cout << "LNR: ";
	printLNR(tree);

	printValidBST(tree);

	return 0;
}