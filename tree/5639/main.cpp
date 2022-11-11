// Authored by : ccocco0609
// Co-authored by : -
// Link : http://boj.kr/681f9d68a83c4f6a8627bd58b3db7178

#include <bits/stdc++.h>
using namespace std;

struct Node {
	friend class BinaryTree;
private:
	Node *left;
	Node *right;
	int key;
public:
	Node(int key, Node *left = NULL, Node *right = NULL) {
		this->key = key;
		this->left = left;
		this->right = right;
	}
};

class BinaryTree {
private:
	Node *root;
public:
	BinaryTree(int key) {
		root = new Node(key);
	}

	Node *getRoot() {
		return root;
	}

	void insert_node(Node *current, int key) {
		if (current->key > key) {
			if (current->left == NULL) {
				current->left = new Node(key);
			}
			else {
				insert_node(current->left, key);
			}
		}
		else if (current->key < key) {
			if (current->right == NULL) {
				current->right = new Node(key);
			}
			else {
				insert_node(current->right, key);
			}
		}
	}

	void print_cur_key(Node *current) {
		cout << current->key << '\n';
	}
	
	void postorder(Node *current) {
		if (current != NULL) {
			postorder(current->left);
			postorder(current->right);
			print_cur_key(current);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int first;
	
	cin >> first;

	BinaryTree tree(first);

	int tmp;

	while (cin >> tmp) {
		tree.insert_node(tree.getRoot(), tmp);
	}

	tree.postorder(tree.getRoot());

	return 0;
}