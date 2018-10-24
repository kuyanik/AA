#include <iostream>
#include <cstdlib>
#include "AA.h"
#include "Node.h"

using namespace std;

AA::AA(){
	int operation_count = 0;
	int count = 0;
	this->root = nullptr;
}

AA::~AA(){
	delete root;
}

Node* AA::insert(Node*& T,int X){
	if(T == nullptr)
		return new Node(X);

	else if(X < T->value)
		T->left = insert(T->left , X);

	else if(X > T->value)
		T->right = insert(T->right , X);

	T = skew(T);
	T = split(T);
	return T;
}

void AA::print(Node* T){
	if(T != nullptr){
		print( T->left );
		cout<< T->value <<endl;
		print( T->right );
		++count;
	}
}

Node* AA::skew(Node*& T){
	if(T == nullptr)
		return nullptr;
	else if(T->left == nullptr)
		return T;
	else if (T->left->level == T->level){
		++operation_count;
		Node* L = T->left;
		T->left = L->right;
		L->right = T;
		return L;
	}
	else
		return T;
}

Node* AA::split(Node*& T){
	if(T == nullptr)
		return nullptr;
	else if (T->right == nullptr || T->right->right == nullptr)
		return T;
	else if (T->level == T->right->right->level){
		++operation_count;
		Node* R = T->right;
		T->right = R->left;
		R->left = T;
		R->level = R->level +1;
		return R;
	}
	else
		return T;
}
