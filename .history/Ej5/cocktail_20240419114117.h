#include <iostream>

using namespace std;
class Cocktail{
public:
    int array_desordenado[20];
    int array_ordenado[20];
    int* ptr_inicio;
    int* ptr_fin;
    bool repetir;
    Cocktail();
    void print();
    void ordenar(); 

};