#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "reversy.h"
#define ROJO     "\x1b[31m"
#define RESET   "\x1b[0m"

using namespace std;


void Reversy::print_tablero() {
    char (*ptr1)[8] = tablero;
    cout << "\033[1;31m" << "\u2588\u2588\u2588";
    for (int l = 0; l < 24; ++l) {
        cout << "\u2588";
        if (l %3 == 0) {cout << l/3;}
    }
    cout << "\u2588\u2588" << "\033[0m" << endl; 
    for (int i = 0; i < 8; i++,ptr1++) {
        char *ptr2 = *ptr1;
        cout << "\033[1;31m" << i << "\u2588" << "\033[0m";
        for (int j = 0; j < 8; j++, ptr2++) {
            cout  << "| " << *(ptr2) << " ";
        }
        cout  << "|" << "\033[1;31m" << "\u2588\u2588" << "\033[0m\n" 
         << "\033[1;31m" << "\u2588\u2588" << "\033[0m" << "---------------------------------" << "\033[1;31m" << "\u2588\u2588" << "\033[0m\n";
    }
    cout << "\033[1;31m"; 
    for (int l = 0; l < 36; ++l) {
        cout << "\u2588";
    }
    cout << "\033[0m" << endl; 
}
bool Reversy::casilla_vacia(int fila, int columna) {
    char (*ptr1)[8] = tablero;
    char *ptr2 = *(ptr1+fila);
    if (*(ptr2+columna) == ' ') { return true; }
    else { return false; }
}
        
void Reversy::colocarPieza(char pieza, int fila, int columna) {
    char (*ptr1)[8] = tablero;
    char *ptr2 = *(ptr1+fila);
    if (*(ptr2+columna) == ' ') 
        {*(ptr2+columna) = pieza;}
    cerr << "pieza colocada en " << fila << columna << endl;
}

void Reversy::checar_alrededor(char pieza, int fila, int columna) {
    char (*ptr1)[8] = tablero;
    char *ptr2 = *(ptr1+fila);
    int llenar_izquierda{0};
    llenar_izquierda = checar_izquierda(pieza, fila, columna);
    for (int i=1; i <= llenar_izquierda; i++) {
        colocarPieza(pieza, fila, columna-i);
    }

}
int Reversy::checar_izquierda(char pieza, int fila, int columna) {
    char (*ptr1)[8] = tablero;
    char *ptr2 = *(ptr1+fila);
    int rellenar{0};
    for (int i = 0; i < columna; i++) {
        if (*(ptr2+columna-i) == pieza) {
            break;
        } 
        if (!(*(ptr2+columna-i) == ' ')) {
            rellenar++;
        } else { 
            break;
        }
    }
    cout << endl <<"rellenar izq" << rellenar << endl;
    return rellenar;
}


Reversy::Reversy(){
    char* ptr_inicio = (char *)tablero;
    char* ptr_fin = (char *)(tablero + 8);
    for (; ptr_inicio < ptr_fin; ptr_inicio++) {
        *ptr_inicio = ' ';
    }
    colocarPieza('X', 3,3);
    colocarPieza('X', 4,4);
    colocarPieza('O', 3,4);
    colocarPieza('O', 4,3);
}

