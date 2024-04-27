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
    int iteracion, f, c{0};
    bool turno;
    char ficha;
    do {
        iteracion++;
        turno = turno_quien(iteracion);
        juego1.print_tablero(); 
        if (turno) {ficha = 'X';
        } else {ficha = 'O';}
        cout << "\nTurno de " << ficha<< "\n"
         << "\nUbica tu ficha!\nIngresa la fila :\n";
        cin >> f;
        if (cin.fail() || !(f >= 0 && f <= 7)){
            cout << "Posición inválida para la pieza." << endl;
            cin.clear();           
            cin.ignore(100, '\n');
            iteracion--;
            continue;
        } else {
            cout << "Ingresa la columna :\n";
            cin >> c;
            if (cin.fail() || !(c >= 0 && c <= 7)) {
                cout << "Posición inválida para la pieza." << endl;
                cin.clear();           
                cin.ignore(100, '\n');
                iteracion--;
                continue;
            } else {
                if (juego1.casilla_vacia(f,c)){
                    juego1.colocarPieza(ficha, f,c);
                    
                } else { 
                    cout << "Posición inválida para la pieza. La celda está llena!" << endl;
                    iteracion--; 
                }
                
                //this_thread::sleep_for(chrono::milliseconds(200));
                system("clear");
            }
        }
    } while (true);
}
bool turno_quien(int ite){
    if (ite%2 == 0){ return true;
    } else { return false; }
}


