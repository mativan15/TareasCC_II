#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "reversy.h"
#define ROJO  "\x1b[31m"
#define RESET "\x1b[0m"
using namespace std;


void Reversy::print_tablero() {
    char (*ptr1)[8] = tablero;
    for (int i = 0; i < 8 + 2; i++) {
        cout << ROJO << " |" << RESET;
    }
    for (int i = 0; i < 9; i++,ptr1++) {
        char *ptr2 = *ptr1;
        for (int j = 0; j < 9; j++, ptr2++) { // Agregar una columna adicional para el borde izquierdo
            if (i == 0 || i == 8 || j == 0 || j == 8) {
                cout << "+ "; // Imprimir borde (+) en las esquinas y bordes
            } else if (j % 2 == 0) {
                cout << *(ptr2-1) << " "; // Imprimir pieza o espacio en blanco
            } else {
                cout << "| "; // Imprimir borde vertical (|) entre celdas
            }
        }
        cout << endl; // Saltar a la siguiente línea después de cada fila
    }
    for (int i = 0; i < 8 + 2; i++) {
        cout << ROJO << " |" << RESET;
    }
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
    char* ptr_fin = (char *)(tablero + 7);
    for (; ptr_inicio < ptr_fin; ptr_inicio++) {
        *ptr_inicio = ' ';
    }
}

