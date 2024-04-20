#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "multi.h"
using namespace std;

MultiMatrix::MultiMatrix(){
    srand(time(0)); 
    //size = (sizeof(array_desordenado)/4);
    int matriz[3][3][3];
    int** i;
    for (**i = **matriz; *i < *(matriz+2); i++) {
        **i = rand() % 100;
    }
}
void MultiMatrix::print(){
    //cout << "\t";
    for (int i = 0; i < size; i++) {
        cout << array_desordenado[i] << " ";
    }
    cout << endl << "\t";
}
void MultiMatrix::ordenar(){
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