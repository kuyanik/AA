#ifndef AA_h
#define AA_h

#include "Node.h"
class AA
{
public:
	int count;
	int operation_count;
	Node* root;
	int level(Node* node_ptr);
	AA();
	~AA();
	void insert(int value);
	void print();
	void insert_hidden(int value,Node*& root);
	void print_hidden(Node* root);
	void skew(Node*& T);
	void split(Node*& T);
};

#endif
