#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "reversy.h"
using namespace std;


void Reversy::print_tablero() {
    char (*ptr1)[8] = tablero;
    cout << "\n\033[1;31m" << "\u2588\u2588\u2588";
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
    for (int l = 0; l < 37; ++l) {
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
    *(ptr2+columna) = pieza;
}

void Reversy::checar_alrededor(char pieza, int fila, int columna) {
    char (*ptr1)[8] = tablero;
    char *ptr2 = *(ptr1+fila);
    int llenar_izquierda, llenar_derecha, llenar_arriba, llenar_abajo{0};
    llenar_izquierda = checar_izquierda(pieza, fila, columna);
    for (int i=1; i <= llenar_izquierda; i++) { colocarPieza(pieza, fila, columna-i);}
    llenar_derecha = checar_derecha(pieza, fila, columna);
    for (int i=1; i <= llenar_derecha; i++) { colocarPieza(pieza, fila, columna+i);}
    llenar_arriba = checar_arriba(pieza, fila, columna); //pendiente de ajustar fucnionessssss
    for (int i=1; i <= llenar_arriba; i++) { colocarPieza(pieza, fila-i, columna);}
    llenar_abajo = checar_abajo(pieza, fila, columna);
    for (int i=1; i <= llenar_abajo; i++) { colocarPieza(pieza, fila+i, columna);}

}
int Reversy::checar_izquierda(char pieza, int fila, int columna) {
    char (*ptr1)[8] = tablero;
    char *ptr2 = *(ptr1+fila);
    int rellenar{0};
    for (int i = 1; i <= columna; i++) {
        if (*(ptr2+columna-i) == pieza) {
            break;
        } 
        if (!(*(ptr2+columna-i) == ' ')) {
            rellenar++;
        } else { 
            rellenar=0;
            break;
        }
    }
    return rellenar;
}
int Reversy::checar_derecha(char pieza, int fila, int columna) {
    char (*ptr1)[8] = tablero;
    char *ptr2 = *(ptr1+fila);
    int rellenar{0};
    for (int i = 1; i <= (7-columna); i++) {
        if (*(ptr2+columna+i) == pieza) {
            break;
        } 
        if (!(*(ptr2+columna+i) == ' ')) {
            rellenar++;
        } else { 
            rellenar=0;
            break;
        }
    }
    return rellenar;
}

int Reversy::checar_arriba(char pieza, int fila, int columna) {
    char (*ptr1)[8] = tablero;
    int rellenar{0};
    for (int i = 1; i <= fila; i++) {
        char *ptr2 = *(ptr1+fila-i);
        if (*(ptr2+columna) == pieza) {
            cout << endl <<"pieza identica encontrada -> fin " << rellenar << endl;
            break;
        } 
        if (!(*(ptr2+columna) == ' ')) {
            cout << endl <<"pieza opuesta encontrada -> continuaaa " << rellenar << endl;
            rellenar++;
        } else { 
            cout << endl <<"pvacio encontrada -> reset " << rellenar << endl;
            rellenar=0;
            break;
        }
    }
    cout << endl <<"rellenar arr" << rellenar << endl;
    return rellenar;
}
int Reversy::checar_abajo(char pieza, int fila, int columna) {
    char (*ptr1)[8] = tablero;
    int rellenar{0};
    for (int i = 1; i <= (7-fila); i++) {
        char *ptr2 = *(ptr1+fila+i);
        if (*(ptr2+columna) == pieza) {
            break;
        } 
        if (!(*(ptr2+columna) == ' ')) {
            rellenar++;
        } else { 
            rellenar=0;
            break;
        }
    }
    return rellenar;
}
bool Reversy::contador() {
    char* ptr_inicio = (char *)tablero;
    char* ptr_fin = (char *)(tablero + 8);
    equis=0;
    circulo=0;
    for (; ptr_inicio < ptr_fin; ptr_inicio++) {
        if (*ptr_inicio == 'X'){ ++equis; }
        else if (*ptr_inicio == 'O'){ ++circulo; }
    }
    cout << endl << "Jugador X: " << equis << endl << "Jugador O: " << circulo << endl;
    if (equis+circulo == 64) {
        if (equis>circulo){cout << "\n\tHa ganado el jugador X!"; }  
        else if (equis<circulo){cout << "\n\tHa ganado el jugador O!"; }
        else {cout << "\n\tEmpate!"; }
        return true;
    } else {
        return false;
    }
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

