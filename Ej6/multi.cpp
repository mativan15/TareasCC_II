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
    int resultado[3][3][3] = {0}; // Inicializamos la matriz resultado con ceros

    // Puntero para recorrer la matriz de resultados
    int (*ptr_resultado)[3][3] = resultado;

    // Puntero para recorrer la primera matriz (primer multiplicando)
    int (*ptr_matriz1)[3][3] = matriz[0];

    // Puntero para recorrer la segunda matriz (segundo multiplicando)
    int (*ptr_matriz2)[3][3] = matriz[1];

    // Puntero para recorrer la tercera matriz (resultado)
    int (*ptr_resultado_actual)[3] = nullptr;

    // Iteramos sobre las filas de la primera matriz
    for (int i = 0; i < 3; i++) {
        // Iteramos sobre las columnas de la segunda matriz
        for (int j = 0; j < 3; j++) {
            // Iteramos sobre las filas de la segunda matriz
            for (int k = 0; k < 3; k++) {
                // Multiplicamos los elementos correspondientes de las matrices
                for (int l = 0; l < 3; l++) {
                    resultado[i][j][k] += matriz[0][i][l] * matriz[1][l][k];
                }
            }
        }
    }

    // Copiamos el resultado a la tercera matriz en el objeto MultiMatrix
    for (int i = 0; i < 3; i++) {
        ptr_resultado_actual = ptr_resultado[i];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                *ptr_resultado_actual = resultado[i][j][k];
                ptr_resultado_actual++;
            }
        }
    }
}