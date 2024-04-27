#include <iostream>

using namespace std;
class MultiMatrix{
public:
    int matriz[3][3][3];
    int m1[3];
    int m2[3];
    int* ptr_inicio;
    int* ptr_fin;
    int size;
    bool repetir;
    MultiMatrix();
    void print();
    void multiplicar(); 
    int operar();
};