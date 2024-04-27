#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "multi.h"
using namespace std;

MultiMatrix::MultiMatrix(){
    srand(time(0)); 
    ptr_inicio = (int *)matriz;
    ptr_fin = (int *)(matriz + 2);
    for (; ptr_inicio < ptr_fin; ptr_inicio++) {
        *ptr_inicio = rand() % 25;
    }

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
int MultiMatrix::operar(){
    int resu;
    for (int i = 0; i < 3; i++) {
        resu += m1[i]*m2[i];
    }
    //int* ptr_m;
    for (int* ptr_m1 = m1, *ptr_m2 = m2; ptr_m1 < m1+3; ptr_m1++) {
        resu += (*ptr_m1)*(*ptr_m2);
    }
    return resu;
}
void MultiMatrix::multiplicar(){
    int (*ptr1)[3][3] = matriz;
    int (*ptr2)[3] = nullptr;
    int *ptr3 = nullptr;
    
    //int valor4,valor5,valor6 {0};
    cout << endl;
    int i=0;
    for (ptr3 = **ptr1 ; ptr3 < **ptr1 + 3; ptr3++,i++) {
        m1[i] = *ptr3;
        cout << m1[i] << " ";

    }
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
    for (ptr2 = *(ptr1+2); ptr2 < *(ptr1+2) + 3; ptr2++) {
        for (ptr3 = *ptr2; ptr3 < *ptr2 + 3; ptr3++) {
            
            *ptr3 = operar();
            cout << *ptr3 << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}