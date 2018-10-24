#ifndef AA_h
#define AA_h

#include "Node.h"
class AA
{
public:
	int count;
	int operation_count;
	Node* root;
	AA();
	~AA();
	Node* insert(Node*& T, int X);
	void print(Node* T);
	Node* skew(Node*& T);
	Node* split(Node*& T);
};

#endif
