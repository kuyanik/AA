#include "Node.h"

Node::Node(int value){
        this->level = 1;
	this->value = value;
        left = nullptr;
        right = nullptr;
}
Node::~Node(){
        delete left;
        delete right;
}
