
class Node {
	private:
		int key;
		Node* leftChild;
		Node* rightChild;
	public:
		Node(int key_, Node * leftChild_, Node * rightChild_);
};

Node::Node(int key_, Node * leftChild_, Node * rightChild_)
	: key(key_)
	,leftChild(leftChild_)
	,rightChild(rightChild_)
{
	/* empty */
}
