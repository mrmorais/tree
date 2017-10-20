#include "binary_tree.h"

/**
 * Default constructor that creates a null tree
 */
BinaryTree::BinaryTree() {
	m_root = NULL;
}

/**
 * Constructor that creates a tree with a initial node
 * @param key_ initial value
 */
BinaryTree::BinaryTree(int key_) {
	m_root = new Node;
	m_root->key = key_;
	m_root->left = NULL;
	m_root->right = NULL;
}

/**
 * Insert a new node into the binary tree
 * @param key_ value of the node
 */
void BinaryTree::insert(int key_) {
	insert(m_root, key_);
}

/**
 * Recursive insertion. It receives the reference node
 * @param node reference node to insert the key into
 * @param key_ value to be inserted into the subtree
 */
void BinaryTree::insert(Node* & node, int key_) {
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
		insert(node->left, key_);
	} else {
		// Insert into the right
		insert(node->right, key_);
	}
}

/**
 * Prints a representation of the binary tree
 */
void BinaryTree::print() const {
	print(m_root);
}

/**
 * Prints a representation on a subtree
 * @param node subtree's root
 */
void BinaryTree::print(Node* node) const {
	if (node == NULL) {
		std::cout << "";
	} else {
		std::cout << "" << node->key << "{";
		print(node->left);
		std::cout << "}{";
		print(node->right);
		std::cout << "}";
	}
}

/**
 * Lookup for a wanted value in the tree
 * @param key_ term for search
 * @return a reference to the node if found; NULL, otherwise.
 */
Node* BinaryTree::search(int key_) const {
	return search(m_root, key_);
}

/**
 * Recursive search feature
 * @param node subtree's root
 * @param key_ term for search
 */
Node* BinaryTree::search(Node* node, int key_) const {
	// if we reach a NULL node, the term is not here
	if (node == NULL) {
		return NULL;
	}
	// if we find the key we got it
	else if (node->key == key_) {
		return node;
	}
	// otherwise, try looking to the subtrees. The left one
	else if (key_ < node->key) {
		return search(node->left, key_);
	}
	// and the right one
	else {
		return search(node->right, key_);
	}
}

int main() {
	BinaryTree bt = BinaryTree();
	bt.insert(10);
	bt.insert(5);
	bt.insert(4);
	bt.insert(20);
	bt.print();
	std::cout << std::endl;
	Node* res = bt.search(20);
}
