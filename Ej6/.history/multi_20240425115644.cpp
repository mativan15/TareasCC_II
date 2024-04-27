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
        *ptr_inicio = rand() % 5;
    }
    ptr1 = matriz;
    ptr3 = nullptr;
    ptr3 = nullptr;
}
void MultiMatrix::print(){
    int (*ptr1)[3][3] = matriz;
    int (*ptr2)[3] = nullptr;
    int *ptr3 = nullptr;
    for (ptr1 = matriz; ptr1 < matriz + 3; ptr1++) {
        cout << "\nMatriz" << ptr1-matriz+1<< endl;
        for (ptr2 = *ptr1; ptr2 < *ptr1 + 3; ptr2++) {
            for (ptr3 = *ptr2; ptr3 < *ptr2 + 3; ptr3++) {
                cout << *ptr3 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
int MultiMatrix::calcular_valor(){
    int resu{0};

    for (int* ptr_m1 = arrColu, *ptr_m2 = m2; ptr_m1 < arrColu+3; ptr_m1++, ptr_m2++) {
        resu += (*ptr_m1)*(*ptr_m2);
    }
    //cout << "res2 "<< resu << " ";
    return resu;
}
int* MultiMatrix::extraer_colu(int i){
    //int (*ptr_inicio)[3][3] = matriz;
    //int *ptr3 = nullptr;
    //int *col = new int[3];
    static int col[3];
    int *ptrCol = col;
    for (ptr3 = *(*ptr1+i) ; ptr3 < *(*ptr1+i) + 3; ptr3++, ptrCol++) { *ptrCol = *ptr3;}
    return col;
}
int* MultiMatrix::extraer_fila(int j){
    //int (*ptr_inicio)[3][3] = matriz;
    //int *ptr3 = nullptr;
    //int *col = new int[3];
    static int fil[3];
    int *ptrFil = fil;
    for (ptr2 = *(ptr1+1); ptr2 < *(ptr1+1) + 3; ptr2++, ptrFil++) {
        for (ptr3 = *(ptr2+j); ptr3 < *(ptr2+j) + 1; ptr3++) {
            *ptrFil = *ptr3;
            cout << *ptrFil << " \n";
        }
        cout << endl;
    }
    return fil;
}
void MultiMatrix::multiplicar(){
    //int (*ptr2)[3] = nullptr;
    //int *ptr3 = nullptr;
    
    //int valor4,valor5,valor6 {0};

    cout << endl;
    arrColu = extraer_colu(0);
    cout << endl << *arrColu << " " << *(arrColu+1) << " " << *(arrColu+2) << " ";
    arrColu = extraer_colu(1);
    cout << endl << *arrColu << " " << *(arrColu+1) << " " << *(arrColu+2) << " ";
    arrColu = extraer_colu(2);
    cout << endl << *arrColu << " " << *(arrColu+1) << " " << *(arrColu+2) << " ";
    cout << endl;

    int j=0;
    //cout << "\nvalorrr" << valor1 << endl;
    for (ptr2 = *(ptr1+1); ptr2 < *(ptr1+1) + 3; ptr2++, j++) {
        for (ptr3 = *ptr2; ptr3 < *ptr2 + 1; ptr3++) {
            m2[j] = *ptr3;
            cout << m2[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    arrFila = extraer_fila(0);
    //cout << endl << *arrFila << " " << *(arrFila+1) << " " << *(arrFila+2) << " ";
    arrFila = extraer_fila(1);
    //cout << endl << *arrFila << " " << *(arrFila+1) << " " << *(arrFila+2) << " ";
    arrFila = extraer_fila(2);
    //cout << endl << *arrFila << " " << *(arrFila+1) << " " << *(arrFila+2) << " ";
    cout << endl;
    for (ptr2 = *(matriz+2); ptr2 < *(matriz+2) + 3; ptr2++) {
        for (ptr3 = *ptr2; ptr3 < *ptr2 + 3; ptr3++) {
            //if ((ptr2 = *(matriz+2)) && (ptr3 = **(matriz+2))){
                *ptr3 = calcular_valor();
            //}
            //
            cout << *ptr3 << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}