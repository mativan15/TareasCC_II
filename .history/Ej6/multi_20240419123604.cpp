#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "multi.h"
using namespace std;

MultiMatrix::MultiMatrix(){
    srand(time(0)); 
    ptr_inicio = (int *)matriz;
    ptr_fin = (int *)(matriz + 3);

    for (; ptr_inicio < ptr_fin; ptr_inicio++) {
        *ptr_inicio = rand() % 100;
    }

}
void MultiMatrix::print(){
    cout << "Matriz:" << endl;
    ptr_inicio = (int *)matriz;
    ptr_fin = (int *)(matriz + 27);

    for (; ptr_inicio < ptr_fin; ptr_inicio++) {
        cout << *ptr_inicio << " ";
        if ((ptr_inicio - (int *)matriz + 1) % 3 == 0) {
            cout << endl;
        }
    }
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