#include <iostream>
#include "includes/heap_max.h"

int main() {
    HeapMax hm = HeapMax();
    std::cout << "Inserindo elementos na Heap Max..." << std::endl;
    hm.insert(4);
    hm.print();
    hm.insert(10);
    hm.print();
    hm.insert(5);
    hm.print();
    hm.insert(5);
    hm.print();

    std::cout << "Removendo elementos da Heap Max..." << std::endl;
    std::cout << "O top é: " << hm.pop() << std::endl;
    hm.print();
    std::cout << "O top é: " << hm.pop() << std::endl;
    hm.print();
    std::cout << "O top é: " << hm.pop() << std::endl;
    hm.print();

    std::vector<int> v {7, 5, 12, 4, 8, 9, 3, 14, 1, 15};
    std::cout << "Construindo uma Heap Max a partir de array..." << std::endl;
    HeapMax hm_array = HeapMax(v);
    hm_array.print();

    std::cout << "Ordenando com Heap Sort" << std::endl;
    std::vector<int> sorted = hm_array.sort();
    std::cout << "[ ";
    for (int c: sorted) {
        std::cout << c << " ";
    }
    std::cout << " ]" << std::endl;
}