#include <iostream>
#include <cstdlib>
#include "cocktail.h"
using namespace std;

Cocktail::Cocktail(){
    srand(time(0)); 
    for (int i = 0; i < 10; i++) {
        array_desordenado[i] = rand() % 100;
    }
    ptr_inicio = array_desordenado;
    ptr_fin = array_desordenado+5;
}
void Cocktail::print(){
    cout << ptr_inicio << endl
      << ptr_fin << endl
      << *ptr_inicio << endl
      << *ptr_fin << endl;
    cout << "Random array: ";
    for (int i = 0; i < 10; i++) {
        cout << array_desordenado[i] << " ";
    }
    cout << endl<<endl;

    char B[5]={"hugo"};
    cout << B << endl; // hugo

    char C[3][5]={"hugo", "paco", "luis"};
    cout << C << endl; //0x16b8df578
    cout << *C << endl; // hugo
    cout << *(C+1) << endl; // paco
    cout << *C+1 << endl; // ugo
    cout << *C+5 << endl; // paco
    cout << *(*C+1) << endl;// u
}
int* Cocktail::ordenar(){
    
}