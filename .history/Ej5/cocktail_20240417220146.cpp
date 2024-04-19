#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "cocktail.h"
using namespace std;

Cocktail::Cocktail(){
    /*srand(time(0)); 
    for (int i = 0; i < 10; i++) {
        array_desordenado[i] = rand() % 100;
    }*/
    ptr_inicio = array_desordenado;
    ptr_fin = array_desordenado+9;
    repetir = true;

}
void Cocktail::print(){
    for (int i = 0; i < 10; i++) {
        cout << array_desordenado[i] << " ";
    }
    cout << endl<<endl;
}
void Cocktail::ordenar(){
    int contador = 0;
    while (repetir){
        contador++;
        cout << "\niteracion  " << contador << endl;
        for (int* p = ptr_inicio, *q = ptr_fin; p < q; p++) {
            if (*p > *(p+1)){
                cout << "cambio " << *p << *(p + 1) << endl;
                swap(*p, *(p+1));
            }
        }
        for (int* p = ptr_inicio, *q = ptr_fin; p < q; q--) {
            if (*q < *(q-1)){
                cout << "cambio " << *q << *(q- 1) << endl;
                swap(*q, *(q-1));
            }
        }
        ptr_inicio++, ptr_fin--;
        print();

    }
    
    /*int contador = 0;
    cout << "*p  " << ptr_inicio << endl;
    cout << "*q  " << ptr_fin << endl;
    cout << "*p+1  " << *(ptr_inicio+1) << endl;
    cout << "*q no usando tdv  " << *ptr_fin << endl;

    for (int* p=ptr_inicio, *q=ptr_fin ; p>=q; p++, q--){
        contador++;
        cout << contador << endl;
        cout << "*p   " << *p << endl;
        cout << "*p+1   " << *(p+1) << endl;
        cout << "*q no usando tdv   " << *q << endl;

        if (*p > *p+1){
            swap(*p, *(p+1));
        }
    }*/
}