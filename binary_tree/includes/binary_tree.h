#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include "node.h"

class BinaryTree {
	private:
		Node* m_root; // The root node

		void recursive_insert(Node* &node, int key_);
	public:
		// Constructors
		BinaryTree();
		BinaryTree(int key_);
		
		void print();
		void printSubtree(Node* node) const;
		void insert(int key_);
		Node* search(int key_) const;
		void destroy();
		void remove(int key_);
};

#endif