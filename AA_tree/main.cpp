#include <iostream>
#include <cstdlib>
#include <chrono>
#include "AA.h"
#include "heap.h"

using namespace std;
using namespace std::chrono;

int main(){

	srand(time(0));
	AA* my_tree = new AA;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int i = 0;i<10000;i++){
		my_tree->root = my_tree->insert( my_tree->root , rand() % 100000);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	double duration1 = duration_cast<microseconds> (t2 - t1).count();

	my_tree->print(my_tree->root);
	cout<<" The time it took AA tree to insert items in seconds: "<<duration1/1000000
	<<"\n Tree rotation operation count: "<< my_tree->operation_count<<endl;

	cout<<" Depth of level is in the tree: "<< my_tree->root->level <<endl;

        b_heap* my_heap = new b_heap;

	high_resolution_clock::time_point t3 = high_resolution_clock::now();
        for (int i = 0; i < 10000; i++) {
                my_heap->insert( rand() % 100000 );
        }
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	double duration2 = duration_cast<microseconds> ( t4 - t3).count();

	cout<<" The time it took heap tree to insert items in seconds: "<<duration2/1000000 <<endl;
	cout<<" Swaps occured in heap tree: "<< my_heap->swap_count<<endl;
	delete my_tree;
        delete my_heap;

        return 0;
}
