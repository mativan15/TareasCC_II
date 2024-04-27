#include <iostream>
#ifndef REVERSY_H
#define REVERSY_H
using namespace std;
class Reversy{
private:
  char tablero[8][8];
public:
    int size;
    bool repetir;
    Reversy();
    void imprimirCelda();
    void print_tablero();
    bool casilla_vacia(int fila, int columna);
    void checar_alrededor(char pieza, int fila, int columna);
    int checar_izquierda(char pieza, int fila, int columna);
    int checar_derecha(char pieza, int fila, int columna);
    int checar_arriba(char pieza, int fila, int columna);
    int checar_abajo(char pieza, int fila, int columna);
    void colocarPieza(char pieza, int fila, int columna);
};
#endif