#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "reversy.h"
#define ROJO     "\x1b[31m"
#define RESET   "\x1b[0m"

using namespace std;


void Reversy::print_tablero() {
    char (*ptr1)[8] = tablero;
    
    cout << "\033[1;31m" << "\u2588\u2588\u2588\u2588";
    for (int l = 0; l < 30; ++l) {
        cout << "\u2588";
        if (l %3 == 0) {cout << l/3;}
    }
    cout << "\033[0m" << endl; 

    for (int i = 0; i < 8; i++,ptr1++) {
        char *ptr2 = *ptr1;
        cout << "\033[1;31m" << "\u2588" << i << "\u2588" << "\033[0m";
        for (int j = 0; j < 8; j++, ptr2++) { // Agregar una columna adicional para el borde izquierdo
            cout  << "| " << *(ptr2) << " "; // Imprimir pieza o espacio en blanco
            
            
        }
        cout  << "|" << "\033[1;31m" << "\u2588\u2588" << "\033[0m\n" 
         << "\033[1;31m" << "\u2588\u2588\u2588" << "\033[0m" << "_________________________________" << "\033[1;31m" << "\u2588\u2588" << "\033[0m\n";
    }


    cout << "\033[1;31m"; 
    for (int i = 0; i < 19; ++i) {
        cout << "\u2588\u2588";
    }
    cout << "\033[0m" << endl; 

}

void Reversy::colocarPieza(char pieza, int fila, int columna) {
    if (fila >= 0 && fila < 8 && columna >= 0 && columna < 8) {
      tablero[fila][columna] = pieza;
    } else {
      cout << "Posición inválida para la pieza." << endl;
    }
}

/*
void Reversy::moverPieza(char pieza, int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino) {
    if (filaOrigen >= 0 && filaOrigen < 8 && columnaOrigen >= 0 && columnaOrigen < 8 &&
        filaDestino >= 0 && filaDestino < 8 && columnaDestino >= 0 && columnaDestino < 8) {
      if (tablero[filaOrigen][columnaOrigen] == pieza) {
        tablero[filaOrigen][columnaOrigen] = ' '; // Celda de origen vacía
        tablero[filaDestino][columnaDestino] = pieza; // Celda de destino con la pieza
      } else {
        std::cout << "No hay pieza '" << pieza << "' en la casilla (" << filaOrigen << "," << columnaOrigen << ")."<< std::endl;
      }
    } else {
      std::cout << "Posición inválida para mover la pieza." << std::endl;
    }
}*/

Reversy::Reversy(){
    char* ptr_inicio = (char *)tablero;
    char* ptr_fin = (char *)(tablero + 8);
    for (; ptr_inicio < ptr_fin; ptr_inicio++) {
        *ptr_inicio = ' ';
    }
}

