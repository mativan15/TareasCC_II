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
    void colocarPieza(char pieza, int fila, int columna);
};
#endif