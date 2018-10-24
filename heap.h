#ifndef heap_h
#define heap_h
#include <vector>
using namespace std;

class b_heap {
public:
        vector<int> arr;
        void insert(int value);
        void sifting(int index);
        void extract();
        void reverse_sifting(int index);
};

#endif
