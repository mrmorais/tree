#include <iostream>
#include "includes/heap_max.h"

/**
 * Default constructor
 */
HeapMax::HeapMax() {
    m_heap = std::vector<int>();
    m_heap.push_back(0); 
    // A primeira posição do array não deve ser usada. Seto como 0
}

HeapMax::HeapMax(std::vector<int> list) {
    m_heap = std::vector<int>();
    m_heap.push_back(0);
    for (unsigned i(0); i < list.size(); i++) {
        m_heap.push_back(list[i]);
    }
    arrange();
}

void HeapMax::goUp(int index) {
    int f = father(index);
    if (f >= 1) {
        if (m_heap[index] > m_heap[f]) {
            swap(index, f);
            goUp(f);
        }
    }
}

void HeapMax::goDown(int index, int limit) {
    int j = left(index);
    int dir = right(index);
    if (j <= limit) {
        if (dir <= limit) {
            if (m_heap[dir] > m_heap[j]) j = dir;
        }
        if (m_heap[index] < m_heap[j]) {
            swap(index, j);
            goDown(j, limit);
        }
    }
}

int HeapMax::father(int index) {
    return index / 2;
}

int HeapMax::left(int index) {
    return 2 * index;
}

int HeapMax::right(int index) {
    return (2 * index) + 1;
}

void HeapMax::swap(int index_a, int index_b) {
    int temp = m_heap[index_a];
    m_heap[index_a] = m_heap[index_b];
    m_heap[index_b] = temp;
}

void HeapMax::arrange() {
    for (unsigned i(m_heap.size()); i > 0; i--) {
        goDown(i, m_heap.size());
    }
}

int HeapMax::size() {
    return m_heap.size() - 1;
}

void HeapMax::print() {
    std::cout << "[ ";
    for (unsigned i(1); i < m_heap.size(); i++) {
        std::cout << m_heap[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// Na inserção o valor é inserido no final da lista e é "subido" caso necessário
void HeapMax::insert(int key_) {
    m_heap.push_back(key_);
    goUp(size());
}

int HeapMax::pop() {
    if (size() == 0) return -1; // It is a error

    int top = m_heap[1];
    swap(1, size());
    m_heap.pop_back();

    goDown(1, m_heap.size());

    return top;
}

int HeapMax::top() {
    return m_heap[1];
}

std::vector<int> HeapMax::sort() {
    std::vector<int> backup = m_heap;

    int m = size();
    while (m > 1) {
        swap(1, m--);
        goDown(1, m);
    }
    std::vector<int> generated = m_heap;
    m_heap = backup;
    return generated;
}