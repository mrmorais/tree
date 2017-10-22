#include "binary_tree.h"

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
