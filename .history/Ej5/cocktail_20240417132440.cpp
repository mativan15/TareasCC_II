#include <iostream>
#include <cstdlib>
#include "cocktail.h"
using namespace std;

Cocktail::Cocktail(){
    srand(time(0)); 
    for (int i = 0; i < 10; i++) {
        array_desordenado[i] = rand() % 100;
    }
    ptr_inicio = nullptr;
    ptr_fin = nullptr;
}
void Cocktail::print(){
    cout << "Random array: ";
    for (int i = 0; i < 10; i++) {
        cout << array_desordenado[i] << " ";
    }
    cout << endl;
}
int* Cocktail::ordenar(){
    
}