#include <iostream>
#include <vector>
#include "binary_tree.h"
#include "heap_max.h"

/**
 * Questão 15
 * 
 * Dada uma lista com n chaves, construir a árvore de busca binária de altura mínima utilizando o
 * algoritmo de inserção. Qual a complexidade do seu método?
 */

int main() {
    std::vector<int> v {15, 19, 3, 42, 90, 50, 21, 73}; // Vetor com valores não ordenados e aleatórios
    HeapMax heap = HeapMax(v); // Criar uma heap max com os valores do vetor
    std::cout << " Heap max gerado: ";
    heap.print();
    std::cout << std::endl;

    std::vector<int> ordenado = heap.sort(); // Ordenar usando heapsort
    std::cout << " Lista ordenada por heapsort: [";

    ordenado.erase(ordenado.begin());
    for (int c: ordenado) {
        std::cout << c << " ";
    }
    std::cout << "]" << std::endl;

    
    BinaryTree bt = BinaryTree();


    while (ordenado.size() > 0) {
        
        bt.insert(ordenado[ordenado.size() / 2]);
        ordenado.erase(ordenado.begin()+ ordenado.size() / 2);
    }

    std::cout << " Árvore binária de altura mínima: ";
    bt.print();
    std::cout << std::endl;
}