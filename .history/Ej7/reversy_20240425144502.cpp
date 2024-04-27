#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "reversy.h"
using namespace std;


  // Mostrar el tablero en la consola
void Reversy::mostrarTablero() {
    for (int i = 0; i < 9; i++) { // Agregar una fila adicional para el borde superior
        for (int j = 0; j < 9; j++) { // Agregar una columna adicional para el borde izquierdo
        if (i == 0 || i == 8 || j == 0 || j == 8) {
            std::cout << "+ "; // Imprimir borde (+) en las esquinas y bordes
        } else if (j % 2 == 0) {
            std::cout << tablero[i - 1][j - 1] << " "; // Imprimir pieza o espacio en blanco
        } else {
            std::cout << "| "; // Imprimir borde vertical (|) entre celdas
        }
        }
        std::cout << std::endl; // Saltar a la siguiente línea después de cada fila
    }
}

  // Colocar una pieza en una casilla específica
  void Reversy::colocarPieza(char pieza, int fila, int columna) {
    if (fila >= 0 && fila < 8 && columna >= 0 && columna < 8) {
      tablero[fila][columna] = pieza;
    } else {
      std::cout << "Posición inválida para la pieza." << std::endl;
    }
  }

  // Mover una pieza de una casilla a otra
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
  }

Reversy::Reversy(){
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        tablero[i][j] = ' '; // Celda vacía
      }
    }
}
void Reversy::print(){
    
}
