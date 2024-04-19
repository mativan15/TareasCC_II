#include <iostream>
using namespace std;
class Binary{
public:
    int array[10];
    int* pos;
    int buscar;
    int* ptr_inicio;
    int* ptr_fin;
    bool repetir;
    Binary();
    void asignar_array(int* array_ptr);
    bool busqueda_bin();
    void print();
    void ejecutar();
};