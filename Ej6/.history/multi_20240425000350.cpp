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
void MultiMatrix::multiplicar(){
    int (*ptr1)[3][3] = matriz;
    int (*ptr2)[3] = nullptr;
    int *ptr3 = nullptr;
    cout << endl;
    for (ptr3 = **ptr1; ptr3 < **ptr1 + 3; ptr3++) {
        //*ptr3 = ***ptr1;
        cout << *ptr3 << " ";
    }
    cout << endl;
    for (ptr2 = *(ptr1+1); ptr2 < *(ptr1+1) + 3; ptr2++) {
        for (ptr3 = *ptr2; ptr3 < *ptr2 + 3; ptr3++) {
            //*ptr3 = ***ptr1;
            cout << *ptr3 << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (ptr2 = *(ptr1+2); ptr2 < *(ptr1+2) + 3; ptr2++) {
        for (ptr3 = *ptr2; ptr3 < *ptr2 + 3; ptr3++) {
            //*ptr3 = ***ptr1;
            cout << *ptr3 << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}