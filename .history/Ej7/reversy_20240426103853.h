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
    void checar_alrededor(int fila, int columna);
    void colocarPieza(char pieza, int fila, int columna);
};
#endif