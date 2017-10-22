### Tree
by Maradona Morais

Implementações em C++ de estruturas de dados organizadas em árvore e seus algoritmos.


#### Features
- Binary Tree & Binary Search Tree
    - Parte do código foi reproduzida do livro "Jumping into C++" do [@alexallain](https://twitter.com/alexallain)
- Heap Max
- Heap Min (TO DO)

#### Complexidades
Parte do arquivo [Big-O Cheat Sheet](https://www.packtpub.com/sites/default/files/downloads/4874OS_Appendix_Big_O_Cheat_Sheet.pdf)

**Árvore binária**

| Operação | Melhor caso | Pior caso |
|----------|:----------:|:---------:|
| Buscar | O(log(n)) | O(n) |
| Inserir | O(log(n)) | O(n) |
| Deletar | O(h) | O(n) |

Em que *n* é a quantidade de elementos na árvore e *h* é a altura da mesma. Todos os casos médios foram O(log(n))
