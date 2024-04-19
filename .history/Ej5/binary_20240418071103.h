#include <iostream>
using namespace std;
class Binary{
public:
    int array[10];
    int* pos;
    int* buscar;
    Binary(int* array_ptr);
    bool busqueda_bin();
};