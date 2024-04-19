#include <iostream>
using namespace std;
class Binary{
public:
    int array[10];
    int* pos;
    int* buscar;
    int* ptr_inicio;
    int* ptr_fin;
    Binary(int* array_ptr);
    bool busqueda_bin();
};