#include <iostream>

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