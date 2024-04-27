#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "multi.h"
using namespace std;

MultiMatrix::MultiMatrix(){
    srand(time(0)); 
    int* ptr_inicio;
    int* ptr_fin;
    ptr_inicio = (int *)matriz;
    ptr_fin = (int *)(matriz + 2);
    for (; ptr_inicio < ptr_fin; ptr_inicio++) {
        *ptr_inicio = rand() % 10;
    }
    ptr1 = matriz;
    ptr3 = nullptr;
    ptr3 = nullptr;
}
void MultiMatrix::print(){
    int (*ptr1)[3][3] = matriz;
    int (*ptr2)[3] = nullptr;
    int *ptr3 = nullptr;
    for (ptr1 = matriz; ptr1 < matriz + 2; ptr1++) {
        cout << "\x1B[31m"<< "\n\tMatriz" << ptr1-matriz+1 << "\x1B[m\n";
        for (ptr2 = *ptr1; ptr2 < *ptr1 + 3; ptr2++) {
            cout << "\t";
            for (ptr3 = *ptr2; ptr3 < *ptr2 + 3; ptr3++) {
                cout << *ptr3 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
int MultiMatrix::calcular_valor(int c, int f){
    int resu{0};
    arrColu = extraer_colu(c);
    arrFila = extraer_fila(f);
    for (int* ptr_m1 = arrColu, *ptr_m2 = arrFila; ptr_m1 < arrColu+3; ptr_m1++, ptr_m2++) {
        resu += (*ptr_m1)*(*ptr_m2);
    }

    //cout << "res2 "<< resu << " ";
    return resu;
}
int* MultiMatrix::extraer_colu(int i){
    static int col[3];
    int *ptrCol = col;
    for (ptr3 = *(*ptr1+i) ; ptr3 < *(*ptr1+i) + 3; ptr3++, ptrCol++) { *ptrCol = *ptr3;}

    return col;
}
int* MultiMatrix::extraer_fila(int j){
    static int fil[3];
    int *ptrFil = fil;
    for (ptr2 = *(ptr1+1); ptr2 < *(ptr1+1) + 3; ptr2++, ptrFil++) {
        for (ptr3 = (*ptr2)+j; ptr3 < (*ptr2)+j + 1; ptr3++) {
            *ptrFil = *ptr3;
        }
    }
    return fil;
}
void MultiMatrix::multiplicar(){
    int (*ptr_1)[3][3] = matriz;
    int (*ptr_2)[3] = nullptr;
    int *ptr_3 = nullptr;
    

    cout << "\x1B[32m" << "\n\tMatriz resultante: " << "\x1B[m\n";

    int c,f{0};
    for (ptr_2 = *(ptr_1+2); ptr_2 < *(ptr_1+2) + 3; ptr_2++, f++) {
        c = 0;
        cout << "\t";
        for (ptr_3 = *ptr_2; ptr_3 < *ptr_2 + 3; ptr_3++,c++) {
            *ptr_3 = calcular_valor(f,c);
            cout << *ptr_3 << "  ";
        }
        cout  << endl;
    }
    cout << endl;
    
}