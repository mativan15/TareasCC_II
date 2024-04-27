#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ncurses.h>
#include "reversy.h"
#define ROJO  "\x1b[31m"
#define RESET "\x1b[0m"
// ANSI escape codes for text colors
#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// ANSI escape codes for background colors
#define ANSI_BG_BLACK   "\x1b[40m"
#define ANSI_BG_RED     "\x1b[41m"
#define ANSI_BG_GREEN   "\x1b[42m"
#define ANSI_BG_YELLOW  "\x1b[43m"
#define ANSI_BG_BLUE    "\x1b[44m"
#define ANSI_BG_MAGENTA "\x1b[45m"
#define ANSI_BG_CYAN    "\x1b[46m"
#define ANSI_BG_WHITE   "\x1b[47m"
using namespace std;


void Reversy::print_tablero() {
    /*char (*ptr1)[8] = tablero;
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
    }*/
// Inicializar ncurses
    initscr();
    start_color();
    use_default_colors();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);

    // Establecer el tamaño de la ventana
    int height = 10; // Altura total (8 celdas + 2 bordes)
    int width = 26; // Ancho total (8 celdas + 2 bordes)
    int starty = (LINES - height) / 2; // Calcular la posición y para centrar la ventana
    int startx = (COLS - width) / 2; // Calcular la posición x para centrar la ventana

    // Crear la ventana
    WINDOW *win = newwin(height, width, starty, startx);
    refresh();

    // Imprimir bordes
    attron(COLOR_PAIR(1)); // Activar el par de colores blanco y negro
    box(win, 0, 0); // Dibujar el borde alrededor de la ventana
    attroff(COLOR_PAIR(1)); // Desactivar el par de colores

    // Imprimir celdas
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            mvwaddch(win, i, j * 3, ' '); // Espacio para la celda
            wrefresh(win);
        }
    }

    // Esperar la pulsación de una tecla antes de salir
    getch();

    // Limpiar y cerrar ncurses
    endwin();
    }

    // Print bottom border
    cout << ANSI_BG_YELLOW;
    for (int i = 0; i < 34; ++i) {
        cout << "-";
    }
    cout << endl;
    cout << ANSI_BG_BLACK << endl;
    cout << endl;
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

