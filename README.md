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

**Heap Max**

| Operação | Complexidade |
|----------|:----------:|
| Construir | O(n) |
| Descer | O(log(n)) |
| Deletar | O(log(n)) |
| Subir | O(log(n)) |
| Inserir | O(log(n)) |
| Heap sort | O(nlog(n)) |

Inserção: Insere no final e sobe. 

Deleção: Substitui o último com o primeiro e desce o primeiro.

#### Heap sort
```
procedimento heapsort
    arranjar(n) // O (n)
    m <- n
    enquanto (m > 1) faça // O (n)
        troca(1, m)
        m <- m - 1
        descer(1, m) // O(log n)
```
