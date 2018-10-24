#include <iostream>
#include <cstdlib>
#include <vector>
#include "heap.h"
using namespace std;

void b_heap::insert(int value) {

	arr.push_back(value);
	int last_index = arr.size() -1 ;

	reverse_sifting(last_index);

}

void b_heap::reverse_sifting(int index) { //for inserting(bottom to top).

	int parent = (index-1)/2;// index of parent
	if( index != 0){ // if at top we don't do anything.

		if (arr[index] < arr[parent]) { 	//if index is smaller than his parent,we swap them.
			int temp = arr[index];
			arr[index] = arr[parent];
			arr[parent] = temp;

			reverse_sifting(parent); //now check swapped position with its's parent...again...
		}
	}
}

void b_heap::extract(){

	cout<< arr[0] <<" "; // print the extracted value.

	int last_index = arr.size()-1;
	arr[0] = arr[last_index]; //  root changed with last node's value.
	arr.pop_back(); // pop out the last item, makes neater solution.

	sifting(0);//now sifting from top to bottom commences.
}

void b_heap::sifting(int index){ //for extracting, top to bottom.

	int child= ( 2 * index ) + 1; //find the index of first child.
	int last_index = arr.size();

	if(child <= last_index){ //check left child first if it exists you can do sifting.

		if( (child+1) <= last_index && arr[child] > arr[child+1] ){ //check which child is smaller when there is two childs, if right child index is out of bounds pass.
			child = child + 1;
		}


		if( arr[index] > arr[child] ){ //if child is smaller than parent we swap.

			int temp = arr[index];
			arr[index] = arr[child];
			arr[child] = temp;

			sifting(child); // Child is the parent now do this till limit...
		}
	}
}

