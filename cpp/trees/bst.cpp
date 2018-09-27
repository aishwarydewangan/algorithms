#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node* insertNode(Node *root, int key) {
	if(root == NULL) {
		Node *temp = new Node;
		temp->data = key;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	if(key <= root->data) {
		root->left = insertNode(root->left, key);
	} else {
		root->right = insertNode(root->right, key);
	}
	return root;
}

void preOrder(Node *root) {
	if(root == NULL)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inorder(Node *root) {
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postOrder(Node *root) {
	if(root == NULL)
		return;
	preOrder(root->left);
	preOrder(root->right);
	cout << root->data << " ";
}

void levelOrder(Node *root) {
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node *temp = q.front();
		q.pop();
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
		cout << temp->data << " ";
	}
}

bool bfs(Node *root, int key) {
	if(root == NULL)
		return false;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node *temp = q.front();
		q.pop();
		if(temp->data == key)
			return true;
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
	return false;
}

bool dfs(Node *root, int key) {
	if(root == NULL)
		return false;
	if(root->data == key)
		return true;
	if(!dfs(root->left, key))
		return dfs(root->right, key);
	return true;
}

int main() {
	Node *root = NULL;
	root = insertNode(root, 4);
	root = insertNode(root, 2);
	root = insertNode(root, 1);
	root = insertNode(root, 3);
	root = insertNode(root, 6);
	root = insertNode(root, 5);
	root = insertNode(root, 7);
	if(dfs(root, 7))
		cout << "Found";
	else
		cout << "Not found";
	return 0;
}