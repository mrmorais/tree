#include <iostream>
#include <vector>

class HeapMax {
    private: 
        std::vector<int> m_heap; //<! Storage array
        void goUp(int index);
        void goDown(int index, int limit);
        
        int father(int index);
        int left(int index);
        int right(int index);

        void swap(int index_a, int index_b);
        void arrange();
    public:
        HeapMax(); // Default constructor
        HeapMax(std::vector<int> list);

        int size();
        void print();
        
        void insert(int key_);
        int pop();
        int top();

        std::vector<int> sort();
};