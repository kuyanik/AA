#ifndef Node_h
#define Node_h
class Node
{
public:
	int data;
	Node* right;
	Node*left;
	Node(int value);
	~Node();
};
#endif
