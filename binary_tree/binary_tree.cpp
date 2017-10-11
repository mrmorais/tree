#include "binary_tree.h"

/**
 * Default constructor
 */
BinaryTree::BinaryTree() {
	// do nothing
}

BinaryTree::BinaryTree(int key_) {
	Node* n = new Node(key_, nullptr, nullptr);
}

int main() {
	BinaryTree bt = BinaryTree();
}
