#include <iostream>

using namespace std;
class MultiMatrix{
public:
    int matriz[3][3][3];
    int* ptr_inicio;
    int* ptr_fin;
    int size;
    bool repetir;
    MultiMatrix();
    void print();
    void multiplicar(); 
    void operar();
};