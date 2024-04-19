#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "cocktail.h"
using namespace std;

Cocktail::Cocktail(){
    srand(time(0)); 
    for (int i = 0; i < sizeof(array_desordenado); i++) {
        array_desordenado[i] = rand() % 100;
    }
    ptr_inicio = array_desordenado;
    ptr_fin = array_desordenado+19;
    repetir = true;
    for (int i = 0; i < sizeof(array_ordenado); i++) {
        array_ordenado[i] = 0;
    }
}
void Cocktail::print(){
    //cout << "\t";
    for (int i = 0; i < 20; i++) {
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