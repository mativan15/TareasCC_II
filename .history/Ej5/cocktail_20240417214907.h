#include <iostream>

using namespace std;
class Cocktail{
public:
    int array_desordenado[10] = {78,99,61,3,2,45,10,56,19,20};
    int array_ordenado[10];
    int* ptr_inicio;
    int* ptr_fin;
    bool repetir;
    Cocktail();
    void print();
    void ordenar(); 

};