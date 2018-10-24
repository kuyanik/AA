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

int AA::level(Node* node_ptr){
		if(node_ptr != nullptr && node_ptr->right !=nullptr){

			return 1 + level(node_ptr->left);
		}
		else
			return 0;
}

void AA::insert(int value){
	insert_hidden( value, this->root);
}

void AA::print(){
	print_hidden( this->root );
}

void AA::insert_hidden(int value, Node*& root){ // Ask teacher why pass reference???
	if(root == nullptr){
//		cout<<"inserting number: "<<value<<endl;
		root = new Node(value);
//		cout<<"going to skew or split and insert another number"<<endl;
	}
	else if(root->data < value){
//		cout<<"moved to right"<<endl;
		insert_hidden(value , root->right);
	}
	else if(root->data >= value){
//		cout<<"moved to left"<<endl;
		insert_hidden(value , root->left);
	}
	skew(root);
	split(root);
}

void AA::print_hidden(Node* root){
	if(root != nullptr){
		print_hidden(root->left);
		cout<< root->data <<endl;
		print_hidden(root->right);
		++count;
	}
}

void AA::skew(Node*& T){
	if(T!=nullptr && T->left != nullptr){
		if(level(T->left) == level(T)){
			Node* temp =  T->left;
			T->left = temp->right;
			temp->right = T;
			T= temp;
			++operation_count;
//			cout<<"SKEWED"<<endl;
		}
	}
}

void AA::split(Node*& T){
	if(T!=nullptr && T->right != nullptr && T->right->right != nullptr){
		if(level(T) == level(T->right->right)){
			Node* temp = T->right;
			T->right = T->right->left;
			temp->left = T;
			T = temp;
			++operation_count;
//			cout<<"SPLIT"<<endl;
		}
	}
}

Node* AA::successor(Node* T){

	T = T->right;
	while(T->left != nullptr){
		T = T->left;
	 }
	return T;
}


Node* AA::predecessor(Node* T){

	T = T->left;
	while(T->right != nullptr){
		T = T->right;
	 }
	return T;
}

void AA::delete(int X, Node*& T){

	if(T == nullptr)
		return T;
	else if(X > T->value)
		T->right = delete(X,T->right);
	else if(X < T->value)
		T->left = delete(X,T->left);
	else{
		if(T->level == 1)
			return nullptr;
		else if(T->left == nullptr)
			Node* L =successor(T);
			T->right = delete(L->value,T->right);
			T->value = L->value;
		else{
			Node* L = predecessor(T);
			T->left = delete(L->value,T->left);
			T->value = L->value;
		}
	}

	T=decrease_level(T);
	T=skew(T);
	T->right = skew(T->right);
	if(T->right !=nullptr)
		T->right->right = skew(T->right->right);

	T = split(T);
	T->right =split(T->right);
	return T;
}

Node* AA::decrease_level(Node* T){

	
