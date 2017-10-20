#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include "node.h"

class BinaryTree {
	private:
		Node* m_root; // The root node
	public:
		// Constructors
		BinaryTree();
		BinaryTree(int key_);
		
		void insert(int key_);
		void insert(Node* &node, int key_);

		Node* search(int key_) const;
		Node* search(Node* node, int key_) const;

		void destroy();
		void remove(int key_);
		
		void print() const;
		void print(Node* node) const;
};

#endif