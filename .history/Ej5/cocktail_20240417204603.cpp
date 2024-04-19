#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "cocktail.h"
using namespace std;

Cocktail::Cocktail(){
    srand(time(0)); 
    for (int i = 0; i < 10; i++) {
        array_desordenado[i] = rand() % 100;
    }
    ptr_inicio = array_desordenado;
    ptr_fin = array_desordenado+9;
}
void Cocktail::print(){
    /*
    cout << ptr_inicio << endl
      << ptr_fin << endl
      << *ptr_inicio << endl
      << *ptr_fin << endl;*/
    cout << "Random array: ";
    for (int i = 0; i < 10; i++) {
        cout << array_desordenado[i] << " ";
    }
    cout << endl<<endl;
/*
    char B[5]={"hugo"};
    cout << B << endl; // hugo

    char C[3][5]={"hugo", "paco", "luis"};
    cout << C << endl; //0x16b8df578
    cout << *C << endl; // hugo
    cout << *(C+1) << endl; // paco
    cout << *C+1 << endl; // ugo
    cout << *C+5 << endl; // paco
    cout << *(*C+1) << endl;// u
    */
}
void Cocktail::ordenar(){
    int contador = 0;
    cout << "*p" << ptr_inicio << endl;
    cout << "*q" << ptr_fin << endl;
    cout << "*p+1" << *(ptr_inicio+1) << endl;
    cout << "*q no usando tdv" << *ptr_fin << endl;

    if (ptr_inicio >= ptr_fin) cout << "condicion correctamente" << endl;
    for (int* p=ptr_inicio, *q=ptr_fin ; p>=q; p++, q--){
        contador++;
        cout << contador << endl;
        cout << "*p   " << *p << endl;
        cout << "*p+1   " << *(p+1) << endl;
        cout << "*q no usando tdv   " << *q << endl;

        if (*p > *p+1){
            swap(*p, *(p+1));
        }
    }
}