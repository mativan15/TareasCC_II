#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "multi.h"
using namespace std;

Cocktail::Cocktail(){
    srand(time(0)); 
    size = (sizeof(array_desordenado)/4);
    for (int i = 0; i < size; i++) {
        array_desordenado[i] = rand() % 100;
    }
    ptr_inicio = array_desordenado;
    ptr_fin = array_desordenado+size-1;
    repetir = true;
    for (int i = 0; i < size; i++) {
        array_ordenado[i] = 0;
    }
}
void Cocktail::print(){
    //cout << "\t";
    for (int i = 0; i < size; i++) {
        cout << array_desordenado[i] << " ";
    }
    cout << endl << "\t";
}
void Cocktail::ordenar(){
    while (repetir){
        repetir = false;
        for (int* p = ptr_inicio, *q = ptr_fin; p < q; p++) {
            if (*p > *(p+1)){
                swap(*p, *(p+1));
                repetir = true;
            }
        }
        for (int* p = ptr_inicio, *q = ptr_fin; p < q; q--) {
            if (*q < *(q-1)){
                swap(*q, *(q-1));
                repetir = true;
            }
        }
        ptr_inicio++, ptr_fin--;
        print();
    }
    
}