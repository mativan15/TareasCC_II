#include <iostream>
#include "romanos.h"
using namespace std;

void iniciar(){
    bool bucle{true};
    int numero{0};
    do {
        cout << "\x1B[31m" << "\n\n\tBienvenido, ingresa un número del 1-9999: " << "\x1B[m \n\t";
        cin >> numero;
        if (cin.fail() || !(numero >= 1 && numero <= 9999)) {
            cout << "\nValor incorrecto! Ingrese una opcion válida:\n\n"; 
            cin.clear();           
            cin.ignore(100, '\n');
        } else {
            Romanos rom1(numero);
            rom1.print_num();
            int res;
            cout << "\n\tIngrese 1 para repetir" << "\n\t";
            cin >> res;
            if (res != 1) {
                bucle = false;
                break;
            }
        }
    } while (bucle);
}


