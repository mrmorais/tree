#include <iostream>
#include <vector>

/**
 * Questão 101
 * 
 * Montei um template de heapsort para um vetor de tipo 't_x', é necessário passar a função de comparação dele
 * a funçào de comparação possibilita ordenar estruturas variadas ou também alterar a ordem de ordenação
 */


template <class t_x> std::vector<t_x> heapsort(std::vector<t_x> x_vec, bool ((*fn)(t_x,t_x))){
  //make heap
  // um vetor vazio ou com um elemento já está ordenado
  for(unsigned int x=1;x<x_vec.size();x++){
    int kid = x,dad;
    while(kid>0){
      dad = (kid-1+kid%2)/2;
      if (fn(x_vec[dad],x_vec[kid])){
        break; //the structure is a heap
      }else{
        //the kid should be above the dad, swap them

        //uses the std op, swaps the memory from &x_vec[dad] to &x_vec[dad+1] (the content of x_vec[dad]) to &x_vec[kid] and the necessary size forward
        std::swap_ranges(&x_vec[dad],&x_vec[dad+1],&x_vec[kid]);

        kid = dad; //the kid resides at the former dad position

      }
    }
  }


  unsigned int size_left = x_vec.size(), replaced;
  while(size_left>0){
    //remove top & put last at top
    std::swap_ranges(&x_vec[0],&x_vec[1],&x_vec[size_left-1]);

    //decrease size
    size_left--;

    //reheap
    unsigned int r_son,l_son,best_son;
    
    replaced = 0;
    while(replaced*2+1<size_left){
      r_son = replaced*2+1;
      l_son = replaced*2+2;
      if(l_son<size_left){
        best_son = fn(x_vec[r_son],x_vec[l_son])?r_son:l_son;
      }else{
        best_son = r_son;
      }
      if(fn(x_vec[replaced],x_vec[best_son])){
        break;
      }else{
        //swap them and keep reordering from where the best son was
        std::swap_ranges(&x_vec[replaced],&x_vec[replaced+1],&x_vec[best_son]);
        replaced = best_son;
      }
    }
  }
  return x_vec;
} 



int main() {
    std::vector<int> v {15, 19, 3, 42, 90, 50, 21, 73}; // Vetor com valores não ordenados e aleatórios

    std::vector<int> ordenado = heapsort(v,+[](int a,int b)->bool{return a>b;});

    for (int c: ordenado) {
        std::cout << c << " ";
    }
    std::cout << "\n";

    srand (time(NULL));
    std::vector<int> x; 


    //#define SEE_RESULTS
    #define test_size 100
    for(int i=test_size;i>0;i--) x.push_back(rand());
    
    #ifdef SEE_RESULTS
    for (int c: x) {
      std::cout << c << " ";
    }
    std::cout << "\n";
    #endif

    x = heapsort(x,+[](int a,int b)->bool{return a>b;});

    #ifdef SEE_RESULTS
    for (int c: x) {
      std::cout << c << " ";
    }
    std::cout << "\n";
    #endif
}
