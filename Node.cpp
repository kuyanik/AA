#include "Node.h"

Node::Node(int value){
        this->data = value;
        left = nullptr;
        right = nullptr;
}
Node::~Node(){
        delete left;
        delete right;
}
