#include "binary_tree.h"

/**
 * Default constructor that creates a null tree
 */
BinaryTree::BinaryTree() {
	m_root = NULL;
}

/**
 * Constructor that creates a tree with a initial node
 */
BinaryTree::BinaryTree(int key_) {
	m_root = new Node;
	m_root->key = key_;
	m_root->left = NULL;
	m_root->right = NULL;
}

void BinaryTree::recursive_insert(Node* & node, int key_) {
	// base case - reached an empty tree and need to insert a new node
	if (node == NULL) {
		node = new Node;
		node->key = key_;
		node->left = NULL;
		node->right = NULL;
		return;
	}
	// decide whether to insert into the left subtree or the right subtree
	// depending on the value of the node
	if (key_ < node->key) {
		// Insert into the left
		recursive_insert(node->left, key_);
	} else {
		// Insert into the right
		recursive_insert(node->right, key_);
	}
}

void BinaryTree::insert(int key_) {
	recursive_insert(m_root, key_);
}

void BinaryTree::printSubtree(Node* node) const {
	if (node == NULL) {
		std::cout << "";
	} else {
		std::cout << "" << node->key << "{";
		printSubtree(node->left);
		std::cout << "}{";
		printSubtree(node->right);
		std::cout << "}";
	}
}

void BinaryTree::print() {
	printSubtree(m_root);
}

int main() {
	BinaryTree bt = BinaryTree();
	bt.insert(10);
	bt.insert(5);
	bt.insert(4);
	bt.insert(20);
	bt.print();
}
