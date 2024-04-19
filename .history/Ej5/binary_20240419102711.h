#include <iostream>
using namespace std;
class Binary{
public:
    int array[10];
    int buscar, pos;
    int* ptr_medio;
    int* ptr_inicio;
    int* ptr_fin;
    bool repetir;
    Binary();
    void asignar_array(int* array_ptr);
    bool busqueda_bin();
    void print();
    void ejecutar();
};