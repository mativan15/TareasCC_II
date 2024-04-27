#include <iostream>

using namespace std;
class MultiMatrix{
public:
    int matriz[3][3][3];
    int m1[3];
    int m2[3];
    int (*ptr1)[3][3];
    int (*ptr2)[3];
    int *ptr3, *arrColu, *arrFila;
    int size;
    bool repetir;
    MultiMatrix();
    void print();
    void multiplicar(); 
    int calcular_valor();
    int* extraer_colu(int i);
    int* extraer_fila(int j);
};