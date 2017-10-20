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

/**
 * Destroy the binary tree, turning it a empty tree
 */
void BinaryTree::destroy() {
	if (m_root != NULL) {
		destroy(m_root->left);
		destroy(m_root->right);
		delete m_root;
		m_root = NULL;
	}
}

/**
 * Recursive function to destroy a subtree
 * @param node the subtree's root
 */
void BinaryTree::destroy(Node* node) {
	if (node != NULL) {
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

/**
 * Find the greatest key value on the subtree
 * @param node subtree's node
 */
Node* BinaryTree::findMax(Node* node) const {
	if (node == NULL) return NULL;
	if (node->right == NULL) return node;
	return findMax(node->right);
}

void BinaryTree::remove(int key_) {
	remove(m_root, key_);
}

Node* BinaryTree::remove(Node* node, int key_) {
	if (node == NULL) return NULL;
	if (node->key == key_) {
		// The first two cases handle having zero or one child node
		if (node->left == NULL) {
			Node* n_right_subtree = node->right;
			delete node;
			// this might return NULL if there are zero child nodes
			return n_right_subtree;
		}
		if (node->right == NULL) {
			Node* n_left_subtree = node->left;
			delete node;
			// this will always return a valid node, never NULL
			return n_left_subtree;
		}
		Node* max_node = findMax(m_root->left);
		max_node->left = node->left;
		max_node->right = node->right;
		delete node;
		return max_node;
	} else if (key_ < node->key) {
		node->left = remove(node->left, key_);
	} else {
		node->right = remove(node->right, key_);
	}
	return node;
}

int main() {
	BinaryTree bt = BinaryTree();
	bt.insert(10);
	bt.insert(5);
	bt.insert(4);
	bt.insert(20);
	bt.print();
	std::cout << std::endl;
	bt.remove(20);
	bt.print();
	std::cout << std::endl;
}
