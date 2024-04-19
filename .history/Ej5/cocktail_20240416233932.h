#include <iostream>

using namespace std;
class Cocktail{
public:
    int array_desordenado[10];
    int array_ordenado[10];
    int* ptr_inicio;
    int* ptr_fin;
    void print();
    int* ordenar(); 

};