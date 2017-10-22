#include <iostream>
#include <queue>
#include "binary_tree.h"

/**
 * Questão 12. Lista de exercícios EDB
 * 
 * Faça um algoritmo de percurso em nível de uma árvore binária
 */
void fillTree(BinaryTree & bt) {
    bt.insert(19);
    bt.insert(2);
    bt.insert(90);
    bt.insert(10);
    bt.insert(42);
    bt.insert(51);
    bt.insert(20);
}

int main() {
    BinaryTree bt = BinaryTree();
    std::queue<Node*> fila = std::queue<Node*>();

    fillTree(bt);

    std::cout << "Árvore gerada: ";
    bt.print();

    fila.push(bt.search(19));

    std::cout << std::endl << "Leitura por nível: [";
    while(! fila.empty()) {
        auto elem = fila.front();
        std::cout << elem->key << " ";
        fila.pop();
        

        if (elem->left != NULL) {
            fila.push(elem->left);
    
        }
        if (elem->right != NULL) {
            fila.push(elem->right);
        }
    }
    std::cout << "]" << std::endl;
}