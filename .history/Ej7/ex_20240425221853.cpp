#include <iostream>
#include <chrono>
#include <thread>
#include "reversy.h"
#include "header.h"
using namespace std;
void inicio(){
    bool bucle{true};
    int res{0};
    do {
        Reversy juego1;
        cout << "\x1B[36m" << "\n\n\tBienvenido:" << "\x1B[m\n";
        jugar(juego1);
          
        //cout << "\n\n\tIngresa la fila del :" << "\n";
        cout << "\n\n\tIngrese 1 para repetir" << "\n\t";
        cin >> res;
        if (res != 1) {
            bucle = false;
            break;
        } else {
            bucle = true;
        } 

    }while (bucle);
}
void jugar(Reversy juego1){
    int turno{0};
    do {
        juego1.print_tablero(); 
        cout << "\n\n\tIngresa la fila del :" << "\n";

        this_thread::sleep_for(std::chrono::milliseconds(2000));
    } while (true);
    
}


