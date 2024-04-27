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
    int iteracion{0};
    bool turno;
    do {
        
        turno = turno_quien(iteracion);
        juego1.print_tablero(); 
        if (turno) {cout << "\nTurno de X" << "\n";
        } else {cout << "\nTurno de O" << "\n";}

        cout << "\n\n\tIngresa la fila del :" << "\n";

        this_thread::sleep_for(chrono::milliseconds(2000));
        system("clear");

    } while (true);
    
}
bool turno_quien(int ite){
    if (ite%2 == 0){ return true;
    } else { return false; }
}


