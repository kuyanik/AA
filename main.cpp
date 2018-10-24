#include <iostream>
#include <cstdlib>
#include <chrono>
#include "AA.h"
#include "heap.h"

using namespace std;
using namespace std::chrono;

int main(){

	srand(time(0));
	AA* anderson_tree = new AA;

//	int set[7] = {10, 3 , 7, 5 , 2 , 1 ,11};
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int i = 0;i<100000;i++){
		anderson_tree->insert(rand() % 10000000);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	double duration1 = duration_cast<microseconds> (t2 - t1).count();

//	anderson_tree->print();
	cout<<"Printed item count is done: "<< anderson_tree->count <<endl;
	cout<<" The time it took AA tree to insert items in seconds: "<<duration1/1000000<<"\n Operation count: "<< anderson_tree->operation_count<<endl;
	cout<<" Depth of level is in the tree: "<< anderson_tree->level(anderson_tree->root)<<endl;

        b_heap* my_heap = new b_heap;

	high_resolution_clock::time_point t3 = high_resolution_clock::now();
        for (int i = 0; i < 100000; i++) {
                my_heap->insert( rand() % 10000000 );
        }
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	double duration2 = duration_cast<microseconds> ( t4 - t3).count();

	cout<<" The time it took heap tree to insert items in seconds: "<<duration2/1000000 <<endl;

/*
        cout<<"My array size after inserting 10000 items: "<< my_heap->arr.size()<<endl;

        for (int i = 0; i < 10000; i++) {
                my_heap->extract();
        }

        cout<<"\nMy array size after extracting 10000 items: "<< my_heap->arr.size()<<endl;
*/

	delete anderson_tree;
        delete my_heap;

        return 0;
}
